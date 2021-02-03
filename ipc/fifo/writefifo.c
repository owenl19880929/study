#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include<fcntl.h> 

#define FIFO_FILE_NAME  "/tmp/fifo_test"
#define WRITE_BUFF_LEN  1000
#define READ_BUFF_LEN  1000

int main(int argc, char** atgv)
{
  int fd;
  int writeLen = 0;

  pid_t pid;
  pid = getpid();
  printf("FIFO TEST: I am process %d\n", pid);

  int ret;
  unlink(FIFO_FILE_NAME);
  ret = mkfifo(FIFO_FILE_NAME, 0777);
  if(ret < 0)
  {
    printf("FIFO TEST: failed to mkfifo\n");
    exit(-1);
  }

  fd = open(FIFO_FILE_NAME, O_WRONLY);
  if(fd < 0)
  {
    printf("FIFO TEST: failed to open fifo\n");
    exit(-1);
  }

  char writeBuf[WRITE_BUFF_LEN];
  while(strncmp(writeBuf, "close", strlen("close")))
  { 
      memset(writeBuf, 0, WRITE_BUFF_LEN);
      printf("Please input something:\n");
      scanf("%s", writeBuf);
      writeLen = write(fd, writeBuf, strlen(writeBuf));
      printf("FIFO TEST: pid-->%d,  write-->%s, length-->%d\n", pid, writeBuf, writeLen);
  } 
  
  close(fd);

  return 0;
  
}
