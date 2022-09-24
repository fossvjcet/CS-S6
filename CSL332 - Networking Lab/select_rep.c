#include<stdlib.h>
#include<stdio.h>

int i,n;
struct frame 
{
	int data;
	char ack;
}f[10];

void send()
{
	for(i=0;i<n;i++)
	{
		printf("Enter the data for packets %d:",i);
		scanf("%d",&f[i].data);
		f[i].ack='y';
	}
}

int ack()
{
	for(i=0;i<n;i++)
		if(f[i].ack=='n')
		{
			printf("\nPacket %d not received!",i);
			resend(i);
		}
}
void resend(int i)
{
	printf("\nResending Packet %d...",i);
	sleep(3);
	f[i].ack='y';
	printf("\nPacket %d Received!",i);
}

void main()
{
	printf("Enter the number of packets to be sent:");
	scanf("%d",&n);
	send();
	f[rand()%n].ack='n';
	ack();
}
