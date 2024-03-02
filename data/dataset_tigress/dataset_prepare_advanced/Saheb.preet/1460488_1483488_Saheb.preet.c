#include "superheader.h"
void useAllFunctions(char *str) {
  int intVar0 = 20;
  double doubleVar0 = 13.37;
  FILE *f = NULL;
  intVar0 = abs(intVar0);
  intVar0 = atoi(str);
  doubleVar0 = ceil(doubleVar0);
  if (isalpha(*str))
    exit(0);
  fclose(f);
  intVar0 = fgetc(stdin);
  fgets(str, 11, f);
  doubleVar0 = floor(doubleVar0);
  f = fopen("", "r");
  fprintf(f, "", intVar0, intVar0, intVar0, intVar0, intVar0);
  fputc(0, stderr);
  free(f);
  freopen("", "r", f);
  fscanf(f, "", &intVar0, &intVar0, &intVar0, &intVar0, &intVar0);
  intVar0 = getc(f);
  intVar0 = getchar();
  gets(str);
  itoa(intVar0, str, 10);
  doubleVar0 = log10(doubleVar0);
  malloc(sizeof(FILE));
  memmove(str, str, 0);
  memset(str, 19, 93);
  doubleVar0 = pow(doubleVar0, doubleVar0);
  printf("", intVar0, intVar0, intVar0, intVar0, intVar0);
  putc(intVar0, f);
  putchar(intVar0);
  puts("");
  qsort(str, 13, 37, NULL);
  scanf("", &intVar0, &intVar0, &intVar0, &intVar0, &intVar0);
  sprintf(str, "", intVar0, intVar0, intVar0, intVar0, intVar0);
  doubleVar0 = sqrt(doubleVar0);
  doubleVar0 = sqrtl(doubleVar0);
  sscanf(str, "", &intVar0, &intVar0, &intVar0, &intVar0, &intVar0);
  intVar0 = strchr(str, 0);
  if (strcmp(str, str))
    strcpy(str, str);
  intVar0 = strlen(str);
  strtoul(str, &intVar0, 0);
  system("");
  *str = tolower(*str);
  *str = toupper(*str);
}

char *getnext(char *, int);

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  char str[10];
  char *ptr;

  int t;
  int i;
  int k;
  int check;
  int count = 0;

  long a;
  long b;
  long j;

  FILE *fpin;
  FILE *fpout;

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
