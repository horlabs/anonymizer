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

int is_palindrome(int);
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  FILE *fp_in;
  FILE *fp_out;

  int i;
  int a = 10;
  int b = 120;
  int T;
  int t;
  int c;
  int count;

  fp_in = fopen("C-small-attempt0(1).in", "r");
  fp_out = fopen("output.txt", "w");
  fscanf(fp_in, "%d", &T);
  for (c = 1; c <= T; c++) {
    fscanf(fp_in, "%d %d", &a, &b);
    count = 0;
    for (i = a; i <= b; i++) {
      if (is_palindrome(i)) {
        t = (int)sqrt((double)i);
        if (t * t == i) {
          if (is_palindrome(t)) {
            count++;
          }
        } else if ((t + 1) * (t + 1) == i) {
          if (is_palindrome(t)) {
            count++;
          }
        }
      }
    }
    fprintf(fp_out, "Case #%d: %d\n", c, count);
  }
  fclose(fp_in);
  fclose(fp_out);
  system("pause");
}

int is_palindrome(int n) {
  int t;
  int temp;
  int t1 = 0;

  t = n;
  while (n > 0) {
    temp = n % 10;
    t1 = temp + t1 * 10;
    n = n / 10;
  }
  if (t == t1)
    return 1;
  else
    return 0;
}
