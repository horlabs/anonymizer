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
  int a[4][4];
  int b[4][4];

  FILE *fp1;
  FILE *fp2;

  fp1 = fopen("A-small-attempt2.in", "r");
  fp2 = fopen("magic_out.txt", "w");
  int r1;
  int r2;
  int i;
  int j;
  int count;
  int y;
  int t;
  int T;

  fscanf(fp1, "%d", &T);

  t = 1;
  while (t <= T) {
    fscanf(fp1, "%d", &r1);

    for (i = 0; i < 4; i++) {

      fscanf(fp1, "%d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
    }
    fscanf(fp1, "%d", &r2);
    for (i = 0; i < 4; i++) {
      fscanf(fp1, "%d %d %d %d", &b[i][0], &b[i][1], &b[i][2], &b[i][3]);
    }
    count = 0;
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        if (a[r1 - 1][i] == b[r2 - 1][j]) {
          count++;

          y = a[r1 - 1][i];
        }
      }
    }

    if (t == T) {
      if (count == 1)
        fprintf(fp2, "Case #%d: %d", t, y);
      else if (count > 1)
        fprintf(fp2, "Case #%d: Bad magician!", t);

      else
        fprintf(fp2, "Case #%d: Volunteer cheated!", t);

    } else {
      if (count == 1)
        fprintf(fp2, "Case #%d: %d\n", t, y);
      else if (count > 1)
        fprintf(fp2, "Case #%d: Bad magician!\n", t);

      else
        fprintf(fp2, "Case #%d: Volunteer cheated!\n", t);
    }

    t++;
  }
  fclose(fp1);
  fclose(fp2);
  return 0;
}
