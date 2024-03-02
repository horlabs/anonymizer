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

int oznaka[10000000];

int daj(int n) {
  int x[10] = {0};
  int rez;
  int i;

  while (n) {
    x[n % 10]++;
    n /= 10;
  }
  rez = 0;
  for (i = 9; i >= 0; i--)
    while (x[i]--)
      rez = 10 * rez + i;
  return rez;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T;
  int tt;

  scanf("%d", &T);

  for (tt = 1; tt <= T; tt++) {
    int x;
    int a;
    int b;
    int ukupno = 0;

    int znam = 0;
    int naj = 1;
    scanf("%d %d", &a, &b);
    int aa = a;

    while (aa) {
      znam++;
      naj *= 10;
      aa /= 10;
    }
    naj /= 10;

    for (x = a; x <= b; x++) {
      int red[10];
      int broj = 0;
      int i;

      aa = x;
      for (i = 0; i < znam; i++) {
        aa = naj * (aa % 10) + aa / 10;
        if (aa < x && !oznaka[aa] && aa >= a && aa <= b) {
          oznaka[aa] = 1;
          red[broj++] = aa;
          ukupno++;
        }
      }
      for (i = 0; i < broj; i++)
        oznaka[red[i]] = 0;
    }
    printf("Case #%d: %d\n", tt, ukupno);
  }

  return 0;
}
