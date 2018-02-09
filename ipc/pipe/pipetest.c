#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>


#define WRITE_BUFF_LEN  1000
#define READ_BUFF_LEN  1000

int main(int argc, char** atgv)
{
  int fd[2];
  int ret = -1;
  ret = pipe(fd);
  int readFD = fd[0];
  int writeFD = fd[1];

  if (-1 == ret)
  {
    printf("pipe test: failed to create pipe\n");
  }

  pid_t pid;
  pid = fork();

  if (0 == pid)
  {
    int writeLen = 0;
    char writeBuf[WRITE_BUFF_LEN];
    memset(writeBuf, 0, sizeof(writeBuf));
    close(readFD);
    while(1)
    {
      printf("Please input something:\n");
      scanf("%s", writeBuf);
      writeBuf[strlen(writeBuf)] = '\0';
      writeLen = write(writeFD, writeBuf, strlen(writeBuf));
      printf("pipe test: Child write-->%s, length=%d\n", writeBuf, writeLen);
      sleep(1);
    }

  }
  else
  {
    char readBuf[READ_BUFF_LEN];
    int readLen = 0;
    close(writeFD);
  
    while(1)
    { 
      memset(readBuf, 0, READ_BUFF_LEN);
      readLen = read(readFD, readBuf, READ_BUFF_LEN);
      readBuf[strlen(readBuf)] = '\0';
      printf("pipe test: Father read-->%s, length=%d\n", readBuf, readLen);
    } 
  
    close(readFD);
  }

  return 0;
  
}
