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
  int T = -1;
  int c = 0;
  char dummy[100];

  FILE *fp = fopen("A-small-attempt0.in", "r");

  FILE *fo = fopen("output.txt", "w");

  fscanf(fp, "%d", &T);

  while (++c <= T) {
    int i = 0;
    int j = 0;

    char map[4][5];
    char prev = 0;
    char empty = 0;

    for (; i < 4; i++) {
      fscanf(fp, "%s", &map[i]);
      prev = (map[i][0] == 'T') ? 0 : map[i][0];
      for (j = 0; j < 4; j++) {
        char x = map[i][j];
        if (prev > 0) {
          if (prev != x && x != 'T') {
            prev = -1;
          }
        } else if (x != 'T' && prev == 0) {
          prev = x;
        }
        if (x == '.')
          empty = 1;
      }
      if (prev > 0 && prev != '.') {
        i++;
        break;
      }
    }
    while (i < 4) {
      fscanf(fp, "%s", dummy);

      i++;
    }

    if (prev <= 0 || prev == '.') {
      for (i = 0; i < 4; i++) {
        prev = (map[0][i] == 'T') ? 0 : map[0][i];

        for (j = 1; j < 4; j++) {
          char x = map[j][i];

          if (prev > 0) {
            if (prev != x && x != 'T') {
              prev = -1;
            }
          } else if (x != 'T' && prev == 0) {
            prev = x;
          }
        }

        if (prev > 0 && prev != '.') {
          break;
        }
      }
    }

    if (prev <= 0 || prev == '.') {
      prev = 0;
      for (i = 0; i < 4; i++) {
        char x = map[i][i];

        if (prev > 0) {
          if (prev != x && x != 'T') {
            prev = -1;
          }
        } else if (x != 'T' && prev == 0) {
          prev = x;
        }
      }
    }

    if (prev <= 0 || prev == '.') {
      prev = 0;
      for (i = 0; i < 4; i++) {
        char x = map[i][3 - i];

        if (prev > 0) {
          if (prev != x && x != 'T') {
            prev = -1;
          }
        } else if (x != 'T' && prev == 0) {
          prev = x;
        }
      }
    }

    if (prev > 0 && prev != '.') {
      fprintf(fo, "Case #%d: %c won\n", c, prev);
    } else {
      fprintf(fo, "Case #%d: %s\n", c,
              (empty) ? "Game has not completed" : "Draw");
    }
  }

  return 0;
}
