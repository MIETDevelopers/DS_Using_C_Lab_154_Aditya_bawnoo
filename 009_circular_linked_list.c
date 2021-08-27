#include<stdio.h>  
#include<stdlib.h>  
    struct node   
    {  
        int data;  
        struct node *next;   
    }; 
	typedef struct node Node;
     Node *tail;  
      
void beginsert ();   
void lastinsert ();  
 void display();
  
    int  main ()  
    {  
        int choice =0;  
        while(choice != 7)   
        {  
            printf("\n*********Main Menu*********\n");  
            printf("\nChoose one option from the following list ...\n");  
            printf("\n===============================================\n");  
            printf("\n1.Insert in begining\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.Search for an element\n6.Show\n7.Exit\n");  
            printf("\nEnter your choice?\n");         
            scanf("\n%d",&choice);  
            switch(choice)  
            {  
                case 1:  
                beginsert();      
                break;  
                case 2:  
                lastinsert();         
                break;
				 
				case 6:
				display();
				break;  
               
                case 7:  
                exit(0);  
                break;  
                default:  
                printf("Please enter valid choice..");  
            }  
        }  
}
    void beginsert()  
    {  
         Node *ptr; 
        int item;   
        ptr = (Node *)malloc(sizeof( Node));
        
		 printf("\nEnter the node data");
		   
            scanf("%d",&ptr -> data);
            
            ptr -> next = 0; 
            
        if(tail == 0)  
        {  
            tail = ptr;
            tail -> next = ptr;
        }  
        else   
        {  
            ptr -> next = tail -> next;
            tail -> next = ptr;
        }
    }
    void lastinsert()  
    {  
        Node  *ptr; 
        int item;  
        ptr = ( Node *)malloc(sizeof( Node)); 
        
		printf("\nEnter Data"); 
		 
            scanf("%d",&ptr -> data);
            
            ptr -> next = 0;
        if(tail == 0)
        {  
        tail = ptr;
        
            tail -> next = ptr;
        }  
        else  
        {  
          ptr -> next = tail -> next;
          tail -> next = ptr;
          tail = ptr;
      }
  }
   void display()  
    {  
         Node *ptr;  
        ptr=tail;  
        if(tail == NULL)  
        {  
            printf("\nnothing to print");  
        }     
        else  
        {  
            printf("\n printing values ... \n");  
              
            while(ptr -> next != tail)  
            {  
              
                printf("%d\n", ptr -> data);  
                ptr = ptr -> next;  
            }  
            printf("%d\n", ptr -> data);  
        }  
                  
    }



      
   
