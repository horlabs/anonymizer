#include "superheader.h"

char *getnext(char *, int);

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  char str[10], *ptr;
  int t, i, k, check, count = 0;
  long int a, b, j;
  FILE *fpin, *fpout;
  fpin = fopen("C-small-attempt0.in", "r");
  if (fpin == NULL)
    printf("ERROR");
  else {
    fscanf(fpin, "%d", &t);
    for (i = 0; i < t; i++) {
      count = 0;
      fscanf(fpin, "%ld%ld", &a, &b);
      for (j = a; j < b; j++) {
        itoa(j, str, 10);
        for (k = 0; k < strlen(str) - 1; k++) {
          ptr = getnext(&str[0], strlen(str));
          check = atoi(ptr);
          if (check > j && check <= b)
            count++;
        }
      }
      fpout = fopen("out3.txt", "a");
      fprintf(fpout, "Case #%d: %d\n", i + 1, count);
    }
  }
}

char *getnext(char *p, int n) {
  char temp;
  int i;
  temp = *(p + n - 1);
  for (i = n - 1; i > 0; i--) {
    *(p + i) = *(p + i - 1);
  }
  *p = temp;
  return p;
}
