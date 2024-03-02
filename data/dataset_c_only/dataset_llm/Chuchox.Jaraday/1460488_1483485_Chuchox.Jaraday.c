#include <stdio.h>

void encodeAndPrint(char ch, int set[]){
    if(ch == ' '){
        putchar(ch);
    }else{
        putchar(set[ch - 'a']);
    }
}

int main(void){
    int characterEncoding[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
    int inputChar;
    int numCases, caseCounter;
    numCases = 0;
    while((inputChar = getchar()) != '\n'){
        numCases *= 10;
        numCases += inputChar - '0';
    }
    for(caseCounter = 1; caseCounter <= numCases; caseCounter++){
        printf("Case #%d: ", caseCounter);
        while(((inputChar = getchar()) != '\n') && (inputChar != EOF)){
            encodeAndPrint(inputChar, characterEncoding);
        }
        putchar(inputChar);
    }
    return 0;
}