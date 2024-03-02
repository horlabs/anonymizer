#include <stdio.h>

int main() {
  int ret_val = 0;
  char redc_Var[26] = {'y', 'n', 'f', 'i', 'c', 'w', 'l', 'b', 'k',
                       'u', 'o', 'm', 'x', 's', 'e', 'v', 'z', 'p',
                       'd', 'r', 'j', 'g', 't', 'h', 'a', 'q'},
       cbvc_Var, ch, cs = 0, ekpc_Var;
  FILE *fqlF_Var, *ryfF_Var;
  fqlF_Var = fopen("A-small-attempt1.in", "r");
  ryfF_Var = fopen("output.txt", "w");
  fscanf(fqlF_Var, "%d", &ekpc_Var);
  for (; (ch = getc(fqlF_Var)) != EOF;) {
    if (ch == '\n') {
      cs++;
      if (cs != 1)
        putc(ch, ryfF_Var);
      if (cs != ekpc_Var + 1)
        fprintf(ryfF_Var, "Case #%d: ", cs);
    }

    if (ch == ' ')
      putc(ch, ryfF_Var);
    else {
      {
        char ooxc_Var = 0;
        while (ooxc_Var < 26) {
          if (ch == redc_Var[ooxc_Var])
            putc((ooxc_Var + 'a'), ryfF_Var);
          ooxc_Var++;
        }
      }
    }
  }
  fclose(fqlF_Var);
  fclose(ryfF_Var);
  return ret_val;
}
