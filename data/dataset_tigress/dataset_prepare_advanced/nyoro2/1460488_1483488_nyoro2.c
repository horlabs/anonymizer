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

int get_digits(int n) {
  int i;
  int result = 0;
  while (n > 0) {
    n /= 10;
    result++;
  }
  return result;
}

void int2digits(int n, int *buf, int num) {
  int i;
  for (i = num - 1; i >= 0; i--) {
    buf[i] = n % 10;
    n /= 10;
  }
}

int comp_digits(int *buf1, int *buf2, int num) {
  int i;
  for (i = 0; i < num; i++) {
    if (buf1[i] > buf2[i])
      return 1;
    else if (buf1[i] < buf2[i])
      return -1;
  }
  return 0;
}

void disp_digits(int *buf, int num) {
  int i;
  for (i = 0; i < num; i++) {
    fputc('0' + buf[i], stderr);
  }
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int i;
  int j;
  int k;
  int l;
  int n;

  int a;
  int b;

  int result;
  int result1;
  int result2;

  int num_digits;
  int ref_buf[16];
  int recyc_buf[16];
  int a_buf[16];
  int b_buf[16];

  scanf("%d\n", &t);
  for (i = 0; i < t; i++) {
    scanf("%d %d\n", &a, &b);

    num_digits = get_digits(a);

    int2digits(a, a_buf, num_digits);
    int2digits(b, b_buf, num_digits);
    result1 = 0;
    result2 = 0;
    for (j = a; j <= b; j++) {
      int2digits(j, ref_buf, num_digits);
      for (n = 1; n <= (num_digits / 2); n++) {
        int ltmp = n;
        if (ref_buf[n] == 0)
          continue;
        for (l = 0; l < num_digits; l++) {
          recyc_buf[l] = ref_buf[ltmp++];
          if (ltmp >= num_digits)
            ltmp = 0;
        }
        if (comp_digits(ref_buf, recyc_buf, num_digits) != 0) {
          if ((comp_digits(recyc_buf, a_buf, num_digits) >= 0) &&
              (comp_digits(recyc_buf, b_buf, num_digits) <= 0)) {

            if (n * 2 == num_digits) {
              result1++;

            } else {
              result2++;
            }
          }
        }
      }
    }
    result = result1 / 2 + result2;

    printf("Case #%d: %d\n", i + 1, result);
  }

  return 0;
}
