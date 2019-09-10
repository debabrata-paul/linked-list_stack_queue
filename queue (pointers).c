#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void create(int *,int , int *,int *);
void delete(int *,int *,int *);
void display(int *,int *,int *);
int arr[MAX];
int fp,fr;

void main()
{
	
	int ch,num;
	fr=fp=-1;
	
	while(1){
	printf("\n --------------------------");
	printf("\n IMPLEMENTATION OF QUEUE USING ARRAY");
	printf("\n 1 -> INSERT 	\n 2 -> DELETE \n 3 -> DISPLAY \n 4 -> EXIT");
	printf("\n ENTER THE CHOICE");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("\n INSERT");
			printf("\n ENTER THE NUMBER");
			scanf("%d",&num);
			create(arr,num,&fp,&fr);
			break;
		case 2: printf("\n DELETE");
			delete(arr,&fp,&fr);
			break;
		case 3: printf("\n DISPLAY");
			display(arr,&fp,&fr);
			break;
		case 4: printf("\n EXITTINGG");
			exit(0);
		default : printf("\n WRONG CHOICE");
	}
	}
}
void create(int *arr,int num,int *fp,int *fr)
{
	if(*fr==MAX-1)
	{
		printf("\n LIST IS FULL");
		return;
	}
	else
	{
		arr[++*fr]=num;
		if(*fp==-1)
		{
		*fp=0;
		}
	}
}
void delete(int *arr,int *fp,int *fr)
{
	if(*fp==-1)
	{
		printf("\n QUEUE IS EMPTY");
		return;
	}
	else
	{
		printf("\n THE DELETED ELEMENT IS %d",arr[*fp]);
		arr[*fp]=0;
		*fp=*fp+1;
		if(*fp==*fr)
		{
			*fp=*fr=-1;
		}
	}
}
void display(int *arr,int *fp,int *fr)
{
	if(*fp==-1)
	{
		printf("\n QUEUE IS EMPTY");
		return;
	}
	else
	{
	int i;
	printf("\n THE ELEMENTS ARE ::");
	for(i=*fp;i<=*fr;i++)
	printf("\n %d",arr[i]);
	}
}


			
