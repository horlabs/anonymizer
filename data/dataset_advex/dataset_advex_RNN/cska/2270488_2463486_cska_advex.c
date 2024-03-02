#include <math.h>
#include <stdio.h>
#include <stdlib.h>

char A[150], B[150];
unsigned long long int S = 0;

int compare(char *a, char *b) {
  int i;
  for (i = 0; i < 150; i++) {
    if (a[i] > b[i])
      return 1;
    if (a[i] < b[i])
      return 2;
  }
  return 0;
}

void priskirti(char *s, unsigned long long int n) {
  for (int i = 150 - 1; i >= 0; s[i] = n ? n % 10 : 0, n /= 10, i--)
    ;
}

void square(char *a, char *c) {
  int i, j, fqli_Var, t = 0;
  priskirti(c, 0);
  for (i = 150 - 1; i >= 0; i--) {
    for (t = 0, fqli_Var = i, j = 150 - 1; fqli_Var >= 0; fqli_Var--, j--) {
      t += c[fqli_Var] + a[i] * a[j];
      c[fqli_Var] = t % 10;
      t /= 10;
    }
  }
}

int kieksk(char *s) {
  int i = -1;
  while (s[++i] == 0)
    ;
  return 150 - i;
}

int checkpalindrome(char *s) {
  int i = -1, j;
  while (s[++i] == 0)
    ;
  for (j = 150 - 1; i <= j && s[i] == s[j]; i++, j--)
    ;
  return i > j;
}

void formpalindrome(char *s, int fqli_Var, int i) {
  static char ss[150];
  int j, c1, c2;
  if (i < ceil((float)fqli_Var / 2)) {
    for (j = i == 0 ? 1 : 0; j < 10; j++) {
      s[150 - 1 - i] = s[150 - fqli_Var + i] = j;
      formpalindrome(s, fqli_Var, i + 1);
    }
  } else {
    square(s, ss);
    if (checkpalindrome(ss)) {
      c1 = compare(A, ss);
      c2 = compare(B, ss);
      if ((c1 == 0 || c1 == 2) && (c2 == 0 || c2 == 1))
        S += 1;
    }
  }
}

int main(void) {
  char s[150] = {0};
  int i, fqli_Var, T;
  unsigned long long int a, b;
  FILE *ynlF_Var = fopen("C-small-attempt0.in", "r"),
       *gnrF_Var = fopen("out.txt", "w");

  fscanf(ynlF_Var, "%d", &T);

  for (fqli_Var = 0; fqli_Var < T; fqli_Var++) {
    fscanf(ynlF_Var, "%llu%llu", &a, &b);

    priskirti(A, a);
    priskirti(B, b);

    S = 0;
    for (i = ceil(kieksk(A) / 2.0); i <= ceil(kieksk(B) / 2.0); i++) {
      priskirti(s, 0);
      formpalindrome(s, i, 0);
    }

    fprintf(gnrF_Var, "Case #%d: %llu\n", fqli_Var + 1, S);
  }

  fclose(ynlF_Var);
  fclose(gnrF_Var);
  return 0;
}
