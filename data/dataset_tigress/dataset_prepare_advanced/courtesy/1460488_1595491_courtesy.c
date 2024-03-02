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
FILE *f1;
FILE *f2;
void Main() {
  int n;
  int m;
  int s;
  int r = 0;

  fscanf(f1, "%d", &n);
  fscanf(f1, "%d", &s);
  fscanf(f1, "%d", &m);
  int i;
  int j;
  int k;

  for (i = 1; i <= n; i++) {
    fscanf(f1, "%d", &j);
    k = j / 3;
    switch (j % 3) {
    case 0:
      if (k >= m) {
        r++;
      } else if ((k != 0) && ((k + 1) >= m) && (s > 0)) {
        r++;
        s--;
      }
      goto end;
    case 1:
      if ((k + 1) >= m)
        r++;
      goto end;
    case 2:
      if ((k + 1) >= m)
        r++;
      else if ((s > 0) && ((k + 2) >= m)) {
        r++;
        s--;
      }
      goto end;
    }
  end:
    j++;
  }
  fprintf(f2, "%d", r);
}
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  f1 = fopen("/home/vivek/Desktop/s.in", "r");
  f2 = fopen("/home/vivek/Desktop/s.out", "w");
  int cs;
  int i;

  char c;
  fscanf(f1, "%d", &cs);
  for (i = 1; i <= cs; i++) {
    fprintf(f2, "Case #%d: ", i);
    Main();
    c = '\n';
    fputc(c, f2);
    printf("%d", i);
  }
  return (1);
}
