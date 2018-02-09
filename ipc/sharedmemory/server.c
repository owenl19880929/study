#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <errno.h>
#include <string.h>

#include "shmsem.h"

/***start definition for global***/
#define SERVER_FAILED -1
#define SERVER_SUCCESS 0
/***end definition for global***/

/***start definition for message queue***/
#define MSG_FILE_NAME  "/tmp/msgq_test"

#define WRITE_BUFF_LEN  1000
#define READ_BUFF_LEN  1000

#define MSG_TYPE_CLIENT 888
#define MSG_TYPE_SERVER 999
/***end definition for message queue***/

typedef struct msg_form
{
  long type;
  char ctx[READ_BUFF_LEN];
}msg_form_t;

int main(int argc, char** argv)
{
  printf("Server setup, listening...\n");
  
  /***init semaphore***/
  sem_t* mutex;
  mutex = sem_open(SEM_NAME, O_CREAT, 0644, 1); 
  if(mutex == SEM_FAILED)
  {
    printf("Server create semphore failed, error: %s\n", strerror(errno));
    sem_unlink(SEM_NAME);
    exit(SERVER_FAILED);
  } 

  /***init msgq***/
  int msgid = msgget(key, IPC_CREAT|0777);
  if(-1 == msgid) 
  {
    printf("Server get message queue failed, error: %s\n", strerror(errno));
    sem_unlink(SEM_NAME);
    exit(SERVER_FAILED);
  }

  /***init shared memory***/
  char* shm;
  int shmid;
  shmid = shmget(key, SHMSZ, IPC_CREAT|0644);
  if(-1 == shmid)
  {
    printf("Server get shared memory failed, error: %s\n", strerror(errno));
    msgctl(msgid, IPC_RMID, 0);
    sem_unlink(SEM_NAME);
    exit(SERVER_FAILED);
  }
  shm = shmat(shmid, NULL, 0);

  /***wait for client mseeage***/
  msg_form_t* msgrecv = malloc(sizeof(msg_form_t));
  int ret;
  int close = 0;
  char shmbuff[128];
  while(1)
  {
    ret = msgrcv(msgid, msgrecv, READ_BUFF_LEN, MSG_TYPE_CLIENT, 0);
    if(-1 == ret)
    {
       printf("Server recv message failed, error: %s\n", strerror(errno));
       continue;
    }
    printf("Server receive msg.type=%ld, msg.ctx=%s.\n", msgrecv->type, msgrecv->ctx);
   
    if(0 == strncmp(msgrecv->ctx, "r", sizeof("r"))) 
    {
      sem_wait(mutex);
      strncpy(shmbuff, shm, strlen(shm)+1);
      snprintf(shm, strlen(shm)+7, "***%s***", shmbuff);
      sem_post(mutex);
    }
    else if(0 == strncmp(msgrecv->ctx, "q", sizeof("q")))
    {
      break;
    }
    else 
    {
      printf("Server get unsupported cmd, continue\n");
    }
  }
  
  msgctl(msgid, IPC_RMID, 0);
  shmctl(shmid, IPC_RMID, 0);
  sem_close(mutex);
  sem_unlink(SEM_NAME);

  return SERVER_SUCCESS;
}
