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
  int ntest;
  int i;
  int j;
  int nparticipant;
  int nsurprising;
  int bscore;
  int pscore;

  int ngoogle[100] = {0};
  int sjscore;
  int remaining;
  scanf("%d", &ntest);

  for (i = 0; i < ntest; i++) {
    scanf("%d", &nparticipant);
    scanf("%d", &nsurprising);
    scanf("%d", &bscore);

    for (j = 0; j < nparticipant; j++) {
      scanf("%d", &pscore);
      sjscore = pscore / 3;
      remaining = pscore % 3;

      if (sjscore == 0 && remaining == 0 && bscore != 0)
        continue;
      if (sjscore >= bscore)
        ngoogle[i]++;
      else if (remaining == 0 && nsurprising > 0 && sjscore + 1 >= bscore &&
               sjscore + 1 <= 10) {

        ngoogle[i]++;
        nsurprising--;
      } else if (remaining == 1 && sjscore + 1 >= bscore && sjscore + 1 <= 10) {

        ngoogle[i]++;
      } else if (remaining == 2) {

        if (sjscore + 1 >= bscore)
          ngoogle[i]++;
        else if (nsurprising > 0 && sjscore + 2 >= bscore &&
                 sjscore + 2 <= 10) {
          nsurprising--;
          ngoogle[i]++;
        }
      }
    }
  }

  for (i = 0; i < ntest; i++) {
    printf("Case #%d: %d\n", i + 1, ngoogle[i]);
  }
}
