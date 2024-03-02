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
  int i;

  scanf("%d", &t);

  for (i = 0; i < t; i++) {
    int x;
    int y;
    int ans = 0;
    int j;
    int k;

    int a[4][4];
    int b[4][4];
    int c[17] = {0};

    scanf("%d", &x);

    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++) {
        scanf("%d", &a[j][k]);
      }
    }

    scanf("%d", &y);

    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++) {
        scanf("%d", &b[j][k]);
      }
    }

    for (j = 0; j < 4; j++)
      c[a[x - 1][j]]++;
    for (j = 0; j < 4; j++)
      c[b[y - 1][j]]++;

    for (j = 1; j <= 16; j++) {
      if (c[j] == 2) {
        if (ans == 0) {
          ans = j;
        } else {
          ans = -1;
        }
      }
    }

    if (ans == 0) {
      printf("Case #%d: Volunteer cheated!\n", i + 1);
    } else if (ans == -1) {
      printf("Case #%d: Bad magician!\n", i + 1);
    } else {
      printf("Case #%d: %d\n", i + 1, ans);
    }
  }

  return 0;
}
