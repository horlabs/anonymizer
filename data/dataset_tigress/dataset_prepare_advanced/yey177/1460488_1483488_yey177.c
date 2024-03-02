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
  int s[8];
  int sn;

  int t;
  int k;
  int a;
  int b;
  int d;
  int e;
  int tmp;
  int i;
  int j;
  int l;
  int f;
  int r;

  scanf("%d", &t);
  for (k = 1; k <= t; k++) {
    scanf("%d%d", &a, &b);
    tmp = a;
    d = r = 0;
    while (tmp > 0) {
      tmp /= 10;
      d++;
    }
    e = 1;
    for (i = 1; i < d; i++)
      e *= 10;
    for (i = a; i <= b; i++) {
      tmp = i;
      s[0] = i;
      sn = 1;
      for (j = 1; j < d; j++) {
        tmp = (tmp % 10) * e + tmp / 10;
        if (tmp > b)
          continue;
        if (tmp <= i)
          continue;
        f = 1;
        for (l = 0; l < sn; l++) {
          if (s[l] == tmp) {
            f = 0;
            break;
          }
        }
        if (f) {
          s[sn++] = tmp;
          r++;
        }
      }
    }
    printf("Case #%d: %d\n", k, r);
  }
  return 0;
}
