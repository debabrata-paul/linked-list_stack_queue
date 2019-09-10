#include<stdio.h>
#include<stdlib.h>
#define MAX 8
void insert();
void delete();
void display();
int arr[MAX];
int rear,front;
void main()
{
	
	int ch,num,i;
	
	rear=front=-1;
	for(i=0;i<MAX-1;i++)
		arr[i]=0;
	
	while(1){
	printf("\n --------------------------");
	printf("\n IMPLEMENTATION OF QUEUE USING ARRAY");
	printf("\n 1 -> INSERT 	\n 2 -> DELETE \n 3 -> DISPLAY \n 4 -> EXIT");
	printf("\n ENTER THE CHOICE");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("\n INSERT");
			insert();
			break;
		case 2: printf("\n DELETE");
			delete();
			break;
		case 3: printf("\n DISPLAY");
			display();
			break;
		case 4: printf("\n EXITTINGG");
			exit(0);
		default : printf("\n WRONG CHOICE");
	}
	}
}
void insert()
{
	if(front==(rear+1)%MAX)
	{
		printf("\n QUEUE IS FULL");
		return;
	}
	else
	{
		int num;
		printf("\n ENTER THE NUMBER::");
		scanf("%d",&num);
		if(rear==MAX-1)
			rear=0;
		else
			rear++;
		arr[rear]=num;
		if(front==-1)
			front++;
	}
}
void delete()
{
	if(front==-1)
	{
		printf("\n LIST IS EMPTY");
		return;
	}
	if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		if(front==MAX-1)
			front=0;
		else
			front++;
	}
}
void display()
{
	if(front==-1)
	{
		printf("\n LIST IS EMPTY");
		return;
	}
	else
	{
		int temp;
		temp=front;
		printf("\n THE ELEMENTS ARE");
		while(temp!=rear)
		{
			printf("\n %d",arr[temp]);
			temp++;
		}
	}
}
		
	
