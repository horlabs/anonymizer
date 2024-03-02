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

  fp = (argc <= 1) ? fopen("input.txt", "r") : fopen(argv[1], "r");
  o = fopen("output.txt", "w+");

  if (fp) {
    int T;
    int i;

    fscanf(fp, "%d", &T);

    for (i = 0; i < T; i++) {
      int x;
      int y;

      int j;
      int k;

      int s = 1;
      int c = 0;
      int ic;
      int me = 10;

      fscanf(fp, "%d %d", &x, &y);
      c = x;
      while (c = c / 10) {
        s++;
        me *= 10;
      }

      for (j = x; j <= y; j++) {
        int m = me;
        while ((m = m / 10) >= 10) {
          int t = (j % m) * (me / m) + (j / m);
          if (j < t && t <= y && t >= x) {
            c++;
          }
        }
      }

      fprintf(o, "Case #%d: %d\n", i + 1, c);
    }
    fclose(fp);
  }
  fclose(o);
  return 0;
}
