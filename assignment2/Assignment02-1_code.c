#include<stdio.h>

#define ROWS 6
#define COLS 6
#define MAX_TERMS 10

typedef struct {
	int row;
	int col;
	int value;
} element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows; //row size
	int cols; //cloumn size
	int terms; // the number of elemnets
}SparseMatrix;

void printMat(element data[]) {
	int k = 0, i, j;
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
			if (data[k].row == i && data[k].col == j) {
				printf("%d ", data[k].value);
				k++;
			}
			else {
				printf("0 ");
			}
		}
		printf("\n");
	}
} //print out Matrix

void main() {
	SparseMatrix B = { {{0,3,7},{1,0,9},{1,5,8},{3,0,6},{3,1,5}, {4,5,1}, {5,2,2}}, ROWS, COLS, 7 };
	//Add B as an input

	SparseMatrix result;
	element temp;
	int i, j, k = 0;

	result.cols = B.cols;
	result.rows = B.rows;
	result.terms = B.terms; //Initialize result

	for (i = 0; i < B.rows; i++) {
		for (j = 0; j < B.cols; j++) {
			if (B.data[k].row == i && B.data[k].col == j) {
				result.data[k].row = j;
				result.data[k].col = i;
				result.data[k].value = B.data[k++].value;
			}
		}
	}//Perform the transpose operation

	for (i = 0; i < result.terms; i++) {
		for (j = i; j < result.terms - 1; j++) {
			if (result.data[j].row > result.data[j + 1].row) {
				temp = result.data[j];
				result.data[j] = result.data[j + 1];
				result.data[j + 1] = temp;
			}
		}
	}//Perform the sorting operation, completing transposed matrix
	//Print out B and B ^T
	printf("== Matrix B ==\n");
	printMat(B.data);

	printf("== Matrix B^T ==\n");
	printMat(result.data);
}