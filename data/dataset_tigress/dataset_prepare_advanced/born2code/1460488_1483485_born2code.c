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

char hash(char x) {
  switch (x) {
  case 'a':
    return 'y';
  case 'b':
    return 'h';
  case 'c':
    return 'e';
  case 'd':
    return 's';
  case 'e':
    return 'o';
  case 'f':
    return 'c';
  case 'g':
    return 'v';
  case 'h':
    return 'x';
  case 'i':
    return 'd';
  case 'j':
    return 'u';
  case 'k':
    return 'i';
  case 'l':
    return 'g';
  case 'm':
    return 'l';
  case 'n':
    return 'b';
  case 'o':
    return 'k';
  case 'p':
    return 'r';
  case 'q':
    return 'z';
  case 'r':
    return 't';
  case 's':
    return 'n';
  case 't':
    return 'w';
  case 'u':
    return 'j';
  case 'v':
    return 'p';
  case 'w':
    return 'f';
  case 'x':
    return 'm';
  case 'y':
    return 'a';
  case 'z':
    return 'q';
  }
  return ' ';
}
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int n;
  int i;
  int j;
  int k;

  char l[200];
  char m[200];

  scanf("%d", &n);
  scanf("%*c");
  for (i = 1; i <= n; i++) {
    gets(l);
    for (j = 0; l[j] != '\0'; j++) {
      m[j] = hash(l[j]);
    }
    m[j] = '\0';
    printf("Case #%d: %s\n", i, m);
  }
  return 0;
}
