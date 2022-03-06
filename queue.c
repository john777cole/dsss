#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
int q[MAX_SIZE];
int front = -1;
int rear = -1;



void display() {
	printf("Queue : \n");
	for(int i=front+1; i<=rear; i++)
		printf("%d   ", q[i]);
	printf("\n");
}



void delete() {
	
	if(front == rear)
		printf("U N D E R F L O W ...!\n");
	else {
		front++;
		printf("delete element %d\n", q[front]);
	}
	
	display();
	
}



void add() {
	printf("enter element to add : ");
	int item;
	scanf("%d", &item);
	
	if(rear == MAX_SIZE-1)
		printf("O V E R F L O W ...!\n");
	else {
		rear++;
		q[rear]=item;
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
		default: printf("wrong choice\n");
	}
	goto repeat;
}
