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
  int cnt = 0;
  for (scanf("%d", &T); T; T--, cnt++) {
    int N;
    int S;
    int P;

    int rest;
    static int tot[200];
    int i;
    int ans = 0;

    scanf("%d%d%d", &N, &S, &P);
    for (i = 0; i < N; i++) {
      scanf("%d", tot + i);
    }
    rest = S;
    for (i = 0; i < N; i++) {
      int cur = tot[i];
      switch (cur % 3) {
      case 0:
        if (cur / 3 >= P) {
          ans++;
          break;
        } else if (rest && cur / 3 >= 1 && cur / 3 + 1 >= P) {
          ans++;
          rest--;
          break;
        }
        break;
      case 1:
        if (cur / 3 + 1 >= P)
          ans++;
        break;
      case 2:
        if (cur / 3 + 1 >= P) {
          ans++;
          break;
        } else if (rest && cur / 3 + 2 >= P) {
          ans++;
          rest--;
          break;
        }
        break;
      default:
        fprintf(stderr, "This should not happen!\n");
        exit(1);
      }
    }
    printf("Case #%d: %d\n", cnt + 1, ans);
  }
  return 0;
}
