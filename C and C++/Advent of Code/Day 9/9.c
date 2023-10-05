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
    vector currentTail = {0, 0};

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

            distance = vecDistance(currentHead, currentTail);
            if(distance > 2){ //pomicanje T
                if(currentHead.x == currentTail.x){
                    currentTail.y += (currentHead.y - currentTail.y)/2;
                }
                else if(currentHead.y == currentTail.y){
                    currentTail.x += (currentHead.x - currentTail.x)/2;
                }
                else{
                    short int tmpX = currentHead.x - currentTail.x;
                    short int tmpY = currentHead.y - currentTail.y;
                    if(tmpX > 0) currentTail.x++;
                    else currentTail.x--;
                    if(tmpY > 0) currentTail.y++;
                    else currentTail.y--;
                }

                if(isVisited(currentTail, vecMesh, numOfVecs) == 1){
                    numOfVecs++;
                    vecMesh = (vector*) realloc(vecMesh, numOfVecs * sizeof(vector));
                    vecMesh[numOfVecs - 1] = currentTail;
                }
            }
        }
    }

    printf("%d", numOfVecs);
}