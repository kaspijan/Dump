#include<stdlib.h>
#include<stdio.h>
#include<math.h>


using namespace std;

//this is the float program

float factoriel(int n);
//float pow(float x, int n);
float Taylor(float x, int precision);
float Series(float x, int precision);
float Inverse(float x, int precision);
	
float factoriel(int n){  //calculates factoriel of any integer, including 0
	float value = 1;
	for(int i = 1; i <= n; i++) value *= i;
	return value;
	}
		
float Taylor(float x, int precision){
	float suma = 0;
	for(int i = 0; i < precision; i++){
		if(i % 2 == 0) suma += (float)pow(x, i)/factoriel(i);
		else suma -= (float)pow(x, i)/factoriel(i);
	}
	return suma;
}
	
float Series(float x, int precision){
	float suma = 1;
	float sumand = 1;
	for(int i = 1; i <= precision - 1; i++){
		sumand *= -x/i;
		suma += sumand;
	}
	return suma;
}

float Inverse(float x, int precision){
	float suma = 1;
	float sumand = 1;
	for(int i = 1; i <= precision - 1; i++){
		sumand *= x/i;
		suma += sumand;
	}
	return 1/suma;
}

float sumand(float x, int prec);  //not really used in this code, it serves for testing for overflow
float sumand(float x, int prec){
	float sumand = 1;
	for(int i = 1; i <= prec - 1; i++){
		sumand *= x/i;
	}
	return sumand;
}

int main(){
	
	printf("Taylor expansion:\n");
	
	int prec_taylor[11] = {1, 38, 29, 26, 24, 22, 21, 20, 20, 19, 19};
	for(int i = 0; i <= 100; i+= 10){
		printf("%d - %.7E - %d\n", i, Taylor((float)(i), prec_taylor[i/10]), prec_taylor[i/10]);
	}
	
	
	int prec_rec[11] = {1, 44, 72, 100, 127, 155, 182, 209, 231, 241, 246};
	printf("Recursion formula:\n");
	
	for(int i = 0; i <= 100; i+= 10){
		printf("%.1f - %.7E - %d\n", (float)i, Series((float)(i), prec_rec[i/10]), prec_rec[i/10]);
	}
	
	printf("Inversion:\n");
	
	int prec_inv[11] = {1, 44, 72, 100, 127, 155, 182, 209, 237, 264, 291};
	for(int i = 0; i <= 100; i+= 10){
		printf("%.1f - %.7E - %d\n", (float)i, Inverse((float)(i), prec_inv[i/10]), prec_inv[i/10]);
	}
	//the highest possible value of pow and factorial was calculates by simply using printf
	// printf("%f", factoriel(n)); printf("%f", (float)pow(x, n); for respective x, and finding the
	//highest possible n for which result exists.
	return 0;
}

