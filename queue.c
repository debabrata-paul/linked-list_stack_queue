#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
struct node *pr,*pf;


void insert();
void delete();
void display();
void main()
{
	
	int ch,num;
	
	pr=pf=NULL;
	
	while(1){
	printf("\n --------------------------");
	printf("\n IMPLEMENTATION OF QUEUE USING LINKED LIST");
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
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	int num;
	printf("\n ENTER THE NUMBER");
	scanf("%d",&num);
	temp->data=num;
	temp->next=NULL;
	if(pr==NULL&&pf==NULL)
	{
		pr=pf=temp;
	}
	else
	{
		pr->next=temp;
		pr=temp;
	}
}
void delete()
{
	if(pf==NULL)
	{
		printf("\n QUEUE IS EMPTY");
		return;
	}
	else
	{
		printf("\n THE DELETED ELEMENT IS %d ",pf->data);
		//struct node *temp;
		//temp=pf;
		if(pr==pf)
		{
			pr=pf=NULL;
		}
		else
		pf=pf->next;
		//free(temp);
	}
}
void display()
{
	if(pf==NULL)
	{
		printf("\n QUEUE IS EMPTY");
		return;
	}
	else
	{
		struct node *temp;
		temp=pf;
		printf("\n THE ELEMENTS ARE::");
		while(temp!=NULL)
		{
			printf("\n %d",temp->data);
			temp=temp->next;
		}
	}
}
	
