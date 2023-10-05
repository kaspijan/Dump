#include<stdio.h>
#include<stdlib.h>

FILE *fptr;
int rowSize = 0;
int columnSize = 1;
int currentX = 0;
int currentY = 0;

void main(){
    //printf("muu");

    fptr = fopen("trees.txt", "r");
    //char* trees;
    //trees = (char*) malloc(sizeof(char));
    //trees = 'c';
    
    char readChar;

    //printf("beee");

    while(1){
        readChar = getc(fptr);
        if(readChar == '\n') break;
        rowSize++;
        /*if(currentX >= rowSize){
            rowSize++;
            trees = (char*) realloc(trees, columnSize * rowSize * sizeof(char));
        }
        *(trees + rowSize * currentY + currentX) = readChar;
        currentX++;*/
    }
    
    char *tmp;
    size_t buffSize = (size_t)rowSize + 1;
    tmp = (char*) malloc(buffSize);

    //printf("gaaaaaa");
    
    while(!feof(fptr)){
        getline(&tmp, &buffSize, fptr);
        columnSize++;
    }

    
    //printf("%d %d", rowSize, columnSize);

    fclose(fptr);

    char trees[columnSize][rowSize];

    fptr = fopen("trees.txt", "r");
    //printf("%c", getc(fptr));

    currentX = 0;
    currentY = 0;

    while(!feof(fptr)){
        readChar = getc(fptr);
        if(readChar == '\n'){
            currentY++;
            currentX = 0;
            continue;
        }

        trees[currentY][currentX] = readChar;

        currentX++;
    }

    char bigTrees[columnSize][rowSize];

    for(int i = 0; i < columnSize; i++)
        for(int j = 0; j < rowSize; j++)
            bigTrees[i][j] = '0';  //'0' je nevidljiv, '1' je vidljiv

    char biggest;
    for(int i = 0; i < columnSize; i++){ //lijevo-desno
        //s lijeva na desno
        biggest = trees[i][0];
        bigTrees[i][0] = '1';
        for(int j = 1; j < rowSize; j++){
            if(trees[i][j] > biggest){
                bigTrees[i][j] = '1';
                biggest = trees[i][j];
            }
        }
        //s desna na lijevo
        biggest = trees[i][rowSize - 1];
        bigTrees[i][rowSize - 1] = '1';
        for(int j = rowSize - 2; j > 0; j--){
            if(trees[i][j] > biggest){
                bigTrees[i][j] = '1';
                biggest = trees[i][j];
            }
        }
    }

    for(int j = 0; j < rowSize; j++){
        //od gore prema dolje
        biggest = trees[0][j];
        bigTrees[0][j] = '1';
        for(int i = 1; i < columnSize; i++){
            if(trees[i][j] > biggest){
                bigTrees[i][j] = '1';
                biggest = trees[i][j];
            }
        }

        //od dolje prema gore
        biggest = trees[columnSize-1][j];
        bigTrees[columnSize-1][j] = '1';
        for(int i = columnSize - 2; i > 0; i--){
            if(trees[i][j] > biggest){
                bigTrees[i][j] = '1';
                biggest = trees[i][j];
            }
        }
    }

    int numOfHidden = 0;
    for(int i = 0; i < columnSize; i++)
        for(int j = 0; j < rowSize; j++)
            if(bigTrees[i][j] == '1') numOfHidden++;

    printf("Prvi output: %d", numOfHidden);
    
    fclose(fptr);

    int maxDistance = 1;
    int currentDistance;
    char isBlocked = '0';
    for(int i = 0; i < columnSize; i++){
        for(int j = 0; j < rowSize; j++){
            currentDistance = 1;
            isBlocked = '0';
            //if(i == 0 || j == 0 || i == columnSize - 1 || j == rowSize - 1) currentDistance = 0;
            for(int k = j + 1; k < rowSize; k++){
                if(trees[i][k] >= trees[i][j]) {
                    currentDistance *= k - j;
                    isBlocked = '1';
                    break;
                }
            }
            if(isBlocked == '0') currentDistance *= rowSize - 1 - j;


            isBlocked = '0';
            for(int k = j - 1; k >= 0; k--){
                if(trees[i][k] >= trees[i][j]){
                    currentDistance *= j - k;
                    isBlocked = '1';
                    break;
                }
            }
            if(isBlocked == '0') currentDistance *= j;

            isBlocked = '0';
            for(int k = i + 1; k < columnSize; k++){
                if(trees[k][j] >= trees[i][j]) {
                    currentDistance *= k - i;
                    isBlocked = '1';
                    break;
                }
            }
            if(isBlocked == '0') currentDistance *= columnSize - 1 - i;

            isBlocked = '0';
            for(int k = i - 1; k >= 0; k--){
                if(trees[k][j] >= trees[i][j]) {
                    currentDistance *= i - k;
                    isBlocked = '1';
                    break;
                }
            }
            if(isBlocked == '0') currentDistance *= i;

            if(currentDistance > maxDistance) maxDistance = currentDistance;
        }
    }

    printf("\nDrugi output: %d", maxDistance);

}

