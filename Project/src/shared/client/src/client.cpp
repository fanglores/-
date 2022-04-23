#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>

#define MSG_SIZE 1

int main()
{
  int sock;
  struct sockaddr_in addr;
  char buf[MSG_SIZE];
  int bytes_read;
  sock = socket(AF_INET, SOCK_DGRAM, 0);
  
  addr.sin_family = AF_INET;
  addr.sin_port = htons(3425);
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  
  if(bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) 
  {
    perror("bind");
    return 1;
  }
  
  while(1) 
  {
    bytes_read = recvfrom(sock, buf, MSG_SIZE, 0, NULL, NULL);
    buf[bytes_read] = '\0';
    printf("%s\n", buf);
  }
}
