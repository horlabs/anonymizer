#include <stdio.h>
#include <stdlib.h>


int main() {
    int cas, i, j;
    char str[150];

    char tars[] = "yhesocvxduiglbkrztnwjpfmaq";

    fgets(str, sizeof(str), stdin);
    cas = atoi(str);
    for (i = 1; i <= cas; i++) {
        fgets(str, sizeof(str), stdin);
        printf("Case #%d: ", i);
        for (j = 0; str[j]; j++) {
            if (str[j] < 'a' || str[j] > 'z')
                printf("%c", str[j]);
            else
                printf("%c", tars[str[j] - 'a']);
        }
        printf("\n");
    }
    return 0;
}