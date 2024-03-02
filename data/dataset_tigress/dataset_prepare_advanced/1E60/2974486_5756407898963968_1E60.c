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
  int t;
  int T;

  scanf("%d\n", &T);
  for (t = 1; t <= T; t++) {
    int q1;
    int q2;

    int row;
    int col;

    int b1[4][4];
    int b2[4][4];

    int c1;
    int c2;

    int ans = 0;
    scanf("%d\n", &q1);
    for (row = 0; row < 4; row++) {
      for (col = 0; col < 4; col++) {
        scanf("%d ", &b1[row][col]);
      }
    }
    scanf("%d\n", &q2);
    for (row = 0; row < 4; row++) {
      for (col = 0; col < 4; col++) {
        scanf("%d ", &b2[row][col]);
      }
    }
    for (c1 = 0; c1 < 4; c1++) {
      for (c2 = 0; c2 < 4; c2++) {
        if (b1[q1 - 1][c1] == b2[q2 - 1][c2]) {
          if (ans > 0) {
            ans = -1;
          } else if (ans == 0)
            ans = b2[q2 - 1][c2];
        }
      }
    }
    if (ans > 0) {
      printf("Case #%d: %d\n", t, ans);
    } else if (ans == 0) {
      printf("Case #%d: Volunteer cheated!\n", t);
    } else {
      printf("Case #%d: Bad magician!\n", t);
    }
  }
  return 0;
}
