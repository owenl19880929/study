#include <stdio.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <pthread.h>

#define SHMSZ 27
char SEM_NAME[] = "vik";

int main(int argc, char** argv)
{
  char* shm, *s;
  sem_t* mutex;
  key_t key = 1000;

  mutex = sem_open(SEM_NAME, O_CREAT, 0644, 1);
  if(mutex == SEM_FAILED)
  {
    perror("unable to create semaphore");
    sem_unlink(SEM_NAME);

    exit(-1);
  }

  int shmid;
  shmid = shmget(key, SHMSZ, IPC_CREAT|0644);
  if(shmid < 0)
  {
    perror("failure in shmget");
    exit(-1);
  }

  shm = shmat(shmid, NULL, 0);
  s = shm;

  for(s = shm; *s != '\0'; s++)
  {
    sem_wait(mutex);
    putchar(*s);
    sem_post(mutex);
  }

  sem_wait(mutex);
  *shm = '*';
  sem_post(mutex);
  
  sem_close(mutex);
  //shmctl(shmid, IPC_RMID, 0);
  return 0;
}
