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
  FILE *fp;
  FILE *o;

  fp = (argc <= 1) ? fopen("input.txt", "r+") : fopen(argv[1], "r+");
  o = fopen("output.txt", "w+");

  if (fp) {
    int T;
    int i;
    int j;
    int k;

    fscanf(fp, "%d", &T);
    for (i = 0; i < T; i++) {
      int ar;
      int grid[4];
      int grid2[4];
      int ignore;

      int matchCount = -1;
      int index = -1;

      long long score = 0;

      fscanf(fp, "%d", &ar);

      for (j = 0; j < 4; j++) {
        if (j == ar - 1) {
          fscanf(fp, "%d %d %d %d", &grid[0], &grid[1], &grid[2], &grid[3]);

        } else {
          fscanf(fp, "%d %d %d %d", &ignore, &ignore, &ignore, &ignore);
        }
      }
      fscanf(fp, "%d", &ar);

      for (j = 0; j < 4; j++) {
        if (j == ar - 1) {
          fscanf(fp, "%d %d %d %d", &grid2[0], &grid2[1], &grid2[2], &grid2[3]);

        } else {
          fscanf(fp, "%d %d %d %d", &ignore, &ignore, &ignore, &ignore);
        }
      }

      for (j = 0; j < 4; j++) {
        for (k = 0; k < 4; k++) {
          if (grid[j] == grid2[k]) {
            matchCount++;
            if (index == -1)
              index = j;
            else
              break;
          }
        }
        if (matchCount > 0)
          break;
      }
      fprintf(o, "Case #%d: ", i + 1);
      if (matchCount == 0) {
        fprintf(o, "%d\n", grid[index]);
      } else if (matchCount < 0) {
        fprintf(o, "%s\n", "Volunteer cheated!");
      } else if (matchCount > 0) {
        fprintf(o, "%s\n", "Bad magician!");
      }
    }
  }

  return 0;
}
