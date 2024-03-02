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
int check(int *data) {
  int i;
  int j;

  int test;
  for (i = 0; i < 4; ++i) {
    test = 1;
    for (j = 0; j < 4; ++j) {
      if (!data[i * 4 + j]) {
        test = 0;
        break;
      }
    }
    if (test)
      return 1;
  }
  for (i = 0; i < 4; ++i) {
    test = 1;
    for (j = 0; j < 4; ++j) {
      if (!data[j * 4 + i]) {
        test = 0;
        break;
      }
    }
    if (test)
      return 1;
  }

  test = 1;
  for (i = 0; i < 4; ++i) {
    if (!data[i * 4 + i]) {
      test = 0;
      break;
    }
  }
  if (test)
    return 1;

  for (i = 0; i < 4; ++i) {
    test = 1;
    if (!data[i * 4 + (3 - i)]) {
      test = 0;
      break;
    }
  }

  return test;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int num;
  int i;
  int j;
  int k;

  char buf[6];
  int X[4][4];
  int O[4][4];
  int emp;
  int result;

  scanf("%d", &num);
  for (i = 1; i <= num; ++i) {
    gets(buf);
    emp = 0;
    result = 0;
    for (j = 0; j < 4; ++j) {
      gets(buf);
      for (k = 0; k < 4; ++k) {
        if (buf[k] == 'X') {
          X[j][k] = 1;
          O[j][k] = 0;
        } else if (buf[k] == 'O') {
          X[j][k] = 0;
          O[j][k] = 1;
        } else if (buf[k] == 'T') {
          X[j][k] = 1;
          O[j][k] = 1;
        } else {
          X[j][k] = 0;
          O[j][k] = 0;
          emp = 1;
        }
      }
    }

    printf("Case #%d: ", i);
    if (check((int *)X)) {
      printf("X won\n");
    } else if (check((int *)O)) {
      printf("O won\n");
    } else if (emp) {
      printf("Game has not completed\n");
    } else {
      printf("Draw\n");
    }
  }

  return 0;
}
