#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
int q[MAX_SIZE];
int front = -1;
int rear = -1;



void display() {
	printf("Queue : \n");
	if(front > rear) {
		for(int i=front; i<MAX_SIZE; i++)
			printf("%d   ", q[i]);
		for(int i=0; i<=rear; i++)
			printf("%d   ", q[i]);
	}
	else  if(front==-1 && rear==-1)  
	{printf("Empty");}
	else { // add condition if front = rear = -1
		for(int i=front; i<=rear; i++)
			printf("%d   ", q[i]);
	}
	printf("\n");
}



void add() {
	int item;
	printf("enter element to add : ");
	scanf("%d", &item);
	
	if( (front == -1) && (rear == -1) ) {
		front = rear = 0;
		q[rear] = item;
	}
	else if( (rear+1)%MAX_SIZE == front) {
		printf("overflow..!!\n");
	}
	else {
		rear = (rear+1)%MAX_SIZE;
		q[rear] = item;
	}
		
	
	display();
}



void delete() {

	if(front == -1)
		printf("underflow..!!\n");
	else if(front == rear) {
		printf("delete element %d\n", q[front]);
		front=rear=-1;
	}
	else {
		printf("delete element %d\n", q[front]);
		front = (front+1)%MAX_SIZE;
	}
	
	display();
}



void main() {
	int choice;
repeat:
	printf("\n1.Add\n2.Delete\n3.Exit\nenter choice : ");
	scanf("%d", &choice);
	switch(choice) {
		case 1: add();
			break;
		case 2: delete();
			break;
		case 3: exit(0);
			break;
		default: printf("invalid choice \n");
	}
	goto repeat;
}
