
#include <assert.h>
#include <stdio.h>
#include <string.h>

char zd2b30c8ecb[(0xdc + 54 - 0xae)][(0xc76 + 6563 - 0x25b5)];
int z4fb356bdc1(int x, int y) {
  int z4c663d012a, z9f9a7cdd23, z0654a4e9d2, max;
  for (z4c663d012a = (0x12d3 + 1246 - 0x17b1); z4c663d012a < x; z4c663d012a++) {
    max = (0xfa7 + 828 - 0x12e3);
    for (z9f9a7cdd23 = (0xa2f + 2396 - 0x138b); z9f9a7cdd23 < y; z9f9a7cdd23++)
      if (zd2b30c8ecb[z4c663d012a][z9f9a7cdd23] > max)
        max = zd2b30c8ecb[z4c663d012a][z9f9a7cdd23];
    for (z9f9a7cdd23 = (0xde3 + 4110 - 0x1df1); z9f9a7cdd23 < y;
         z9f9a7cdd23++) {
      if (zd2b30c8ecb[z4c663d012a][z9f9a7cdd23] < max) {
        for (z0654a4e9d2 = (0x9f1 + 6962 - 0x2523); z0654a4e9d2 < x;
             z0654a4e9d2++)
          if (zd2b30c8ecb[z0654a4e9d2][z9f9a7cdd23] >
              zd2b30c8ecb[z4c663d012a][z9f9a7cdd23])
            return (0x76f + 6020 - 0x1ef3);
      }
    }
  }
  return (0x3ac + 3402 - 0x10f5);
}
void ze61d3a58ba(int x, int y) {
  int z4c663d012a, z9f9a7cdd23;
  for (z4c663d012a = (0x1b57 + 2615 - 0x258e); z4c663d012a < x; z4c663d012a++) {
    for (z9f9a7cdd23 = (0x31a + 5028 - 0x16be); z9f9a7cdd23 < y;
         z9f9a7cdd23++) {
      printf("\x25\x63", zd2b30c8ecb[z4c663d012a][z9f9a7cdd23]);
    }
    printf("\n");
  }
}
int main(int z2ec6c7df68, char **z46bcc83282) {
  int zcd668a2baa, z4c663d012a, zf6797c50f6, z6ba06cc08b, x, y;
  char line[(0x5f + 2048 - 0x855)];
  assert(scanf("\x25\x64\x20", &zcd668a2baa) == (0x347 + 7970 - 0x2268));
  for (z4c663d012a = (0x5b4 + 8524 - 0x26ff); z4c663d012a <= zcd668a2baa;
       z4c663d012a++) {
    assert(scanf("\x25\x64\x20\x25\x64\x20", &zf6797c50f6, &z6ba06cc08b) ==
           (0x308 + 4705 - 0x1567));
    for (x = (0x2122 + 593 - 0x2373); x < zf6797c50f6; x++)
      for (y = (0x2097 + 817 - 0x23c8); y < z6ba06cc08b; y++)
        assert(scanf("\x25\x63\x20", &zd2b30c8ecb[x][y]) ==
               (0x1413 + 1051 - 0x182d));
    if (z4fb356bdc1(zf6797c50f6, z6ba06cc08b) == (0xe63 + 3533 - 0x1c2f))
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x59\x45\x53"
             "\n",
             z4c663d012a);
    else
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x4e\x4f"
             "\n",
             z4c663d012a);
  }
  return (0x18b8 + 2327 - 0x21cf);
}
