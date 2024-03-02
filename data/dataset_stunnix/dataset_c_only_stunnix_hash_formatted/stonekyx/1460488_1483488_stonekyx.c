
#include <stdio.h>

const int z5e7bb87f95[(0xe72 + 948 - 0x121c)] = {(0x933 + 5368 - 0x1e2a),
                                                 (0x55c + 2424 - 0xeca),
                                                 (0x15c0 + 193 - 0x161d),
                                                 (0x1aa7 + 3020 - 0x228b),
                                                 10000,
                                                 100000,
                                                 1000000,
                                                 10000000,
                                                 100000000,
                                                 1000000000};
static int zb0c25b1dd3(int x, int z93f4cd66c4) {
  int z49ae17411c = x % (0x1758 + 1099 - 0x1b99);
  x /= (0x158 + 7605 - 0x1f03);
  if (z49ae17411c == (0x1490 + 3005 - 0x204d))
    return x;
  x += z5e7bb87f95[z93f4cd66c4 - (0xba7 + 1120 - 0x1006)] * z49ae17411c;
  return x;
}
static int z44e40392eb(int x, int za969b45dd2, int z1bde3274f7) {
  int zacf67246bd;
  int z214b2b1c69 = (0x788 + 1657 - 0xe01);
  int zf7ac908114 = (0x480 + 4431 - 0x15cf);
  if (z1bde3274f7 < za969b45dd2)
    return (0x2423 + 564 - 0x2657);
  for (zf7ac908114 = (0x3b7 + 6863 - 0x1e86), zacf67246bd = x; zacf67246bd;
       zacf67246bd /= (0x1505 + 3644 - 0x2337), zf7ac908114++)
    ;
  for (zacf67246bd = zb0c25b1dd3(x, zf7ac908114);
       zacf67246bd != -(0x2222 + 360 - 0x2389) && zacf67246bd != x;
       zacf67246bd = zb0c25b1dd3(zacf67246bd, zf7ac908114)) {
    if (zacf67246bd > x && zacf67246bd >= za969b45dd2 &&
        zacf67246bd <= z1bde3274f7)
      z214b2b1c69++;
  }
  return z214b2b1c69;
}
int main() {
  int z2bdbb1fa0e;
  int zc3b47d1b54 = (0xbff + 6422 - 0x2515);
  for (scanf("\x25\x64", &z2bdbb1fa0e); z2bdbb1fa0e;
       z2bdbb1fa0e--, zc3b47d1b54++) {
    int z4a7a868c37, z2c13e45993;
    int zacf67246bd;
    int z214b2b1c69 = (0x29b + 4860 - 0x1597);
    scanf("\x25\x64\x25\x64", &z4a7a868c37, &z2c13e45993);
    for (zacf67246bd = z4a7a868c37; zacf67246bd <= z2c13e45993; zacf67246bd++) {
      z214b2b1c69 += z44e40392eb(zacf67246bd, z4a7a868c37, z2c13e45993);
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           zc3b47d1b54 + (0x34b + 5427 - 0x187d), z214b2b1c69);
  }
  return (0x118b + 2828 - 0x1c97);
}
