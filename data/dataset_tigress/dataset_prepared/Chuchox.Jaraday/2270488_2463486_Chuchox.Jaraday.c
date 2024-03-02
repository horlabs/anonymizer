#include "superheader.h"

int espalindromo(long long n);

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  long long cases, casos, i, j;
  long long a, b, minimo, maximo, total;

  scanf("%I64d", &cases);
  for (casos = 1; casos <= cases; casos++) {
    scanf("%I64d %I64d", &a, &b);

    minimo = sqrt(a);
    maximo = sqrt(b);
    if (minimo * minimo < a)
      minimo++;

    total = 0;
    for (i = minimo; i <= maximo; i++) {
      if (espalindromo(i)) {
        if (espalindromo(i * i)) {

          total++;
        }
      }
    }

    printf("Case #%I64d: %I64d\n", casos, total);
  }
}

int espalindromo(long long n) {
  long long cadena[110];
  long long i, total;

  i = 0;
  while (n) {
    cadena[i] = n % 10;
    n /= 10;
    i++;
  }
  total = i - 1;
  i = 0;
  while (i <= (total - i)) {
    if (cadena[i] != cadena[total - i]) {
      return (0);
    }
    i++;
  }
  return (1);
}
