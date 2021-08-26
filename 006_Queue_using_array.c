#include<stdio.h>
#include<stdlib.h>
# define N 5
int queue[N],front = -1, rear = -1, i;
	int enqueue();
	int dequeue();
	void display(); 
int main(){
	
int ch;
printf("\n 1.Enqueue or Insert ");
printf("\n 2. Dequeue or Delete");
printf("\n 3. Display");
printf("\n 4. Exit");
for(;;)
{
	printf("\n Enter Choice:");
	scanf("%d",&ch);
      switch(ch)  
        {  
            case 1:  
            {   
                enqueue(2); 
                break;  
            }  
            case 2:  
            {  
                dequeue();
                break;  
            }  
            case 3:  
            {  
                display();
                break;  
            }  
            case 4:   
            {  
                exit(0);  
            }  
            default:  
            {  
                printf("\nPlease Enter valid choice ");  
            }   
        }  
    }  
}   
	int enqueue(){
		int X;
		if(rear == N-1){
			printf("Overflow");
		}
		else if ( front == -1 && rear == -1){
			front = rear = 0;
			
			printf("Enter Elements");
			scanf("%d",&X);
				
			queue[rear] = X;
		}
			else {
				rear ++;
				queue[rear] = X;
			}
	}
	
int dequeue(){
	if(front == -1 && rear == -1){
		printf("Underflow Condition");
	}
else if(front == rear){
	front = rear = -1;
}
else {
	printf("The dequeued Element is %d ",queue[front]);
	front ++;
}
}
void display(){
	
if(front == -1 && rear == -1){
	printf("Queue is Empty");
}
else {
	for ( i = front; i < rear + 1; i++){
		printf("%d",queue[i]);
	}
}
}

