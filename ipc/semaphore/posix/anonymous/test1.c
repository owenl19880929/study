#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/types.h>

static int number = 0;
sem_t sem_id;

void* pthread_fun1(void* arg)
{
  int csemValue;
  sem_getvalue(&sem_id, &csemValue);
  printf("csemValue = %d\n", csemValue);
  sem_wait(&sem_id);
  printf("pthread_fun1 have the semaphore\n");
  sem_getvalue(&sem_id, &csemValue);
  printf("csemValue = %d\n", csemValue);
  number++;
  sleep(2);
  printf("pthread_fun1: number = %d\n", number);
  sem_post(&sem_id);
  sem_getvalue(&sem_id, &csemValue);
  printf("csemValue = %d\n", csemValue);
  return NULL;
}

void* pthread_fun2(void* arg)
{
  sem_wait(&sem_id);
  printf("pthread_fun2 have the semaphore\n");
  number++;
  printf("pthread_fun2: number = %d\n", number);
  sem_post(&sem_id);
  return NULL;
}

int main(int argc, char** argv)
{
  pthread_t pid1, pid2;
  sem_init(&sem_id, 0, 1);
  printf("main start...\n");
  pthread_create(&pid1, NULL, pthread_fun1, NULL);
  pthread_create(&pid2, NULL, pthread_fun2, NULL);  
  pthread_join(pid1, NULL);
  pthread_join(pid2, NULL);
  printf("main return...\n");
  return 0;
}
