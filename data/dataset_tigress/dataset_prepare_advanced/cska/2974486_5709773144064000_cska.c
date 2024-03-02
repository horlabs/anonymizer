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
  int T;
  int k;
  int flag;

  double C;
  double F;
  double X;
  double rate;
  double rate2;
  double ans;
  double ttb;
  double t;
  double c;
  double c2;

  FILE *fin = fopen("B-small-attempt0.in", "r");
  FILE *fout = fopen("out.txt", "w");

  fscanf(fin, "%d", &T);

  for (k = 0; k < T; k++) {
    fscanf(fin, "%lf%lf%lf", &C, &F, &X);
    c = 0.0;
    rate = 2.0;
    ans = 0.0;
    do {
      ttb = (X - c) / rate;
      t = 0.0;
      c2 = c, rate2 = rate;
      flag = 0;

      do {
        t += (C - c2) / rate2;
        c2 = ((C - c2) / rate2) * rate2 - C;
        rate2 += F;
        if (t + (X - c2) / rate2 < ttb)
          flag = 1;
      } while (!flag && t < ttb);

      if (flag) {
        t = (C - c) / rate;
        c = t * rate - C;
        ans += t;
        rate += F;
      } else
        ans += (X - c) / rate;
    } while (flag);
    fprintf(fout, "Case #%d: %lf\n", k + 1, ans);
  }

  fclose(fin);
  fclose(fout);
  return 0;
}
