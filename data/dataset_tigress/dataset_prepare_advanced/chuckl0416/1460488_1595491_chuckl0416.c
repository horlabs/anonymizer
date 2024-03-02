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

void Merge(int A[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1 + 1];
  int R[n2 + 1];

  int i;
  int j;
  int k;

  for (i = 0; i < n1; i++)
    L[i] = A[p + i];
  for (j = 0; j < n2; j++)
    R[j] = A[q + j + 1];

  i = 0;
  j = 0;
  for (k = p; k <= r; k++) {
    if (i < n1 && j < n2) {
      if (L[i] <= R[j]) {
        A[k] = L[i];
        i++;
      } else {
        A[k] = R[j];
        j++;
      }
    } else if (i < n1) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
}

void Partition(int A[], int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    Partition(A, p, q);
    Partition(A, q + 1, r);
    Merge(A, p, q, r);
  }
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  FILE *fin;
  FILE *fout;

  fin = freopen("B-small-attempt0.in", "r", stdin);
  fout = freopen("B-small-attempt0.out", "w", stdout);

  int TestCases;
  int t;
  int i;

  scanf("%d", &TestCases);
  int Number;
  int Surprise;
  int StdScore;
  int Answer;
  int Score[100000];
  int Highest;

  for (t = 1; t <= TestCases; t++) {
    Answer = 0;
    scanf("%d%d%d", &Number, &Surprise, &StdScore);
    for (i = 0; i < Number; i++)
      scanf("%d", &Score[i]);
    Partition(Score, 0, Number - 1);

    for (i = Number - 1; i >= 0; i--) {
      if (Score[i] == 0) {
        if (StdScore == 0)
          Answer++;
        continue;
      }

      if ((Score[i] % 3) == 0) {
        Highest = Score[i] / 3;
        if (Highest >= StdScore) {
          Answer++;
        } else if (Surprise) {
          Highest++;
          if (Highest >= StdScore) {
            Answer++;
            Surprise--;
          }
        }
        continue;
      }

      if ((Score[i] % 3) == 1) {
        Highest = (Score[i] + 2) / 3;
        if (Highest >= StdScore)
          Answer++;
        continue;
      }

      if ((Score[i] % 3) == 2) {
        Highest = (Score[i] + 1) / 3;
        if (Highest >= StdScore) {
          Answer++;
        } else if (Surprise) {
          Highest++;
          if (Highest >= StdScore) {
            Answer++;
            Surprise--;
          }
        }
        continue;
      }
    }

    printf("Case #%d: %d\n", t, Answer);
  }

  fclose(fin);
  fclose(fout);

  return 0;
}
