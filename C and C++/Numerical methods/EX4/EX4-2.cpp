#include<stdio.h>
#include<math.h>

using namespace std;

double trap1(double N);
double trap2(double N);

double simps1(double N);
double simps2(double N);

double trap1(double N){
	double a = 0;
	double b = M_PI;
	double suma = 0;
	double h = (b - a)/N;
	for(int i = 1; i < N; i++){
		//suma += 1/pow(a + i*h, 2);
		suma += sin(a + i*h);
	}
	suma += sin(a) + sin(b);
	//suma += 1/pow(a, 2)/2 + 1/pow(b, 2)/2;
	suma *= h;
	return suma;
}

double simps1(double N){
	double a = 0;
	double b = M_PI;
	double h = (b - a)/N;
	double suma = 0;
	for(int i = 1; i < N; i++){
		if(i % 2 == 0) suma += 2*sin(a + i*h);
		else suma += 4*sin(a + i*h);
	}
	suma += sin(a) + sin(b);
	suma *= h/3;
	return suma;
}

double trap2(double N){
	double a = 0;
	double b = 0.5;
	double suma = 0;
	double h = (b - a)/N;
	for(int i = 1; i < N; i++){
		//suma += 1/pow(a + i*h, 2);
		suma += (a+i*h)*exp(pow(a + i*h, 2));
	}
	suma += (a)*exp(pow(a , 2)) + (b)*exp(pow(b, 2));
	//suma += 1/pow(a, 2)/2 + 1/pow(b, 2)/2;
	suma *= h;
	return suma;
}

double simps2(double N){
	double a = 0;
	double b = 0.5;
	double h = (b - a)/N;
	double suma = 0;
	for(int i = 1; i < N; i++){
		if(i % 2 == 0) suma += 2*(a+i*h)*exp(pow(a + i*h, 2));
		else suma += 4*(a+i*h)*exp(pow(a + i*h, 2));
	}
	suma += (a)*exp(pow(a , 2)) + (b)*exp(pow(b, 2));
	suma *= h/3;
	return suma;
}

int main(){
	int step[19] = {100, 200, 500, 800, 1000, 2000, 5000, 7500, 10000, 35000, \
	50000, 70000, 100000, 500000, 1000000, 5000000, 10000000, 30000000, 60000000};
	printf("Analytical solution: 2\n\n");
	for(int i = 0; i < 19; i++){
		//printf("%.15lf, ", simps1(step[i]));
		printf("%d, %.15lf, %.15lf\n", step[i], trap1(step[i]), simps1(step[i]));
	}
	
	printf("\nAnalytical solution: %.15lf\n", exp(0.25)/2 - 0.5);
	for(int i = 0; i < 19; i++){
		//printf("%.15lf, ", simps2(step[i]));
		printf("%d, %.15lf, %.15lf\n", step[i], trap2(step[i]), simps2(step[i]));
	}
	return 0;
}

