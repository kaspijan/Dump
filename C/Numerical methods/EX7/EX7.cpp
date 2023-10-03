#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

/// matrix element Aij is accessed with *(ptrA + size*i + j) where i tells the row and j tells the columb 
double sumAB(double* a, double* b, int size){
	double sum = 0;
	printf("\nMatrix A + B:\n");
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++)
			printf("%7.2lf ", *(a + size*i + j) + *(b + size*i + j));
		printf("\n");
	}
}

double prodAB(double* a, double* b, int size){
	
	double sum;
	
	printf("\nMatrix AB:\n");
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			sum = 0;
			for(int k = 0; k < size; k++) {
				sum += (*(a + size*i + k)) * (*(b + size*k + j));
				}
			printf("%7.2lf ", sum);
		}
		printf("\n");
	}	
}

void type(double* ptr, int size){
	bool upper = 1; //upper is 1 if matrix is upper triangular
	bool lower = 1; //lower is 1 if matrix is lower triangular
					//if both are 1, matrix is diagonal
	for(int i = 0; i < size; i++){
		for(int j = i+1; j < size; j++){
			if(*(ptr + i*size + j) != 0) {
				lower = 0;
				//printf("Matrix is not lower triangular");
				break;
			}
		}
		if (lower == 0) break;
	}
	
	for(int j = 0; j < size; j++){
		for(int i = j+1; i < size; i++){
			if(*(ptr + i*size + j) != 0) {
				upper = 0;
				//printf("Matrix is not lower triangular");
				break;
			}
		}
		if (upper == 0) break;
	}
	
	if(upper == 1 && lower == 1) printf("Matrix is diagonal.\n");
	else if (upper == 0 && lower == 1) printf("Matrix is lower triangular.\n");
	else if(upper == 1 && lower == 0) printf("Matrix is upper triangular.\n");
	else printf("Matrix is neither diagonal nor triangular.\n");
	
}

int main(){
	int size;
	printf("Input size of matrix n: ");
	scanf("%d", &size);
	
	double* ptrA;
	ptrA = (double*)malloc(size*size*sizeof(double));
	double* ptrB;
	ptrB = (double*)malloc(size*size*sizeof(double));
	
	printf("Input elements of matrix A:\n");
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++){
			printf("Row %d, column %d: ", i+1, j+1);
			scanf("%lf", (ptrA + size*i + j));
		}
	
	printf("Input elements of matrix B:\n");
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++){
			printf("Row %d, column %d: ", i+1, j+1);
			scanf("%lf", (ptrB + size*i + j));
		}
		
		
	printf("\nMatrix A:\n");
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++)
			printf("%7.2lf ", *(ptrA + size*i + j));
		printf("\n");
	}
	
	printf("\nMatrix B:\n");
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++)
			printf("%7.2lf ", *(ptrB + size*i + j));
		printf("\n");
	}
	
	sumAB(ptrA, ptrB, size);
	prodAB(ptrA, ptrB, size);
	
	printf("\nType of matrix A:\n");
	type(ptrA, size);
	
	printf("\nType of matrix B:\n");
	type(ptrB, size);
	
	free(ptrA);
	free(ptrB);
	return 0;
}
