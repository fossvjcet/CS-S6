#include<conio.h>
#include<stdio.h>
void main()
{
	int windowSize,frameNumber=0,ack=-1,i;
	printf("Enter the window size:");
	scanf("%d",&windowSize);
	do
	{
		for(frameNumber=ack+1;frameNumber<windowSize;frameNumber++)
			printf("\nFrame %d is sent",frameNumber);
		printf("\n\nEnter the last acknowledgement");
		scanf("%d",&ack);
	}while(ack<windowSize-1);
}