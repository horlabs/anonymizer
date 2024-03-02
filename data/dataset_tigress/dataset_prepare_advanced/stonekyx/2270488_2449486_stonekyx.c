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

int N;
int M;
int map[110][110];
int real[110][110];
struct rec_t {
  int x, y;
} rec[11000];
int rcnt;
int locked[110][110];

int compare_record(const void *a, const void *b) {
  struct rec_t *na = (struct rec_t *)a;
  struct rec_t *nb = (struct rec_t *)b;

  return map[nb->x][nb->y] - map[na->x][na->y];
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
    int i;
    rcnt = 0;
    scanf("%d%d", &N, &M);
    for (i = 0; i < N; i++) {
      int j;
      for (j = 0; j < M; j++) {
        scanf("%d", map[i] + j);
        rec[rcnt].x = i;
        rec[rcnt].y = j;
        rcnt++;
        real[i][j] = 100;
      }
    }
    qsort(rec, rcnt, sizeof(struct rec_t), compare_record);
    memset(locked, 0, sizeof(locked));
    for (i = 0; i < rcnt; i++) {
      int j;
      int hei = map[rec[i].x][rec[i].y];

      for (j = 0; j < N; j++) {
        if (real[j][rec[i].y] > hei && locked[j][rec[i].y])
          break;
      }
      if (j >= N) {
        for (j = 0; j < N; j++) {
          if (real[j][rec[i].y] > hei) {
            real[j][rec[i].y] = hei;
          }
        }
      } else {
        for (j = 0; j < M; j++) {
          if (real[rec[i].x][j] > hei && locked[rec[i].x][j])
            break;
        }
        if (j >= M) {
          for (j = 0; j < M; j++) {
            if (real[rec[i].x][j] > hei) {
              real[rec[i].x][j] = hei;
            }
          }
        } else {
          break;
        }
      }
      locked[rec[i].x][rec[i].y] = 1;
    }
    printf("Case #%d: ", ++Tcnt);
    if (i >= rcnt) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
