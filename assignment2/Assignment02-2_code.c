//Implement a function 'mem-alloc_3D_double' of allocationg 3D array of double.
//Then, use this as below
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define HEIGHT 3
#define ROW 3
#define COL 3

void mem_Alloc_3D_double(double ****p) {
	(*p) = (double***)malloc(sizeof(double**) * HEIGHT);
	int i = 0, j = 0, k=0;

	//allocate memory for each dimension of the 3D array
	for (i = 0; i < HEIGHT; i++) {
		(*p)[i] = (double**)malloc(sizeof(double*) * ROW);
		for (j = 0; j < ROW; j++) {
			(*p)[i][j] = (double*)malloc(sizeof(double) * COL);
			for (k = 0; k < COL; k++){
				(*p)[i][j][k] = (i*ROW*COL)+(j*COL)+k+1;
				//initialize
				printf("%.2f ", (*p)[i][j][k]);
				//print result
			}
			printf("\n");
		}
		printf("[%d]================\n\n", i+1);
	}
	printf(">>Allocation Completed!\n\n");
}

void addition_3D(double ***p1, double ***p2) {
	int i, j, k;

	//iterate each element of the matrices and print sum
	printf("\nSum of the two 3D arrays!---------------------\n");
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < ROW; j++) {
			for (k = 0; k < COL; k++) {
				printf("%.2f ", p1[i][j][k] + p2[i][j][k]);
			}
			printf("\n");
		}
		printf("[%d]================\n", i+1);
	}
	printf(">>Addition Completed!\n\n");
}

void main() {
	//Define two matrices A and B using 'mem_alloc_3D_double';
	double ***A = NULL;
	double ***B = NULL;

	mem_Alloc_3D_double(&A);
	mem_Alloc_3D_double(&B);
	
	//Perform addition of two matrices using 'addition_3D()'
	addition_3D(A, B);

	//Deallocate A and B
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < ROW; j++) {
			free(A[i][j]);
			free(B[i][j]);
		}
		free(A[i]);
		free(B[i]);
	}
	free(A);
	free(B);
	printf(">>Deallocation Completed!\n\n");
}