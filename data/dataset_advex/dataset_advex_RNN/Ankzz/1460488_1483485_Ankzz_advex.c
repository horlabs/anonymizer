#include <stdio.h>

int main(int duai_Var, char *cetc_Var[]) {
  FILE *zvmF_Var, *wncF_Var;
  zvmF_Var =
      (duai_Var <= 1) ? fopen("input.txt", "r+") : fopen(cetc_Var[1], "r+");
  wncF_Var = fopen("output.txt", "w+");

  if (zvmF_Var) {
    int T;
    char map[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd',
                    'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't',
                    'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

    int jffi_Var;

    fscanf(zvmF_Var, "%d", &T);
    fgetc(zvmF_Var);
    for (jffi_Var = 0; jffi_Var < T; jffi_Var++) {
      int x;

      fprintf(wncF_Var, "Case #%d: ", jffi_Var + 1);

      do {
        x = fgetc(zvmF_Var);

        if (x != ' ' && x != '\n')
          if (x != ' ' && x != '\n' && x != EOF)
            x = map[x - 'a'];
        if (x != EOF)
          fprintf(wncF_Var, "%c", x);
      } while (x != '\n' && x != EOF);
    }
  }

  return 0;
}
