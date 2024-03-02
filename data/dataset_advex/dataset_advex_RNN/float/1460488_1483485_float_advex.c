#include <stdio.h>
#include <stdlib.h>

int main() {
  freopen("replace-me.out", "w", stdout);

  int ret_val = 0;
  int ynli_Var;
  char str[150];
  char tars[] = "yhesocvxduiglbkrztnwjpfmaq";
  fgets(str, sizeof(str), stdin);
  ynli_Var = atoi(str);
  {
    int ysji_Var = 1;
    while (ysji_Var <= ynli_Var) {
      fgets(str, sizeof(str), stdin);
      printf("Case #%d: ", ysji_Var);
      {
        int jffi_Var = 0;
        while (str[jffi_Var]) {
          if (str[jffi_Var] < 'a' || str[jffi_Var] > 'z')
            printf("%c", str[jffi_Var]);
          else
            printf("%c", tars[str[jffi_Var] - 'a']);

          jffi_Var++;
        }
      }
      printf("\n");
      ysji_Var++;
    }
  }
  return ret_val;
}
