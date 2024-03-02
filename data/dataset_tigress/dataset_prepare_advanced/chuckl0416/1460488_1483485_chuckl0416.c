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
  FILE *fin;
  FILE *fout;

  fin = freopen("A-small-attempt1.in", "r", stdin);
  fout = freopen("A-small-attempt1.out", "w", stdout);

  int Testcases;
  int t;

  char Line[100000];
  scanf("%d", &Testcases);
  int i;
  int L;

  getchar();
  for (t = 1; t <= Testcases; t++) {
    printf("Case #%d: ", t);
    gets(Line);
    i = 0;
    L = strlen(Line);

    for (i = 0; i < L; i++) {
      if (isalpha(Line[i]))
        switch (Line[i]) {
        case 'a':
          putchar('y');
          break;
        case 'b':
          putchar('h');
          break;
        case 'c':
          putchar('e');
          break;
        case 'd':
          putchar('s');
          break;
        case 'e':
          putchar('o');
          break;
        case 'f':
          putchar('c');
          break;
        case 'g':
          putchar('v');
          break;
        case 'h':
          putchar('x');
          break;
        case 'i':
          putchar('d');
          break;
        case 'j':
          putchar('u');
          break;
        case 'k':
          putchar('i');
          break;
        case 'l':
          putchar('g');
          break;
        case 'm':
          putchar('l');
          break;
        case 'n':
          putchar('b');
          break;
        case 'o':
          putchar('k');
          break;
        case 'p':
          putchar('r');
          break;
        case 'q':
          putchar('z');
          break;
        case 'r':
          putchar('t');
          break;
        case 's':
          putchar('n');
          break;
        case 't':
          putchar('w');
          break;
        case 'u':
          putchar('j');
          break;
        case 'v':
          putchar('p');
          break;
        case 'w':
          putchar('f');
          break;
        case 'x':
          putchar('m');
          break;
        case 'y':
          putchar('a');
          break;
        case 'z':
          putchar('q');
          break;
        }
      else
        putchar(Line[i]);
    }

    putchar(10);
  }

  fclose(fin);
  fclose(fout);

  return 0;
}
