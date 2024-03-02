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

char a[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
char b[] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
char c[] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";

char d[] = "our language is impossible to understand";
char e[] = "there are twenty six factorial possibilities";
char f[] = "so it is okay if you want to just give up";

int map[256];

void makemap(char *s, char *t) {
  while (*s)
    map[(int)*(s++)] = *(t++);
}

char s[16384];

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int caseno = 1;
  int T;
  int i;

  memset(map, 0, sizeof(map));
  makemap(a, d);
  makemap(b, e);
  makemap(c, f);
  map['q'] = 'z';
  map['z'] = 'q';
  gets(s);
  sscanf(s, "%d", &T);
  while (T--) {
    gets(s);
    for (i = 0; s[i]; i++)
      s[i] = map[(int)s[i]];
    printf("Case #%d: %s\n", caseno++, s);
  }
  return 0;
}
