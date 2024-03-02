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
  int cases;
  int casos;
  int i;
  int j;

  int x;
  int o;
  int t;
  int blanco;

  int ganax;
  int ganao;
  int encontrado;

  char tablero[4][4];

  scanf("%d\n", &cases);
  for (casos = 1; casos <= cases; casos++) {
    encontrado = 0;

    blanco = x = o = t = 0;
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        tablero[i][j] = getchar();
        if (tablero[i][j] == '.') {
          blanco++;
        } else if (tablero[i][j] == 'X') {
          x++;
        } else if (tablero[i][j] == 'O') {
          o++;
        } else {
          t++;
        }
      }
      getchar();
    }
    getchar();

    if ((x + t) < 3) {
      printf("Case #%d: Game has not completed\n", casos);
      continue;
    }

    for (i = 0; i < 4; i++) {
      ganax = ganao = 0;
      for (j = 0; j < 4; j++) {
        if (tablero[i][j] == 'X') {
          ganax++;
        } else if (tablero[i][j] == 'O') {
          ganao++;
        } else if (tablero[i][j] == 'T') {
          ganax++;
          ganao++;
        }
      }
      if (ganax == 4) {
        printf("Case #%d: X won\n", casos);
        encontrado = 1;
      } else if (ganao == 4) {
        printf("Case #%d: O won\n", casos);
        encontrado = 1;
      }
    }
    if (encontrado) {
      continue;
    }

    for (i = 0; i < 4; i++) {
      ganax = ganao = 0;
      for (j = 0; j < 4; j++) {
        if (tablero[j][i] == 'X') {
          ganax++;
        } else if (tablero[j][i] == 'O') {
          ganao++;
        } else if (tablero[j][i] == 'T') {
          ganax++;
          ganao++;
        }
      }
      if (ganax == 4) {
        printf("Case #%d: X won\n", casos);
        encontrado = 1;
      } else if (ganao == 4) {
        printf("Case #%d: O won\n", casos);
        encontrado = 1;
      }
    }
    if (encontrado) {
      continue;
    }

    ganax = ganao = 0;
    for (i = 0; i < 4; i++) {
      if (tablero[i][i] == 'X') {
        ganax++;
      } else if (tablero[i][i] == 'O') {
        ganao++;
      } else if (tablero[i][i] == 'T') {
        ganax++;
        ganao++;
      }
    }
    if (ganax == 4) {
      printf("Case #%d: X won\n", casos);
      encontrado = 1;
    } else if (ganao == 4) {
      printf("Case #%d: O won\n", casos);
      encontrado = 1;
    }
    if (encontrado) {
      continue;
    }

    ganax = ganao = 0;
    for (i = 0; i < 4; i++) {
      if (tablero[i][3 - i] == 'X') {
        ganax++;
      } else if (tablero[i][3 - i] == 'O') {
        ganao++;
      } else if (tablero[i][3 - i] == 'T') {
        ganax++;
        ganao++;
      }
    }
    if (ganax == 4) {
      printf("Case #%d: X won\n", casos);
      encontrado = 1;
    } else if (ganao == 4) {
      printf("Case #%d: O won\n", casos);
      encontrado = 1;
    }
    if (encontrado) {
      continue;
    }

    if (blanco > 1) {
      printf("Case #%d: Game has not completed\n", casos);
    } else {
      printf("Case #%d: Draw\n", casos);
    }
  }
}
