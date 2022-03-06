#include<stdio.h>
#include<stdlib.h>


typedef struct node {
	int data;
	struct node* link;
} Node;

Node* front = NULL;
Node* rear = NULL;


void display() {
	Node* temp = front;
	printf("\n");
	while(temp != NULL) {
		printf("%d  ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}


void add() {
	Node* n = (Node*)malloc(sizeof(Node));
	printf("\nenter data : ");
	scanf("%d", &n->data);
	n->link = NULL;
	
	if(front == NULL) 
		front = rear = n;
	else {
		rear->link = n;
		rear = n;
	}
	
	display();
}


void delete() {
	if(front == NULL) 
		printf("\nunderflow...!");
	else if(front == rear)
		front = rear = NULL;
	else
		front = front->link;
		
	display();
}


void main() {
	int choice;
repeat:
	printf("\n1.Add element\n2.Delete element\n3.Exit\nenter your choice : ");
	scanf("%d", &choice);
	switch(choice) {
		case 1: add();
			break;
		case 2: delete();
			break;
		case 3: exit(0);
			break;
		default: printf("invalid choice.......!\n");
	}
	goto repeat;
}
