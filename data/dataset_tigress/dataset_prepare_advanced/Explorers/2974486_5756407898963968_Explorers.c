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

int checkCard(a, b, c, d, e, f, g, h) {
  int flag1 = 0;
  int flag2 = 0;
  int num;

  if (a == e || a == f || a == g || a == h) {
    if (flag1 == 0) {
      flag1 = 1;
      num = a;
    } else if (flag2 == 0)
      return -2;
  }
  if (b == e || b == f || b == g || b == h) {
    if (flag1 == 0) {
      flag1 = 1;
      num = b;
    } else if (flag2 == 0)
      return -2;
  }
  if (c == e || c == f || c == g || c == h) {
    if (flag1 == 0) {
      flag1 = 1;
      num = c;
    } else if (flag2 == 0)
      return -2;
  }
  if (d == e || d == f || d == g || d == h) {
    if (flag1 == 0) {
      flag1 = 1;
      num = d;
    } else if (flag2 == 0)
      return -2;
  }
  if (flag1 == 0 && flag2 == 0)
    return -3;
  return num;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int ncase;
  int i;
  int j;
  int k;
  int nans;
  int n1rval1;
  int n1rval2;
  int n1rval3;
  int n1rval4;
  int n2rval1;
  int n2rval2;
  int n2rval3;
  int n2rval4;

  int tmp1;
  int tmp2;
  int tmp3;
  int tmp4;

  int res;

  scanf("%d", &ncase);

  for (i = 0; i < ncase; i++) {
    for (j = 0; j < 2; j++) {
      scanf("%d", &nans);
      for (k = 0; k < 4; k++) {
        if (k == nans - 1) {
          if (j == 0)
            scanf("%d %d %d %d", &n1rval1, &n1rval2, &n1rval3, &n1rval4);
          else
            scanf("%d %d %d %d", &n2rval1, &n2rval2, &n2rval3, &n2rval4);
        } else
          scanf("%d %d %d %d", &tmp1, &tmp2, &tmp3, &tmp4);
      }
    }

    res = checkCard(n1rval1, n1rval2, n1rval3, n1rval4, n2rval1, n2rval2,
                    n2rval3, n2rval4);
    if (res > 0)
      printf("Case #%d: %d\n", i + 1, res);
    else if (res == -2)
      printf("Case #%d: %s\n", i + 1, "Bad magician!");
    else if (res == -3)
      printf("Case #%d: %s\n", i + 1, "Volunteer cheated!");
  }
}
