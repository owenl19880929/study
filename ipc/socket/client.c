#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

/***start const value definition***/
#define CLIENT_SUCCESS 0
#define CLIENT_FAILED -1
#define SEND_BUFF_SIZE 1024
#define SOCKET_NAME "/tmp/unix.domain"
/***end const value definition***/

int main(int argc, char** argv)
{
  int ret = -1;

  int client_socket = -1;
  client_socket = socket(PF_UNIX, SOCK_STREAM, 0);
  if(client_socket < 0)
  {
    printf("%s-%d: Client create socket failed, error=%s\n", __FILE__, __LINE__, strerror(errno));
    exit(CLIENT_FAILED);
  }

  struct sockaddr_un client_addr;
  client_addr.sun_family = PF_UNIX;
  strncpy(client_addr.sun_path, SOCKET_NAME, sizeof(client_addr.sun_path)-1);

  ret = connect(client_socket, (struct sockaddr*)&client_addr, sizeof(client_addr));
  if(ret < 0)
  {
    printf("%s-%d: Client connect failed, error=%s\n", __FILE__, __LINE__, strerror(errno));
    close(client_socket);
    exit(CLIENT_FAILED);
  }

  char send_buff[SEND_BUFF_SIZE];
  int send_len = 0;

  while(1)
  {
    memset(send_buff, 0, sizeof(send_buff));
    printf("Please input something to send to server:\n");
    printf("->");
    scanf("%s", send_buff);
   
    send_len = write(client_socket, send_buff, strlen(send_buff));

    if(0 == strncmp(send_buff, "q", send_len))
      break;     
  }
  
  //sleep(1);
  close(client_socket);
  return CLIENT_SUCCESS;

}

