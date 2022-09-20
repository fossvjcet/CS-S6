#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
 	int clientSocket=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in serverAddr;
	char data[1024];
	
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=3003;
	serverAddr.sin_addr.s_addr=INADDR_ANY;
	
	connect(clientSocket,(struct sockaddr*)&serverAddr, sizeof(serverAddr));

	FILE *f=fopen("abc.txt","r");
	while(fgets(data,1024,f)!=NULL)
		send(clientSocket,data,sizeof(data),0);

}