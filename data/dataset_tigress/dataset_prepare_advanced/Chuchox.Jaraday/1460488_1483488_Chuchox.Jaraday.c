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
  int cases;
  int min;
  int max;
  int num;
  int cand;

  int ndigit;
  int potencia;
  int temp;

  int i;
  int j;
  int total;

  int k;
  int enc;
  int nenc;

  int encontrados[10];
  scanf("%d", &cases);
  for (i = 1; i <= cases; i++) {
    scanf("%d", &min);
    scanf("%d", &max);

    j = max;
    ndigit = 0;
    potencia = 1;
    while (j) {
      j /= 10;
      ndigit++;
      potencia *= 10;
    }
    potencia /= 10;

    total = 0;
    for (num = min; num < max; num++) {
      cand = num;
      k = nenc = 0;
      for (j = 1; j < ndigit; j++) {
        temp = cand % 10;
        cand /= 10;
        cand += (temp * potencia);
        if ((num < cand) && (cand <= max)) {
          enc = 1;
          for (k = 0; k < nenc; k++) {
            if (cand == encontrados[k]) {
              enc = 0;
            }
          }
          if (enc) {
            encontrados[nenc] = cand;
            nenc++;
            total++;
          }
        }
      }
    }
    printf("Case #%d: %d\n", i, total);
  }
  return 0;
}
