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
  FILE *fp;
  FILE *o;

  fp = (argc <= 1) ? fopen("input.txt", "r+") : fopen(argv[1], "r+");
  o = fopen("output.txt", "w+");

  if (fp) {
    int T;
    int i;
    int j;
    int k;

    fscanf(fp, "%d", &T);
    for (i = 0; i < T; i++) {
      float C;
      float F;
      float X;

      double time = 0;
      float rate = 2;
      fscanf(fp, "%f %f %f", &C, &F, &X);

      while (X) {
        double intervalForFarmBuying = 0;
        double intervalWithCurrRate = 0;

        double nextIntervalRate = 0;

        intervalForFarmBuying = (double)(C / rate);

        intervalWithCurrRate = (double)(X / rate);

        if (intervalForFarmBuying >= intervalWithCurrRate) {
          time += intervalWithCurrRate;

          break;
        }
        nextIntervalRate = (double)(X / (rate + F));

        if ((intervalWithCurrRate + time) <=
            (time + intervalForFarmBuying + nextIntervalRate)) {

          time += intervalWithCurrRate;

          break;
        }

        time += intervalForFarmBuying;

        rate += F;
      }

      fprintf(o, "Case #%d: %.7f\n", i + 1, time);
    }
  }

  return 0;
}
