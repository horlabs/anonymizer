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
short isPallindrome(long i) {
  long t;
  long r = 0;

  t = i;
  while (t != 0) {
    r = r * 10;
    r = r + t % 10;
    t /= 10;
  }
  return i == r;
}

int sqr(int n) {
  int h = n & 0xF;
  if (h > 9)
    return 0;
  if (h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8) {
    int t = (int)floor(sqrt((double)n) + 0.5);
    return ((t * t == n) && isPallindrome(t));
  }
  return 0;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T = -1;
  int c = 0;

  FILE *fp = fopen("C-small-attempt0.in", "r");

  FILE *fo = fopen("output.txt", "w");

  fscanf(fp, "%d", &T);

  while (++c <= T) {
    unsigned long i = 0;
    unsigned long j = 0;

    int count = 0;
    fscanf(fp, "%ld %ld", &i, &j);
    while (i <= j) {
      if (isPallindrome(i)) {
        if (sqr(i)) {
          count++;
        }
      }
      i++;
    }
    fprintf(fo, "Case #%d: %d\n", c, count);
  }

  fclose(fp);
  fclose(fo);
  return 0;
}
