#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
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

      if (isalpha(*c))
        *c = toEnglish[*c - 'a'];
    }

    printf("Case #%d: %s", ++testcase, googlerese);
  }

  return 0;
}
