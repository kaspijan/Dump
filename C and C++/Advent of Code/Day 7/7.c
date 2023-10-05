#include<stdio.h>
#include<stdlib.h>

FILE *fptr;

typedef struct {
    //int indexOfDir;
    int fatherOfDir;
    int valueOfDir; //0 na poč.
    short int jeNadodanOcu; //0 za ne, 1 za da
    //int numOfChilds;  //0 na poč.
} myDirectory;

void main(){
    fptr = fopen("naredbe.txt", "r");


    int currentDir = 0;
    int maxNumOfDir = 0;
    myDirectory* dir;
    dir = (myDirectory*) malloc(1 * sizeof(myDirectory));

    dir[0].valueOfDir = 0;
    //dir[0].numOfChilds = 0;

    size_t lineSize = 40;
    char *line;
    line = (char*) malloc(lineSize * sizeof(char));


    while(!feof(fptr)){
        getline(&line, &lineSize, fptr);
        //printf("%s", line);
        if(line[0] == '$') { //naredba, može biti $ cd ili $ ls
            if(line[2] == 'l') continue; //ls
            else{ //cd
                if(line[5] == '/') currentDir = 0; //cd /
                else if (line[5] == '.') { //cd ..
                    int father = dir[currentDir].fatherOfDir;
                    dir[father].valueOfDir += dir[currentDir].valueOfDir;
                    dir[currentDir].jeNadodanOcu = 1;
                    currentDir = dir[currentDir].fatherOfDir;

                }
                else{ //cd dirName
                    maxNumOfDir++;
                    dir = (myDirectory*) realloc(dir, (maxNumOfDir + 1) * sizeof(myDirectory));
                    dir[maxNumOfDir].fatherOfDir = currentDir;
                    //dir[currentDir].numOfChilds++;
                    currentDir = maxNumOfDir;
                    dir[currentDir].valueOfDir = 0;
                    dir[currentDir].jeNadodanOcu = 0;
                }
            }
            
        }

        else {  //listanje, znači ili dir gsigsdu; ili 14791 hgsig
            if(line[0] == 'd') { //direktorij
                //dir = (myDirectory*) realloc(dir, ((maxNumOfDir + 1) * sizeof(myDirectory)));
                continue;
            }
            else{  //datoteka, pribroji ju sumi
                int size;
                sscanf(line, "%d ", &size);
                dir[currentDir].valueOfDir += size;
            }
            
        }
    }

    for(int i = maxNumOfDir; i >= 0; i--){
        if(dir[i].jeNadodanOcu == 0){
            int father = dir[i].fatherOfDir;
            dir[father].valueOfDir += dir[i].valueOfDir;
            dir[i].jeNadodanOcu = 1;
        }
    }

    int sumaSumarum = 0;
    int smallestDir = dir[0].valueOfDir;
    int neededSpace = 30000000 - (70000000 - dir[0].valueOfDir);

    if(neededSpace <= 0) neededSpace = 0;
    //if(unusedSpace >= 30000000) unusedSpace = 0;

    for(int i = 0; i <= maxNumOfDir; i++){
        if(dir[i].valueOfDir <= 100000) sumaSumarum += dir[i].valueOfDir;
        if(dir[i].valueOfDir < smallestDir && dir[i].valueOfDir >= neededSpace) smallestDir = dir[i].valueOfDir;

    }
    printf("Output prvog dijela je: %d\n", sumaSumarum);
    printf("Output drugog dijela je: %d\n", smallestDir);

    //struct myDirectory dir;
    //printf("%d", dir[0].valueOfDir);
    
}