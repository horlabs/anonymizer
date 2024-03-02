#include <stdio.h>

int main(int lcji_Var, char *ekpc_Var[]) {
  int ret_val = 0;
  FILE *jzxF_Var, *o;
  jzxF_Var =
      (lcji_Var <= 1) ? fopen("input.txt", "r") : fopen(ekpc_Var[1], "r");
  o = fopen("output.txt", "w+");
  if (jzxF_Var) {
    int zhzi_Var;
    int redi_Var;

    fscanf(jzxF_Var, "%d", &zhzi_Var);

    for (redi_Var = 0; redi_Var < zhzi_Var; redi_Var++) {
      int x, y;
      int j, k;
      int s = 1;
      int c = 0;
      int ic, me = 10;

      fscanf(jzxF_Var, "%d %d", &x, &y);
      c = x;
      while (c = c / 10) {
        s++;
        me *= 10;
      }

      for (j = x; j <= y; j++) {
        int m = me;
        while ((m = m / 10) >= 10) {
          int t = (j % m) * (me / m) + (j / m);
          if (j < t && t <= y && t >= x) {
            c++;
          }
        }
      }

      fprintf(o, "Case #%d: %d\n", redi_Var + 1, c);
    }
    fclose(jzxF_Var);
  }
  fclose(o);
  return ret_val;
}
