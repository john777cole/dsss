#include<stdio.h>
#include<string.h>
#include<ctype.h>

int stack[100];
int size = -1;


int exponent(int base, int power) {
	int result = 1;
	for(int i=1; i<=power; i++)
		result *= base;
	return result;
}


void pushToStack(int operand) {
	size++;
	stack[size] = operand;
}


int popFromStack() {
	return stack[size--];
}


int evaluatePostfix(char* exp) {
	
	for(int i=0; i<strlen(exp); i++) {
		if(isdigit(exp[i]))
			pushToStack((int) exp[i]);
		else {
			int value1, value2;
			value1 = popFromStack();
			value2 = popFromStack();
			switch(exp[i]) {
				case '+':pushToStack(value2+value1);
					 break;
				case '-':pushToStack(value2-value1);
					 break;
				case '*':pushToStack(value2*value1);
					 break;
				case '/':pushToStack(value2/value1);
					 break;
				case '^':pushToStack(exponent(value2, value1));
					 break;
			}
		}
	}
}


void main() {
	printf("enter the postfix expression : \n");
	char exp[100];
	scanf("%[^\n]", exp);
	printf("result : %d\n", evaluatePostfix(exp));
}
