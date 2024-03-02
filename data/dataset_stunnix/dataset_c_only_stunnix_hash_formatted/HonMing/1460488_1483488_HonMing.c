
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int zc836e8d863;
  int z8462c3e37c, z48b8e500ac, z49ad5c23e4, zcf4434f8e2;
  int z0f1b04e830, z6fba26ccbe, zb5f1af012f;
  int zd8f5c775c4;
  int x, y, zbb5c45c46b;
  int zf46eacb202;
  int z4552e77e09;
  int z0b6f6ea69a, zc47d4d41ce;
  char z3eabf64ac1[(0x744 + 3821 - 0x15cd)];
  int z8d36b060e2[(0x20c0 + 769 - 0x23b7)];
  scanf("\x25\x64", &zc836e8d863);
  for (zf46eacb202 = (0xf21 + 1968 - 0x16d0); zf46eacb202 <= zc836e8d863;
       zf46eacb202++) {
    scanf("\x25\x64\x25\x64", &z0b6f6ea69a, &zc47d4d41ce);
    int z0f4853a8b6;
    if (z0b6f6ea69a < (0x325 + 7929 - 0x2214))
      zb5f1af012f = (0x1a95 + 525 - 0x1ca2);
    else if (z0b6f6ea69a < (0x40d + 5018 - 0x1743))
      zb5f1af012f = (0x9b8 + 6029 - 0x2144);
    else if (z0b6f6ea69a < (0xbc5 + 396 - 0x969))
      zb5f1af012f = (0xfef + 3513 - 0x1da6);
    else if (z0b6f6ea69a < 10000)
      zb5f1af012f = (0x157c + 1525 - 0x1b6e);
    else if (z0b6f6ea69a < 100000)
      zb5f1af012f = (0x5b0 + 5248 - 0x1a2c);
    else if (z0b6f6ea69a < 1000000)
      zb5f1af012f = (0xa2f + 692 - 0xcde);
    else if (z0b6f6ea69a < 10000000)
      zb5f1af012f = (0x729 + 3591 - 0x152a);
    z4552e77e09 = (0x451 + 8073 - 0x23da);
    if (zb5f1af012f > (0x21e3 + 1006 - 0x25d1)) {
      for (z0f1b04e830 = z0b6f6ea69a; z0f1b04e830 <= zc47d4d41ce;
           z0f1b04e830++) {
        zbb5c45c46b = (0x158f + 1805 - 0x1c92);
        memset(z8d36b060e2, (0x13d8 + 4845 - 0x26c5),
               (0x1a7c + 2649 - 0x24cb) * sizeof(int));
        for (z6fba26ccbe = (0x132 + 5349 - 0x1617); z6fba26ccbe < zb5f1af012f;
             z6fba26ccbe++) {
          x = z0f1b04e830 % zbb5c45c46b;
          y = z0f1b04e830 / zbb5c45c46b;
          sprintf(z3eabf64ac1, "\x25\x64\x25\x64", x, y);
          z0f4853a8b6 = atoi(z3eabf64ac1);
          if ((z0f4853a8b6 > z0f1b04e830) && (z0f4853a8b6 <= zc47d4d41ce) &&
              (z0f4853a8b6 >= z0b6f6ea69a)) {
            int z3a5da25aa7 = (0x1234 + 4667 - 0x246f);
            for (zd8f5c775c4 = (0x7e6 + 3352 - 0x14fe);
                 zd8f5c775c4 < z6fba26ccbe; zd8f5c775c4++) {
              if (z8d36b060e2[zd8f5c775c4] == z0f4853a8b6)
                z3a5da25aa7 = (0x633 + 43 - 0x65d);
            }
            if (!z3a5da25aa7) {
              z4552e77e09++;
              z8d36b060e2[z6fba26ccbe] = z0f4853a8b6;
            }
          }
          zbb5c45c46b *= (0x828 + 1250 - 0xd00);
        }
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           zf46eacb202, z4552e77e09);
  }
}
