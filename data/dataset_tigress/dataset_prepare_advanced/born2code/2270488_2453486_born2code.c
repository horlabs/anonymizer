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
  int T1;
  int T;
  int dot;
  int x;
  int o;
  int i;
  int j;
  int xc;
  int oc;
  int t;

  char a[4][4];

  T = 1;
  for (scanf("%d", &T1); T <= T1; T++) {
    dot = x = o = 0;
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        do {
          a[i][j] = getchar();
        } while (!(a[i][j] == '.' || a[i][j] == 'T' || a[i][j] == 'O' ||
                   a[i][j] == 'X'));

        if (a[i][j] == '.')
          dot = 1;
      }
    }

    for (i = 0; i < 4; i++) {
      xc = oc = t = 0;
      for (j = 0; j < 4; j++) {
        if (a[i][j] == 'T')
          t = 1;
        else if (a[i][j] == 'X')
          xc++;
        else if (a[i][j] == 'O')
          oc++;
      }
      if ((xc == 4) || (xc == 3 && t == 1))
        x = 1;
      if ((oc == 4) || (oc == 3 && t == 1))
        o = 1;
    }

    for (j = 0; j < 4; j++) {
      xc = oc = t = 0;
      for (i = 0; i < 4; i++) {
        if (a[i][j] == 'T')
          t = 1;
        else if (a[i][j] == 'X')
          xc++;
        else if (a[i][j] == 'O')
          oc++;
      }
      if ((xc == 4) || (xc == 3 && t == 1))
        x = 1;
      if ((oc == 4) || (oc == 3 && t == 1))
        o = 1;
    }
    xc = oc = t = 0;
    for (j = 0; j < 4; j++) {
      if (a[j][j] == 'T')
        t = 1;
      else if (a[j][j] == 'X')
        xc++;
      else if (a[j][j] == 'O')
        oc++;
    }
    if ((xc == 4) || (xc == 3 && t == 1))
      x = 1;
    if ((oc == 4) || (oc == 3 && t == 1))
      o = 1;

    xc = oc = t = 0;
    for (j = 3; j >= 0; j--) {
      if (a[j][3 - j] == 'T')
        t = 1;
      else if (a[j][3 - j] == 'X')
        xc++;
      else if (a[j][3 - j] == 'O')
        oc++;
    }
    if ((xc == 4) || (xc == 3 && t == 1))
      x = 1;
    if ((oc == 4) || (oc == 3 && t == 1))
      o = 1;

    printf("Case #%d: ", T);
    if (x == 1)
      printf("X won\n");
    else if (o == 1)
      printf("O won\n");
    else if (dot == 1)
      printf("Game has not completed\n");
    else
      printf("Draw\n");
  }
  return 0;
}
