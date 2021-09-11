//Author: Aditya Bawnoo                                                                                      
// Creation Date : 09 September 2021
// Purpose:   
         //  Write a C program to compare the running times (in milliseconds) of follwing
		 //	Bubble Sort 
		 //	Merge Sort 
		 // Given Array: {1,3,42,2,41,66,66,33,98,0}
		 
#include<stdio.h>    //  Pre-Processor directive to include standard input and output funtion header files
#include<stdlib.h>	//  Pre-Processor directive to include standard library function
#include<time.h>    // The time.h header file contains definitions of functions to get and manipulate date and time information. 

int p1,p2;

void swap(int *alpha1, int *alpha2)  	//pass the address of the variables to swap
{ 					
	int head; // Declaraing head varibale to store adress of alpha 1 and 2  
	head=*alpha1; // assigning alpha 1 to head 
	*alpha1=*alpha2;
	*alpha2=head;
}
void bubbleSort(int *array, int size)
{
	
	int i, j; // Declaring i as sort_index and j as unosorted_index
	for (i= 0;i< (size-1); ++i) // initiating for loop 
	{
		for (j= 0;j< (size-(i+1)); ++j)
		{
			if (array[j]>array[j+1]) //using if loop for iterating array
			{
				swap(&array[j], &array[j+1]);
			}
		}
	}      
}

void merge(int *alpha, int leftValue, int mergeValue, int rightValue) 
{
	
	 p1 = mergeValue-leftValue+1;
	 p2 = rightValue-mergeValue;                     //right value-(merge value+1)+1;
	int leftArray[p1], rightArray[p2]; // Decalraing Two Array Variable with int data type 
	int p,b,x;
									 //Copy data to temp arrays */
    for (p= 0; p< p1; p++)
        leftArray[p] = alpha[leftValue +p];
    for (b= 0; b< p2; b++)
        rightArray[b] = alpha[(mergeValue + 1) +b];
	b = 0;                                           // Initial index of first or left subarray
    p = 0;                                           // Initial index of second or right subarray
    x = leftValue;                                          // Initial index of merged subarray
    while(p<p1 && b<p2){
    	if (leftArray[p]<=rightArray[b])
    	{
    		alpha[x] = leftArray[p];
    		p++;
    	} else{
    		alpha[x] = rightArray[b];
    		b++;
    	}
    	x++;
    }
    while (p<p1) { // right is empty
        alpha[x] = leftArray[p];
        p++;
        x++;
    }
    while (b<p2) { // left is empty
        alpha[x] = rightArray[b];
        b++;
        x++;
    }
}
void mergeSort(int *alpha, int leftValue, int rightValue)
     {                                    					   //recursive function
	int mergeeValue;
				/* leftValueIn is for left index and r is right index of the sub-array of arr to be sorted 
	 					split if there are more than 1 elements: when leftValue<rightValue */
	if (leftValue < rightValue)
	{
									/* split the array and length = (r-l)+1
										we will use (l+r)/2 */
		mergeeValue = (leftValue+rightValue)/2;
											// call mergeSort() for left subarray
		mergeSort(alpha, leftValue, mergeeValue);
										// call mergeSort() for right subarray
		mergeSort(alpha, mergeeValue+1, rightValue);
										// merge the left and right subarray
		merge(alpha, leftValue, mergeeValue, rightValue);
	}
}
int printArray(int *alpha, int size)
{
	int counter; // Counter variable  for printing sort ed
	for (counter = 0; counter < size; ++counter)
	{
		
		printf("\nArray Your Entered Is..."); // 
		printf("\narr[%d] = %d", counter, *(alpha+counter)); // Printing the Required Array
	}
	return (counter+1);										// returns the number of elements printed
}
int getInput(int *alpha, int size)
{
	int counter2; // counter variable for taking  unsorted array
	for (counter2= 0; counter2 < size; ++counter2)
	{
		printf("Enter arr[%d]=",counter2);
		scanf(" %d", (alpha+counter2));        // taking array fromm user 
	}
	return (counter2+1);// returns the number of elements read
}

int main()
{
	int alpha[10];// declaraing array with size 10 
	int ch;	
	printf("\n	Time Calculator \n\n\n");
    printf("\n Required Array : [1, 3, 42, 2, 41, 66, 66, 33, 98, 0 ]   \n\n");
    getInput(alpha, 10);  
    
	clock_t begin = clock(); //The C library function clock_t begin returns the number of clock ticks elapsed since the program was launched.
	
    bubbleSort(alpha, 10);  /* Function to for bubblesort an array */
    printArray(alpha, 10);  /* Function to print an array */
    printf("\n\n");
    clock_t end = clock();  //The C library function clock_t end returns the number of clock ticks elapsed since the program was ended.
    
    float duration = (float)(end - begin) / CLOCKS_PER_SEC; //  It will convert the number of CPU cycles to the CPU time taken by the process as shown in the following code:
    
	printf("Bubble sort Completed By Compiler In : %f ms\n", duration * 1000); //   // Dividing a count of clock ticks by this expression yields the number of seconds.
    printf("\n\n");
    begin = clock();
    mergeSort(alpha, 0, 9); /* Function to for merge_sort an array */
    printArray(alpha, 10);   /* Function to print an array */
    printf("\n\n");
    end = clock();
    duration = (float)(end - begin) / CLOCKS_PER_SEC; // It will convert the number of CPU cycles to the CPU time taken by the process as shown in the following code:
    printf("Merge sort Completed By Compiler In : %f ms\n", duration * 1000);
    do
	{
	printf("\n    1.Press 1 For Getting Question");
    printf("\n    2.Press 2 For Answer");
    printf("\n    3.Exit From A program");
    scanf("%d",&ch);
    switch(ch)
    {
    	case 1:
    		printf("\n\t\tWhich algorithm is faster  Bubble OR Merge and why? ");
    		break;
    	case 2:
    printf("\n\t\tWhich algorithm is faster  Bubble OR Merge and why?\n\n ");
    printf("\n  1.)Bubble sort is a simple sorting algorithm. ");
	printf("\n  2.)This sorting algorithm is comparison-based algorithm in which each pair of adjacent elements is compared and the elements are swapped if they are not in order. ");
	printf(" \n 3.)Just like the movement of air bubbles in the water that rise up to the surface, each element of the array move to the end in each iteration. ");	 
	printf(" \n 4.)Just like the movement of air bubbles in the water that rise up to the surface, each element of the array move to the end in each iteration. ");
	printf(" \n 5.) First Iteration (Compare and Swap)" );
	printf(" \n 6.)   Starting from the first index, compare the first and the second elements.");
	printf("\n  7.)If the first element is greater than the second element, they are swapped. ");
	printf("\n  8.)Now, compare the second and the third elements. Swap them if they are not in order. ");
	printf("\n  9.)The above process goes on until the last element.");
	printf(" \n 10.)The same process goes on for the remaining iterations. ");
	printf(" \n 11.)After each iteration, the largest element among the unsorted elements is placed at the end.");
	printf(" \n 12.)The array is sorted when all the unsorted elements are placed at their correct positions.");
	printf(" \n 13.)Bubble Sort Applications");
	printf(" \n 14.)Bubble sort is used if comlexity does not matter");
	printf(" \n 15.)Bubble sort is used if short and simple code is preferred");
	printf("\n\t\tThanks");
	break;
	case 3: exit(0);
        break;

	default:
        printf("Invalid choice! :/");
           break;
            }
     printf("\n Do you want to continue? (Press y/n): -->    ");
scanf(" %c",&ch);
}while(ch=='y'   || ch=='Y');
}
