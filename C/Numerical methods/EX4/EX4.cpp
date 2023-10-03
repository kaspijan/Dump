#include<stdio.h>
#include<math.h>

using namespace std;

double trap1(double N);
double trap2(double N);
double trap3(double N);


double trap1(double N){
	double a = 1;
	double b = 2;
	//exact solution is 0.5
	double suma = 0;
	double h = (b - a)/N;
	for(int i = 1; i < N; i++){
		suma += 1/pow(a + i*h, 2);
	}
	suma += 1/pow(a, 2)/2 + 1/pow(b, 2)/2;
	suma *= h;
	return suma;
}


double trap2(double N){
	double a = 0;
	double b = 1;
	//exact solution is e - 1 = 1.7183...
	double suma = 0;
	double h = (b - a)/N;
	for(int i = 1; i < N; i++){
		suma += exp(a + i*h);
	}
	suma += exp(a)/2 + exp(b)/2;
	suma *= h;
	return suma;
}

double trap3(double N){
	double a = 0;
	double b = 1;
	//exact solution is pi/4 = 0.78540...
	double suma = 0;
	double h = (b - a)/N;
	for(int i = 1; i < N; i++){
		suma += sqrt(1 - pow(a + i*h, 2));
	}
	suma += sqrt(1 - pow(a, 2))/2 + sqrt(1 - pow(b, 2))/2;
	suma *= h;
	return suma;
}


double simps1(double N);
double simps2(double N);
double simps3(double N);


double simps1(double N){
	double a = 1;
	double b = 2;
	double h = (b - a)/N;
	double suma = 0;
	for(int i = 1; i < N; i++){
		if(i % 2 == 0) suma += 2/pow(a + i*h, 2);
		else suma += 4/pow(a + i*h, 2);
	}
	suma += 1/pow(a, 2) + 1/pow(b, 2);
	suma *= h/3;
	return suma;
}

double simps2(double N){
	double a = 0;
	double b = 1;
	double h = (b - a)/N;
	double suma = 0;
	for(int i = 1; i < N; i++){
		if(i % 2 == 0) suma += 2*exp(a + i*h);
		else suma += 4*exp(a + i*h);
	}
	suma += exp(a) + exp(b);
	suma *= h/3;
	return suma;
}

double simps3(double N){
	double a = 0;
	double b = 1;
	double h = (b - a)/N;
	double suma = 0;
	for(int i = 1; i < N; i++){
		if(i % 2 == 0) suma += 2*sqrt(1 - pow(a + i*h, 2));
		else suma += 4*sqrt(1 - pow(a + i*h, 2));
	}
	suma += sqrt(1 - pow(a, 2)) + sqrt(1 - pow(b, 2));
	suma *= h/3;
	return suma;
}


int main(){
	/*
	printf("0.5 ---- %.15lf ---- %.15lf\n", trap1(500), simps1(500));
	printf("%.15lf ---- %.15lf ---- %.15lf\n", exp(1) - 1, trap2(500), simps2(500));
	printf("%.15lf ---- %.15lf ---- %.15lf", M_PI/4, trap3(500), simps3(500));*/
	printf("First function:\nAnalytical solution is: %.15lf\n", 0.5);
	int step[22] = {10, 50, 70, 100, 200, 500, 800, 1000, 2000, 5000, 7500, 10000, 35000, \
	50000, 70000, 100000, 500000, 1000000, 5000000, 10000000, 30000000, 60000000};
	for(int i = 0; i < 22; i++){
		printf("N = %d,  trap = %.15lf,   simps = %.15lf\n", step[i], trap1(step[i]), simps1(step[i]));
		//printf("%.15lf, ", trap3(step[i]));
		//printf("%.15lf, ", simps3(step[i]));
	}
	
	printf("\nSecond functions: \nAnalytical solution is: %.15lf\n", exp(1) - 1);
	for(int i = 0; i < 22; i++){
		printf("N = %d,  trap = %.15lf,   simps = %.15lf\n", step[i], trap2(step[i]), simps2(step[i]));
		//printf("%.15lf, ", trap3(step[i]));
		//printf("%.15lf, ", simps3(step[i]));
	}
	
	printf("\nThird functions: \nAnalytical solution is: %.15lf\n", M_PI/4);
	for(int i = 0; i < 22; i++){
		printf("N = %d,  trap = %.15lf,   simps = %.15lf\n", step[i], trap3(step[i]), simps3(step[i]));
		//printf("%.15lf, ", trap3(step[i]));
		//printf("%.15lf, ", simps3(step[i]));
	}
	return 0;
}
