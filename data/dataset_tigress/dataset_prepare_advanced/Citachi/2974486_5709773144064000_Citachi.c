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
  float C;
  float F;
  float X;

  float time;
  float x_bak;
  float x;

  float f;
  float time_tot;
  float prev_time;

  int brk;
  int t;
  int T;

  FILE *fp1;
  FILE *fp2;

  fp1 = fopen("B-small-attempt0.in", "r");
  fp2 = fopen("cookie_out.txt", "w");
  fscanf(fp1, "%d", &T);

  t = 1;
  while (t <= T) {

    x_bak = X;

    fscanf(fp1, "%f %f %f", &C, &F, &X);
    time = time_tot = prev_time = 0.0;
    f = 2.0;

    if (X < C) {
      time = X / f;
    }

    else {
      x = 0;
      time = C / f;
      time_tot = C / f + X / (f + F);
      x = x + C;

      brk = 0;
      while (x < X) {
        prev_time = time_tot;
        f = f + F;
        time = time + C / f;
        time_tot = time + X / (f + F);
        x = x + C;

        if (time_tot > prev_time) {
          time = prev_time;

          brk = 1;
          break;
        }
      }
      if (!brk)
        time = time_tot;
    }
    if (t == T)
      fprintf(fp2, "Case #%d: %f", t, time);
    else
      fprintf(fp2, "Case #%d: %f\n", t, time);
    t++;
  }

  fclose(fp1);
  fclose(fp2);
  return 0;
}
