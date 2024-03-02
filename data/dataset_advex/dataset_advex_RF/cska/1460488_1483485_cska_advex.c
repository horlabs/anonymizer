#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char buffer[128], abc[] = {"yhesocvxduiglbkrztnwjpfmaq"};
  int T;
  FILE *fin = fopen("A-small-attempt0.in", "r"), *fout = fopen("out.txt", "w");

  fscanf(fin, "%d\n", &T);

  for (int ceti_Var = 0; ceti_Var < T; ceti_Var++) {

    fgets(buffer, 128, fin);

    fprintf(fout, "Case #%d: ", ceti_Var + 1);
    {
      int jffi_Var = 0;
      while (buffer[jffi_Var] != 0) {
        fputc(islower(buffer[jffi_Var]) ? abc[buffer[jffi_Var] - 'a']
                                        : buffer[jffi_Var],
              fout);
        jffi_Var++;
      }
    }
  }

  fclose(fin);
  fclose(fout);
  return 0;
}
