#include<conio.h>
#include<stdlib.h>
#include<stdio.h>

int i,n;
struct frame
{
	int data,ack;
}f[20];

void sent()
{
	printf("\nFrame %d sent",i);
}

void receive()
{
	printf("\nFrame %d received",i);
}
void main()
{
	printf("Enter the number of frames: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
			printf("\n");
		sent();
		sleep(1);
		f[i].ack=rand()%2;
		while(1)
		{
			if (f[i].ack==1)
			{
				receive();
				break;
			}
			else
			{
				printf("\nFrame %d ack not recived ",i);
				sent();
				f[i].ack=rand()%2;
			}
				
		}
		
	}
}