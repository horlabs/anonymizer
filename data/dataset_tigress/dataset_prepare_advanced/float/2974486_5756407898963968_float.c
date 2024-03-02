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

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T;
  int t;
  int row;
  int r;
  int tmp;
  int i;

  int num[8];
  int count;
  int ans;

  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    count = 0;
    scanf("%d", &row);
    for (r = 1; r <= 4; r++) {
      if (r == row) {
        scanf("%d %d %d %d", &num[0], &num[1], &num[2], &num[3]);
      } else {
        scanf("%d %d %d %d", &tmp, &tmp, &tmp, &tmp);
      }
    }
    scanf("%d", &row);
    for (r = 1; r <= 4; r++) {
      if (r == row) {
        scanf("%d %d %d %d", &num[4], &num[5], &num[6], &num[7]);
      } else {
        scanf("%d %d %d %d", &tmp, &tmp, &tmp, &tmp);
      }
    }
    qsort(num, 8, sizeof(int), cmp);
    for (i = 1; i < 8; i++) {
      if (num[i] == num[i - 1]) {
        count++;
        ans = num[i];
      }
    }
    printf("Case #%d: ", t);
    switch (count) {
    case 1:
      printf("%d\n", ans);
      break;
    case 0:
      printf("Volunteer cheated!\n");
      break;
    default:
      printf("Bad magician!\n");
      break;
    }
  }
  return 0;
}
