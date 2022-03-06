#include<stdio.h>
#include<stdlib.h>


typedef struct node {
	int data;
	struct node* link;
} mark;

mark* head = NULL;


void display() {
	mark* temp = head;
	printf("\n");
	while(temp != NULL) {
		printf("%d  ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}


void sort() {
	mark* temp = head;
	int swapped = 0;
	
	do {
	
		temp = head;
		swapped = 0;
		
		while(temp->link != NULL) {
			if(temp->data < temp->link->data) {
				int t = temp->data;
				temp->data = temp->link->data;
				temp->link->data = t;
				swapped = 1;
			}
			temp = temp->link;
		}
	
	}while(swapped);
}


void inputmarks(int n) {
	mark* temp;
	for(int i=0; i<n; i++) {
		printf("\nenter mark %d : ", i+1);
		mark* n = (mark*)malloc(sizeof(mark));
		scanf("%d", &n->data);
		n->link = NULL;
		
		if(head == NULL)
			head = temp = n;
		else {
			temp->link = n;
			temp = n;
		}
	}
}


void main() {
	int n;
	printf("enter number of students : ");
	scanf("%d", &n);
	inputmarks(n);
	
	printf("\nMarks sorted in descending order : \n");
	sort();
	display();
}
