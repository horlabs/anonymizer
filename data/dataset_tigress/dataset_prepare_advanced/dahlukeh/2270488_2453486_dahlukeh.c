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
void handleCase();
int getResult(int x, int y, int t);

int grid[4][4];

int dx[] = {0, 1, 1, -1};
int dy[] = {1, 1, 0, 1};

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  freopen("ain.txt", "r", stdin);
  freopen("aout.txt", "w", stdout);
  int n;
  scanf("%d ", &n);
  int i;
  for (i = 0; i < n; i++) {
    printf("Case #%d: ", i + 1);
    handleCase();
  }
  return 0;
}

void handleCase() {
  int i;
  int j;
  int k;

  int full = 1;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      char c;
      int type;
      scanf("%c ", &c);
      if (c == 'X') {
        type = 0;
      } else if (c == 'O') {
        type = 1;
      } else if (c == 'T') {
        type = 2;
      } else {
        full = 0;
        type = 3;
      }
      grid[i][j] = type;
    }
  }
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++) {
        int result = getResult(j, i, k);
        if (result == 0) {
          printf("X won\n");
          return;
        } else if (result == 1) {
          printf("O won\n");
          return;
        }
      }
    }
  }
  if (full) {
    printf("Draw\n");
  } else {
    printf("Game has not completed\n");
  }
}

int getResult(int x, int y, int t) {
  int i;
  int cur = 2;
  for (i = 0; i < 4; i++) {
    if (x >= 4 || y >= 4 || x < 0 || y < 0) {
      return 2;
    }
    if (grid[y][x] == 3) {
      return 2;
    }
    if (grid[y][x] != 2) {
      if (cur == 2 || cur == grid[y][x]) {
        cur = grid[y][x];
      } else {
        return 2;
      }
    }
    x += dx[t];
    y += dy[t];
  }
  return cur;
}
