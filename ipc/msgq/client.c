#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

#define MSG_FILE_NAME  "/tmp/msgq_test"

#define WRITE_BUFF_LEN  1000
#define READ_BUFF_LEN  1000

#define MSG_TYPE_CLIENT 888
#define MSG_TYPE_SERVER 999


struct msg_form
{
  long type;
  char ctx[READ_BUFF_LEN];
};

int main(int argc, char** atgv)
{
  key_t key = ftok(MSG_FILE_NAME,'z');
  if (-1 == key)
  {
    printf("MSG QUENE: failed to create key, error=%s\n", strerror(errno));
    exit(-1);
  } 

  int msgid = msgget(key, IPC_CREAT|0777);
  if (-1 == msgid)
  {
    printf("MSG QUENE: failed to create msgid, error=%s\n", strerror(errno));
    exit(-1);
  }

  printf("MSG QUENE: my msqid is: %d.\n", msgid);
  printf("MSG QUENE: my pid is: %d.\n", getpid());

  struct msg_form *msg = malloc(sizeof(struct msg_form));
  int ret = -1;
  while(1)
  {
    printf("Please input something to send:\n");
    msg->type = MSG_TYPE_CLIENT;
    scanf("%s", msg->ctx);
    ret = msgsnd(msgid, msg, sizeof(msg->ctx), 0);
    if (-1 == ret)
    {
      printf("MSG QUENE: client send error=%s\n", strerror(errno));
      continue;
    }

    ret = msgrcv(msgid, msg, READ_BUFF_LEN, MSG_TYPE_SERVER, 0);
    if (-1 == ret)
    {
      printf("MSG QUENE: client recv error=%s\n", strerror(errno));
      continue;
    }
    printf("MSG QUENE: client receive msg.type=%ld, msg.ctx=%s.\n", msg->type, msg->ctx);

  }

  return 0;
  
}
