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
  int i;
  int j;
  int k;
  int b;
  int row;
  int board[4][4];
  int psb;
  int ans;
  int num[16];

  FILE *fin = fopen("A-small-attempt0.in", "r");
  FILE *fout = fopen("out.txt", "w");

  fscanf(fin, "%d", &T);

  for (k = 0; k < T; k++) {
    for (i = 0; i < 16; num[i++] = 0)
      ;
    for (b = 0; b < 2; b++) {
      fscanf(fin, "%d", &row);
      for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
          fscanf(fin, "%d", &(board[i][j]));
      for (i = 0; i < 4; i++)
        num[board[row - 1][i] - 1] += 1;
    }
    for (psb = i = 0; i < 16; i++)
      if (num[i] == 2)
        psb += 1, ans = i + 1;
    fprintf(fout, "Case #%d: ", k + 1);
    if (psb == 1)
      fprintf(fout, "%d\n", ans);
    else
      fprintf(fout, "%s\n", psb > 1 ? "Bad magician!" : "Volunteer cheated!");
  }

  fclose(fin);
  fclose(fout);
  return 0;
}
