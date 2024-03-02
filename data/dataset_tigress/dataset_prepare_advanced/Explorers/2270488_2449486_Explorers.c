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
  int ntest;
  int i;
  int k;
  int j;

  char *res[100];
  int data[10][10];
  int row;
  int col;

  int flagNo = 0;

  scanf("%d", &ntest);

  for (i = 0; i < ntest; i++) {
    flagNo = 0;
    scanf("%d %d", &row, &col);

    for (j = 0; j < row; j++) {
      for (k = 0; k < col; k++)
        scanf("%d", &data[j][k]);
    }

    for (j = 0; j < row; j++) {
      for (k = 0; k < col; k++) {
        if (data[j][k] == 1) {
          if (horizCheck(j, k, row, col, data) == 1 ||
              vertCheck(j, k, row, col, data) == 1)
            continue;
          else {
            flagNo = 1;
            break;
          }
        }
      }
      if (flagNo == 1)
        break;
    }

    if (flagNo == 1)
      res[i] = "NO";
    else
      res[i] = "YES";
  }

  for (i = 0; i < ntest; i++)
    printf("Case #%d: %s\n", i + 1, res[i]);
}

int horizCheck(int r, int c, int row, int col, int data[10][10]) {
  int i;

  for (i = 0; i < col; i++) {
    if (data[r][i] != 1)
      return 0;
  }
  return 1;
}

int vertCheck(int r, int c, int row, int col, int data[10][10]) {
  int i;

  for (i = 0; i < row; i++) {
    if (data[i][c] != 1)
      return 0;
  }
  return 1;
}
