#include<stdio.h>
#include<stdlib.h>
#include<math.h>


using namespace std;


double dx = 0.0001;  //arbitrarilly chosen, used in calculating derivatives

double f(double *x, int i){   //function f implemented with switch-case
	switch(i){
		case 0:
			return 3*x[3] + 4*x[4] +4*x[5] - 8;
			break;
		case 1:
			return 3*x[0] + 4*x[1] -4*x[2];
			break;
		case 2:
			return x[6]*x[0] - x[7]*x[1] - 10;
			break;
		case 3:
			return x[6]*x[3] - x[7]*x[4];
			break;
		case 4:
			return x[7]*x[1] + x[8]*x[2] - 20;
			break;
		case 5:
			return x[7]*x[4] - x[8]*x[5];
			break;
		case 6:
			return x[0]*x[0] + x[3]*x[3] - 1;
			break;
		case 7:
			return x[1]*x[1] + x[4]*x[4] - 1;
			break;
		case 8:
			return x[2]*x[2] + x[5]*x[5] - 1;
			break;
	}
}

double deriv(double *x0, int i, int j, double (*f)(double*, int)){   //here i denotes the function component, and j denotes partial derivation
	double x1[9];
	for(int l = 0; l < 9; l++) {
		if (l == j) x1[l] = x0[l] + dx;
		else x1[l] = x0[l];
	}
	double f1 = f(&x1[0], i);
	double f0 = f(x0, i);
	return (f1 - f0)/dx;
}

void matrixF(double *F, double *x0){
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			*(F + i*9 + j) = deriv(x0, i, j, f);   //F[i][j] = *(F + i*9 + j)
}


double determinant(double *A, int n){  //algorithm for computing determinants
	double sum = 0;
	double *B;
	if(n == 2) sum = (*(A)) * (*(A + 3)) - (*(A + 1)) * (*(A + 2));
	else {
		for(int i = 0; i < n; i++){
			B = (double*) malloc(sizeof(double) * (n-1) * (n-1));
			if (*(A + i) == 0) continue;
			for(int j = 0; j < n-1; j++)
			for(int k = 0; k < n-1; k++) {   //Laplace expansion
				if(k < i) *(B+(n-1)*j + k) = *(A + n*(j+1) + k);
				else if (k >= i) *(B + (n-1)*j + k) = *(A + n*(j+1) + k + 1);
				
				}
			
			sum += pow(-1, i)*determinant(B, n-1)*(*(A + i));  //Laplace expansion
			free(B);
		}
	}
	return sum;
}


void inverse(double *A, double *Ai, int n){   //algorithm for computing inverse using matrix of coefficients
	double *B = (double*) malloc(sizeof(double) * (n-1) * (n-1));; 
	double det = determinant(A, n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			
			for(int i2 = 0; i2 < n-1; i2++)
			for(int j2 = 0; j2 < n-1; j2++){
				if(i2 < i && j2 < j) *(B + (n-1)*i2 + j2) = *(A + n*i2 + j2);
				else if(i2 < i && j2 >= j) *(B + (n-1)*i2 + j2) = *(A + n*i2 + j2 + 1);
				else if(i2 >=i && j2 < j) *(B + (n-1)*i2 + j2) = *(A + n*(i2+1) + j2);
				else if(i2 >= i && j2 >= j) *(B + (n-1)*i2 + j2) = *(A + n*(i2+1) + j2 + 1);
				
			}
			*(Ai + n*j + i) = pow(-1, i+j)*determinant(B, n-1)/det;
			
		}
	}
	
	free(B);
	
}


void prod(double *A, double *B, double *AB, int dim1, int dim2){  //dim1 is dimension of (square) matrix A, dim2 refers to number of rows of
	double sum;  													//matrix B
	for(int i = 0; i < dim1; i++){
		for(int j = 0; j < dim2; j++){
			sum = 0;
			for(int k = 0; k < dim1; k++)
				sum += (*(A + dim1*i + k)) * (*(B + dim2*k + j));
			*(AB + dim2*i + j) = sum;
		}
	}
}

int main(){
	//double x[9] = {-10, -1000.3, 3000.3, 50000.3, 0.3, -110.3, -1500, 1500, -1500};
	double x[9] = {0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 15, 15, 15}; //vector of initial guess of solution x
	double precision = 1E-06;
	
	double *F = (double*) malloc(sizeof(double) * 9 * 9);
	double *G = (double*) malloc(sizeof(double) * 9 * 9);   //G is inverse of F
	
	
	
	double *del_x = (double*) malloc(sizeof(double) * 9);  //change in vector x
	double *ff = (double*) malloc(sizeof(double) * 9);  //vector of function f
	//double *ttt = (double*) malloc(sizeof(double) * 9);
	
	for(int i = 0; i < 9; i++) *(ff + i) = -f(&x[0], i);  //setting elements of vector f
	
	matrixF(F, &x[0]);
	inverse(F, G, 9);

	bool temp = 1;
	
	while(1){
		prod(G, ff, del_x, 9, 1);
		for(int i = 0; i < 9; i++) x[i] += *(del_x + i);
		for(int i = 0; i < 9; i++) *(ff + i) = -f(&x[0], i);
		temp = 1;
		for(int i = 0; i < 9; i++)
			if(fabs(*(ff + i)) > precision) {
				temp = 0;
				//printf("%lf\n", *(ff+i));
				break;
			}
		if (temp == 1) break;
		
		matrixF(F, &x[0]);
		inverse(F, G, 9);
	}
	
	
	for(int i = 0; i < 9; i++){
		printf("%.8lf\n", x[i]);
	}
	
	printf("\nChecking the solution:\n");
	for(int i = 0; i < 9; i++) printf("%.8lf\n", f(x, i));
	
	return 0;
}
