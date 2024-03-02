
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int z8dca5615e0;
int zc18d9ca003;
int zadbb3ab4f8;
int z5016515543;
int max[(0xf5f + 4752 - 0x21d0)][(0x7e2 + 7240 - 0x2428)];
int main() {
  int ze5eef7db3b;
  int z0d4df5ecdd, z6b24cb8774;
  int z09f79c9520;
  int Case = (0x12d6 + 3645 - 0x2113);
  for (z0d4df5ecdd = (0x295 + 2521 - 0xc6e);
       z0d4df5ecdd < (0x19c0 + 2207 - 0x2240); ++z0d4df5ecdd) {
    max[z0d4df5ecdd][(0x1478 + 3327 - 0x2177)] =
        (z0d4df5ecdd + (0x1639 + 2173 - 0x1eb4)) / (0x552 + 2157 - 0xdbc);
    max[z0d4df5ecdd][(0x7cb + 3852 - 0x16d6)] =
        (0xfd1 + 1238 - 0x14a5) +
        (z0d4df5ecdd - (0x759 + 3000 - 0x130f)) / (0xd29 + 6441 - 0x264f);
    if (max[z0d4df5ecdd][(0x58a + 1543 - 0xb90)] * (0x1200 + 2246 - 0x1ac3) -
                (0xe7c + 1400 - 0x13f0) >
            z0d4df5ecdd ||
        max[z0d4df5ecdd][(0x1d07 + 1170 - 0x2198)] > (0x17c1 + 1832 - 0x1edf))
      max[z0d4df5ecdd][(0x911 + 2756 - 0x13d4)] =
          max[z0d4df5ecdd][(0xc46 + 2606 - 0x1674)];
  }
  scanf("\x25\x64", &ze5eef7db3b);
  while (ze5eef7db3b--) {
    scanf("\x25\x64\x20\x25\x64\x20\x25\x64", &z8dca5615e0, &zc18d9ca003,
          &zadbb3ab4f8);
    z09f79c9520 = (0xe24 + 4138 - 0x1e4e);
    while (z8dca5615e0--) {
      scanf("\x20\x25\x64", &z5016515543);
      if (max[z5016515543][(0xcb8 + 987 - 0x1093)] >= zadbb3ab4f8) {
        ++z09f79c9520;
      } else if (max[z5016515543][(0x436 + 7578 - 0x21cf)] >= zadbb3ab4f8 &&
                 zc18d9ca003 > (0xc3c + 5303 - 0x20f3)) {
        ++z09f79c9520;
        --zc18d9ca003;
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           ++Case, z09f79c9520);
  }
  return (0x34 + 2992 - 0xbe4);
}
