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

  FILE *fp = fopen("B-small-attempt3.in", "r");

  FILE *fo = fopen("output.txt", "w");

  fscanf(fp, "%d", &T);

  while (++c <= T) {
    int x;
    int y;

    int i;
    int j;

    short sane = 1;
    int m[100][100];
    fscanf(fp, "%d %d", &x, &y);

    for (i = 0; i < x; i++) {
      int prev = -1;
      for (j = 0; j < y; j++) {
        int p;
        fscanf(fp, "%d", &p);
        m[i][j] = p;
        if (sane) {
          if (prev == -1)
            prev = p;
          else {
            if (i != 0 && j != 0 && i != x - 1 && j != y - 1 && p < prev) {
              sane = 0;
            }
          }
        }
      }
    }

    if (sane) {
      for (i = 0; i < x; i++) {
        int prev = -1;
        for (j = 0; j < y; j++) {
          int p = m[j][i];
          if (prev == -1)
            prev = p;
          else {
            if (i != 0 && j != 0 && i != x - 1 && j != y - 1 && p < prev) {
              sane = 0;
              break;
            }
          }
        }
      }
    }

    if (sane) {
      int prev = -1;
      i = 0;
      {
        for (j = 0; j < y; j++) {
          int p = m[i][j];

          if (prev == -1)
            prev = p;
          else {
            if (prev != p) {
              int k = i;
              for (; k < x; k++) {
                if (m[k][j] != p) {
                  sane = 0;
                  break;
                }
              }
            }
          }
        }
      }

      if (sane) {
        j--;
        for (; i < x; i++) {
          int p = m[i][j];

          if (prev == -1)
            prev = p;
          else {
            if (prev != p) {
              int k = j;
              for (; k >= 0; k--) {
                if (m[i][k] != p) {
                  sane = 0;
                  break;
                }
              }
            }
          }
        }
      }

      if (sane) {
        i--;
        for (; j >= 0; j--) {
          int p = m[i][j];

          if (prev == -1)
            prev = p;
          else {
            if (prev != p) {
              int k = i;
              for (; k >= 0; k--) {
                if (m[k][j] != p) {
                  sane = 0;
                  break;
                }
              }
            }
          }
        }
      }

      if (sane) {
        j = 0;
        for (; i > 0; i--) {
          int p = m[i][j];

          if (prev == -1)
            prev = p;
          else {
            if (prev != p) {
              int k = j;
              for (; k < y; k++) {
                if (m[i][k] != p) {
                  sane = 0;
                  break;
                }
              }
            }
          }
        }
      }
    }

    fprintf(fo, "Case #%d: %s\n", c, (sane) ? "YES" : "NO");
  }

  return 0;
}
