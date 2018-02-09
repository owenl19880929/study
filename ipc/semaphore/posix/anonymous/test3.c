#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>

#define LOOP 10

int main(int argc, char** argv)
{
  int fd, zero = 0;
  int* ptr;
  sem_t sem_id;
  sem_init(&sem_id, 1, 1);
  int number;
 
  printf("main start...\n");
  fd = open("log.txt", O_RDWR | O_CREAT, S_IRWXU);
  write(fd,&zero,sizeof(int));
  ptr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  pid_t pid = fork();
  if(0 == pid)
  { int index;
    for(index = 0; index < LOOP; index++)
    {
      sem_wait(&sem_id);
      //number++;
      sleep(1);
      printf("Child-->number = %d\n", (*ptr)++);
      sem_post(&sem_id);
    }
    return 0;
  }
  int index;
  for(index = 0; index < LOOP; index++)
  {
      sem_wait(&sem_id);
      //number+;
      sleep(1);
      printf("Parent-->number = %d\n", (*ptr)++);
      sem_post(&sem_id);
  }

  printf("main return...\n");
  return 0;
}
