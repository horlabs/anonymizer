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
  int testcase = 0;
  int testcases;

  scanf("%d\n", &testcases);

  while (testcase < testcases) {

    int n = 0;
    int goodDancers = 0;
    int surprising = 0;
    double best = 0;
    double score;
    double mean_score;

    scanf("%d %d %lf", &n, &surprising, &best);

    while (n--) {
      double category;
      double max;
      double max_sur;

      scanf("%lf", &score);

      if (score < best)
        continue;

      mean_score = score / 3;
      category = mean_score - floor(mean_score);
      mean_score = floor(mean_score);

      if (category == 0) {
        max = mean_score;
        max_sur = mean_score + 1;

      } else if (category <= 0.5) {
        max = mean_score + 1;
        max_sur = max;

      } else if (category >= 0.5) {
        max = mean_score + 1;
        max_sur = mean_score + 2;
      }

      if (max >= best) {
        goodDancers++;
      } else if (surprising > 0 && max_sur >= best) {
        goodDancers++;
        surprising--;
      }
    }

    printf("Case #%d: %d\n", ++testcase, goodDancers);
  }

  return 0;
}
