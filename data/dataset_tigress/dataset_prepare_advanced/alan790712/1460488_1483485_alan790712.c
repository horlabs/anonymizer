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

char str[1234567];
char trans[256];
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int i;
  int j;

  for (i = 0; i < 256; ++i) {
    trans[i] = i;
  }
  trans['a'] = 'y';
  trans['b'] = 'h';
  trans['c'] = 'e';
  trans['d'] = 's';
  trans['e'] = 'o';
  trans['f'] = 'c';
  trans['g'] = 'v';
  trans['h'] = 'x';
  trans['i'] = 'd';
  trans['j'] = 'u';
  trans['k'] = 'i';
  trans['l'] = 'g';
  trans['m'] = 'l';
  trans['n'] = 'b';
  trans['o'] = 'k';
  trans['p'] = 'r';
  trans['q'] = 'z';
  trans['r'] = 't';
  trans['s'] = 'n';
  trans['t'] = 'w';
  trans['u'] = 'j';
  trans['v'] = 'p';
  trans['w'] = 'f';
  trans['x'] = 'm';
  trans['y'] = 'a';
  trans['z'] = 'q';

  scanf("%d", &t);
  gets(str);

  for (i = 1; i <= t; ++i) {
    gets(str);
    printf("Case #%d: ", i);
    for (j = 0; str[j] != '\0'; ++j) {
      putchar(trans[str[j]]);
    }
    puts("");
  }

  return 0;
}
