#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>

using namespace std;
const double k = 2.3;
const double m = 1.3;
const double T = 2*M_PI*sqrt(m/k);


FILE *f_point;

int main(){
	clock_t tStart = clock();  //used to check time
	int N = 1000;  //number of steps
	double x0 = 1;  //initial conditions
	double y0 = 0;
	double tF = 6*T;  //final time

		
	double sol[3][N]; //array of values of position, velocity and energy
	sol[0][0] = x0; //position
	sol[1][0] = y0;  //velocity
	double h = tF/N; //t0 = 0;
	
	for(int i = 1; i < N; i++){   //calculates x and v using Eulers method
		sol[0][i] = sol[0][i-1] + h*sol[1][i-1];
		sol[1][i] = sol[1][i-1] -h*k/m*sol[0][i-1];
		sol[2][i] = 0.5*m*pow(sol[1][i], 2) + 0.5*k*pow(sol[0][i], 2);  //from calculated variables, this line calculates energy
	}
	
	printf("Computation time: %.15lf\n", (double)(clock() - tStart)/CLOCKS_PER_SEC); //time for solving the ODE
	
	//this part is for easier plotting in python, it writes solutions to a text file which can be copy-pasted to Python
	f_point = fopen("plot.txt", "w");   
	fprintf(f_point, "x3 = [%lf", x0);
	for (int i = 1; i < N; i++){
		fprintf(f_point, ", %lf", sol[0][i]);
		if (i % 9==0) fprintf(f_point, "\\\n");
	}
	fprintf(f_point, "]\n\n\nv3 = [%lf", y0);
	for (int i = 1; i < N; i++){
		fprintf(f_point, ", %lf", sol[1][i]);
		if (i % 9==0) fprintf(f_point, "\\\n");
	} 
	fprintf(f_point, "]\n\n\nE3 = [%lf", 0.5*m*pow(y0, 2) + 0.5*k*pow(x0, 2));
	for (int i = 1; i < N; i++){
		fprintf(f_point, " ,%lf", sol[2][i]);
		if (i % 9==0) fprintf(f_point, "\\\n");
	} 
	fprintf(f_point, "]");
	fclose(f_point);
	
	
	return 0;
}


