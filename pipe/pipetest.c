#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>
#include <string.h>

int main(int argc, char** argv)
{
  int pipefd[2];
  int result = -1;
  result = pipe(pipefd);
  if(result == -1){
    printf("pipe create pipe error!\n");
    exit(EXIT_FAILURE);
  }

  pid_t pid;
  pid = fork();

  if(pid == -1){
    printf("pipe: create child process  error!\n");
    exit(EXIT_FAILURE);
  }
  
  char buf[1024];
  int flag;
  if(pid == 0){
    while(1){
      read(pipefd[0], buf, 1024);
      printf("pipe: child read from pipe-> %s\n", buf);
      if(strncmp(buf, "exit", sizeof(buf)) == 0){
        exit(EXIT_SUCCESS);
      }

    }
  }else{
    while(1){
      waitpid(pid, NULL, WNOHANG);
      if(flag == 1){
        exit(0);
      }
       
      scanf("%s", buf);
      write(pipefd[1], buf, strlen(buf)+1);
      if(strncmp(buf, "exit", sizeof(buf))  == 0){
        flag = 1;
        sleep(1);
      }
      
    }

  }

  return 0;
}
