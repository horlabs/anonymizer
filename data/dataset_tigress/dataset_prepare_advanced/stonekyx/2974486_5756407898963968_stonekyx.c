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
  int Tcnt = 0;

  for (scanf("%d", &T); T; T--) {
    int row1;
    int row2;

    int map1[4][4];
    int map2[4][4];

    static int count[16];
    int ans;
    int i;
    scanf("%d", &row1);
    for (i = 0; i < 4; i++) {
      int j;
      for (j = 0; j < 4; j++) {
        scanf("%d", map1[i] + j);
      }
    }
    scanf("%d", &row2);
    for (i = 0; i < 4; i++) {
      int j;
      for (j = 0; j < 4; j++) {
        scanf("%d", map2[i] + j);
      }
    }
    memset(count, 0, sizeof(count));
    for (i = 0; i < 4; i++) {
      count[map1[row1 - 1][i] - 1]++;
      count[map2[row2 - 1][i] - 1]++;
    }
    ans = -1;
    for (i = 0; i < 16; i++) {
      if (count[i] == 2) {
        if (ans != -1) {
          ans = -2;
          break;
        }
        ans = i;
      }
    }
    printf("Case #%d: ", ++Tcnt);
    if (ans == -1)
      puts("Volunteer cheated!");
    else if (ans == -2)
      puts("Bad magician!");
    else
      printf("%d\n", ans + 1);
  }
  return 0;
}
