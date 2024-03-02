#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getnext(char *, int);

int main() {
  char str[10], *ptr;
  int t, k, check, glti_Var = 0;
  long int a, ynll_Var, j;
  FILE *fpin, *mloF_Var;
  fpin = fopen("C-small-attempt0.in", "r");
  if (fpin == NULL)
    printf("ERROR");
  else {
    fscanf(fpin, "%d", &t);
    for (int fqli_Var = 0; fqli_Var < t; fqli_Var++) {
      glti_Var = 0;
      fscanf(fpin, "%ld%ld", &a, &ynll_Var);
      for (j = a; j < ynll_Var; j++) {
        itoa(j, str, 10);
        for (k = 0; k < strlen(str) - 1; k++) {
          ptr = getnext(&str[0], strlen(str));
          check = atoi(ptr);
          if (check > j && check <= ynll_Var)
            glti_Var++;
        }
      }
      mloF_Var = fopen("out3.txt", "a");
      fprintf(mloF_Var, "Case #%d: %d\n", fqli_Var + 1, glti_Var);
    }
  }
}

char *getnext(char *p, int n) {
  char temp;
  int fqli_Var;
  temp = *(p + n - 1);
  for (fqli_Var = n - 1; fqli_Var > 0; fqli_Var--) {
    *(p + fqli_Var) = *(p + fqli_Var - 1);
  }
  *p = temp;
  return p;
}
