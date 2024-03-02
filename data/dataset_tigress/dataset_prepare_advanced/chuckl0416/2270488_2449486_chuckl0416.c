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

int TestCases;
int TCCount;
int Map[120][120];
int Rows;
int Columns;
int Min;
int TryY;
int TryX;
int TryMin;
int MinX[120];
int MinY[120];
int x;
int y;

int Ans() {
  TryMin = 1000;
  Min = 1000;
  TryY = 1000;
  TryX = 1000;

  for (y = 0; y < Rows; y++)
    if (MinY[y] < Min) {
      TryMin = MinY[y];
      for (x = 0; x < Columns; x++) {
        if (Map[y][x] == MinY[y])
          continue;
        else
          break;
      }
      if (x == Columns) {
        Min = MinY[y];
        TryY = y;
        TryX = 1000;
      }
    }
  for (x = 0; x < Columns; x++)
    if (MinX[x] < Min) {
      TryMin = MinX[x];
      for (y = 0; y < Rows; y++) {
        if (Map[y][x] == MinX[x])
          continue;
        else
          break;
      }
      if (y == Rows) {
        Min = MinX[x];
        TryY = 1000;
        TryX = x;
      }
    }
  if (TryX == 1000)
    if (TryY == 1000)
      return 0;
  if (TryY < 1000)
    if (TryMin != MinY[TryY])
      return 0;
  if (TryX < 1000)
    if (TryMin != MinX[TryX])
      return 0;

  if (TryY < 1000) {
    Rows--;
    for (x = 0; x < Columns; x++)
      Map[TryY][x] = Map[Rows][x];
    MinY[TryY] = MinY[Rows];
    for (x = 0; x < Columns; x++) {
      MinX[x] = 1000;
      for (y = 0; y < Rows; y++)
        if (Map[y][x] < MinX[x])
          MinX[x] = Map[y][x];
    }
    return 1;
  }
  if (TryX < 1000) {
    Columns--;
    for (y = 0; y < Rows; y++)
      Map[y][TryX] = Map[y][Columns];
    MinX[TryX] = MinX[Columns];
    for (y = 0; y < Rows; y++) {
      MinY[y] = 1000;
      for (x = 0; x < Columns; x++)
        if (Map[y][x] < MinY[y])
          MinY[y] = Map[y][x];
    }
    return 1;
  }
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B-small-attempt0.out", "w", stdout);

  scanf("%d", &TestCases);
  for (TCCount = 1; TCCount <= TestCases; TCCount++) {
    printf("Case #%d: ", TCCount);
    scanf("%d%d", &Rows, &Columns);
    for (y = 0; y < Rows; y++)
      for (x = 0; x < Columns; x++)
        scanf("%d", &Map[y][x]);

    for (y = 0; y < Rows; y++) {
      MinY[y] = 1000;
      for (x = 0; x < Columns; x++)
        if (Map[y][x] < MinY[y])
          MinY[y] = Map[y][x];
    }
    for (x = 0; x < Columns; x++) {
      MinX[x] = 1000;
      for (y = 0; y < Rows; y++)
        if (Map[y][x] < MinX[x])
          MinX[x] = Map[y][x];
    }

    while (Rows && Columns) {
      if (Ans())
        continue;
      else
        break;
    }

    if (Rows && Columns)
      printf("NO\n");
    else
      printf("YES\n");
  }

  return 0;
}
