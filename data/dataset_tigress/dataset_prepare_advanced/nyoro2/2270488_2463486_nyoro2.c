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
  int i;
  int t;
  long long num_a;
  long long num_b;
  long long num_x;
  long k;
  long k_min;
  long k_max;
  char num_buf[16];
  int l;
  int l_max;

  int m;
  int m_max;

  int result;

  scanf("%d\n", &t);
  for (i = 0; i < t; i++) {
    scanf("%lld %lld", &num_a, &num_b);

    printf("Case #%d: ", i + 1);
    k_min = sqrt((double)num_a) - 1;
    k_max = sqrt((double)num_b) - 1;

    num_x = k_min + 1;
    num_x = num_x * num_x;
    if (num_x < num_a) {
      k_min++;
      num_x += (k_min * 2 + 1);
    }
    result = 0;

    for (k = k_min + 1; k <= k_max + 1; k++) {
      sprintf(num_buf, "%lld", num_x);
      l_max = strlen(num_buf);
      for (l = 0; l < l_max / 2; l++) {
        if (num_buf[l] != num_buf[l_max - l - 1])
          break;
      }
      if (l >= l_max / 2) {
        sprintf(num_buf, "%ld", k);
        m_max = strlen(num_buf);
        for (m = 0; m < m_max / 2; m++) {
          if (num_buf[m] != num_buf[m_max - m - 1])
            break;
        }
        if (m >= m_max / 2) {

          result++;
        }
      }
      num_x += (k * 2 + 1);
    }
    printf("%d", result);
    printf("\n");
  }

  return 0;
}
