#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
 	int clientSocket=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in serverAddr;
	char buffer[1024];
	
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=3003;
	serverAddr.sin_addr.s_addr=INADDR_ANY;
	
	connect(clientSocket,(struct sockaddr*)&serverAddr, sizeof(serverAddr));

	printf("\nSenting Hai to server");
    strcpy(buffer,"HAI");
    send(clientSocket,buffer,1024,0);
   
    printf("\nWaiting for server response...");
    recv(clientSocket,buffer,1024,0);
	printf("\nServer response:%s",buffer);

	printf("\n\nEnter From Address:");
    scanf("%s",&buffer);
	send(clientSocket,buffer,1024,0);

    printf("Waiting for server response...");
    recv(clientSocket,buffer,1024,0);
	printf("\nServer response:%s",buffer);

	printf("\n\nEnter To Address:");
    scanf("%s",&buffer);
	send(clientSocket,buffer,1024,0);

    printf("Waiting for server response...");
    recv(clientSocket,buffer,1024,0);
	printf("\nServer response:%s",buffer);

	printf("\n\nEnter body of the message:");
    scanf("%s",&buffer);
	send(clientSocket,buffer,1024,0);

    printf("Waiting for server response...");
    recv(clientSocket,buffer,1024,0);
	printf("\nServer response:%s",buffer);

	printf("\n\nSenting QUIT to server");
    strcpy(buffer,"QUIT");
	send(clientSocket,buffer,1024,0);

    printf("\nWaiting for server response...");
    recv(clientSocket,buffer,1024,0);
	printf("\nServer response:%s",buffer);

    printf("\nClosing connection");

}

