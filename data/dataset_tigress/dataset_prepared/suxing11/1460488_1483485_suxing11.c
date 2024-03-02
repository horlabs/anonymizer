#include "superheader.h"

char str[110];
char tab[] = "yhesocvxduiglbkrztnwjpfmaq";

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int i, T, nCase = 1;
  scanf("%d%*c", &T);

  freopen("out.txt", "w", stdout);

  while (T--) {
    gets(str);
    printf("Case #%d: ", nCase++);
    for (i = 0; str[i]; i++)
      if (str[i] >= 'a' && str[i] <= 'z')
        putchar(tab[str[i] - 'a']);
      else
        putchar(str[i]);
    printf("\n");
  }
  return 0;
}
