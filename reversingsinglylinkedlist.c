#include<stdio.h>
#include<stdlib.h>

typedef struct node {
   	int data;
	struct node *link;
}listnode;

listnode *front = NULL;

listnode *create(int value){
	listnode *node;
	node = (listnode*)malloc(sizeof(listnode));
	node->data = value;
	node->link = NULL;
	return node;
}

void display(){
	listnode *temp = front;
	if(temp==NULL){
		printf("\nThe List is Empty !!!\n\n");
	}
	while(temp!=NULL){
		printf(" %d   ",temp->data);
		temp = temp->link;
	}
	printf("\n");
}


void insert_begin(int value){
	listnode *node = create(value);
	if(node!=NULL){
		if(front==NULL){
			front = node;
		}
		else{
			node->link = front;
			front = node;
		}
	}
	else{
		printf("\nOVERFLOW!!!\n");
	}
	display();
}

void insert_end(int value){
	listnode *node = create(value);
	listnode *temp = front;
	while(temp->link!=NULL){
		temp = temp->link;
	}
	if(node!=NULL){
		temp->link = node;
	}
	else{
		printf("\nOVERFLOW!!!\n");
	}
	display();
}


void reverse(){
	int count = 1,i,ct;
	listnode *temp = front;
	listnode *ptr;

	while(temp->link!=NULL){
		count++;
		temp=temp->link;
	}
	ptr = temp;
	for(i=0;i<(count-1);i++){
		temp = front->link;
		front->link = ptr->link;
		ptr->link = front;
		front = temp;
	}    
	front = ptr;
	printf("\nThe REVERSED List is : \n");
	display();
}

void main(){
	int choice,value,check;
repeat:
	printf("\n1.Insert at beginning\n2.Insert at end\n3.Reverse list\n4.Exit\nenter your choice : ");
	scanf("%d",&choice);
        switch(choice){
        	case 1 :    printf("\nEnter the value to be inserted : ");
                    scanf("%d",&value);
                    insert_begin(value);
                    break;
        	case 2 :    printf("\nEnter the value to be inserted : ");
                    scanf("%d",&value);
                    insert_end(value); 
                    break;  
        	case 3 :    reverse();
                    break;
        	case 4 :    exit(0);         
        	    break;
        	default:    printf("\nEnter a valid choice !!\n");         
	}
	goto repeat;
}
