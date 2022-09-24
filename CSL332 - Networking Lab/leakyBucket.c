#include<conio.h>
#include<stdlib.h>
#include<stdio.h>


void main()
{
	int n,b,o,j,i,bucket=0;
	printf("Enter the number of queries:");
	scanf("%d",&n);
	printf("Enter the bucket size:");
	scanf("%d",&b);
	printf("Enter the output size:");
	scanf("%d",&o);
	for(j=0;j<n;j++)
	{
		printf("\n\nEnter the input size:");
		scanf("%d",&i);
		if (b<bucket+i-o)
			printf("Error!Overflow");
		
		else if (bucket+i>o)
			{
				bucket=bucket+i-o;
				printf("%d Packets Sent\nPackets in bucket:%d",o,bucket);
			}
		else 
			{
				printf("%d Packets Sent\nPackets in bucket: 0",bucket+i);
				bucket=0;
			}
	}
	
}