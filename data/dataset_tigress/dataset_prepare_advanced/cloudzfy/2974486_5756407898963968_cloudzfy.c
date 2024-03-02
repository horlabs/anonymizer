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

int data[16];
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  freopen("A-small-attempt0.in.txt", "r", stdin);
  freopen("A-small-attempt0.out.txt", "w", stdout);
  int t;
  int T;
  int A1;
  int A2;
  int card;
  int ans;

  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    memset(data, 0, sizeof(data));
    scanf("%d", &A1);
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        scanf("%d", &card);
        if (i == A1 - 1) {
          data[card - 1]++;
        }
      }
    }
    scanf("%d", &A2);
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        scanf("%d", &card);
        if (i == A2 - 1) {
          data[card - 1]++;
        }
      }
    }
    ans = 0;
    for (int i = 0; i < 16; i++) {
      if (data[i] == 2 && ans == 0) {
        ans = i + 1;
      } else if (data[i] == 2 && ans != 0) {
        ans = -1;
      }
    }
    printf("Case #%d: ", t);
    if (ans == 0) {
      printf("Volunteer cheated!\n");
    } else if (ans == -1) {
      printf("Bad magician!\n");
    } else {
      printf("%d\n", ans);
    }
  }
}
