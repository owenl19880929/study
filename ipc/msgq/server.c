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
  //printf("MSG QUENE: my pid is: %d.\n", getpid());

  pid_t pid;
  pid = fork();

  if (0 == pid)
  {
  	struct msg_form *msgrecv = malloc(sizeof(struct msg_form));
  	int ret1 = -1;
  	while(1)
  	{
    		ret1 = msgrcv(msgid, msgrecv, READ_BUFF_LEN, MSG_TYPE_CLIENT, 0);
    		if (-1 == ret1)
    		{
      			printf("MSG QUENE: server recv error=%s\n", strerror(errno)); 
      			continue;
    		}
    		printf("MSG QUENE: server child proces receive msg.type=%ld, msg.ctx=%s.\n", msgrecv->type, msgrecv->ctx);
                if(0 == strncmp(msgrecv->ctx, "q", sizeof("r")))
                {
                  msgctl(msgid, IPC_RMID, 0);
                  break;
                }
 
  	}
  }

  struct msg_form *msgsend = malloc(sizeof(struct msg_form));
  int ret2 = -1;
  while(1)
  {
    printf("Please input something to send:\n");

    msgsend->type = MSG_TYPE_SERVER;
    scanf("%s", msgsend->ctx);
    ret2 = msgsnd(msgid, msgsend, sizeof(msgsend->ctx), 0);
    if (-1 == ret2)
    {
      printf("MSG QUENE: server send error=%s\n", strerror(errno));
      continue;
    }

  }
  msgctl(msgid, IPC_RMID, 0);
  return 0;
  
}
