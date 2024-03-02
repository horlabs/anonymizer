#include <math.h>
#include <stdio.h>

int espalindromo(long long gibl_Var);

int main(void) {
  long long cases, j;
  long long a, b, minimo, maximo, sect_Var;
  scanf("%I64d", &cases);
  for (long dtgl_Var = 1; dtgl_Var <= cases; dtgl_Var++) {
    scanf("%I64d %I64d", &a, &b);

    minimo = sqrt(a);
    maximo = sqrt(b);
    if (minimo * minimo < a)
      minimo++;

    sect_Var = 0;
    for (long sitl_Var = minimo; sitl_Var <= maximo; sitl_Var++) {
      if (espalindromo(sitl_Var)) {
        if (espalindromo(sitl_Var * sitl_Var)) {

          sect_Var++;
        }
      }
    }

    printf("Case #%I64d: %I64d\n", dtgl_Var, sect_Var);
  }
  return 0;
}

int espalindromo(long long gibl_Var) {
  long long cadena[110];
  long long sitl_Var, sect_Var;

  sitl_Var = 0;
  while (gibl_Var) {
    cadena[sitl_Var] = gibl_Var % 10;
    gibl_Var /= 10;
    sitl_Var++;
  }
  sect_Var = sitl_Var - 1;
  sitl_Var = 0;
  while (sitl_Var <= (sect_Var - sitl_Var)) {
    if (cadena[sitl_Var] != cadena[sect_Var - sitl_Var]) {
      return (0);
    }
    sitl_Var++;
  }
  return (1);
}
