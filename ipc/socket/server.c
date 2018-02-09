#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <errno.h>
#include <pthread.h>

/***start const value definition***/
#define SERVER_SUCCESS 0
#define SERVER_FAILED -1
#define RECV_BUFF_SIZE 1024
#define THREAD_NUM 1024

#define SOCKET_NAME "/tmp/unix.domain"
/***end const value definition***/

/***start global variable definition***/
pthread_t pid[THREAD_NUM];
static int thread_num = 0;
static int quit_server = 0;
/***end global variable definition***/

void* handle_message_fun(void* argv)
{
  int conn_socket = *((int*)argv);
  printf("%s-%d: Thread-%d->Server handle socket conn_socket  %d\n", __FILE__, __LINE__,(int)pthread_self(), conn_socket);
  
  char* recv_buff = malloc(RECV_BUFF_SIZE);
  while(1)
  {
    memset(recv_buff, 0, RECV_BUFF_SIZE);
    int read_len = read(conn_socket, recv_buff, sizeof(recv_buff)); 

    printf("%s-%d: Thread-%d->Server recv message = %s, len = %d\n", __FILE__, __LINE__, (int)pthread_self(),  recv_buff, read_len);
    //sleep(1);
    if(0 == strncmp(recv_buff, "q", read_len))
    { 
       printf("%s-%d: Thread-%d->Server close conn_socket = %d\n", __FILE__, __LINE__,(int)pthread_self(), conn_socket);
       if(NULL != recv_buff)
       {
         free(recv_buff);
         recv_buff = NULL;
       }
       quit_server = 1;
       break;
    }
  }
  
  close(conn_socket);
}

void handle_request(int conn_socket)
{
   printf("%s-%d: Server setup conn_socket =  %d\n", __FILE__, __LINE__, conn_socket);
   int ret = pthread_create(&pid[thread_num++], NULL, handle_message_fun, (void*)&conn_socket);
   printf("%s-%d: Server thread-%d setup\n", __FILE__, __LINE__, thread_num); 
   sleep(1); 
}


int main(int argc, char** argv)
{
  int ret = -1;

  int server_socket = -1;
  server_socket = socket(PF_UNIX, SOCK_STREAM, 0);
  if(-1 == server_socket)
  {
    printf("%s-%d: Server create socket failed, error=%s", __FILE__, __LINE__, strerror(errno));
    exit(SERVER_FAILED);
  }

  struct sockaddr_un server_addr;
  server_addr.sun_family = PF_UNIX;
  strncpy(server_addr.sun_path, SOCKET_NAME, sizeof(server_addr.sun_path)-1);
  unlink(SOCKET_NAME);
  
  ret = bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
  if(ret < 0)
  {
    printf("%s-%d: Server bind failed, error=%s\n", __FILE__, __LINE__, strerror(errno));
    close(server_socket);
    unlink(SOCKET_NAME);
    exit(SERVER_FAILED);
  }

  ret = listen(server_socket, 1024);
  if(ret < 0)
  {
    printf("%s-%d: Server listen failed, error=%s\n", __FILE__, __LINE__, strerror(errno));
    close(server_socket);
    unlink(SOCKET_NAME);
    exit(SERVER_FAILED);
  }

  int conn_socket = -1;
  struct sockaddr_un ctl_addr;
  int sockaddr_len = sizeof(ctl_addr);
  //printf("%s-%d: Server is waiting client connect!\n",  __FILE__, __LINE__);
  while(1)
  {
    printf("%s-%d: Server is waiting client connect!, server_socket=%d\n",  __FILE__, __LINE__, server_socket);
    conn_socket = accept(server_socket, (struct sockaddr*)&ctl_addr, &sockaddr_len);
    if(conn_socket < 0)
    {
      printf("%s-%d: Server accept failed, error=%s\n", __FILE__, __LINE__, strerror(errno));
      continue;
    } 
    printf("%s-%d: Server recv client connect request!, conn_socket=%d\n", __FILE__, __LINE__, conn_socket);
    handle_request(conn_socket);
    printf("\r\n");
  }

  close(server_socket);
  unlink(SOCKET_NAME);
  return SERVER_SUCCESS;

}

