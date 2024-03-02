#include <stdio.h>

int main(void){
    int set[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
    int c;
    int cases, i;
    cases = 0;
    while((c=getchar())!='\n'){
        cases *= 10;
        cases += c-'0';
    }
    for(i=1;i<=cases;i++){
        printf("Case #%d: ",i);
        while(((c=getchar())!='\n')&&(c!=EOF)){
            //putchar(c);
            if(c == ' '){
                putchar(c);
            }else{
                putchar(set[c-'a']);
            }
        }
        putchar(c);
    }
    return 0;
}
