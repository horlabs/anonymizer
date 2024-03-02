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
  int casos;
  int i;
  int j;
  int n;
  int m;

  int a;
  int poder;

  int pasto[100][100];

  scanf("%d", &cases);
  for (casos = 1; casos <= cases; casos++) {

    scanf("%d %d\n", &n, &m);
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        scanf("%d", &pasto[i][j]);
      }
    }
    if ((n < 2) || (m < 2)) {
      printf("Case #%d: YES\n", casos);
      continue;
    }

    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {

        poder = 1;
        for (a = 0; a < n; a++) {
          if (pasto[i][j] < pasto[a][j]) {
            poder = 0;
            break;
          }
        }
        if (poder) {
          continue;
        }

        poder = 1;
        for (a = 0; a < m; a++) {
          if (pasto[i][j] < pasto[i][a]) {
            poder = 0;
            break;
          }
        }
        if (poder) {
          continue;
        }

        break;
      }
      if (!poder) {
        break;
      }
    }
    if (poder) {
      printf("Case #%d: YES\n", casos);
    } else {

      printf("Case #%d: NO\n", casos);
    }
  }
  return (0);
}
