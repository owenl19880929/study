#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define FIFO_FILE_NAME  "/tmp/fifo_test"
#define WRITE_BUFF_LEN  1000
#define READ_BUFF_LEN  1000

int main(int argc, char** atgv)
{
  int fd;
  
  pid_t pid;
  pid = getpid();
  printf("FIFO TEST: I am process %d\n", pid);
  
  fd = open(FIFO_FILE_NAME, O_RDONLY);
  if(fd < 0)
  {
    printf("FIFO TEST: failed to open fifo\n");
    exit(-1);
  }

  char readBuf[READ_BUFF_LEN];
  int readLen = 0;
  
  while(strncmp(readBuf, "close", strlen("close")))
  { 
    memset(readBuf, 0, READ_BUFF_LEN);
    readLen = read(fd, readBuf, READ_BUFF_LEN);
    readBuf[strlen(readBuf)] = '\0';
    printf("FIFO TEST: pid-->%d,  read-->%s, length-->%d\n", pid, readBuf, readLen);
  } 
 
  close(fd);

  return 0;
  
}
