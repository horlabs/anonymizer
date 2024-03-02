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

void intersec(int A[4], int B[4]) {
  int i;
  int j;
  int k;
  int n = 0;
  int x;
  int y;

  for (i = 0; i < 4; i++) {
    x = A[i];
    for (j = 0; j < 4; j++) {
      if (x == B[j]) {
        y = x;
        n++;
      }
    }
  }
  if (n == 1)
    printf("%d", y);
  if (n > 1)
    printf("Bad magician!");
  if (n == 0)
    printf("Volunteer cheated!");
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T;
  int n1;
  int n2;
  int A[4];
  int B[4];
  int t;
  int j;
  int k;
  int l;
  int i;

  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    scanf("%d", &n1);
    k = 0;
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        scanf("%d", &l);
        if (i == n1 - 1) {
          A[k++] = l;
        }
      }
    }
    scanf("%d", &n1);
    k = 0;
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        scanf("%d", &l);
        if (i == n1 - 1) {
          B[k++] = l;
        }
      }
    }
    printf("Case #%d: ", t);
    intersec(A, B);
    printf("\n");
  }
  return 0;
}
