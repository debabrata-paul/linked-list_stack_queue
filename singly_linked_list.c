#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
int data;
struct node *next;
};
struct node *p=NULL;
void create(int );
void display();
void append(int );
int count();
void delete(int );
void bubble_sort(int );
void reverse_print();
void search(int );
void reverselist();
void add_after(int , int );
void main()
{
	int g,ch,num,pos;
	while(1){
	printf("\n---------------------------");
	printf("\n 1 -> CREATE \n 2 -> DISPLAY \n 3 -> EXIT\n 4 -> APPEND \n 5 -> COUNT \n 6 -> DELETE \n 7 -> BUBBLE SORT \n 8 -> ADD AFTER \n 9 -> REVERSE PRINT \n 10 -> SEARCH \n 11 -> REVERSE LIST");
	printf("\nENTER THE CHOICE\n");
	scanf("%d",&ch);
	switch(ch){
		case 1: printf("\n CREATE");
			printf("\n ENTER THE NUMBER\n");
			scanf("%d",&num);
			create(num);
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
			printf("\n ENTER THE NUMBER YOU WANT TO DELETE");
			scanf("%d",&pos);
			delete(pos);
			break;
		case 7:printf("\n BUBBLE SORT"); 
			int num=count(); 
			bubble_sort(num);
			break;
		case 8: printf("\n ADD AFTER");
			printf("ENTER THE NUMBER & POS");
			scanf("%d%d",&num,&pos);
			add_after(num,pos);
			break;
		case 9: printf("\n REVERSE PRINT");
			reverse_print();
			break;
		case 10: printf("\n SEARCH");
			 printf("\n ENTER THE NUMBER TO SEARCH");
			 scanf("%d",&num);
			 search(num);
			 break;
		case 11: printf("\n REVERSE LIST");
			 reverselist();
			 break;
		default : printf("WRONG CHOICE");
		}
	}
}
void create(int num)
{
	struct node *nw;
	nw=(struct node *)malloc(sizeof(struct node));
	nw->data=num;
	nw->next=NULL;
	p=nw;
}
void display()
{
	if(p==NULL)
	{
		printf("\nLIST IS EMPTY");
	}
	else
	{
		struct node *temp;
		temp=p;
		printf("\n THE DATAS ARE::");
		while(temp!=NULL)
		{
			printf("\n %d",temp->data);
			temp=temp->next;
		}
	}
}
void append(int num)
{
	if(p==NULL)
	{
		struct node *nw;
	nw=(struct node *)malloc(sizeof(struct node));
	nw->data=num;
	nw->next=NULL;
	p=nw;
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
	temp->next=nw;
	}
}
int count()
{
	if(p==NULL)
	{
		printf("\nLIST IS EMPTY");
	}
	else
	{
		int c=0;
		struct node *temp;
		temp=p;
		while(temp!=NULL)
		{
			c++;
			temp=temp->next;
		}
		return (c);
	}
}
void delete(int num)
{
	if(p==NULL)
	{
		printf("\n LIST EMPTY");
	}
	else
	{
		struct node *temp,*old;
		temp=p;
		if(temp->data==num)
		{
			if(temp==p)
			{
				p=temp->next;
			}
			else		
			{
				old->next=temp->next;
			}
			free(temp);
			return ;
		}
		else
		{
			old=temp;
			temp=temp->next;
		}
	}
	printf("\n DATA NOT FOUND");
}
void bubble_sort(int num)
{
	if(p==NULL)
		{
			printf("\nLIST IS EMPTY");
		}
	else
	{
		struct node *x,*y;
		int i,j,temp;
		x=p;
		for(i=0;i<num-1;i++)
		{
			y=x->next;
		for(j=0;j<num-i-1;j++)
		{
			temp=x->data;
			x->data=y->data;
			y->data=temp;
		}
			x=x->next;
			y=y->next;
		}	
		struct node *disp;
		disp=p;
		while(disp!=NULL)
		{
			printf("\n THE DATAS ARE %d",disp->data);
			disp=disp->next;
		}
	}
	
}
void reverse_print()
{
	if(p==NULL)
		{
			printf("\nLIST IS EMPTY");
		}
	else
	{
		int j,arr[count()],i=0;
		struct node *temp;
		temp=p;
		while(temp!=NULL)
		{
			arr[i]=temp->data;
			i++;
			temp=temp->next;
		}
		printf("\n THE DATAS IN REVERSE ORDER ARE");
		for(j=i-1;j>=0;j--)
		printf("\n%d",arr[j]);
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
				printf("\n ELEMENT FOUND %d",temp->data);
				return;
			}			
			else
			{
				temp=temp->next;
			}
			
		}
		printf("\n NOT FOUND");
	}
}
void reverselist()
{
	struct node *x,*y,*z;
	x=p;
	y=NULL;
	while(x!=NULL)
	{
		z=y;
		y=x;
		x=x->next;
		y->next=z;
	}
	p=y;
}
void add_after(int num,int pos)
{
	struct node *temp,*nw;
	temp=p;
	int i;
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
		temp->next=nw;
	}
}
