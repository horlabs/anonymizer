#include <stdio.h>

int eygi_Var, nmji_Var;
int nvpi_Var, B, S, E;
int ryfi_Var[10] = {1, 4, 9, 121, 484, 1200};

int main() {

  scanf("%d", &eygi_Var);
  for (nmji_Var = 1; nmji_Var <= eygi_Var; nmji_Var++) {
    printf("Case #%d: ", nmji_Var);
    scanf("%d%d", &nvpi_Var, &B);
    for (S = 0; ryfi_Var[S] < nvpi_Var; S++) {
      ;
    }
    for (E = S; ryfi_Var[E] <= B; E++) {
      ;
    }
    printf("%d\n", E - S);
  }

  return 0;
}
