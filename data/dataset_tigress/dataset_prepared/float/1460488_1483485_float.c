#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
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
