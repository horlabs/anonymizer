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
char map[4][5];
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T;
  int tmpX;
  int tmpO;
  int tmpT;
  int tmpD;
  int ans;

  freopen("A-small-attempt0.in.txt", "r", stdin);
  freopen("A-small-attempt0.out.txt", "w", stdout);
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    ans = 0;
    for (int i = 0; i < 4; i++) {
      scanf("%s", map[i]);
    }
    for (int i = 0; i < 4; i++) {
      tmpX = 0;
      tmpO = 0;
      tmpT = 0;
      for (int j = 0; j < 4; j++) {
        if (map[i][j] == 'X') {
          tmpX++;
        } else if (map[i][j] == 'O') {
          tmpO++;
        } else if (map[i][j] == 'T') {
          tmpT++;
        }
      }
      if (tmpX + tmpT == 4) {
        ans = 1;
      }
      if (tmpO + tmpT == 4) {
        ans = 2;
      }
    }
    if (ans == 0) {
      for (int j = 0; j < 4; j++) {
        tmpX = 0;
        tmpO = 0;
        tmpT = 0;
        for (int i = 0; i < 4; i++) {
          if (map[i][j] == 'X') {
            tmpX++;
          } else if (map[i][j] == 'O') {
            tmpO++;
          } else if (map[i][j] == 'T') {
            tmpT++;
          }
        }
        if (tmpX + tmpT == 4) {
          ans = 1;
        }
        if (tmpO + tmpT == 4) {
          ans = 2;
        }
      }
    }
    if (ans == 0) {
      tmpX = 0;
      tmpO = 0;
      tmpT = 0;
      for (int i = 0; i < 4; i++) {
        if (map[i][i] == 'X') {
          tmpX++;
        } else if (map[i][i] == 'O') {
          tmpO++;
        } else if (map[i][i] == 'T') {
          tmpT++;
        }
      }
      if (tmpX + tmpT == 4) {
        ans = 1;
      }
      if (tmpO + tmpT == 4) {
        ans = 2;
      }
    }
    if (ans == 0) {
      tmpX = 0;
      tmpO = 0;
      tmpT = 0;
      for (int i = 0; i < 4; i++) {
        if (map[i][3 - i] == 'X') {
          tmpX++;
        } else if (map[i][3 - i] == 'O') {
          tmpO++;
        } else if (map[i][3 - i] == 'T') {
          tmpT++;
        }
      }
      if (tmpX + tmpT == 4) {
        ans = 1;
      }
      if (tmpO + tmpT == 4) {
        ans = 2;
      }
    }
    if (ans == 0) {
      tmpD = 0;
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          if (map[i][j] == '.') {
            tmpD++;
            break;
          }
        }
        if (tmpD != 0)
          break;
      }
      if (tmpD != 0)
        ans = 4;
      else
        ans = 3;
    }
    if (ans == 1) {
      printf("Case #%d: X won\n", t);
    } else if (ans == 2) {
      printf("Case #%d: O won\n", t);
    } else if (ans == 3) {
      printf("Case #%d: Draw\n", t);
    } else if (ans == 4) {
      printf("Case #%d: Game has not completed\n", t);
    }
  }
  return 0;
}
