
#include <stdio.h>

void zb93b11eb1a(double C, double F, double X) {
  int z802a2dbd62, zb020ee76be, z19a9e8dde7;
  double min, zbdab84a5f7;
  zbdab84a5f7 = X / 2.0;
  z19a9e8dde7 = (0x97d + 6528 - 0x22fd);
  do {
    min = zbdab84a5f7;
    zbdab84a5f7 = (0x10cd + 1563 - 0x16e8);
    for (z802a2dbd62 = (0xc42 + 4874 - 0x1f4c); z802a2dbd62 < z19a9e8dde7;
         z802a2dbd62++) {
      zbdab84a5f7 =
          zbdab84a5f7 + C / (z802a2dbd62 * F + (0x1498 + 3971 - 0x2419));
    }
    zbdab84a5f7 =
        zbdab84a5f7 + X / (z802a2dbd62 * F + (0x1cfa + 2403 - 0x265b));
    z19a9e8dde7++;
  } while (zbdab84a5f7 <= min);
  printf("\x25\x66"
         "\n",
         min);
}
int main() {
  int zc5bd47b761, ze30719e2b2;
  double C, F, X;
  scanf("\x25\x64", &ze30719e2b2);
  for (zc5bd47b761 = (0xe69 + 3089 - 0x1a79); zc5bd47b761 <= ze30719e2b2;
       zc5bd47b761++) {
    scanf("\x25\x6c\x66\x25\x6c\x66\x25\x6c\x66", &C, &F, &X);
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", zc5bd47b761);
    zb93b11eb1a(C, F, X);
  }
  return (0x105b + 408 - 0x11f3);
}
