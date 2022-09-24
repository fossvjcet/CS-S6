#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
	int newSocket,serverSocket=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in serverAddr,newAddr;
	socklen_t addr_size;
	char buffer[1024];

	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=3003;
	serverAddr.sin_addr.s_addr=INADDR_ANY;
	
	bind(serverSocket,(struct sockaddr*)&serverAddr, sizeof(serverAddr));
	
	listen(serverSocket,5);
	printf("listening...\n");
	
	addr_size=sizeof(newAddr);
	newSocket=accept(serverSocket,(struct sockaddr*)&newAddr,&addr_size);

	recv(newSocket,buffer,1024,0);
	printf("\nMessage from client: %s",buffer);

    printf("\nSenting Response...");
    strcpy(buffer,"250 OK");
	send(newSocket,buffer,1024,0);

    recv(newSocket,buffer,1024,0);
	printf("\nMessage from client: TO ADDRESS: %s",buffer);

    printf("\nSenting Response...");
    strcpy(buffer,"250 OK");
	send(newSocket,buffer,1024,0);

    recv(newSocket,buffer,1024,0);
	printf("\nMessage from client: FROM ADDRESS: %s",buffer);

    printf("\nSenting Response...");
    strcpy(buffer,"250 OK");
	send(newSocket,buffer,1024,0);

    recv(newSocket,buffer,1024,0);
	printf("\nMessage from client: MAIL BODY: %s",buffer);

    printf("\nSenting Response...");
    strcpy(buffer,"250 OK");
	send(newSocket,buffer,1024,0);

    recv(newSocket,buffer,1024,0);
	printf("\nMessage from client: %s",buffer);

    printf("\nSenting Response...");
    strcpy(buffer,"GOODBYE");
	send(newSocket,buffer,1024,0);

	printf("\nClosing connection");
}
 