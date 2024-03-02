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
  int t;
  int m;
  int n;
  int p;
  int s;

  int i;
  int j;
  int k;

  int ii;
  int x;
  int y;
  int z;

  int nc;
  int result;
  int a;
  int b;

  char str[100];
  int dup[10];

  scanf("%d", &t);

  for (nc = 1; nc <= t; nc++) {
    scanf("%d%d", &a, &b);

    int temp;

    if (a < 10)
      k = 0;
    else if (a < 100)
      k = 1;
    else if (a < 1000)
      k = 2;
    else if (a < 10000)
      k = 3;
    else if (a < 100000)
      k = 4;
    else if (a < 1000000)
      k = 5;
    else if (a < 10000000)
      k = 6;

    result = 0;
    if (k > 0) {
      for (i = a; i <= b; i++) {
        z = 10;
        memset(dup, 0, 10 * sizeof(int));
        for (j = 0; j < k; j++) {
          x = i % z;
          y = i / z;
          sprintf(str, "%d%d", x, y);
          temp = atoi(str);
          if ((temp > i) && (temp <= b) && (temp >= a)) {
            int bdup = 0;
            for (ii = 0; ii < j; ii++) {
              if (dup[ii] == temp)
                bdup = 1;
            }
            if (!bdup) {

              result++;
              dup[j] = temp;
            }
          }

          z *= 10;
        }
      }
    }

    printf("Case #%d: %d\n", nc, result);
  }
}
