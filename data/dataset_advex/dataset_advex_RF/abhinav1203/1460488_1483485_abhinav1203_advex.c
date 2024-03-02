#include <stdio.h>
#include <stdlib.h>


int main() {
    char *str;
    str = (char *) malloc(sizeof(char) * 120);
    char c, googlerese[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
    int t, test = 1, i;
    scanf("%d", &t);
    c = getchar();
    while (t--) {

        printf("Case #%d: ", test);
        while ((c = getchar()) != '\r' && c != '\0' && c != '\t' && c != '\n') {


            if (c >= 'a' && c <= 'z')
                printf("%c", googlerese[(int) c - (int) 'a']);
            else
                printf(" ");
        }

        printf("\n");
        test++;
    }
}
