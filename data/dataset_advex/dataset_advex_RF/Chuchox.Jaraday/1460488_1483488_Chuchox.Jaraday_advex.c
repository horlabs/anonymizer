#include <math.h>
#include <stdio.h>

int main(void) {
  int cases, min, max, cand;
  int ndigit, potencia, temp;
  int j, total;
  int k, enc, nenc;
  int encontrados[10];
  scanf("%d", &cases);
  for (int i = 1; i <= cases; i++) {
    scanf("%d", &min);
    scanf("%d", &max);

    j = max;
    ndigit = 0;
    potencia = 1;
    while (j) {
      j /= 10;
      ndigit++;
      potencia *= 10;
    }
    potencia /= 10;

    total = 0;
    for (int num = min; num < max; num++) {
      cand = num;
      k = nenc = 0;
      for (j = 1; j < ndigit; j++) {
        temp = cand % 10;
        cand /= 10;
        cand += (temp * potencia);
        if ((num < cand) && (cand <= max)) {
          enc = 1;
          for (k = 0; k < nenc; k++) {
            if (cand == encontrados[k])
              enc = 0;
          }
          if (enc) {
            encontrados[nenc] = cand;
            nenc++;
            total++;
          }
        }
      }
    }
    printf("Case #%d: %d\n", i, total);
  }
  return 0;
}
