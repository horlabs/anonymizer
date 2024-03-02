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
  int T;
  int t;

  scanf("%d\n", &T);
  for (t = 1; t <= T; t++) {
    int A;
    int B;

    scanf("%d %d\n", &A, &B);
    int ret = 0;

    int i;
    for (i = A; i <= B; i++) {

      char i_str_org[100];
      char i_str[100];

      int i_str_len;

      sprintf(i_str_org, "%d", i);
      i_str_len = strlen(i_str_org);
      strcpy(i_str, i_str_org);
      while (1) {

        char c0 = i_str[i_str_len - 1];
        memmove(&i_str[1], &i_str[0], sizeof(char) * (i_str_len - 1));
        i_str[0] = c0;

        if (strcmp(i_str, i_str_org) == 0)
          break;

        if (i_str[0] == '0')
          continue;

        int i2 = atoi(i_str);

        if (A <= i2 && i2 <= B) {

          ret++;
        }
      }
    }
    (ret % 2 == 0);
    printf("Case #%d: %d\n", t, ret / 2);
  }
  return 0;
}
