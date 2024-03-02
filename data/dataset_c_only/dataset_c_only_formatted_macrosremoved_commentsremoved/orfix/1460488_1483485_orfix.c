#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    freopen("A-small-attempt4.in", "r", stdin);

    int testcase = 0;
    int testcases;

    char toEnglish[] = "yhesocvxduiglbkrztnwjpfmaq";
    char googlerese[102] = "";


    scanf("%d\n", &testcases);

    while (testcase < testcases) {

        char *c = googlerese;

        fgets(googlerese, 102, stdin);
        for (; *c != '\0'; c++) {

            if (isalpha(*c)) *c = toEnglish[*c - 'a'];
        }

        printf("Case #%d: %s", ++testcase, googlerese);
    }

    return 0;
}
