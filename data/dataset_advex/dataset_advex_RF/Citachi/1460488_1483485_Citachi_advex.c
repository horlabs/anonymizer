#include <stdio.h>

typedef FILE td_FILE;
typedef FILE td_FILEF;

typedef FILE td_FI;

typedef FILE td_F;

typedef FILE td_FIL;

int main() {
  int ret_val = 0;
  char ezhc_Var[26] = {'y', 'n', 'f', 'i', 'c', 'w', 'l', 'b', 'k',
                       'u', 'o', 'm', 'x', 's', 'e', 'v', 'z', 'p',
                       'd', 'r', 'j', 'g', 't', 'h', 'a', 'q'},
       secc_Var, ch, cs = 0, ekpc_Var;
  FILE *zglF_Var, *ldoF_Var;
  zglF_Var = fopen("A-small-attempt1.in", "r");
  ldoF_Var = fopen("output.txt", "w");
  fscanf(zglF_Var, "%d", &ekpc_Var);
  for (; (ch = getc(zglF_Var)) != EOF;) {
    if (ch == '\n') {
      cs++;
      if (cs != 1)
        putc(ch, ldoF_Var);
      if (cs != ekpc_Var + 1)
        fprintf(ldoF_Var, "Case #%d: ", cs);
    }

    if (ch == ' ')
      putc(ch, ldoF_Var);
    else {

      for (char vabc_Var = 0; vabc_Var < 26; vabc_Var++) {
        if (ch == ezhc_Var[vabc_Var])
          putc((vabc_Var + 'a'), ldoF_Var);
      }
    }
  }
  fclose(zglF_Var);
  fclose(ldoF_Var);
  return ret_val;
}
