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
  int t;
  int a;
  int b;
  int magic[4];
  int i;
  int j;
  int temp;
  int k;
  int l;

  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d", &a);
    for (j = 0; j < (a - 1) * 4; j++)
      scanf("%d", &temp);
    for (; j < 4 * a; j++)
      scanf("%d", &magic[j - (a - 1) * 4]);
    for (; j < 16; j++)
      scanf("%d", &temp);
    scanf("%d", &a);
    for (j = 0; j < (a - 1) * 4; j++)
      scanf("%d", &temp);
    l = -1;
    for (; j < a * 4; j++) {
      scanf("%d", &temp);
      for (k = 0; k < 4; k++)
        if (temp == magic[k])
          if (l == -1)
            l = magic[k];
          else
            l = 0;
    }
    for (; j < 16; j++)
      scanf("%d", &temp);
    printf("Case #%d: ", i + 1);
    switch (l) {
    case -1:
      puts("Volunteer cheated!");
      break;
    case 0:
      puts("Bad magician!");
      break;
    default:
      printf("%d\n", l);
    }
  }
  return 0;
}
