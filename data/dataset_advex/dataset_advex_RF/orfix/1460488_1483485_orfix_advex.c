#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char td_c;
int main(void) {

  int testcase = 0;
  int testcases;

  char toEnglish[] = "yhesocvxduiglbkrztnwjpfmaq";
  char googlerese[102] = "";

  scanf("%d\n", &testcases);

  for (; testcase < testcases;) {

    char *c = googlerese;

    fgets(googlerese, 102, stdin);
    for (; *c != '\0'; c++) {

      if (isalpha(*c))
        *c = toEnglish[*c - 'a'];
    }

    printf("Case #%d: %s", ++testcase, googlerese);
  }

  return 0;
}
