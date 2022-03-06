#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	struct node* left;
	char data;
	struct node* right;
} Node;

Node* leftend = NULL;
Node* rightend = NULL;


void createdoublylinkedlist(char* s) {
	for(int i=0; i<strlen(s); i++) {
	
		Node* n = (Node*)malloc(sizeof(Node));
		n->left = NULL;
		n->right = NULL;
		n->data = s[i];
		
		if(leftend == NULL)
			leftend = rightend = n;
		else {
			rightend->right = n;
			n->left = rightend;
			rightend = n;
		}
	}
}


int checkpalindrome() {
	Node* templeft = leftend;
	Node* tempright = rightend;
	
	while( (templeft!=NULL) && (tempright!=NULL)) {
		if (templeft->data != tempright->data)
			return 0;
		templeft = templeft->right;
		tempright = tempright->left;
	}
	
	return 1;
}


void main() {
	char s[100];
	printf("enter a word :\n");
	scanf("%s", s);
	createdoublylinkedlist(s);
	
	if(checkpalindrome()) 
		printf("\nentered word is a palindrome\n");
	else
		printf("\nentered word is not palindrome\n");
}
