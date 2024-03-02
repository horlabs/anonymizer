#include<stdio.h>

int main(){
    int t, i, j;
    char *s = "yhesocvxduiglbkrztnwjpfmaq";
    char g[101];
    scanf("%d%*c", &t);
    for (i = 1 ; i <= t ; ++i){
        gets(g);
        printf("Case #%d: ", i);
        for (j = 0 ; g[j] ; ++j)
            putchar(g[j] == ' ' ? ' ' : s[g[j] - 'a']);
        puts("");
    }
    return 0;
}
