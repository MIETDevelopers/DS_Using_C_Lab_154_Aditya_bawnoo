//Author Name: Aditya Bawnoo
//Creation Date: 8 August 2021
//Purpose: Implementing a queue using Linked List and develop functions to perform enqueue and dequeue operations.

#include<stdio.h>	//Preprocessor directive to include standard input output header file   
#include<stdlib.h>  //Preprocessor directive to include standard library header file

struct node   // creating data type namely struct node
{  
    int data;   //Member Variable
    struct node *next;  //Member Variable and creating pointer next
};

typedef struct node Node;
  
Node *front=NULL;  // Creating a pointer namely front
Node *rear=NULL;   // Creating a pointer namely rear

void Enqueue();  //Function Prototype
void Dequeue();  //Function Prototype
void Display(); //Function Prototype




void main ()  // main function
{  
    int choice; 
	 
    while(1)   
    {     
        printf("\nSelect 1 to Enqueue\n");
		printf("\nSelect 2 to Dequeue\n");
		printf("\nSelect 3 to Display\n");
		printf("\nSelect 4 toExit\n"); 
        
		printf("\nEnter Your Choice: ");  
        scanf("%d",& choice);  
        switch(choice)  
        {  
            case 1:
                    printf("\nImplementing Enqueue function\n");                           
                    Enqueue();
                    break;
            case 2:
                	printf("\nImplementing Dequeue function\n"); 
                    Dequeue();
                    break;
            case 3:
                    printf("\nImplementing Display function\n");                           
                    Display();
                    break;    
            case 4:
            		printf("Exiting the program!");
                    exit(0);
                    break;
            default:
                    printf("\nWrong Choice! :/");
                    break; 
        }  
    }  
}  
void Enqueue()  // enqueue function declaration
{  
    Node *pointer;  
    int store;   
      
    pointer = (Node *) malloc (sizeof(Node));  // using malloc function
    if(pointer == NULL)  
    {  
        printf("\nNo Space!\n");  
        return;  
    }  
    else  
    {   
        printf("\nEnter Value: ");  
        scanf("%d",&store);  
        pointer -> data = store;  //pointer is storing the value of store in data
        if(front == NULL)  
        {  
            front =rear= pointer; // adress of pointer is being stored in front and rear  
            front -> next = NULL;  // the next part of front is being initialized as null
            rear -> next = NULL;  // the next part of rear is being initialized as null
        }  
        else   
        {  
            rear -> next = pointer;  //
            rear = pointer;  
            rear->next = NULL;  
            printf("Enqueing Succesfully");
        }  
        
    }  
}     
void Dequeue ()  // dequeue function declaration
{  
    Node *pointer;  
    if(front == NULL)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
    }  
    else   
    {  
        pointer = front;  
        front = front -> next;  
        printf("Dequeing Succesfully");
        free(pointer); 
	 
    }  
    
}  
void Display()  // display function declaration
{  
    Node *pointer;  
    pointer = front;      
    if(front == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\n\tPrinting values .....\n");  
        while(pointer != NULL)   
        {  
            printf("\n%d\n",pointer -> data);  
            pointer = pointer -> next;  
        }  
    }  
} 

