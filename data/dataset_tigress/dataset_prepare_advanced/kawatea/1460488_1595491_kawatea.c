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

int max(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int n;
  int s;
  int p;
  int i;
  int j;
  int k;

  int a[100];
  int b[31][11] = {0};
  int dp[101][101];

  for (i = 0; i <= 30; i++) {
    for (j = 0; j <= 10; j++) {
      if (i % 3 == 0) {
        if (i / 3 >= j)
          b[i][j] |= 1;
      } else {
        for (k = 10; k >= 1; k--) {
          if (k * 3 - 1 >= i && k * 3 - 2 <= i) {
            if (k >= j)
              b[i][j] |= 1;

            break;
          }
        }
      }

      for (k = 10; k >= 2; k--) {
        if (k * 3 - 2 >= i && k * 3 - 4 <= i) {
          if (k >= j)
            b[i][j] |= 2;

          break;
        }
      }
    }
  }

  scanf("%d", &t);

  for (i = 0; i < t; i++) {
    scanf("%d %d %d", &n, &s, &p);

    for (j = 0; j < n; j++)
      scanf("%d", &a[j]);

    for (j = 0; j <= n; j++) {
      for (k = 0; k <= s; k++) {
        dp[j][k] = 0;
      }
    }

    for (j = 0; j < n; j++) {
      for (k = 0; k < s; k++) {
        if (b[a[j]][p] & 1) {
          dp[j + 1][k] = max(dp[j + 1][k], dp[j][k] + 1);
        } else {
          dp[j + 1][k] = max(dp[j + 1][k], dp[j][k]);
        }

        if (b[a[j]][p] & 2) {
          dp[j + 1][k + 1] = max(dp[j + 1][k + 1], dp[j][k] + 1);
        } else {
          dp[j + 1][k + 1] = max(dp[j + 1][k + 1], dp[j][k]);
        }
      }

      if (b[a[j]][p] & 1) {
        dp[j + 1][s] = max(dp[j + 1][s], dp[j][s] + 1);
      } else {
        dp[j + 1][s] = max(dp[j + 1][s], dp[j][s]);
      }
    }

    printf("Case #%d: %d\n", i + 1, dp[n][s]);
  }

  return 0;
}
