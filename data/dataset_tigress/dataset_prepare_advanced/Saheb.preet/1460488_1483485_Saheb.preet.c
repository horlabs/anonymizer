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

char googlerese(char);

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  char a[105];
  int i;
  int t;
  int j;

  FILE *fpin;
  FILE *fpout;

  fpin = fopen("A-small-attempt2.in", "r");
  if (fpin == NULL)
    printf("error");
  fpout = fopen("output1.out", "a");
  fscanf(fpin, "%d", &t);
  fgets(a, 2, fpin);
  for (j = 0; j < t; j++) {
    fprintf(fpout, "Case #%d: ", j + 1);
    fgets(a, 105, fpin);
    for (i = 0; i < strlen(a) - 1; i++) {
      fprintf(fpout, "%c", googlerese(a[i]));
    }
    fprintf(fpout, "\n", a);
  }
}

char googlerese(char p) {
  int i;
  char a[] = "our language is impossible to understand there are twenty six "
             "factorial possibilities so it is okay if you want to just give "
             "up";
  char b[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh "
             "wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc "
             "jv";
  if (p == 'z')
    return 'q';
  if (p == 'q')
    return 'z';
  for (i = 0; i < strlen(b); i++) {
    if (p == b[i])
      break;
  }
  return a[i];
}
