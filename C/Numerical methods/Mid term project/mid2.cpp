#include<stdio.h>
#include<math.h>
#include <time.h>


double Legendre( int n, double x) {  //taken from the textbook, calculates legendre polynomials
	double r, s, t;
	int m;
	r = 0; s = 1.;   //s is polynomial Ln.
	// Use recursion relation to generate p1 and p2
	for (m=0; m < n; m++ )
	{
	t = r; r = s;
	s = (2*m+1)*x*r - m*t;
	s /= (m+1);
	}
	return s;
}
int sign(double x){
	if(x<0) return -1;
	else return 1;
}

double Legendre_np(double xi[], int n){  //calculates nul-point of legendre polynomials
	int i = 0;
	int J = 20000000;  //precision!
	double dx = 2./J;
	for(int j = 1; j < J; j++){
		if(sign(Legendre(n, -1 + dx*j - dx)) != sign(Legendre(n, -1 + dx*j))) {
			xi[i] = -1 + dx*j - dx/2;
			i++;
		}
	}
	return 0;
}

double weight(double xi[], double wi[], int n){ //calculates weights for integration
	for(int j = 0; j < n; j++){
		wi[j] = 2*(1-pow(xi[j], 2))/n/n/pow(xi[j]*Legendre(n, xi[j]) - Legendre(n-1, xi[j]), 2);
	}
	return 0;
}

double trap(int N){
	double a = 0;
	double b = 1;
	double sum = 0;
	double h = (b-a)/N;
	for(int i = 1; i<N; i++){
		sum += exp(-a - i*h);
	}
	sum += exp(-a)/2 + exp(-b)/2;
	sum *= h;
	return sum;
}

double Simps(int N){
	double a = 0;
	double b = 1;
	double sum = 0;
	double h = (b-a)/N;
	for(int i = 1; i < N; i++){
		if(i % 2 == 0) sum += 2*exp(-a - i*h);
		else sum += 4*exp(-a - i*h);
	}
	sum += exp(-a) + exp(-b);
	sum *= h/3;
	return sum;
}

double Gauss(double xi[], double wi[], int N){
	Legendre_np(xi, N);
	weight(xi, wi, N);
	double sum = 0;
	for(int i = 0; i < N; i++){
		sum += 0.5*wi[i]*exp(-0.5*xi[i] - 0.5);
	}
	return sum;
}

int main(){
	int N = 10;
	int M = 14;
	int N_mesh[M] = {2, 5, 10, 20, 40, 80, 160, 300, 500, 700, 1000, 5000, 10000, 100000};
	//We will be using Legendre-Gauss quadrature
	//precision is 7 digits!
	double xi[N];
	double wi[N];
	
	double exact = 0.632120558828557;//1 - exp(-1);
	printf("Gauss-Legendre quadrature:\n");
	
	double temp;
	
	temp = Gauss(xi, wi, 2);
	printf("N = 2: %.15lf, error = %E\n", temp, fabs(temp-exact)/exact);
	
	temp = Gauss(xi, wi, 5);
	printf("N = 5: %.15lf, error = %E\n", temp, fabs(temp-exact)/exact);
	
	temp = Gauss(xi, wi, 7);
	printf("N = 7: %.15lf, error = %E\n", temp, fabs(temp-exact)/exact);
	
	clock_t tStart = clock();
	temp = Gauss(xi, wi, 10);
	printf("N = 10: %.15lf, error = %E\n", temp, fabs(temp-exact)/exact);
	printf("Computation time for Gaussian (n=10): %.15lf s\n\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	double res_trap[M];
	double res_simp[M];
	
	for(int i = 0; i < M; i++){
		res_trap[i] = trap(N_mesh[i]);
		res_simp[i] = Simps(N_mesh[i]);
	}
	//printf("%.10lf\n", Simps(50));
	//error
	
	double error_trap[M];
	double error_simp[M];
	for(int i = 0; i < M; i++){
		error_trap[i] = fabs(res_trap[i] - exact)/exact;
		error_simp[i] = fabs(res_simp[i] - exact)/exact;
		printf("trapezoidal: N = %d, %.10lf, error = %.10E\n",N_mesh[i], res_trap[i], error_trap[i]);
		printf("Simpson: N = %d, %.10lf, error = %.10E\n\n", N_mesh[i], res_simp[i], error_simp[i]);
	}
	
	
	return 0;
}
