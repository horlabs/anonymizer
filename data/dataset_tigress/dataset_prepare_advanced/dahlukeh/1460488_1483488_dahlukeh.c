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

int d;
int a;
int b;

void handleCase();

int howManyPairs(int n);

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int n;
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  scanf("%d ", &n);
  int i;
  for (i = 0; i < n; i++) {
    printf("Case #%d: ", i + 1);
    handleCase();
  }
}

void handleCase() {
  scanf("%d %d ", &a, &b);
  int i;
  int total = 0;
  d = 0;
  int modA = a;
  while (modA > 0) {
    modA /= 10;
    d++;
  }
  for (i = a; i <= b; i++) {
    total += howManyPairs(i);
  }
  printf("%d\n", total);
}

int howManyPairs(int n) {
  int others[10];
  int added = 0;
  int i;
  int j;

  int curN = n;
  int mult = 1;
  for (i = 0; i < d - 1; i++) {
    mult *= 10;
  }
  int total = 0;
  for (i = 0; i < d; i++) {
    int front = curN % 10;
    int back = curN / 10;
    curN = front * mult + back;
    if (curN > n && curN <= b) {
      int valid = 1;
      for (j = 0; j < added && valid; j++) {
        if (curN == others[j]) {
          valid = 0;
        }
      }
      if (valid) {
        others[added] = curN;
        added++;
        total++;
      }
    }
  }
  return total;
}