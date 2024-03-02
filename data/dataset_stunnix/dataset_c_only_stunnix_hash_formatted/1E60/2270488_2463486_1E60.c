
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int zb089cb25ef(long long z98161e2cd8) {
  char z1f249a28b5[(0x1725 + 3705 - 0x253a)];
  sprintf(z1f249a28b5, "\x25\x6c\x6c\x64", z98161e2cd8);
  int zd4bd2d3436, zfed91a8c46;
  zfed91a8c46 = strlen(z1f249a28b5);
  int z7a2951b66f = (0x3e3 + 1442 - 0x984);
  for (zd4bd2d3436 = (0x1266 + 903 - 0x15ed); zd4bd2d3436 < zfed91a8c46;
       zd4bd2d3436++) {
    if (z1f249a28b5[zd4bd2d3436] !=
        z1f249a28b5[zfed91a8c46 - (0xfa5 + 818 - 0x12d6) - zd4bd2d3436])
      z7a2951b66f = (0x4b6 + 6651 - 0x1eb1);
  }
  return z7a2951b66f;
}
int main(int z98e0bf113c, char **z217af99fdb) {
  int za73608ee0e, z0dc1b1c792;
  long long z959c6c041f, z64edbe256a, z438f420b1a, zd365a5c195, z98161e2cd8,
      ze9301b9556;
  double z5b9289e92b, z6f1b388748;
  scanf("\x25\x64"
        "\n",
        &z0dc1b1c792);
  for (za73608ee0e = (0x8b8 + 5728 - 0x1f17); za73608ee0e <= z0dc1b1c792;
       za73608ee0e++) {
    int zb96958268a = (0x1815 + 3339 - 0x2520);
    scanf("\x25\x6c\x6c\x64\x20\x25\x6c\x6c\x64"
          "\n",
          &z959c6c041f, &z64edbe256a);
    z5b9289e92b = (double)z959c6c041f;
    z6f1b388748 = (double)z64edbe256a;
    z438f420b1a = sqrt(z5b9289e92b) - (0x1081 + 2779 - 0x1b5b);
    zd365a5c195 = sqrt(z6f1b388748) + (0x1b5b + 2957 - 0x26e7);
    if (z438f420b1a < (0x11e8 + 1442 - 0x1789))
      z438f420b1a = (0xe2c + 4263 - 0x1ed2);
    for (z98161e2cd8 = z438f420b1a; z98161e2cd8 <= zd365a5c195; z98161e2cd8++) {
      ze9301b9556 = z98161e2cd8 * z98161e2cd8;
      if (z959c6c041f <= ze9301b9556 && ze9301b9556 <= z64edbe256a) {
        if (zb089cb25ef(z98161e2cd8) && zb089cb25ef(ze9301b9556)) {
          zb96958268a++;
        }
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           za73608ee0e, zb96958268a);
  }
  return (0xd7b + 4646 - 0x1fa1);
}
