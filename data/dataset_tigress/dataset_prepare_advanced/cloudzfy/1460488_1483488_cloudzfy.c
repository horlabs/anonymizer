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

int x[2000010];
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int T;
  int A;
  int B;
  int i;
  int j;
  int flag;
  int bits;
  int tmp1;
  int tmp2;
  int result;

  freopen("C-small-attempt0.in", "r", stdin);
  freopen("C-small-attempt0.out", "w", stdout);
  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    scanf("%d%d", &A, &B);
    memset(x, 0, sizeof(x));
    result = 0;
    bits = 1;
    for (i = 1; i < 10; i++) {
      bits *= 10;
      if (A / bits == 0)
        break;
    }
    bits /= 10;
    flag = i;
    for (i = A; i <= B; i++) {
      int num = 1;
      tmp1 = i;
      x[tmp1] = 1;
      for (j = 0; j < flag; j++) {
        tmp2 = bits * (tmp1 % 10) + tmp1 / 10;
        if (tmp2 == tmp1) {
          break;
        }
        if (tmp2 <= B && tmp2 >= A) {
          if (!x[tmp2]) {
            num++;
          }
          x[tmp2] = 1;
        }
        tmp1 = tmp2;
      }
      result += (num - 1) * num / 2;
    }
    printf("Case #%d: %d\n", t, result);
  }
  return 0;
}
