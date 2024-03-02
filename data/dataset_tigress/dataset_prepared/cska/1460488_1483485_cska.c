#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  char buffer[128], abc[] = {"yhesocvxduiglbkrztnwjpfmaq"};
  int i, j, T;
  FILE *fin = fopen("A-small-attempt0.in", "r"), *fout = fopen("out.txt", "w");

  fscanf(fin, "%d\n", &T);

  for (i = 0; i < T; i++) {

    fgets(buffer, 128, fin);

    fprintf(fout, "Case #%d: ", i + 1);
    for (j = 0; buffer[j] != 0; j++)
      fputc(islower(buffer[j]) ? abc[buffer[j] - 'a'] : buffer[j], fout);
  }

  fclose(fin);
  fclose(fout);
  return 0;
}
