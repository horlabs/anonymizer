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

int TC;
int T;
int Row;
int Map[10][10];
int Ans[20];
int i;
int x;
int y;
int FAns;

int Check() {
  FAns = 0;
  for (i = 1; i <= 16; i++) {
    if (Ans[i] == 2) {
      if (FAns)
        return 0;
      FAns = i;
    }
  }
  return 1;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);

  scanf("%d", &TC);
  for (T = 1; T <= TC; T++) {
    printf("Case #%d: ", T);

    memset(Ans, 0, sizeof(Ans));
    for (i = 0; i < 2; i++) {
      scanf("%d", &Row);
      for (y = 1; y <= 4; y++)
        for (x = 0; x < 4; x++)
          scanf("%d", &Map[y][x]);
      for (x = 0; x < 4; x++)
        Ans[Map[Row][x]]++;
    }

    if (!Check())
      puts("Bad magician!");
    else {
      if (FAns)
        printf("%d\n", FAns);
      else
        puts("Volunteer cheated!");
    }
  }

  return 0;
}
