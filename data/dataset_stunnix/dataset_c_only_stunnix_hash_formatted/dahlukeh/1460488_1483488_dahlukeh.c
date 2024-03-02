
#include <stdio.h>
#include <stdlib.h>

int zeb663d4d96;
int z6d9a744535, zf1cf1701f7;
void z4037365eb9();
int zf9973bb9cf(int ze364a1910c);
int main() {
  int ze364a1910c;
  freopen("\x69\x6e\x2e\x74\x78\x74", "\x72", stdin);
  freopen("\x6f\x75\x74\x2e\x74\x78\x74", "\x77", stdout);
  scanf("\x25\x64\x20", &ze364a1910c);
  int z5a3cfda519;
  for (z5a3cfda519 = (0x51 + 2352 - 0x981); z5a3cfda519 < ze364a1910c;
       z5a3cfda519++) {
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
           z5a3cfda519 + (0x576 + 3299 - 0x1258));
    z4037365eb9();
  }
}
void z4037365eb9() {
  scanf("\x25\x64\x20\x25\x64\x20", &z6d9a744535, &zf1cf1701f7);
  int z5a3cfda519;
  int z83f4b748d1 = (0x588 + 6687 - 0x1fa7);
  zeb663d4d96 = (0x805 + 546 - 0xa27);
  int z3e9b88d7b5 = z6d9a744535;
  while (z3e9b88d7b5 > (0x16e6 + 2931 - 0x2259)) {
    z3e9b88d7b5 /= (0x11b1 + 4255 - 0x2246);
    zeb663d4d96++;
  }
  for (z5a3cfda519 = z6d9a744535; z5a3cfda519 <= zf1cf1701f7; z5a3cfda519++) {
    z83f4b748d1 += zf9973bb9cf(z5a3cfda519);
  }
  printf("\x25\x64"
         "\n",
         z83f4b748d1);
}
int zf9973bb9cf(int ze364a1910c) {
  int zf1b27553c1[(0xc8a + 2813 - 0x177d)];
  int z1c6634c5ac = (0xf1 + 5255 - 0x1578);
  int z5a3cfda519, z53fd4823ab;
  int z30a09d0439 = ze364a1910c;
  int z939f8c0df4 = (0x34a + 3037 - 0xf26);
  for (z5a3cfda519 = (0xadc + 6999 - 0x2633);
       z5a3cfda519 < zeb663d4d96 - (0x14e2 + 3770 - 0x239b); z5a3cfda519++) {
    z939f8c0df4 *= (0x7b1 + 1520 - 0xd97);
  }
  int z83f4b748d1 = (0x988 + 5036 - 0x1d34);
  for (z5a3cfda519 = (0x4bd + 4082 - 0x14af); z5a3cfda519 < zeb663d4d96;
       z5a3cfda519++) {
    int zb2e87697db = z30a09d0439 % (0x352 + 6698 - 0x1d72);
    int z79a789fffc = z30a09d0439 / (0x13c1 + 1092 - 0x17fb);
    z30a09d0439 = zb2e87697db * z939f8c0df4 + z79a789fffc;
    if (z30a09d0439 > ze364a1910c && z30a09d0439 <= zf1cf1701f7) {
      int z2e0dd57d4d = (0x1ad9 + 1529 - 0x20d1);
      for (z53fd4823ab = (0xff2 + 3858 - 0x1f04);
           z53fd4823ab < z1c6634c5ac && z2e0dd57d4d; z53fd4823ab++) {
        if (z30a09d0439 == zf1b27553c1[z53fd4823ab]) {
          z2e0dd57d4d = (0x1396 + 3829 - 0x228b);
        }
      }
      if (z2e0dd57d4d) {
        zf1b27553c1[z1c6634c5ac] = z30a09d0439;
        z1c6634c5ac++;
        z83f4b748d1++;
      }
    }
  }
  return z83f4b748d1;
}
