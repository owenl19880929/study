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
#define CLIENT_FAILED -1
#define CLIENT_SUCCESS 0
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
  printf("Client setup...\n");
  
  /***init semaphore***/
  sem_t* mutex;
  mutex = sem_open(SEM_NAME, O_CREAT, 0644, 1); 
  if(mutex == SEM_FAILED)
  {
    printf("Client create semphore failed, error: %s\n", strerror(errno));
    sem_unlink(SEM_NAME);
    exit(CLIENT_FAILED);
  } 

  /***init msgq***/
  int msgid = msgget(key, IPC_CREAT|0777);
  if(-1 == msgid) 
  {
    printf("Client get message queue failed, error: %s\n", strerror(errno));
    sem_unlink(SEM_NAME);
    exit(CLIENT_FAILED);
  }

  /***init shared memory***/
  char* shm;
  int shmid;
  shmid = shmget(key, SHMSZ, IPC_CREAT|0644);
  if(-1 == shmid)
  {
    printf("Client get shared memory failed, error: %s\n", strerror(errno));
    msgctl(msgid, IPC_RMID, 0);
    sem_unlink(SEM_NAME);
    exit(CLIENT_FAILED);
  }
  shm = shmat(shmid, NULL, 0);

  /***get user onput and send mseeage***/
  msg_form_t* msg = malloc(sizeof(msg_form_t));
  int ret;
  int close = 0;
  char* shmbuff;
  while(1)
  {
    char c;
    printf("Please input cmd: r or q\n");
    printf("->");
    scanf("%s", &c);
    switch(c)
    {
      case 'r':
        printf("Client input r\n");
        sem_wait(mutex);
        printf("Client please input something to shared memory\n");
        printf("->");
        scanf("%s", shm);
        sem_post(mutex);

        msg->type = MSG_TYPE_CLIENT;
        snprintf(msg->ctx, sizeof("r"), "r");
        ret = msgsnd(msgid, msg, sizeof(msg->ctx), 0);
        if(-1 == ret)
        {
          printf("Client send message failed, error: %s\n", strerror(errno));
          continue;
        }
        sleep(1);       
        sem_wait(mutex);
        printf("Client show shared memory: %s\n", shm);
        sem_post(mutex);
        break;

      case 'q':
        msg->type = MSG_TYPE_CLIENT;
        snprintf(msg->ctx, sizeof("q"), "q");
        ret = msgsnd(msgid, msg, sizeof(msg->ctx), 0);
        close = 1;
        if(-1 == ret)
        {
          printf("Client send message failed, error: %s\n", strerror(errno));
          continue;
        }
        break;
      case '\n':
      case '\r':
        break;
      default:
        printf("Cmd not supported, continue\n");
        break;
    }
    
    if(1 ==close)
      break;
   
  }
  
  //msgctl(msgid, IPC_RMID, 0);
  //shmctl(shmid, IPC_RMID, 0);
  sem_close(mutex);
  //sem_unlink(SEM_NAME);

  return CLIENT_SUCCESS;
}
