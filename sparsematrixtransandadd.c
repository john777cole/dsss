#include <stdio.h>

typedef struct {
	int row;
	int col;
	int value;
} array;

array A[50], B[50], AT[50], BT[50], sum[50];



void displaymform(int a[20][20],int ar, int ac) {
	
	for(int i=0; i<ar; i++) {
		for(int j=0; j<ac; j++)
			printf("%d   ", a[i][j]);
		printf("\n");
	}	
}



void matrixtotuple(int m[20][20], int mr, int mc, array t[50]) {
	t[0].row = mr;
	t[0].col = mc;
	t[0].value = 0;
	
	for(int i=0; i<mr; i++) {
		for(int j=0; j<mc; j++) {
			if(m[i][j] != 0) {
				t[0].value++;
				t[t[0].value].row = i;
				t[t[0].value].col = j;
				t[t[0].value].value = m[i][j];
			}
		}
	}
}



void displaytupform(array t[50]) {
	
	for(int i=0; i<=t[0].value; i++)
		printf("%d   %d   %d\n", t[i].row, t[i].col, t[i].value);
}



void transpose(array m[50], array t[50]) {
	t[0].row = m[0].col;
	t[0].col = m[0].row;
	t[0].value = 0;
	
	for(int i=0; i<m[0].col; i++) {
		for(int j=1; j<=m[0].value; j++) {
			if( m[j].col==i ) {
				t[0].value++;
				t[t[0].value].row = m[j].col;
				t[t[0].value].col = m[j].row;
				t[t[0].value].value = m[j].value;
			}
		}
	}
	
}



void add() {
	if( (A[0].row == B[0].row) && (A[0].col == B[0].col) ) {
		printf("\n A + B = \n");
		
		sum[0].row = A[0].row;
		sum[0].col = A[0].col;
		sum[0].value = 0;
		
		int a = 1;
		int b = 1;
		
		while( (a<=A[0].value) && (b<=B[0].value) ) {
		
			if( (A[a].row==B[b].row) && (A[a].col==B[b].col) ) {
				if( A[a].value + B[b].value != 0) {
					sum[0].value++;
					sum[sum[0].value].row = A[a].row;
					sum[sum[0].value].col = A[a].col;
					sum[sum[0].value].value = A[a].value + B[b].value;
				}
			a++;
			b++;	
			}
			
			else {
				if( A[a].row < B[b].row ) {
					sum[0].value++;
					sum[sum[0].value].row = A[a].row;
					sum[sum[0].value].col = A[a].col;
					sum[sum[0].value].value = A[a].value;
					a++;
				}
				else if( B[b].row < A[a].row ) {
					sum[0].value++;
					sum[sum[0].value].row = B[b].row;
					sum[sum[0].value].col = B[b].col;
					sum[sum[0].value].value = B[b].value;
					b++;
				}
				else {
					if( A[a].col < B[b].col) {
						sum[0].value++;
						sum[sum[0].value].row = A[a].row;
						sum[sum[0].value].col = A[a].col;
						sum[sum[0].value].value = A[a].value;
						a++;
					}
					else {
						sum[0].value++;
						sum[sum[0].value].row = B[b].row;
						sum[sum[0].value].col = B[b].col;
						sum[sum[0].value].value = B[b].value;
						b++;
					}
				}
				
			}
			
		}
		
		while( a<=A[0].value ) {
			sum[0].value++;
			sum[sum[0].value].row = A[a].row;
			sum[sum[0].value].col = A[a].col;
			sum[sum[0].value].value = A[a].value;
			a++;
		}
		
		while( b<=A[0].value) {
			sum[0].value++;
			sum[sum[0].value].row = B[b].row;
			sum[sum[0].value].col = B[b].col;
			sum[sum[0].value].value = B[b].value;
			b++;
		}
		
		
	}
	
	else 
		printf("\nMatrices A and B cannot be added\n");
}



void main() {
	int a[20][20], b[20][20], ar, ac, br, bc;
	
	printf("rows in A : ");
	scanf("%d", &ar);
	printf("cols in A : ");
	scanf("%d", &ac);
	printf("enter matrix A : \n");
	for(int i=0; i<ar; i++)
		for(int j=0; j<ac; j++)
			scanf("%d", &a[i][j]);
	
	printf("rows in B : ");
	scanf("%d", &br);
	printf("cols in B : ");
	scanf("%d", &bc);
	printf("enter matrix B : \n");
	for(int i=0; i<br; i++)
		for(int j=0; j<bc; j++)
			scanf("%d", &b[i][j]);
			
	printf("\nMatrix A : \n");
	displaymform(a, ar, ac);
	printf("\nMatrix B : \n");
	displaymform(b, br, bc);
	
	matrixtotuple(a, ar, ac, A);
	matrixtotuple(b, br, bc, B);
	
	printf("\nMatrix A in tuple form : \n");
	displaytupform(A);
	printf("\nMatrix B in tuple form : \n");
	displaytupform(B);
	
	transpose(A, AT);
	transpose(B, BT);
	
	printf("\nA Transpose in tuple form : \n");
	displaytupform(AT);
	printf("\nB Transpose in tuple form : \n");
	displaytupform(BT);
	
	add();
	displaytupform(sum);
}
