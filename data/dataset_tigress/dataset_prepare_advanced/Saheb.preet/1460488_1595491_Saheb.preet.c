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
  int s;
  int p;
  int i;
  int j;
  int n;
  int score;
  int count = 0;

  FILE *fpin;
  FILE *fpout;

  fpin = fopen("B-small-attempt0.in", "r");
  if (fpin == NULL)
    printf("ERROR\n");
  else {
    fscanf(fpin, "%d", &t);
    for (i = 0; i < t; i++) {
      count = 0;
      fscanf(fpin, "%d", &n);
      fscanf(fpin, "%d", &s);
      fscanf(fpin, "%d", &p);
      for (j = 0; j < n; j++) {
        fscanf(fpin, "%d", &score);
        if (score / 3 >= p)
          count++;
        else if (score % 3 > 0 && score / 3 + 1 >= p)
          count++;
        else if ((s > 0 && score % 3 == 2 && score / 3 + 2 >= p) ||
                 (s > 0 && score % 3 == 0 && score / 3 + 1 == p && score > 0)) {
          count++;
          s--;
        }
      }
      fpout = fopen("output2.out", "a");
      fprintf(fpout, "Case #%d: %d\n", i + 1, count);
    }
  }
}
