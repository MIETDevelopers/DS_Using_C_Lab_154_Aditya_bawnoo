//Creation Date: 7 August 2021
//Purpose: Implementing a Stack using Linked List and develop functions to perform push and pop operations.

#include<stdio.h>	//Preprocessor directive to include standard input output header file
#include<stdlib.h>	//Preprocessor directive to include standard library header file

void push();	//Function Prototype
void pop();	//Function Prototype
void display();	//Function Prototype
void Stack_Count();

struct node	// Structure namely struct node
{
	int data;	//Member Variable
	struct node *next;	//Member Variable
};

typedef struct node Node;	// Using typedef function to change name from struct node to Node

Node *head = NULL;	// Creating a pointer namely head to store the address of first node
int count=0;

void main()	// main function
{
	int choice;
	
	while(1)	// menu 
	{
		printf("\n Select 1 for Push\n");
		printf("\n Select 2 for Pop\n");
		printf("\n Select 3 for Display\n");
		printf("\n Select 4 for Total Nodes\n");
		printf("\n Select 5 for Exit\n");
		printf("\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
                    printf("\nImplementing push function\n");                           
                    push();
                    break;
            case 2:
                	printf("\nImplementing pop function\n"); 
                    pop();
                    break;
            case 3:
                    printf("\nImplementing display function\n");                           
                    display();
                    break;    
            case 4:
            		printf("\nDisplaying total nodes in the stack\n");
            		Stack_Count();
                    break;
            case 5:
            		printf("Exiting the program!");
                    exit(0);
                    break;
            default:
                    printf("\nWrong Choice! :/");
                    break;
		}
	}
}

void push ()  // push function declaration
{  
    int val;  
    Node *ptr = (Node*)malloc(sizeof(Node));   // using malloc function for dynamically allocating memory
    if(ptr == NULL)  
    {  
        printf(" no space ");   
    }  
    else   
    {  
        printf("\nEnter the value: ");  
        scanf("%d",&val);  
        if(head==NULL)  
        {         
            ptr->data = val;  
            ptr -> next = NULL;  
            head=ptr;  
        }   
        else   
        {  
            ptr->data = val;  
            ptr->next = head;  
            head=ptr;  
               
        }  
        printf("\nItem pushed\n");
		count++;  
          
    }  
}  
  
void pop()  // pop function declaration
{  
    int item;  
    Node *ptr;  
    if (head == NULL)  
    {  
        printf("Underflow");  
    }  
    else  
    {  
        item = head->data;  
        ptr = head;  
        head = head->next;  
        free(ptr);  
        printf("\nItem popped\n",item);  
        count--;
          
    }  
}  
void display()  // display function declaration
{  
    int i;  
    Node *ptr;  
    ptr=head;  
    if(ptr == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {  
        printf("\nPrinting Stack elements \n");  
        while(ptr!=NULL)  
        {  
            printf("%d\n",ptr->data);  
            ptr = ptr->next;  
        }  
    }  
}  

void Stack_Count()
{
    printf("\n No. of nodes in stack : %d", count);
}
