#include "superheader.h"

int oznaka[10000000];

int daj(int n) {
  int x[10] = {0};
  int rez, i;

  while (n) {
    x[n % 10]++;
    n /= 10;
  }
  rez = 0;
  for (i = 9; i >= 0; i--)
    while (x[i]--)
      rez = 10 * rez + i;
  return rez;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T, tt;

  scanf("%d", &T);

  for (tt = 1; tt <= T; tt++) {
    int x, a, b, ukupno = 0;
    int znam = 0;
    int naj = 1;
    scanf("%d %d", &a, &b);
    int aa = a;

    while (aa) {
      znam++;
      naj *= 10;
      aa /= 10;
    }
    naj /= 10;

    for (x = a; x <= b; x++) {
      int red[10];
      int broj = 0;
      int i;

      aa = x;
      for (i = 0; i < znam; i++) {
        aa = naj * (aa % 10) + aa / 10;
        if (aa < x && !oznaka[aa] && aa >= a && aa <= b) {
          oznaka[aa] = 1;
          red[broj++] = aa;
          ukupno++;
        }
      }
      for (i = 0; i < broj; i++)
        oznaka[red[i]] = 0;
    }
    printf("Case #%d: %d\n", tt, ukupno);
  }

  return 0;
}
