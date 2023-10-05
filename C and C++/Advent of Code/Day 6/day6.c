#include<stdio.h>
#include<stdlib.h>


FILE *fptr;


short int compareStringElements(char* s, short int stringSize){ //uspoređuje jesu li svi različiti u stringu
    if(stringSize == 2) {
        if(s[0] != s[1]) return 1;
        else return 0;
    }
    for(short int i = 1; i < stringSize; i++){
        if(s[0] == s[i]) return 0;
    }
    short int tmp = compareStringElements(&s[1], stringSize - 1);
    return tmp;
}

void main(){
    int signalIndex = 0;
    int signalSize = 14;
    char s[signalSize];

    fptr = fopen("signal.txt", "r");

    for(char i = 0; i < signalSize; i++){
        s[i] = getc(fptr);
    }
    

    if(compareStringElements(s, signalSize) == 1) printf("Traženi indeks: %d", signalIndex + signalSize);
    else{
        while(!feof(fptr)){
            signalIndex++;
            for(char i = 0; i < signalSize - 1; i++){
                s[i] = s[i+1];
            }
            s[signalSize - 1] = getc(fptr);
            if(compareStringElements(s, signalSize) == 1) {printf("Traženi indeks: %d", signalIndex + signalSize); break;}
        }
    }

}