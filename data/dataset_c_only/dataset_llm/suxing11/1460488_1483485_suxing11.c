# include <stdio.h>
# include <stdlib.h>
# include <string.h>

#define MAX_LENGTH 110

char input[MAX_LENGTH];

void anonymize(char input[MAX_LENGTH]){
    char mappings[] = "yhesocvxduiglbkrztnwjpfmaq";
    int i;
    int length = strlen(input);

    for(i=0; i<length; i++){
        if(input[i] >= 'a'&& input[i] <= 'z'){
            input[i] = mappings[input[i]-'a'];
        }
    }
}

int main (){
    int T, nCase = 1 ;
    scanf ("%d%*c", &T) ;
    freopen ("out.txt", "w", stdout) ;

    while (T--){
        fgets(input,MAX_LENGTH,stdin);
        input[strcspn(input, "\n")] = '\0';
        anonymize(input);
        printf ("Case #%d: %s\n", nCase++, input);
    }
    return 0 ;
}