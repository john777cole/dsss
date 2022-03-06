#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void main() {
	
	int stack[MAX_SIZE];
	int top = -1,i, proceed;
	proceed = 1;
	int option,item;
	do {
		printf("1.push\n2.pop\n3.view\n4.exit\n");
		scanf("%d", &option);
	 	switch(option)
	  	{
		case 1: if(top==MAX_SIZE-1)
			printf("Stack overflow \n");
			else
			{
			printf("Enter the element to be added");
	      		scanf("%d",&item);
	  		stack[++top]=item;
			}
			break;
		case 2: if(top==-1)
	   		printf("Stack underflow");
			else
			printf("Deleting element = %d \n",stack[top--]);
			break;
		case 3: printf("Elements are \n"); 
			for(i=top;i>=0;i--)
			printf("%d \n",stack[i]);
			break;	
		case 4: exit(0);
                        break;
		default:printf("invalid choice");	
		}
	} while(proceed = 1);
}
