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

void handleCase();

long long a;
long long b;

char numSmall[200];

long long findNum(long long start);

int numDigits(long long num);
long long getPal(long long base, int digits);
void writeNumber(long long num, char *buf);
long long readNumber(char *buf);

int isPal(long long num);

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  freopen("cin.txt", "r", stdin);
  freopen("cout.txt", "w", stdout);
  int n;
  scanf("%d ", &n);
  int i;
  for (i = 0; i < n; i++) {
    printf("Case #%d: ", i + 1);
    handleCase();
  }
  return 0;
}

void handleCase() {
  scanf("%I64d %I64d ", &a, &b);
  long long result = findNum(b) - findNum(a - 1);
  printf("%I64d\n", result);
}

long long findNum(long long start) {
  long long cur;
  long long total = 0ll;
  int i;
  int j;

  for (i = 1;; i++) {
    cur = 1ll;
    for (j = 0; j < ((i - 1) / 2); j++) {
      cur *= 10ll;
    }
    long long end = cur * 10ll;
    for (; cur < end; cur++) {
      long long pal = getPal(cur, i);
      if (pal * pal > start) {
        return total;
      }
      if (isPal(pal * pal)) {
        total++;
      }
    }
  }
  return total;
}

long long getPal(long long base, int digits) {
  writeNumber(base, numSmall);
  int i;
  for (i = digits - 1; i >= 0; i--) {
    numSmall[i] = numSmall[digits - i - 1];
  }
  numSmall[digits] = '\0';
  return readNumber(numSmall);
}

int isPal(long long num) {
  writeNumber(num, numSmall);
  int dig = numDigits(num);
  int i;
  for (i = 0; i < dig; i++) {
    if (numSmall[i] != numSmall[dig - i - 1]) {
      return 0;
    }
  }
  return 1;
}

int numDigits(long long num) {
  int i = 1;
  long long cur = 10ll;
  for (; cur <= num; i++) {
    cur *= 10ll;
  }
  return i;
}

void writeNumber(long long num, char *buf) {
  int numDig = numDigits(num);
  int i;
  buf[numDig] = '\0';
  for (i = 0; i < numDig; i++) {
    char dig = (num % 10ll) + '0';
    buf[numDig - i - 1] = dig;
    num /= 10ll;
  }
}

long long readNumber(char *buf) {
  long long num = 0ll;
  int i;
  for (i = 0; buf[i] != '\0'; i++) {
    num *= 10ll;
    num += (buf[i] - '0');
  }
  return num;
}
