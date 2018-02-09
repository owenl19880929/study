#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/types.h>

static int number = 0;
sem_t sem_id1, sem_id2;

void* pthread_fun1(void* arg)
{
  sem_wait(&sem_id2);
  printf("pthread_fun1 have the semaphore\n");
  number++;
  printf("pthread_fun1: number = %d\n", number);
  sem_post(&sem_id1);
  return NULL;
}

void* pthread_fun2(void* arg)
{
  sem_wait(&sem_id1);
  printf("pthread_fun2 have the semaphore\n");
  number++;
  printf("pthread_fun2: number = %d\n", number);
  sem_post(&sem_id2);
  return NULL;
}

int main(int argc, char** argv)
{
  pthread_t pid1, pid2;
  sem_init(&sem_id1, 0, 1);
  sem_init(&sem_id2, 0, 0);
  printf("main start...\n");
  pthread_create(&pid1, NULL, pthread_fun1, NULL);
  pthread_create(&pid2, NULL, pthread_fun2, NULL);  
  pthread_join(pid1, NULL);
  pthread_join(pid2, NULL);
  printf("main return...\n");
  return 0;
}
