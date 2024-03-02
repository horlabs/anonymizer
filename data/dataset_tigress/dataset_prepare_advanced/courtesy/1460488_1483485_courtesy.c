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

FILE *f1;
FILE *f2;
char map[26];
void st() {
  map[0] = 'y';
  map[1] = 'n';
  map[2] = 'f';
  map[3] = 'i';
  map[4] = 'c';
  map[5] = 'w';
  map[6] = 'l';
  map[7] = 'b';
  map[8] = 'k';
  map[9] = 'u';
  map[10] = 'o';
  map[11] = 'm';
  map[12] = 'x';
  map[13] = 's';
  map[14] = 'e';
  map[15] = 'v';
  map[16] = 'z';
  map[17] = 'p';
  map[18] = 'd';
  map[19] = 'r';
  map[20] = 'j';
  map[21] = 'g';
  map[22] = 't';
  map[23] = 'h';
  map[24] = 'a';
  map[25] = 'q';
}
char re(char c) {
  int i;
  for (i = 0; i < 26; i++) {
    if (map[i] == c)
      return (i + 'a');
  }
  return (' ');
}
void Main() {
  char c;
  char ch;
  char str[500];
  char co = 0;

  int i;

  c = fgetc(f1);
  while (c != '\n') {
    str[co++] = c;
    c = fgetc(f1);
  }
  for (i = 0; i < co; i++)
    str[i] = re(str[i]);
  str[co] = '\0';
  fprintf(f2, "%s", str);
}
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  f1 = fopen("/home/vivek/Desktop/s.in", "r");
  f2 = fopen("/home/vivek/Desktop/s.out", "w");
  int cs;
  int i;

  char c;
  st();
  fscanf(f1, "%d", &cs);
  while (fgetc(f1) != '\n')
    ;
  for (i = 1; i <= cs; i++) {
    fprintf(f2, "Case #%d: ", i);
    Main();
    c = '\n';
    fputc(c, f2);
    printf("%d", i);
  }
  return (1);
}
