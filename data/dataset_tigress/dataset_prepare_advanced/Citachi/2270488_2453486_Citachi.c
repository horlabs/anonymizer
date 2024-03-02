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
  FILE *fp_in;
  FILE *fp_out;

  int i;
  int j;
  int T;
  int flag_x;
  int flag_o;
  int flagd_x;
  int flagd_o;
  int c;
  int flag = 0;

  char t[4][4];
  fp_in = fopen("A-small-attempt1(1).in", "r");
  fp_out = fopen("output.txt", "w");
  fscanf(fp_in, "%d", &T);

  for (c = 1; c <= T; c++) {
    for (i = 0; i < 4; i++)
      fscanf(fp_in, "%s", t[i]);
    flag = 0;
    flagd_x = flagd_o = 4;
    for (i = 0; i < 4; i++) {
      flag_x = flag_o = 4;
      for (j = 0; j < 4; j++) {
        if (t[i][j] == 'X' || t[i][j] == 'T')
          flag_x -= 1;
        if (t[i][j] == 'O' || t[i][j] == 'T')
          flag_o -= 1;
        if (i == j) {
          if (t[i][j] == 'X' || t[i][j] == 'T')
            flagd_x -= 1;
          else if (t[i][j] == 'O' || t[i][j] == 'T')
            flagd_o -= 1;
        }
      }
      if (flag_x == 0) {
        fprintf(fp_out, "Case #%d: X won\n", c);
        break;
      } else if (flag_o == 0) {
        fprintf(fp_out, "Case #%d: O won\n", c);
        break;
      }
    }
    if (flagd_x == 0) {
      fprintf(fp_out, "Case #%d: X won\n", c);
      continue;
    } else if (flagd_o == 0) {
      fprintf(fp_out, "Case #%d: O won\n", c);
      continue;

    } else if (flag_x == 0 || flag_o == 0)
      continue;
    flagd_x = flagd_o = 4;
    for (j = 0; j < 4; j++) {
      flag_x = flag_o = 4;
      for (i = 0; i < 4; i++) {
        if (t[i][j] == 'X' || t[i][j] == 'T')
          flag_x -= 1;
        if (t[i][j] == 'O' || t[i][j] == 'T')
          flag_o -= 1;
        if (t[i][j] == '.') {
          flag = 1;
        }
        if ((i + j) == 3) {
          if (t[i][j] == 'X' || t[i][j] == 'T')
            flagd_x -= 1;
          if (t[i][j] == 'O' || t[i][j] == 'T')
            flagd_o -= 1;
        }
      }
      if (flag_x == 0) {
        fprintf(fp_out, "Case #%d: X won\n", c);
        break;
      } else if (flag_o == 0) {
        fprintf(fp_out, "Case #%d: O won\n", c);
        break;
      }
    }
    if (flagd_x == 0) {
      fprintf(fp_out, "Case #%d: X won\n", c);
      continue;
    } else if (flagd_o == 0) {
      fprintf(fp_out, "Case #%d: O won\n", c);
      continue;

    } else if (flag_x == 0 || flag_o == 0)
      continue;
    if (flag == 1)
      fprintf(fp_out, "Case #%d: Game has not completed\n", c);
    else
      fprintf(fp_out, "Case #%d: Draw\n", c);
  }
  fclose(fp_in);
  fclose(fp_out);
  system("pause");
}
