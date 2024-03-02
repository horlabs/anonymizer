#include <stdio.h>

char str[110];
char tab[] = "yhesocvxduiglbkrztnwjpfmaq";

int main() {
  int omgi_Var, T, cuai_Var = 1;
  scanf("%d%*c", &T);

  freopen("out.txt", "w", stdout);

  while (T--) {
    gets(str);
    printf("Case #%d: ", cuai_Var++);
    {
      omgi_Var = 0;
      while (str[omgi_Var]) {
        if (str[omgi_Var] >= 'a' && str[omgi_Var] <= 'z')
          putchar(tab[str[omgi_Var] - 'a']);
        else
          putchar(str[omgi_Var]);
        omgi_Var++;
      }
    }
    printf("\n");
  }
  return 0;
}
