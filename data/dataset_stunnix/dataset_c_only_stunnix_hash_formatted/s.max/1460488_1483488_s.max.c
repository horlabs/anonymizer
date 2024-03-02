
#include <stdio.h>

int z550eb8f1b0[10000000];
int za2c4f46252(int za995f7a686) {
  int x[(0x10b + 7060 - 0x1c95)] = {(0x1da0 + 1982 - 0x255e)};
  int z6e23adafe0, z64f9689dea;
  while (za995f7a686) {
    x[za995f7a686 % (0xda1 + 4252 - 0x1e33)]++;
    za995f7a686 /= (0x9aa + 2757 - 0x1465);
  }
  z6e23adafe0 = (0x71f + 160 - 0x7bf);
  for (z64f9689dea = (0x525 + 139 - 0x5a7);
       z64f9689dea >= (0x7e4 + 119 - 0x85b); z64f9689dea--)
    while (x[z64f9689dea]--)
      z6e23adafe0 = (0x1963 + 1769 - 0x2042) * z6e23adafe0 + z64f9689dea;
  return z6e23adafe0;
}
int main() {
  int z66dc11ae54, z8328be2196;
  scanf("\x25\x64", &z66dc11ae54);
  for (z8328be2196 = (0xcb4 + 1005 - 0x10a0); z8328be2196 <= z66dc11ae54;
       z8328be2196++) {
    int x, z1bbdbbdfcf, zc0bc3916a0, zfcba35a181 = (0xff + 751 - 0x3ee);
    int z7ea41eef5e = (0x801 + 3170 - 0x1463);
    int zbdb53d8397 = (0x928 + 1521 - 0xf18);
    scanf("\x25\x64\x20\x25\x64", &z1bbdbbdfcf, &zc0bc3916a0);
    int zfaae82852e = z1bbdbbdfcf;
    while (zfaae82852e) {
      z7ea41eef5e++;
      zbdb53d8397 *= (0x58a + 4553 - 0x1749);
      zfaae82852e /= (0xeb9 + 5638 - 0x24b5);
    }
    zbdb53d8397 /= (0x15d5 + 1111 - 0x1a22);
    for (x = z1bbdbbdfcf; x <= zc0bc3916a0; x++) {
      int z10779762e0[(0xf21 + 5780 - 0x25ab)];
      int z1fa71a0aa0 = (0x3d0 + 7988 - 0x2304);
      int z64f9689dea;
      zfaae82852e = x;
      for (z64f9689dea = (0xdb1 + 4525 - 0x1f5e); z64f9689dea < z7ea41eef5e;
           z64f9689dea++) {
        zfaae82852e = zbdb53d8397 * (zfaae82852e % (0xeb2 + 4780 - 0x2154)) +
                      zfaae82852e / (0x9f1 + 7271 - 0x264e);
        if (zfaae82852e < x && !z550eb8f1b0[zfaae82852e] &&
            zfaae82852e >= z1bbdbbdfcf && zfaae82852e <= zc0bc3916a0) {
          z550eb8f1b0[zfaae82852e] = (0x592 + 3237 - 0x1236);
          z10779762e0[z1fa71a0aa0++] = zfaae82852e;
          zfcba35a181++;
        }
      }
      for (z64f9689dea = (0x19a + 1945 - 0x933); z64f9689dea < z1fa71a0aa0;
           z64f9689dea++)
        z550eb8f1b0[z10779762e0[z64f9689dea]] = (0x333 + 701 - 0x5f0);
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z8328be2196, zfcba35a181);
  }
  return (0x463 + 696 - 0x71b);
}
