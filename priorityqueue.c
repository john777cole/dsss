#include <stdio.h>
#include <stdlib.h>


#define maxsize 100
int pq[maxsize][2];
int size = -1;


void display() {
	for(int i=0; i<=size; i++)
		printf(" %d(%d)   ", pq[i][0], pq[i][1]);
	printf("\n");
}


void enqueue() {
	if(size == maxsize-1)
		printf("\noverflow\n");
	else {
		int data, prio;
		printf("\ndata : ");
		scanf("%d", &data);
		printf("priority : ");
		scanf("%d", &prio);
		size++;
		pq[size][0] = data;
		pq[size][1] = prio;
	}
	
	display();
}


void dequeue() {

	if(size == -1) 
		printf("\nunderflow\n");
	
	else {
		int pos = 0;
		for(int i=0; i<=size; i++) 
			if(pq[i][1] < pq[pos][1])
				pos = i;
	
		for(int i=pos; i<size; i++) {
			pq[i][0] = pq[i+1][0];
			pq[i][1] = pq[i+1][1];
		}
	
		size--;
	}
	
	display();

}


void main() {
	
	int choice;
repeat:
	printf("1.Add\n2.Delete\n3.Exit\nenter your choice : ");
	scanf("%d", &choice);
	switch(choice) {
		case 1: enqueue();
			break;
		case 2: dequeue();
			break;
		case 3: exit(0);
		default : printf("Wrong input\n");
	}
	goto repeat;
}
