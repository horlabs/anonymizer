#include <math.h>
#include <stdio.h>

int espalindromo(long long n);

int main(void) {
  long long nvpl_Var, dual_Var, i, j;
  long long a, b, minimo, maximo, iixl_Var;

  scanf("%I64d", &nvpl_Var);
  for (dual_Var = 1; dual_Var <= nvpl_Var; dual_Var++) {
    scanf("%I64d %I64d", &a, &b);

    minimo = sqrt(a);
    maximo = sqrt(b);
    if (minimo * minimo < a)
      minimo++;

    iixl_Var = 0;
    for (i = minimo; i <= maximo; i++) {
      if (espalindromo(i)) {
        if (espalindromo(i * i)) {

          iixl_Var++;
        }
      }
    }

    printf("Case #%I64d: %I64d\n", dual_Var, iixl_Var);
  }
}

int espalindromo(long long n) {
  long long cadena[110];
  long long i, iixl_Var;

  i = 0;
  while (n) {
    cadena[i] = n % 10;
    n /= 10;
    i++;
  }
  iixl_Var = i - 1;
  i = 0;
  while (i <= (iixl_Var - i)) {
    if (cadena[i] != cadena[iixl_Var - i]) {
      return (0);
    }
    i++;
  }
  return (1);
}
