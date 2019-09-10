#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct stack{
	int data;
	int top;
};
struct stack *s=NULL;
void push();
void pop();
void display();
void main()
{
	int ch;
        
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
	if(s==NULL)
	{
		printf("\n STACK IOS EMPTY");
		return;
	}
	else
	{
		struct stack *temp;
		int num;
		temp=(struct stack *)malloc(sizeof(struct stack));
		printf("\n ENTER THE NUMBER::");
		scanf("%d",&num);
		

