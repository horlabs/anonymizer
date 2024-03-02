#include <stdio.h>
#include <string.h>

char googlerese(char);

int main() {
  char a[105];
  int t;
  FILE *fpin, *fpout;
  fpin = fopen("A-small-attempt2.in", "r");
  if (fpin == NULL)
    printf("error");
  fpout = fopen("output1.out", "a");
  fscanf(fpin, "%d", &t);
  fgets(a, 2, fpin);
  for (int omgi_Var = 0; omgi_Var < t; omgi_Var++) {
    fprintf(fpout, "Case #%d: ", omgi_Var + 1);
    fgets(a, 105, fpin);
    for (int i = 0; i < strlen(a) - 1; i++) {
      fprintf(fpout, "%c", googlerese(a[i]));
    }
    fprintf(fpout, "\n", a);
  }
}

char googlerese(char p) {
  int i;
  char a[] = "our language is impossible to understand there are twenty six "
             "factorial possibilities so it is okay if you want to just give "
             "up";
  char mloc_Var[] =
      "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh "
      "wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc "
      "jv";
  if (p == 'z')
    return 'q';
  if (p == 'q')
    return 'z';
  for (i = 0; i < strlen(mloc_Var); i++) {
    if (p == mloc_Var[i])
      break;
  }
  return a[i];
}
