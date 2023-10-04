#include <stdio.h>
#include <math.h>

const double m = 1.3;
const double k = 2.52;
const double tF = 25.5;

int sign(double x);   //function that returns 1 if x is positive and -1 if negative
int sign(double x){
	if(x < 0) return -1;
	else return 1;
}

FILE *f_point;

int main(){
	int p;
	double x0 = 1;  //initial conditions
	double y0 = 0;
	int N = 6000;
	
	printf("Value of h = %lf\nInput desired value of p: ", tF/N);
	scanf("%d", &p);
	printf("Input desired amplitude: "); scanf("%lf", &x0);
	double k1, k2, k3, k4, l1, l2, l3, l4;  //k are for position, l are for velocity
	
	double sol[3][N]; //array of values of position, velocity and energy
	sol[0][0] = x0; //position
	sol[1][0] = y0;  //velocity
	double h = tF/N; //t0 = 0;
	
	for(int i = 1; i < N; i++){ 
		k1 = h*sol[1][i-1];
		l1 = h*(-k/m)*pow(sol[0][i-1], p-1);
		k2 = h*(sol[1][i-1] + l1/2);
		l2 = h*pow(sol[0][i-1] + k1/2, p-1)*(-k/m);
		k3 = h*(sol[1][i-1] + l2/2);
		l3 = h*pow(sol[0][i-1] + k2/2, p-1)*(-k/m);
		k4 = h*(sol[1][i-1] + l3);
		l4 = h*pow(sol[0][i-1] + k3, p-1)*(-k/m);
		sol[0][i] = sol[0][i-1] + (k1 + 2*k2 + 2*k3 + k4)/6;
		sol[1][i] = sol[1][i-1] + (l1 + 2*l2 + 2*l3 + l4)/6; 
		sol[2][i] = 0.5*m*pow(sol[1][i], 2) + 1.0/p*k*pow(sol[0][i], p);  
		}
	
	double max_v = fabs(sol[1][0]);   //this part of code is used to determine maximal velocity and position.
	double max_x = fabs(sol[0][0]);
	//printf("%lf", sol[1][20]);
	for(int i = 1; i < N; i++){
		if (fabs(sol[1][i]) > max_v) max_v = fabs(sol[1][i]);
		if (fabs(sol[0][i]) > max_x) max_x = fabs(sol[0][i]);
		//printf("%lf\n", sol[1][i]);
	}
	
	for(int i = 1; i < N; i++){
		if(sign( sol[0][i] ) != sign( sol[0][i-1] )) {
			int iM = i;
			printf("x = 0 at moment t = %lf\n", h*iM);
			printf("Velocity for x = 0 is v=%lf, while v_max = %lf\n", sol[1][iM], max_v);
		}
	}
	printf("\n");
	for(int i = 1; i < N; i++){
		if(sign( sol[1][i] ) != sign( sol[1][i-1] )) {
			int iM = i;
			printf("x = v at moment t = %lf\n", h*iM);
			printf("Position for v = 0 is x=%lf, while x_max = %lf\n", sol[0][iM], max_x);
		}
	}
	printf("We can say that velocity at x = 0 is equal to maximal velocity\n");
	printf("We can say the same for position at v = 0.\n");
	printf("We can also examine time differences between two such events and conclude the motion is periodic.\n");
	printf("\nDetermining period:(if number of detemrined periods is too small, increase value of tF)\n");
	double period[5] = {0,0,0,0,0};
	double t_previous = 0;
	int j = 0;
	for(int i = 1; i < N; i++){
		if(sign( sol[0][i] ) != sign( sol[0][i-1] ) and sign(sol[0][i]) == 1){
			int iM = i;
			if(t_previous == 0) t_previous = iM*h;
			else {
				period[j] = iM*h - t_previous;
				j++;
				t_previous = iM*h;
				if(j == 5) break;
			}
		}
	}
	for(int i = 0; i < 5; i++){
		if(period[i] != 0) printf("%lf\n", period[i]);
	}
	
	f_point = fopen("mid_plot.txt", "w");    //writting positions in text file to be copy-pasted to python. 
	fprintf(f_point, "x = [%lf", x0);
	for (int i = 1; i < N; i++){
		fprintf(f_point, ", %lf", sol[0][i]);
		if (i % 9==0) fprintf(f_point, "\\\n");
	}
	
	
	return 0;
}
