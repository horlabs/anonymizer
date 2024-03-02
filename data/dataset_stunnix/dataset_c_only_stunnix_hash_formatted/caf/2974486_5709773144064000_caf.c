
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double z0734b83d67(long zecf96c21b6, double z2eed513e59, double f) {
  if (zecf96c21b6 > (0x314 + 5704 - 0x195c))
    return z2eed513e59 / ((zecf96c21b6 - (0x18cc + 934 - 0x1c71)) * f + 2.0) +
           z0734b83d67(zecf96c21b6 - (0x12f3 + 1264 - 0x17e2), z2eed513e59, f);
  return (0x1181 + 4579 - 0x2364);
}
void z38ea331621(int zc97dcdbc19) {
  long zecf96c21b6;
  double z2eed513e59, f, x;
  double time = 0.0;
  scanf("\x25\x6c\x66\x20\x25\x6c\x66\x20\x25\x6c\x66", &z2eed513e59, &f, &x);
  zecf96c21b6 = x / z2eed513e59 - 2.0 / f;
  if (zecf96c21b6 < (0x1a1c + 2317 - 0x2329))
    zecf96c21b6 = (0xae4 + 1119 - 0xf43);
  time = z0734b83d67(zecf96c21b6, z2eed513e59, f) + x / (zecf96c21b6 * f + 2.0);
  printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x2e\x37\x66"
         "\n",
         zc97dcdbc19 + (0xa91 + 6877 - 0x256d), time);
}
int main() {
  int zc97dcdbc19, zd732effe7c;
  scanf("\x25\x64", &zc97dcdbc19);
  for (zd732effe7c = (0x140d + 4584 - 0x25f5); zd732effe7c < zc97dcdbc19;
       zd732effe7c++)
    z38ea331621(zd732effe7c);
  return (0x2037 + 279 - 0x214e);
}
