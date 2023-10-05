#include<stdio.h>
#include<stdlib.h>


FILE *fptr;


void main(){
    char isAdd; //'0' ako se vrti addx ciklus, '1' ako se ne vrti
    int X = 1; 
    
    int addX;
    int sum = 0;

    int pixelX = 0;
    int pixelY = 0;

    fptr = fopen("signal.txt", "r");

    char read;
    char tmp;
    while(!feof(fptr)){
        read = getc(fptr);
        if(read == 'n') {fscanf(fptr, "%c%c%c\n", &tmp, &tmp, &tmp); addX = 0;}
        else {
            fscanf(fptr, "%c%c%c ", &tmp, &tmp, &tmp);
            fscanf(fptr, "%d\n", &addX);

            if((X - pixelX)*(X - pixelX) <= 1) printf("#");
            else printf(".");

            pixelX++;
            if(pixelX == 40) {pixelX = 0; pixelY++; printf("\n");}

            
        }
        
        if((X - pixelX)*(X - pixelX) <= 1) printf("#");
        else printf(".");

        pixelX++;
        if(pixelX == 40) {pixelX = 0; pixelY++; printf("\n");}

        X += addX;

    }
    
    fclose(fptr);
}