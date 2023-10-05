#include<stdio.h>
#include<stdlib.h>


FILE *fptr;

typedef struct{
    short int x;
    short int y;
} vector;


short int isVisited(vector query, vector* list, int sizeOfList){ //vraća 0 ako je već posjećeno, 1 ako nije
    for(int i = 0; i < sizeOfList; i++){
        if(query.x == list[i].x && query.y == list[i].y) return 0;
    }
    return 1;
}

short int vecDistance(vector a, vector b){ //kvadratna udaljenost
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}


void main(){

    int numOfVecs = 1; //zapravo size of vecMesh
    vector *vecMesh;
    vecMesh = (vector*) malloc(1*sizeof(vector));
    vecMesh[0].x = 0;
    vecMesh[0].y = 0;

    vector currentHead = {0, 0};
    vector currentTails[9];
    for(int i = 0; i < 9; i++) {currentTails[i].x = 0; currentTails[i].y = 0;}

    char direction; //u kojem smjeru se H pomiče
    short int steps; //za koliko se H pomiče
    short int distance; //udaljenost između H i T

    fptr = fopen("rope.txt", "r");
    while(!feof(fptr)){
        fscanf(fptr, "%c %hi\n", &direction, &steps);
        for(short int currentStep = 0; currentStep < steps; currentStep++){

            switch(direction){
                case 'L':
                    currentHead.x--;
                    break;
                case 'R':
                    currentHead.x++;
                    break;
                case 'U':
                    currentHead.y++;
                    break;
                case 'D':
                    currentHead.y--;
                    break;
            }

            vector Head = currentHead;
            for(int i = 0; i < 9; i++){
                distance = vecDistance(Head, currentTails[i]);
                if(distance > 2){ //pomicanje T
                    if(Head.x == currentTails[i].x){
                        currentTails[i].y += (Head.y - currentTails[i].y)/2;
                    }
                    else if(Head.y == currentTails[i].y){
                        currentTails[i].x += (Head.x - currentTails[i].x)/2;
                    }
                    else{
                        short int tmpX = Head.x - currentTails[i].x;
                        short int tmpY = Head.y - currentTails[i].y;
                        if(tmpX > 0) currentTails[i].x++;
                        else currentTails[i].x--;
                        if(tmpY > 0) currentTails[i].y++;
                        else currentTails[i].y--;
                    }
                }
                Head = currentTails[i];

            }

            if(isVisited(currentTails[8], vecMesh, numOfVecs) == 1){
                    numOfVecs++;
                    vecMesh = (vector*) realloc(vecMesh, numOfVecs * sizeof(vector));
                    vecMesh[numOfVecs - 1] = currentTails[8];
            }            
        }
    }

    printf("%d", numOfVecs);
}