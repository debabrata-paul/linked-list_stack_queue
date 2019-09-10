#include<stdio.h>
#include<stdlib.h>

#define max 10
struct stack{
int arr[max];

int top;
};
struct stack s;


void push();
void pop();
void display();

void main()
{
	int ch;
        s.top=-1;
	while(1)
	{
		printf("\n--------------------------------");
		printf("\n STACK OPERATION USING ARRAY");
		printf("\n 1 -> PUSH \n 2 -> POP \n 3->DISPLAY \n 4-> EXIT");
		printf("\n ENTER THE CHOICE");

		scanf("%d",&ch);
		switch(ch){
		case 1: printf("\n PUSH");
			push();
			break;
		case 2: printf("\nPOP");
			pop();
			break;
		case 3: printf("\n DISPLAY");
			display();
			break;
		case 4: printf("\n EXITTING!!!!!!!");
			exit(0);
			break;
		default: printf("\n WRONG CHOICE");
		}
	}
}
void push()
{
	if(s.top==max-1)
	{
		printf("\n STACK IS FULL");
		return;
	}
	s.top++;
	int num;
	printf("\n ENTER THE NUMBER::");
	scanf("%d",&num);
	s.arr[s.top]=num;

}
void pop()
{
	if(s.top==-1)
	{
		printf("\n STACK IS EMPTY");
		return;
	}
	else
	{
		printf("\n THE DELETED VALUE IS %d",s.arr[s.top]);
		s.top--;
	}
}
void display()
{
	if(s.top==-1)
	{
		printf("\n STACK IS EMPTY");
		return;
	}
	else
	{
		int num=s.top;
		printf("\n THE VALUES ARE::");
		while(num!=-1)
		{
			printf("\n%d",s.arr[num]);
			num--;
		}
	}
}
		

