#include<stdlib.h>
#include<stdio.h>
#include<math.h>
using namespace std;


double factoriel(int n);
double exp(double x, int precision);
double Series(double x, int precision);
double Inverse(double x, int precision);
	
double factoriel(int n){
	double value = 1;
	for(int i = 1; i <= n; i++) value *= i;
	return value;
}
		
double Taylor(double x, int precision){    //Calculates exp(-x) using its taylor expansion
	double suma = 1;
	for(int i = 1; i <= precision - 1; i++){
		if(i % 2 == 0) suma += pow(x, i)/factoriel(i);
		else suma -= pow(x, i)/factoriel(i);
	}
	return suma;
}


double Series(double x, int precision){   //calculates exp(-x) using taylor expansion and recurrence relation for summands
	double suma = 1;
	double sumand = 1;
	for(int i = 1; i <= precision - 1; i++){
		sumand *= -x/i;
		suma += sumand;
	}
	return suma;
}

double Inverse(double x, int precision){  //calculates exp(x) then returns 1/exp(x)
	double suma = 1;
	double sumand = 1;
	for(int i = 1; i <= precision - 1; i++){
		sumand *= x/i;
		suma += sumand;
	}
	return 1/suma;
}



int main(){
	int prec_taylor[11] = {1, 50, 65, 95, 115,  140, 170, 169, 163, 169, 169};
	
	printf("Taylor series:\n");
	
	for(int i = 0; i <= 100; i+= 10){
		printf("%.1f - %E - %d\n", (double)i, Taylor((double)(i), prec_taylor[i/10]), prec_taylor[i/10]);
	}
	
	int prec_rec[11] = {1, 44, 72, 100, 127, 155, 182, 209, 237, 264, 291};
	printf("Recursion formula:\n");
	
	for(int i = 0; i <= 100; i+= 10){
		printf("%.1f - %E - %d\n", (double)i, Series((double)(i), prec_rec[i/10]), prec_rec[i/10]);
	}
	
	printf("Inversion:\n");
	
	for(int i = 0; i <= 100; i+= 10){
		printf("%.1f - %E - %d\n", (double)i, Inverse((double)(i), prec_rec[i/10]), prec_rec[i/10]);
	}
	
	//printf("%E", pow(100, 154));
	
	return 0;
}
