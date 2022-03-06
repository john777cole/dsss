#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int coeff;
	int pow;
	struct Node* link;
} expression;

expression* heada = NULL;
expression* headb = NULL;
expression* headresult = NULL;


void displayExpression(expression* exp) {
	expression* temp = exp;
	printf("\n");
	while(temp!=NULL) {
		if(temp == exp)
			printf("%d(x^%d)", temp->coeff, temp->pow);
		else
			printf("%+d(x^%d)", temp->coeff, temp->pow);
			
		temp = temp->link;
	}
	printf("\n");
}


void sortExpression(expression* exp) {
	expression* i = exp;
	int swapped = 0;
	
	if(exp == NULL)
		return;
	
	do {
		i = exp;
		swapped = 0;
		
		while(i->link != NULL) {
			if(i->pow < i->link->pow) {
				int temppow = i->pow;
				int tempcoeff = i->coeff;
				i->pow = i->link->pow;
				i->coeff = i->link->coeff;
				i->link->pow = temppow;
				i->link->coeff = tempcoeff;
				swapped = 1;
			}
			i = i->link;
		}
		
	}while(swapped);
}


expression* inputExpression() {
	int num;
	expression* temp;
	expression* first = NULL;
	printf("enter number of terms : ");
	scanf("%d", &num);
	printf("\n");
	for(int i=1; i<=num; i++) {
		printf("\nterm %d\n", i);
		expression* node = (expression*)malloc(sizeof(expression));
		printf("coefficient : ");
		scanf("%d", &node->coeff);
		printf("power : ");
		scanf("%d", &node->pow);
		node->link = NULL;
		if(first == NULL) {
			temp = first = node;
		}
		else {
			temp->link = node;
			temp = node;
		}
	}
	
	sortExpression(first);
	
	displayExpression(first);
	
	printf("--------------------------------------\n");
	
	return first;
}


void findSum(expression* expa, expression* expb) {
	
	expression* temp;
	expression* node;
	
	while((expa != NULL) && (expb != NULL)) {
		if(expa->pow == expb->pow) {
			int sum = expa->coeff + expb->coeff;
			if(sum) {
				node = (expression*)malloc(sizeof(expression));
				node->coeff = sum;
				node->pow = expa->pow;
				node->link = NULL;
				if(headresult==NULL)
					headresult = temp = node;
				else {
					temp->link = node;
					temp = node;
				}
			}
			expa = expa->link;
			expb = expb->link;
		}
		
		else if(expa->pow > expb->pow) {
			node = (expression*)malloc(sizeof(expression));
			node->coeff = expa->coeff;
			node->pow = expa->pow;
			node->link = NULL;
			if(headresult==NULL)
				headresult = temp = node;
			else {
				temp->link = node;
				temp = node;
			}
			
			expa = expa->link;
		}
		
		else {
			node = (expression*)malloc(sizeof(expression));
			node->coeff = expb->coeff;
			node->pow = expb->pow;
			node->link = NULL;
			if(headresult==NULL)
				headresult = temp = node;
			else {
				temp->link = node;
				temp = node;
			}
			
			expb = expb->link;
		}
	}
	
	while(expa != NULL) {
		node = (expression*)malloc(sizeof(expression));
		node->coeff = expa->coeff;
		node->pow = expa->pow;
		node->link = NULL;
		if(headresult==NULL)
			headresult = temp = node;
		else {
			temp->link = node;
			temp = node;
		}
		
		expa = expa->link;
	}
	
	while(expb != NULL) {
		node = (expression*)malloc(sizeof(expression));
		node->coeff = expb->coeff;
		node->pow = expb->pow;
		node->link = NULL;
		if(headresult==NULL)
			headresult = temp = node;
		else {
			temp->link = node;
			temp = node;
		}
		
		expb = expb->link;
	}
	
}


void main() {
	printf("\nexpression 1 :\n");
	heada = inputExpression();
	printf("\nexpression 2 :\n");
	headb = inputExpression();
	
	findSum(heada, headb);
	
	printf("\nSum of both expressions : \n");
	displayExpression(headresult);
}
