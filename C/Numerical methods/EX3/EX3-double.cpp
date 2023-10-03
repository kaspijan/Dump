#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

const double e = 2.718281828459045;  //taken from Python

double abso(double x);

double abso(double x){   //function for calculating absolute value
	if(x < 0) return -x;
	else return x;
}

double first_der(double x, double h);
double second_der(double x, double h);


double first_der(double x, double h){
	//return (pow(e, x + h) - pow(e, x - h))/2/h - h/6*pow(e, x);
	return (exp(x + h) - exp(x - h))/2/h;//-h*h/6*exp(x);  //nez dal treba taj dio ili ne !?!?
}

double second_der(double x, double h){
	//return (pow(e, x+h) + pow(e, x-h) - 2*pow(e,x))/h/h;
	return (exp(x+h) + exp(x-h) - 2*exp(x))/h/h;
}

void optimal_first(double x, double exact);
void optimal_sec(double x, double exact);

void optimal_first(double x, double exact){
	double h = 0.1;
	double error = log10( abso( (first_der(x, 0.1) - exact) / exact ) );
	double h_optimal = 0.1;
	for(int j = 1; j != 8; j++){
		h *= 0.1;
		if(log10( abso( (first_der(x, h) - exact ) / exact  ) )  < error){
			error = log10( abso( ( first_der(x, h) - exact  ) / exact ) );
			h_optimal = h;
			}
		
	}
	printf("x = %.1lf, h = %.1E, dexp/dx = %.15lf, error = %.15lf\n", x, h_optimal, first_der(x, h_optimal), error);
		
}

void optimal_second(double x, double exact){
	double h = 0.1;
	double error = log10( abso( (second_der(x, 0.1) - exact) / exact ) );
	double h_optimal = 0.1;
	for(int j = 1; j != 8; j++){
		h *= 0.1;
		if(( log10( abso( (second_der(x, h) -  exact) / exact ) ) ) < error){
			error = log10( abso( ( second_der(x, h) - exact ) / exact ) );
			h_optimal = h;
			}
		
	}
	printf("x = %.1lf, h = %.1E, d2exp/dx2 = %.15lf, error = %.15lf\n", x, h_optimal, second_der(x, h_optimal), error);
		
}

double five_point(double x, double h);
double five_point(double x, double h){
	//return (pow(e, x - 2*h) - pow(e, x + 2*h) + 8*pow(e, x + h) - 8*pow(e, x - h))/12/h;
	return (exp(x - 2*h) - exp(x + 2*h) + 8*exp(x + h) - 8*exp(x - h))/12/h;
}

void optimal_five(double x, double exact);
void optimal_five(double x, double exact){
	double h = 0.1;
	double error = log10( abso( (five_point(x, 0.1) - exact) / exact ) );
	double h_optimal = 0.1;
	for(int j = 1; j != 8; j++){
		h *= 0.1;
		if(( log10( abso( (five_point(x, h) -  exact) / exact ) ) ) < error){
			error = log10( abso( (five_point(x, h) - exact ) / exact ) );
			h_optimal = h;
			}
		
	}
	printf("x = %.1lf, h = %.1E, d2exp/dx2 = %.15lf, error = %.15lf\n", x, h_optimal, five_point(x, h_optimal), error);
	
}

int main(){
	double exact[11] = {1.0, 2.718281828459045, 7.38905609893065, 20.085536923187668, 54.598150033144236, 148.4131591025766, 403.4287934927351,\
	1096.6331584284585, 2980.9579870417283, 8103.083927575384, 22026.465794806718};  //from Python
	
	
	double h;
	printf("First derivative:\n");
	for(int i = 0; i <= 10; i++){
		h = 1;
		printf("\nx = %.1lf,  exp(x) = %.15lf:\n", (double)i, exact[i]);
		for(int j = 0; j <= 7; j++){
			h *= 0.1;
			printf("h = %.1E,  dexp(x)/dx = %.15lf\n", h, first_der(i, h));
			//printf("%.15lf,", first_der(i, h));
		}
		printf("Optimal result: ");
		optimal_first(i, exact[i]);
		
	}
	
	
	printf("\nSecond derivative:\n");
	for(int i = 0; i <= 10; i++){
		h = 1;
		printf("\nx = %.1lf, exp(x) = %.15lf:\n", (double)i, exact[i]);
		for(int j = 0; j <= 7; j++){
			h *= 0.1;
			//printf("%.15lf, ", second_der(i, h));
			printf("h = %.1E,  d2exp(x)/dx2 = %.15lf\n", h, second_der(i, h));
		
		}
		printf("Optimal second derivative: ");
		optimal_second(i, exact[i]);
	
	}
	
	
	
	
	printf("\nFive-point formula(first derivative):\n");
	for(int i = 0; i <= 10; i++){
		h = 1;
		printf("\nx = %.1lf, exp(x) = %.15lf:\n", (double)i, exact[i]);
		for(int j = 1; j != 9; j++){
			h *= 0.1;
			printf("h = %.1E,  dexp(x)/dx = %.15lf\n", h, five_point(i, h));
		}
		printf("Optimal derivative: ");
		optimal_five(i, exact[i]);
	}
	 
	return 0;
}
