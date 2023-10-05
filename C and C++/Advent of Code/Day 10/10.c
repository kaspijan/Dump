#include<stdio.h>
#include<stdlib.h>


FILE *fptr;


void main(){
    char isAdd; //'0' ako se vrti addx ciklus, '1' ako se ne vrti
    int X = 1; 
    int cycle = 1;
    int startCycle = 20; //kad gledamo X
    int cycleIncrease = 40; //za koliko se povećavaju koraci kad gledamo X
    int addX;
    int sum = 0;

    int pixelX = 0;
    int pixelY = 0;

    fptr = fopen("signal.txt", "r");

    char read;
    char tmp;
    while(!feof(fptr)){
        if(cycle == startCycle) {sum += X*cycle; startCycle += cycleIncrease; printf("%d %d\n", cycle, X);}
        read = getc(fptr);
        if(read == 'n') fscanf(fptr, "%c%c%c\n", &tmp, &tmp, &tmp);
        else {
            fscanf(fptr, "%c%c%c ", &tmp, &tmp, &tmp);
            fscanf(fptr, "%d\n", &addX);
            cycle++;
            if(cycle == startCycle) {sum += X*cycle; startCycle += cycleIncrease; printf("%d %d\n", cycle, X);}
            X += addX;
        }
        
        cycle++;
    }
    printf("%d", sum);
    fclose(fptr);
}