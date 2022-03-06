#include<stdio.h>
#include<stdlib.h>


struct Node {
	struct Node* prev;
	int data;
	struct Node* next;
};

struct Node* beg = NULL;
struct Node* end = NULL;


void displayList() {
	printf("\n");
	struct Node* temp = beg;
	while(temp != NULL) {
		printf("%d   ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}


void insertElement(int pos) {
	int data;
	printf("\nenter data : ");
	scanf("%d", &data);
	
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->prev = NULL;
	n->next = NULL;
	
	if(pos == 0) {
		printf("enter position to insert data : ");
		scanf("%d", &pos);
	}
	
	if((beg == NULL) && (end == NULL))
		beg = end = n;
	else if(pos == 1) {
		beg->prev = n;
		n->next = beg;
		beg = n;
	}
	else {
		struct Node* temp = beg;
		int count = 0;
		
		while(temp != NULL) {
			count++;
			if(count == pos)
				break;
			temp = temp->next;
		}
		
		if(temp != NULL) {
			n->prev = temp->prev;
			temp->prev->next = n;
			n->next = temp;
			temp->prev = n;
		}
		else {
			end->next = n;
			n->prev = end;
			end = n;
		}
	}
	
	/*
	if((beg == NULL) && (end == NULL))
		beg = end = n;
	else if(pos == 0) {
		beg->prev = n;
		n->next = beg;
		beg = n;
	}
	else if(pos == 1) {
		end->next = n;
		n->prev = end;
		end = n;
	}
	else {
		printf("enter position to insert data : ");
		int p;
		scanf("%d", &p);
	}
	*/
	
	displayList();
}


void deleteElement() {

	if( (beg == NULL) && (end == NULL) ) {
		printf("underflow...!\n");
		return;
	}
	
	int ele;
	printf("\nenter element to delete : ");
	scanf("%d", &ele);
	
	struct Node* temp = beg;
	
	while(temp != NULL) {
		if(temp->data == ele) {
			if((temp == beg) && (temp == end))
				beg = end = NULL;
			else if(temp == beg) {
				beg = beg->next;
				beg->prev = NULL;
			}
			else if(temp == end) {
				end = end->prev;
				end->next = NULL;
			}
			else {
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
			
			free(temp);
			break;
		}
		
		temp = temp->next;
	}
	
	displayList();
}


void main() {
	int choice;
repeat:
	printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at a position\n4.Delete a node\n5.Exit\nenter your choice : ");
	scanf("%d", &choice);
	switch(choice) {
		case 1: insertElement(1);
			break;
		case 2: insertElement(-1);
			break;
		case 3: insertElement(0);
			break;
		case 4: deleteElement();
			break;
		case 5: exit(0);
			break;
		default: printf("wrong choice...!\n");
	}
	goto repeat;
}
