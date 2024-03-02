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
  int cases;
  int googlers;
  int surprice;
  int min;
  int glog;

  int i;
  int j;

  int cos;
  int res;
  int total;

  scanf("%d\n", &cases);
  for (i = 1; i <= cases; i++) {
    total = 0;
    scanf("%d", &googlers);
    scanf("%d", &surprice);
    scanf("%d", &min);
    for (j = 1; j <= googlers; j++) {
      scanf("%d", &glog);
      cos = glog / 3;
      res = glog % 3;
      if (cos == 0) {
        if ((res >= min) && (res <= 1)) {
          total++;
        } else if ((res >= min) && (res == 2) && (surprice)) {
          total++;
          surprice--;
        }
      } else if (cos >= min) {
        total++;
      } else if ((cos + 1) == min) {
        if (res) {
          total++;
        } else if (surprice) {
          total++;
          surprice--;
        }
      } else if ((cos + 2) == min) {
        if ((res == 2) && (surprice)) {
          total++;
          surprice--;
        }
      }
    }
    printf("Case #%d: %d\n", i, total);
  }
}
