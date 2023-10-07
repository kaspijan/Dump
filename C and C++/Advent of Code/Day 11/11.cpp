#include<stdio.h>
#include<stdlib.h>

const int bigLen = 50;



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

    if(passDigit == 0){ 
        *isDivisable = 1;}
    else{
        *isDivisable = 0;}

    for(int i = 0; i< bigLen; i++){
        prod[i] = prodRev[bigLen - i - 1];
    }

}


class myMonkey{
    private:
        int numOfItems = 0; //koliko stvari majmun drži
        int maxNumOfItems = 40; //koliko ukupno ima stvari
        int Items[40][bigLen]; //polje sa stvarima
        short int divisable; //s kojim brojem se dijeli važnost
        short int throwMonkeyTrue; //kojem majmunu baca ako True
        short int throwMonkeyFalse; //kojem majmunu baca ako False
        int inspectLevel = 0;

    public:
        void setItems(){ 
            for(int i = 0; i < maxNumOfItems; i++) bigInit(&Items[i][0]);
        }

        int getNumOfItems(){
            return numOfItems;
        }

        int getInspect(){
            return inspectLevel;
        }

        int* getItem(int i){
            return &Items[i][0];
        }

        void setDivisable(short int a){
            divisable = a;
        }

        void setMonkeyTrue(short int a){
            throwMonkeyTrue = a;
        }

        void setMonkeyFalse(short int a){
            throwMonkeyFalse = a;
        }

        void pushItem(int item[]){ 
            for(int i = 0; i < bigLen; i++)
                Items[numOfItems][i] = item[i];
            numOfItems++;
        }
        /*
        void reverseArray(){ 
            int tmp[numOfItems][bigLen];
            for(int i = 0; i < numOfItems; i++) 
                for(int j = 0; j < bigLen; j++) tmp[i][j] = Items[numOfItems - 1 - i][j];
            for(int i = 0; i < numOfItems; i++) 
                for(int j = 0; j < bigLen; j++) Items[i] = tmp[i];
        }*/

        void setWorry(int monkey){ //velika promjena!!
            int isDivisable = 0;
            switch (monkey){
                case 0:{
                    int tmp[bigLen];
                    bigInit(tmp);
                    bigTimes(&Items[0][0], 13, tmp);
                    for(int i = 0; i < bigLen; i++) Items[0][i] = tmp[i];
                    bigInit(tmp);
                    bigDiv(&Items[0][0], 3, tmp, &isDivisable);
                    for(int i = 0; i < bigLen; i++) Items[0][i] = tmp[i];
                    break;}
                case 1:{
                    int tmp[bigLen];
                    bigInit(tmp);
                    int adder[bigLen];
                    bigInit(adder);
                    adder[0] = 3;
                    bigAdd(&Items[0][0], adder, tmp);
                    for(int i = 0; i < bigLen; i++) Items[0][i] = tmp[i];
                    bigInit(tmp);
                    bigDiv(&Items[0][0], 3, tmp, &isDivisable);
                    for(int i = 0; i < bigLen; i++) Items[0][i] = tmp[i];
                    break;}
                case 2:{
                    int tmp[bigLen];
                    bigInit(tmp);
                    bigTimesBig(&Items[0][0], &Items[0][0], tmp);
                    for(int i = 0; i < bigLen; i++) {Items[0][i] = tmp[i]; }//printf("%d", tmp[i]);}
                    bigInit(tmp);
                    bigDiv(&Items[0][0], 3, tmp, &isDivisable);
                    for(int i = 0; i < bigLen; i++) Items[0][i] = tmp[i];
                    break;}
                case 3:{
                    int tmp[bigLen];
                    bigInit(tmp);
                    int adder[bigLen];
                    bigInit(adder);
                    adder[0] = 5;
                    bigAdd(&Items[0][0], adder, tmp);
                    for(int i = 0; i < bigLen; i++) Items[0][i] = tmp[i];
                    bigInit(tmp);
                    bigDiv(&Items[0][0], 3, tmp, &isDivisable);
                    for(int i = 0; i < bigLen; i++) Items[0][i] = tmp[i];
                    break;}
                case 4:{
                    int tmp[bigLen];
                    bigInit(tmp);
                    int adder[bigLen];
                    bigInit(adder);
                    adder[0] = 7;
                    bigAdd(&Items[0][0], adder, tmp);
                    for(int i = 0; i < bigLen; i++) Items[0][i] = tmp[i];
                    bigInit(tmp);
                    bigDiv(&Items[0][0], 3, tmp, &isDivisable);
                    for(int i = 0; i < bigLen; i++) Items[0][i] = tmp[i];
                    break;}
                case 5:{
                    int tmp[bigLen];
                    bigInit(tmp);
                    int adder[bigLen];
                    bigInit(adder);
                    adder[0] = 4;
                    bigAdd(&Items[0][0], adder, tmp);
                    for(int i = 0; i < bigLen; i++) Items[0][i] = tmp[i];
                    bigInit(tmp);
                    bigDiv(&Items[0][0], 3, tmp, &isDivisable);
                    for(int i = 0; i < bigLen; i++) Items[0][i] = tmp[i];
                    break;}
                case 6:{
                    int tmp[bigLen];
                    bigInit(tmp);
                    bigTimes(&Items[0][0], 19, tmp);
                    for(int i = 0; i < bigLen; i++) Items[0][i] = tmp[i];
                    bigInit(tmp);
                    bigDiv(&Items[0][0], 3, tmp, &isDivisable);
                    for(int i = 0; i < bigLen; i++) Items[0][i] = tmp[i];
                    break;}
                case 7:{
                    int tmp[bigLen];
                    bigInit(tmp);
                    int adder[bigLen];
                    bigInit(adder);
                    adder[0] = 2;
                    bigAdd(&Items[0][0], adder, tmp);
                    for(int i = 0; i < bigLen; i++) Items[0][i] = tmp[i];
                    bigInit(tmp);
                    bigDiv(&Items[0][0], 3, tmp, &isDivisable);
                    for(int i = 0; i < bigLen; i++) Items[0][i] = tmp[i];
                    break;}
            }
        }

        void throwItem(int *returnValues, int monkey){ //vraća kojem majmunu baciti i koliko
            this->setWorry(monkey);
            int isDivisable = 0;
            int tmpProd[bigLen];
            bigDiv(&Items[0][0], divisable, tmpProd, &isDivisable);
            if(isDivisable == 1) returnValues[0] = throwMonkeyTrue;
            else returnValues[0] = throwMonkeyFalse;
            for(int i = 0; i < bigLen; i++)
                returnValues[1 + i] = Items[0][i];
                
            //pomaknuti sve za jedan gore
            for(int i = 1; i < numOfItems; i++)
                for(int j = 0; j < bigLen; j++)
                    Items[i-1][j] = Items[i][j];
            bigInit(&Items[numOfItems-1][0]);
            numOfItems--;
            inspectLevel++;
        }

    
};


FILE *fptr;

int main(){
    fptr = fopen("monkey.txt", "r");
    myMonkey Monkeys[8];
    int Rounds = 20;
    //int inspectArray[8];
    //for(int i = 0; i < 8; i++) inspectArray[i] = 0; //koliko puta je majmun dirao stvari


    int monkeyIndex;
    int item;
    char tmpC = '0';
    


    //inicijalizacija - mijenjaj
    while(!feof(fptr)){
        fscanf(fptr, "Monkey %d:\n", &monkeyIndex);
        Monkeys[monkeyIndex].setItems();

        fscanf(fptr, "  Starting items: ");
        fscanf(fptr, "%d", &item);
        int tmpArray[bigLen];
        bigInit(tmpArray);
        tmpArray[0] = item%10;
        tmpArray[1] = item/10;
        Monkeys[monkeyIndex].pushItem(tmpArray);
        while(1){
            tmpC = getc(fptr);
            if(tmpC == '\n') break;
            fscanf(fptr, " %d", &item);
            bigInit(tmpArray);
            tmpArray[0] = item%10;
            tmpArray[1] = item/10;
            Monkeys[monkeyIndex].pushItem(tmpArray);
        }
        //Monkeys[monkeyIndex].reverseArray();

        while(1){
            tmpC = getc(fptr);
            if(tmpC == '\n') break;
        }

        fscanf(fptr, "  Test: divisible by %d\n", &item);
        Monkeys[monkeyIndex].setDivisable(item);

        fscanf(fptr, "    If true: throw to monkey %d\n", &item);
        Monkeys[monkeyIndex].setMonkeyTrue(item);

        fscanf(fptr, "    If false: throw to monkey %d\n", &item);
        Monkeys[monkeyIndex].setMonkeyFalse(item);
        fscanf(fptr, "\n");
    }

    
    //tu ubaciti provjeru majmunovih itema
    //printf("%d %d\n", Monkeys[3].getItem(0), Monkeys[3].getItem(1));
    /*int tmp[2];
    Monkeys[0].throwItem(tmp, 0);
    printf("%d %d\n", tmp[0], tmp[1]);

    Monkeys[0].throwItem(tmp, 0);
    printf("%d %d\n", tmp[0], tmp[1]);*/
    //printf("%d\n", Monkeys[1].getNumOfItems());

    int toThrow[1 + bigLen];
    for(int i = 0; i < Rounds; i++){ //ide po rundama
        for(int j = 0; j < 8; j++){ //ide po majmunima
            int itemNum = Monkeys[j].getNumOfItems();
            for(int k = 0; k < itemNum; k++){ //ide po stvarima            
                Monkeys[j].throwItem(toThrow, j);
                /*printf("Runda %d, majmun %d baca item ", i, j);
                for(int elem = bigLen; elem > 0; elem--) printf("%d", toThrow[elem]);
                printf(" majmunu %d\n", toThrow[0]);*/
                //if(toThrow[1] < 0) printf("Uzbuna!!!\n");
                Monkeys[toThrow[0]].pushItem(&toThrow[1]);
            }
            
            //printf("Runda %d, majmun %d inspektao %d stvari\n", i, j, Monkeys[j].getInspect());
        }
    }

    int inspectValues[8];
    for(int i = 0; i < 8; i++) {
        inspectValues[i] =  Monkeys[i].getInspect();
        printf("%d ", inspectValues[i]);
        }

    int max = inspectValues[0];
    int maxIndex = 0;
    for(int i = 1; i < 8; i++) if(inspectValues[i] > max) {max = inspectValues[i]; maxIndex = i;}

    inspectValues[maxIndex] = 0;
    int max2 = inspectValues[0];
    for(int i = 1; i < 8; i++) if(inspectValues[i] > max2) {max2 = inspectValues[i];}

    printf("\nMonkey buisness: %d", max*max2);

    fclose(fptr);
    return 0;
}