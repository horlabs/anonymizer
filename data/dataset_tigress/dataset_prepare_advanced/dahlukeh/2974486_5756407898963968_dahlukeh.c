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

int an;
int grid[101][101];

int isValid1[101];
int isValid2[101];

void find(int *ar) {
  int i;
  for (i = 1; i <= 16; i++) {
    ar[i] = 0;
  }
  for (i = 0; i < 4; i++) {
    ar[grid[an - 1][i]] = 1;
  }
}

void handle() {
  int i;
  int j;

  scanf("%d ", &an);
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      scanf("%d ", &grid[i][j]);
    }
  }
  find(isValid1);
  scanf("%d ", &an);
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      scanf("%d ", &grid[i][j]);
    }
  }
  find(isValid2);
  int found = 0;
  int mult = 0;
  int ans = 0;
  for (i = 1; i <= 16; i++) {
    if (isValid1[i] && isValid2[i]) {
      if (found) {
        mult = 1;
      }
      found = 1;
      ans = i;
    }
  }
  if (!found) {
    printf("Volunteer cheated!\n");
  } else if (mult) {
    printf("Bad magician!\n");
  } else {
    printf("%d\n", ans);
  }
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int i;

  scanf("%d ", &t);
  for (i = 0; i < t; i++) {
    printf("Case #%d: ", i + 1);
    handle();
  }
  return 0;
}