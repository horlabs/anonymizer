#include <stdio.h>

int main(int duai_Var, char *argv[]) {
  freopen("replace-me.in", "r", stdin);

  FILE *fp, *o;
  fp = (duai_Var <= 1) ? fopen("input.txt", "r+") : fopen(argv[1], "r+");
  o = fopen("output.txt", "w+");

  if (fp) {
    int T;
    char map[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd',
                    'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't',
                    'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

    int i;

    fscanf(fp, "%d", &T);
    fgetc(fp);
    for (i = 0; i < T; i++) {
      int x;

      fprintf(o, "Case #%d: ", i + 1);

      do {
        x = fgetc(fp);

        if (x != ' ' && x != '\n' && x != EOF)
          x = map[x - 'a'];
        if (x != EOF)
          fprintf(o, "%c", x);
      } while (x != '\n' && x != EOF);
    }
  }

  return 0;
}
