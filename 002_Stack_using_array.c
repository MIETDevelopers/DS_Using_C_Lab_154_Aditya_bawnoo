// Author name : Aditya Bawnoo
// Creation date : 5 June 2021       
#define N 5
#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();
int stack[N], top = -1 ,y,ch;
int main () 
{
		printf(" \nWelcome user\n   ");
		printf("\nEnter array size\n  ");
		scanf("%d",&y);
	for (;;){
	
		printf(" \n Please select 1 for push\n");
			printf("\n Please select 2 for pop\n");
				printf("\n Please select 3 for display\n");
					printf("\n Please select 4 for exit\n");
					scanf("%d",&ch);
					switch(ch)
					{
						
						
						case 1 : 
						push();
						break;
						
						case 2 : 
						pop ();
						break;
						
						case 3 : 
						display();
						break;
						
						case 4 : 
						exit(0);
						break;						
					
					default : 
					printf("\nInvalid statement\n");
					
				}
	}
	

}
void push()
{
	int x ;
	printf("\nEnter data :    \n ");
	scanf("%d",&x);
	if ( top == N - 1 )
	
	{
		printf(" \noverflow\n");
				
	}
	else 
	{		
		top ++;
		stack[top] = x;
	}
}
void pop()
{
	int a ;
	if (top == -1  )
	{
		printf(" \n Stack is Underflow");
	}
	else {
	
		
		a = stack[top];
		
		top--;
		printf("%d\n",a);
	
		
	}
}
void display()
{
	int i;

		for ( i = top; i >= 0 ; i--)
		{
			printf( " %d\n", stack [i]);
		}
	}
	


