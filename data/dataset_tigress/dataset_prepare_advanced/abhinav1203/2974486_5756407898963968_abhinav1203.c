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
  int test = 1;
  int R1;
  int R2;
  int i;
  int j;
  int answer;
  int tmp;
  int h[17];

  scanf("%d", &T);
  while (T--) {
    scanf("%d", &R1);
    for (i = 1; i <= 16; i++)
      h[i] = false;
    for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++) {
        scanf("%d", &tmp);
        if (i == R1 - 1)
          h[tmp] = true;
      }

    scanf("%d", &R2);
    answer = -1;
    for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++) {
        scanf("%d", &tmp);
        if (i == R2 - 1) {
          if (h[tmp] && answer != -1)
            answer = -2;
          else if (h[tmp] && answer == -1)
            answer = tmp;
        }
      }
    printf("Case #%d: ", test++);
    if (answer == -2)
      printf("Bad Magician!\n");
    else if (answer == -1)
      printf("Volunteer cheated!\n");
    else
      printf("%d\n", answer);
  }
  return 0;
}
