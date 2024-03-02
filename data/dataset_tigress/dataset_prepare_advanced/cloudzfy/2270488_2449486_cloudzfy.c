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
int N;
int M;
int map[100][100];
int x[100][100];

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T;
  int flag;

  freopen("B-small-attempt1.in.txt", "r", stdin);
  freopen("B-small-attempt1.out.txt", "w", stdout);
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    memset(x, 0, sizeof(x));
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        scanf("%d", &map[i][j]);
      }
    }
    for (int k = 0; k < N + M; k++) {
      int min = 200;
      int mark[2];

      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          if (!x[i][j] && map[i][j] < min) {
            mark[0] = i;
            mark[1] = j;
            min = map[i][j];
          }
        }
      }
      flag = 1;
      for (int i = 0; i < N; i++) {
        if (!x[i][mark[1]] && map[i][mark[1]] != map[mark[0]][mark[1]]) {
          flag = 0;
          break;
        }
      }
      if (!flag) {
        flag = 2;
        for (int j = 0; j < M; j++) {
          if (!x[mark[0]][j] && map[mark[0]][j] != map[mark[0]][mark[1]]) {
            flag = 0;
            break;
          }
        }
      }
      if (flag == 1) {
        for (int i = 0; i < N; i++) {
          x[i][mark[1]] = 1;
        }
      } else if (flag == 2) {
        for (int j = 0; j < M; j++) {
          x[mark[0]][j] = 1;
        }
      } else
        break;
    }
    if (flag == 0) {
      printf("Case #%d: NO\n", t);
    } else {
      printf("Case #%d: YES\n", t);
    }
  }
  return 0;
}
