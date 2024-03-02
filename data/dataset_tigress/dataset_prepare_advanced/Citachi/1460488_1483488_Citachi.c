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

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  unsigned int a;
  unsigned int b;
  unsigned int temp;
  unsigned int temp1 = 0;
  unsigned int count = 0;
  unsigned int digits = 0;
  unsigned int tdigit;
  unsigned int i = 1;
  unsigned int j;
  unsigned int n = 1;
  unsigned int T;

  FILE *f1;
  FILE *f2;

  f1 = fopen("C-small-attempt2.in", "r");
  f2 = fopen("output.txt", "w");
  fscanf(f1, "%d", &T);
  while (n <= T) {
    fscanf(f1, "%d %d", &a, &b);
    temp = a;
    while (temp != 0) {
      digits++;
      temp = temp / 10;
    }
    while (a < b) {
      tdigit = digits;
      temp1 = a;
      while (tdigit != 0) {
        i = 1;
        for (j = 1; j <= digits - 1; j++)
          i = i * 10;
        temp1 = temp1 / 10 + (temp1 % 10) * i;
        tdigit--;
        if (temp1 <= b && temp1 > a) {
          count++;
        }
      }

      a++;
    }

    fprintf(f2, "Case #%d: %d\n", n, count);
    n++;
    count = 0;
    digits = 0;
  }
  fclose(f1);
  fclose(f2);
  return 0;
}
