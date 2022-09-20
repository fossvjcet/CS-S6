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
	
	FILE *f=fopen("abc.txt","w");
	recv(newSocket,buffer,1024,0);
	fprintf(f,"%s",buffer);
	
}
