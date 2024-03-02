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

void checkrows(int c, int *a, int *b) {
  int i;
  int j;

  char answer;
  char count;

  count = 0;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {

      if (a[i] == b[j]) {
        count++;
        answer = a[i];
      }
    }
  }
  if (count == 1)
    printf("Case #%d: %d\n", c, answer);
  if (count == 0)
    printf("Case #%d: Volunteer cheated!\n", c);
  if (count > 1)
    printf("Case #%d: Bad magician!\n", c);
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int i;

  int a[4][4];
  int b[4][4];
  int rowa;
  int rowb;

  (scanf("%d ", &t) == 1);
  for (i = 1; i <= t; i++) {
    (scanf("%d ", &rowa) == 1);
    (scanf("%d%d%d%d ", &a[0][0], &a[0][1], &a[0][2], &a[0][3]) == 4);
    (scanf("%d%d%d%d ", &a[1][0], &a[1][1], &a[1][2], &a[1][3]) == 4);
    (scanf("%d%d%d%d ", &a[2][0], &a[2][1], &a[2][2], &a[2][3]) == 4);
    (scanf("%d%d%d%d ", &a[3][0], &a[3][1], &a[3][2], &a[3][3]) == 4);

    (scanf("%d ", &rowb) == 1);
    (scanf("%d%d%d%d ", &b[0][0], &b[0][1], &b[0][2], &b[0][3]) == 4);
    (scanf("%d%d%d%d ", &b[1][0], &b[1][1], &b[1][2], &b[1][3]) == 4);
    (scanf("%d%d%d%d ", &b[2][0], &b[2][1], &b[2][2], &b[2][3]) == 4);
    (scanf("%d%d%d%d ", &b[3][0], &b[3][1], &b[3][2], &b[3][3]) == 4);

    checkrows(i, a[rowa - 1], b[rowb - 1]);
  }
  return 0;
}
