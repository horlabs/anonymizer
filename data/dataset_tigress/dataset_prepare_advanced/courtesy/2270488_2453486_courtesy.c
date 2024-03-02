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
  freopen("C:\\Users\\vivek\\Desktop\\in.txt", "r", stdin);
  freopen("C:\\Users\\vivek\\Desktop\\out.txt", "w", stdout);
  char s[4][5];
  char c;

  int i;
  int j;
  int k;
  int t;
  int cs;
  int f;

  scanf("%d", &t);
  for (cs = 1; cs <= t; cs++) {
    for (i = 0; i < 4; i++)
      scanf("%s", s[i]);
    for (i = 0, k = 0; i < 4; i++) {
      for (j = 0; (j < 4) && ((s[i][j] == 'X') || (s[i][j] == 'T')); j++)
        ;
      if (j == 4) {
        k = 1;
        break;
      }
      for (j = 0; (j < 4) && ((s[i][j] == 'O') || (s[i][j] == 'T')); j++)
        ;
      if (j == 4) {
        k = 2;
        break;
      }
      for (j = 0; (j < 4) && ((s[j][i] == 'X') || (s[j][i] == 'T')); j++)
        ;
      if (j == 4) {
        k = 1;
        break;
      }
      for (j = 0; (j < 4) && ((s[j][i] == 'O') || (s[j][i] == 'T')); j++)
        ;
      if (j == 4) {
        k = 2;
        break;
      }
    }
    if (k == 1)
      printf("Case #%d: X won\n", cs, i);
    else if (k == 2)
      printf("Case #%d: O won\n", cs, i);
    else {
      for (j = 0; (j < 4) && ((s[j][j] == 'X') || (s[j][j] == 'T')); j++)
        ;
      if (j == 4)
        printf("Case #%d: X won\n", cs);
      else {
        for (j = 3, k = 0; (j >= 0) && ((s[j][k] == 'X') || (s[j][k] == 'T'));
             j--, k++)
          ;
        if (k == 4)
          printf("Case #%d: X won\n", cs);
        else {
          for (j = 0; (j < 4) && ((s[j][j] == 'O') || (s[j][j] == 'T')); j++)
            ;
          if (j == 4)
            printf("Case #%d: O won\n", cs);
          else {
            for (j = 3, k = 0;
                 (j >= 0) && ((s[j][k] == 'O') || (s[j][k] == 'T')); j--, k++)
              ;
            if (k == 4)
              printf("Case #%d: O won\n", cs);
            else {
              for (i = 0; i < 4; i++) {
                for (j = 0; (j < 4) && (s[i][j] != '.'); j++)
                  ;
                if (j < 4)
                  break;
              }
              if (i < 4)
                printf("Case #%d: Game has not completed\n", cs);
              else
                printf("Case #%d: Draw\n", cs);
            }
          }
        }
      }
    }
  }
  return 0;
}
