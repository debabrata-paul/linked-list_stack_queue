#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
struct node *prev;
int data;
struct node *next;
};
struct node *p=NULL;
void add_at_begin(int );
void display();
void append(int );
int count();
void delete(int );
void bubble_sort(int );
void add_after(int , int );
void search(int );
void reverse_print();
void reverse_list();
void selection_sort(int );
void main()
{
	int g,ch,num,pos;
	while(1){
	printf("\n---------------------------");
	printf("\n 1 -> ADD AT BEGIN \n 2 -> DISPLAY \n 3 -> EXIT\n 4 -> APPEND \n 5 -> COUNT \n 6 -> DELETE \n 7 -> BUBBLE SORT \n 8 -> ADD AFTER \n 9 -> SEARCH \n 10 -> REVERSE PRINT \n 11 -> REVERSE LIST \n 12 -> SELECTION SORT");
	printf("\nENTER THE CHOICE\n");
	scanf("%d",&ch);
	switch(ch){
		case 1: printf("\n ADD AT BEGIN");
			printf("\n ENTER THE NUMBER\n");
			scanf("%d",&num);
			add_at_begin(num);
			break;
		case 2: printf("\nDISPLAY");
			display();
			break;
		case 3: exit(0);
		case 4: printf("\nAPPEND");
			printf("\nENTER THE NUMBER\n");
			scanf("%d",&num);
			append(num);
			break;
		case 5: printf("COUNT");
			g=count();
			printf("\n THE NO OF ELEMENT IN THE LIST IS :: %d",g);
			break;
		case 6: printf("\nDELETE");
			printf("\n ENTER THE POSITION");
			scanf("%d",&pos);
			delete(pos);
			break;
		case 7: bubble_sort(count());
			break;
		case 8: printf("\n ADD AFTER");
			printf("\nENTER THE NUMBER & POS::");
			scanf("%d%d",&num,&pos);
			add_after(num,pos);
			break;
		case 9: printf("\n SEARCH");
			printf("\n ENTER THE NUMBER TO SEARCH::");
			scanf("%d",&num);
			search(num);
			break;
		case 10: printf("\n REVERSE PRINT");
			 reverse_print();
			 break;
		case 11: printf("\n REVERSE LIST");
			 reverse_list();
			 break;
		case 12: printf("\n SELECTION SORT");
			 num=count();
			 selection_sort(num);
			 break; 
		default : printf("WRONG CHOICE");
		}
	}
}
void add_at_begin(int num)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=num;
	temp->next=p;
	temp->prev=NULL;
	p=temp;
}
void display()
{
		
	struct node *temp;
	temp=p;
	printf("\n THE DATAS ARE::");

	while(temp!=NULL)
	{
		printf("\n%d",temp->data);
		temp=temp->next;
	}
}
void append(int num)
{
	if(p==NULL)
	{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=num;
	temp->next=NULL;
	temp->prev=NULL;
	p=temp;
	}
	else
	{
	struct node *temp,*nw;
	temp=p;
	while(temp->next!=NULL)
	temp=temp->next;
	nw=(struct node *)malloc(sizeof(struct node));
	nw->data=num;
	nw->next=NULL;
	nw->prev=temp;
	temp->next=nw;
	}
}
int count()
{
	struct node *temp;
	temp=p;
	int c=0;
	if(p==NULL)
	{
		printf("THE LIST IS EMPTY");
	}
	else{
		while(temp!=NULL){
			c++;
			temp=temp->next;
		}
	}
	return(c);
}
void delete(int pos)
{
	struct node *temp,*old;
	temp=p;
	while(temp!=NULL)
	{
		if(temp->data==pos)
		{
			if(temp==p)
			{			
				p=temp->next;
				p->prev=NULL;
				free(temp);
				return;
			}
			else{
				old->next=temp->next;
				if(temp->next!=NULL)
				{
					temp->next->prev=old;
				}
				free(temp);
				return;
			}
		}
		else{
			old=temp;
			temp=temp->next;
		}
	}
	printf("DATA NOT FOUND");
}
void bubble_sort(int n)
{
	int i,j,temp;
	struct node *x,*y;
	int k=count();
	for(i=0;i<n-1;i++,k--)
	{
		x=p;
		y=x->next;
		for(j=1;j<k;j++)
		{
			if(x->data>y->data)
			{
				temp=x->data;
				x->data=y->data;
				y->data=temp;
			}
			x=x->next;
			y=y->next;
		}
	}
	printf("\n LIST HAS BEEN SORTED");
}
void add_after(int num,int pos)
{
	int i;
	struct node *temp,*nw,*x;
	temp=p;
	for(i=1;i<pos;i++)
	{
		temp=temp->next;
		if(temp==NULL)
		{
			printf("\n ERROR");
		}
	}
	if(i==pos)
	{
		nw=(struct node *)malloc(sizeof(struct node));
		nw->data=num;
		nw->next=temp->next;
		nw->prev=temp;
		temp->next=nw;
		
		//ctemp=temp->next;
		temp->prev=nw;
	}
}
void search(int num)
{
	if(p==NULL)
	{
		printf("\nLIST IS EMPTY");
	}
	else
	{
		struct node *temp;
		temp=p;
		while(temp!=NULL)
		{
			if(temp->data==num)
			{
				printf("\n ELEMENT FOUND %d",num);

				return;
			}
			else
			{
				temp=temp->next;
			}
		}
		printf("\n ELEMENT NOT FOUND");
	}
}
void reverse_print()
{
	
	struct node *temp;
	temp=p;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	while(temp!=NULL)
	{
		printf("\n %d",temp->data);
		temp=temp->prev;
	}
}
void reverse_list()
{
		struct node *temp=NULL;
		struct node *current=p;
		while(current!=NULL)
		{
			temp=current->prev;
			current->prev=current->next;
			current->next=temp;
			current=current->prev;
		}
		if(temp!=NULL)
		{
			p=temp->prev;
		}
	printf("\n LIST HAS BEEN REVERSED");
}
void selection_sort(int n)
{
	struct node *x,*y;
	int i,j,temp;
	x=p;
	for(i=0;i<n-1;i++)
	{
		y=x->next;
		for(j=(i+1);j<n;j++)
		{
			if(x->data>y->data)
			{
				temp=x->data;
				x->data=y->data;
				y->data=temp;
			}
		y=y->next;
		}
		x=x->next;
	}
	printf("\n LIST HAS BEEN SORTED");
}
