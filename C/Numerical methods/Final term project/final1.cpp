#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

double V0 = 10;
double a = 1;

//functions for energy equations
double even(double e){
	return sqrt(V0 - e)*sin(sqrt(V0-e)) - sqrt(e)*cos(sqrt(V0-e));
}

double odd(double e){
	return sqrt(V0 - e)*cos(sqrt(V0-e)) - sqrt(e)*sin(sqrt(V0-e));
}

//derivative of even function
double d_even(double e){   
	return -0.5*sin(sqrt(V0 - e))*(1 + sqrt(e))/sqrt(V0-e) - 0.5*cos(sqrt(V0-e))*(1+1/sqrt(e));
}

//derivative of odd function
double d_odd(double e){   
	return 0.5*cos(sqrt(V0 - e))/sqrt(V0 - e)*(sqrt(e) - 1) + 0.5*sin(sqrt(V0-e))*(1 - 1/sqrt(e));
}


//algorithm for bisection method
double bisec(double x1, double x2, double precision, double (*f)(double)){
	double f1 = f(x1);
	double f2 = f(x2);
	int i = 0;
	
	if ((f1 > 0 && f2 > 0) || (f1 < 0 && f2 < 0)){
		printf("Error, estimates do not have different signs.");
		return -1;
	}
	
	double s1 = fabs(f1)/f1;  //signs
	double s2 = fabs(f2)/f2;  //signs
	
	double x0, f0, s0, sol;
	
	while(1){
		x0 = (x1+x2)/2;
		f0 = f(x0);
		if (fabs(f0) < precision) {
			sol = x0;
			break;
		}
		else{
			s0 = fabs(f0)/f0;
			if(s0 == s1) x1 = x0;
			else x2 = x0;
		}
		i++;
	}
	printf("No. of steps: %d\n", i);
	return sol;
}


//algorithm for Newton-Raphson method
double raphs(double x0, double precision, double (*f)(double), double (*df)(double)){
	double f0, df0, del_x, sol;
	f0 = f(x0);
	int i = 1;
	while(1){
		df0 = df(x0);
		del_x = -f0/df0;
		x0 += del_x;
		f0 = f(x0);
		if(fabs(f0) < precision){
			sol = x0;
			break;
		}
		i++;
	}
	printf("No. of steps: %d\n", i);
	return sol;
}


int main(){
	printf("Bisec:\n");
	printf("%.12lf\n", bisec(8, 9.5, 1E-08, even));
	printf("\nRaphs:\n");
	printf("%.12lf\n", raphs(8, 1E-08, even, d_even));
	return 0;
}
