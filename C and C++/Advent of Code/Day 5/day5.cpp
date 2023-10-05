#include<stdio.h>
#include<stdlib.h>


class MyStack{
    private:
        char stack[80];
        short int sizeOfStack;

    public:
        void initialize(){   //potrebno pokrenuti prije početka rada sa stackom
            sizeOfStack = 0; //broj elemenata u stacku
            stack[0] = '0';  //'0' označava kraj stacka
        }


        void push(char c){
            stack[sizeOfStack] = c;
            sizeOfStack++;
            stack[sizeOfStack] = '0';
        }

        char pop(){
            if(sizeOfStack != 0){
                char forPopping = stack[sizeOfStack - 1];
                stack[sizeOfStack - 1] = '0';
                sizeOfStack--;
                return forPopping;
            }
            else return '0';
        }

        void reverseOrder(){
            char tmp[80];

            for(short int i = 0; i < sizeOfStack; i++){
                tmp[i] = stack[sizeOfStack - 1 - i];
            }

            for(short int i = 0; i < sizeOfStack; i++){
                stack[i] = tmp[i];
            }
            
        }
};

FILE *fptr;

char crates[9][80];  //po jedan red za svaku nakupinu kutija
short int instructions[3]; //prvi red broj kutija, drugi odakle premještamo, treći kamo stavljamo
char *stringForReading;
size_t stringSize = 20;

int main(){
    fptr = fopen("crates.txt", "r");
    MyStack stackMesh[9];
    for(short int i = 0; i < 9; i++) stackMesh[i].initialize();

    //ovaj dio inicira početne stackove
    char tmp1, tmp2, tmp3, tmp4;  //poslužit će samo kod 
    while(true){
        getline(&stringForReading, &stringSize, fptr);
        if(stringForReading[0] == '\n') break;
        printf("%s", stringForReading);
        
        for(short int i = 0; i < 9; i++){
            sscanf(&stringForReading[4*i], "%c%c%c%c", &tmp1, &tmp2, &tmp3, &tmp4);
            if(tmp1 == '[') stackMesh[i].push(tmp2);
        }
    }

    for(short int i = 0; i < 9; i++) stackMesh[i].reverseOrder();
    //////////////

    //sad kreću permutacije
    short int moveHowMuch, moveFromWhere, moveToWhere;
    while(!feof(fptr)){
        fscanf(fptr, "move %hi from %hi to %hi\n", &moveHowMuch, &moveFromWhere, &moveToWhere);
        char tmp;
        for(short int i = 0; i < moveHowMuch; i++){
            tmp = stackMesh[moveFromWhere - 1].pop();
            if(tmp == '0') continue;
            stackMesh[moveToWhere - 1].push(tmp);
        }
    }
        
    for(short int i = 0; i < 9; i++) printf("%c", stackMesh[i].pop());

    fclose(fptr);
    return 0;
}