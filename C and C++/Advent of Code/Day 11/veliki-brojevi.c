#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

const int bigLen = 4;

void bigInit(int big[]){
    for(int i = 0; i < bigLen; i++){
        big[i] = 0;
    }
}

void bigAdd(int big1[], int big2[], int sum[]){
    int passDigit = 0;
    for(int i = 0; i<bigLen; i++){
        sum[i] = (big1[i] + big2[i] + passDigit)%10;
        passDigit = (big1[i] + big2[i] + passDigit)/10;
    }
}


void bigTimes(int big[], int times, int prod[]){
    int passDigit = 0;
    for(int i = 0; i < bigLen; i++){
        prod[i] = (big[i]*times + passDigit)%10;
        passDigit = (big[i]*times + passDigit)/10;
    }
}


void bigTimesBig(int big1[], int big2[], int prod[]){
    int tmpBig1[bigLen];
    int tmpBig2[bigLen];
    for(int i = 0; i <bigLen; i++){
        bigTimes(big1, big2[i], tmpBig1);

        for(int j = 0; j < i; j++){
            tmpBig2[j] = 0;
        }
        for(int j = i; j < bigLen; j++){
            tmpBig2[j] = tmpBig1[j-i];
        }

        bigAdd(prod, tmpBig2, tmpBig1);
        for(int j = 0; j < bigLen; j++) 
            prod[j] = tmpBig1[j];
    }
}


void bigDiv(int big[], int div, int prod[], int* isDivisable){ 
    int bigRev[bigLen];
    for(int i = 0; i < bigLen; i++){
        bigRev[i] = big[bigLen - i - 1];
    }

    int prodRev[bigLen];
    int passDigit = 0;
    for(int i = 0; i < bigLen; i++){
        prodRev[i] = ((passDigit * 10 + bigRev[i])/div);
        passDigit = ((passDigit * 10 + bigRev[i])%div);
    }

    if(passDigit == 0){  //nece promijeniti u true i false (??)
        printf("\ntrun\n");
        *isDivisable = 1;}
    else{printf("\nfalse\n");
        *isDivisable = 0;}

    for(int i = 0; i< bigLen; i++){
        prod[i] = prodRev[bigLen - i - 1];
    }

}



void main(){
    int big1[4]={3,1,0,0};  //broj 
    int big2[4]={0,2,6,1};  //broj 1620
    int sum[4];
    int prod[4];
    bigAdd(big1, big2, sum);
    printf("%d\n", sum[3]);

    bigTimes(big2, 2, prod);
    for(int i = 0; i < bigLen; i++) printf("%d", prod[i]);

    int tmp = 0;
    bigDiv(big1, 10, prod, &tmp);
    printf("\n%d ", tmp);
    for(int i = 0; i < bigLen; i++) printf("%d", prod[i]);
    printf("\n");

    bigInit(prod);
    /*bigTimesBig(big1, big1, prod);
    printf("\n");
    for(int i = 0; i < bigLen; i++){
        printf("%d", prod[i]);
    }*/

    int array[3][4];
    bigInit(&array[1][0]);
    array[1][0] = 4;
    bigTimesBig(&array[1][0], &array[1][0], prod);
    for(int i = 0; i < bigLen; i++){
        printf("%d", prod[i]);
    }
}