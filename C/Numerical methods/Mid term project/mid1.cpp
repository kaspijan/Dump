#include<stdio.h>
#include<math.h>

double sin(double x, int N, bool t);
double sin(double x, int N, bool t){
	int sign = 1;
	if (t == 1){	   //if t = 1, than we set the value of x between 0 and m_pi
		int n = (int)(x/2/M_PI);  //otherwise, we don't change the value of x
		x = x - n*2*M_PI;
		if(x > M_PI) {
			sign = -1;
			x = x - M_PI;
			}
	}
	double sum = x;
	double temp = x;
	for(int i = 1; i < N; i++){
		temp *= x*x/(2.0*i+1)/(2.0*i);
		if (i%2 == 0) sum += temp;
		else sum -= temp;
	}
	return sign*sum;
}

double sin2(double x, bool t);
double sin2(double x, bool t){
	int sign = 1;
	if (t == 1){	   //if t = 1, than we set the value of x between 0 and m_pi
		int n = (int)(x/2/M_PI);  //otherwise, we don't change the value of x
		x = x - n*2*M_PI;
		if(x > M_PI) {
			sign = -1;
			x = x - M_PI;
			}
	}
	double sum = x;
	double temp = x;
	int i = 1;
	while(1){
		temp *= x*x/(2.0*i+1)/(2.0*i);
		//printf("%lf %lf ", fabs(temp), temp);
		if (temp <= pow(10, -7)*fabs(sum)) {
			//printf("%E %E ", temp, pow(10, -7)*fabs(sum));
			break;}
		if (i%2 == 0) sum += temp;
		else sum -= temp;
		//sum += temp;
		i++;
	}
	printf("Terms: %d,  ", i);
	return sign*sum;
}

int main(){
	double x = 0;
	//printf("%lf", sin2(0.1,0));
	//printf("Calculating sin for x <= 1:\n");
	printf("Using sin function:\n");
	for(int i = 0; i < 11; i++){
		x = 0.1*i;
		printf("Terms = 50, X: %.1lf,   sin x = %.16lf\n", x, sin(x, 50, 0));
	}
	
	x = 0;
	printf("\nUsing sin2 function:\n");
	
	for(int i = 0; i < 11; i++){
		x = 0.1*i;
		printf("X: %.1lf,   sin x = %.16lf\n", x, sin2(x, 0));
	}
	
	printf("\nExamining large terms in series for x = 3pi:\n");
	x = 3*M_PI;
	double terms[30];
	terms[0] = x;
	double temp = x;
	double sum = x;
	for(int i = 1; i < 12; i++){
		temp *= -x*x/(2.0*i+1)/(2.0*i);
		//printf("Terms %d and %d: %.10lf, %.10lf\n", i-1, i, terms[i-1],temp);
		//printf("Term %d + term %d: %.10lf\n", i, i-1, temp + terms[i-1]);
		terms[i] = temp;
		printf("N = %d:\n", i);
		for(int j = 0; j<i; j++){
			printf("%.5lf ", terms[j]);
			if(j != i-1) printf("+ ");
		}
		printf("= %.5lf\n", sum);
		sum += temp;
	}
	/*
	double sum = x;
	for(int i = 1; i < 16; i++){
		sum += terms[i];
		printf("N = %d:\n", i);
		for(int j = 0; j<i; j++){
			printf("%.5lf ", terms[j]);
			if(j != i-1) printf("+ ");
		}
		printf("= %.5lf\n", sum);
	}*/
	
	
	printf("\nBounding x to interval <0, pi> for x = 10:\nExact = -0.54402111088937\n");
	for(int n = 1; n < 20; n+= 3){
		printf("N = %d, %.15lf %.15lf\n",n ,sin(10, n, 1), sin(10, n, 0));
	}
	
	
	
	//printf("%lf\n", sin2(100, 0));
	printf("\nDetermining lose of accuracy for increasing x (50 terms):\n");
	double xmesh[19];
	for(int i = 0; i <10; i++) xmesh[i] = i+1;
	for(int i = 10; i < 19; i++) xmesh[i] = (i-8)*10;
	for(int i = 0; i < 19; i++) printf("%.2lf %.15lf\n", xmesh[i], sin(xmesh[i], 50, 0));
	
	//error
	printf("\nError values were calculated in Python, this code was used to generate numerical values:\n");
	
	int M = 16;
	int N[M] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 16, 20, 25, 30};
	double error[M];
	//double exact = 0.64421768723769105367261435;
	printf("x = 10\n");
	for(int i = 0; i < M; i++){
		double s = sin(10, N[i], 0);
		//error[i] = fabs(s - exact)/exact;
		printf("Terms = %d, %.15lf\n", N[i], s);
	}
	
	return 0;
}
