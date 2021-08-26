#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*next;
	struct node*previous;
};
typedef struct node Node; 
 Node *head;
void main(){
Node*first,*second,*third,*temp;



first  = (Node*) malloc(sizeof(Node));
second = (Node*) malloc(sizeof(Node));
third  = (Node*) malloc(sizeof(Node));	

first -> previous = NULL;
first -> data = 12;
first -> next = second;

second -> previous = first;
second -> data = 13;
second -> next = third;

third -> previous = second;
third -> data = 14;
third -> next = NULL;

head = first;

temp = head;

while (temp != NULL){
printf("Elements %d", temp -> data);
temp = temp -> next;
}
}

