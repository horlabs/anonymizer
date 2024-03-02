
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int zc72ac1acf7(int zf33f1a1f9f, int z65180ec01d) {
  if (zf33f1a1f9f == (0x366 + 1906 - 0xad8)) {
    assert(!z65180ec01d);
    return (0x42b + 4968 - 0x1793);
  }
  if (!z65180ec01d) {
    if (zf33f1a1f9f % (0x1c + 5810 - 0x16cb) == (0x896 + 3822 - 0x1784))
      return zf33f1a1f9f / (0x27d + 8728 - 0x2492);
    else
      return zf33f1a1f9f / (0x1601 + 577 - 0x183f) + (0x130b + 140 - 0x1396);
  } else {
    if (zf33f1a1f9f % (0x3f + 2785 - 0xb1d) == (0x4eb + 70 - 0x52f))
      return zf33f1a1f9f / (0x7c + 5567 - 0x1638) + (0x1613 + 3426 - 0x2373);
    else
      return zf33f1a1f9f / (0xdb + 1145 - 0x551) + (0x514 + 2381 - 0xe60);
  }
  assert((0x195f + 2036 - 0x2153));
}
int z2dea547b4e;
void z6c7f97cf56(int *z2c8d6c6074, int zcd58821599, int z281b9f231d,
                 int za65f619575, int zf571c1a527) {
  int zf33f1a1f9f = *z2c8d6c6074;
  if (zcd58821599 == (0x657 + 5266 - 0x1ae9)) {
    assert(z281b9f231d == (0x8db + 4253 - 0x1978));
    if (z2dea547b4e < zf571c1a527) {
      z2dea547b4e = zf571c1a527;
    }
    return;
  }
  if (zcd58821599 > z281b9f231d) {
    int zfb511712e0;
    zfb511712e0 =
        (zc72ac1acf7(zf33f1a1f9f, (0x1c5f + 1302 - 0x2175)) >= za65f619575)
            ? (0x451 + 6375 - 0x1d37)
            : (0x58d + 3252 - 0x1241);
    z6c7f97cf56(z2c8d6c6074 + (0x3cd + 3774 - 0x128a),
                zcd58821599 - (0x6c8 + 8249 - 0x2700), z281b9f231d, za65f619575,
                zf571c1a527 + zfb511712e0);
  }
  if (z281b9f231d > (0x29f + 5710 - 0x18ed) &&
      zf33f1a1f9f >= (0x8b9 + 4329 - 0x19a0)) {
    int zfb511712e0;
    zfb511712e0 =
        (zc72ac1acf7(zf33f1a1f9f, (0x129a + 1492 - 0x186d)) >= za65f619575)
            ? (0x1957 + 1919 - 0x20d5)
            : (0x18ef + 197 - 0x19b4);
    z6c7f97cf56(z2c8d6c6074 + (0x10e6 + 2496 - 0x1aa5),
                zcd58821599 - (0x1021 + 5055 - 0x23df),
                z281b9f231d - (0x16e4 + 4046 - 0x26b1), za65f619575,
                zf571c1a527 + zfb511712e0);
  }
}
int main(void) {
  int z923132fcb7, z21e096c4d9;
  scanf("\x25\x64"
        "\n",
        &z923132fcb7);
  for (z21e096c4d9 = (0xbc4 + 2243 - 0x1486); z21e096c4d9 <= z923132fcb7;
       z21e096c4d9++) {
    int z5aea8ed7e1, z281b9f231d, za65f619575;
    int zf5d71563c8;
    int z2c8d6c6074[(0x1cc + 66 - 0x1aa)];
    memset(z2c8d6c6074, (0x22db + 384 - 0x245b), sizeof(z2c8d6c6074));
    scanf("\x25\x64\x20\x25\x64\x20\x25\x64\x20", &z5aea8ed7e1, &z281b9f231d,
          &za65f619575);
    for (zf5d71563c8 = (0x712 + 2891 - 0x125d); zf5d71563c8 < z5aea8ed7e1;
         zf5d71563c8++) {
      scanf("\x25\x64\x20", &z2c8d6c6074[zf5d71563c8]);
    }
    z2dea547b4e = (0x220 + 2654 - 0xc7e);
    z6c7f97cf56(z2c8d6c6074, z5aea8ed7e1, z281b9f231d, za65f619575,
                (0xed5 + 5519 - 0x2464));
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z21e096c4d9, z2dea547b4e);
  }
  return (0x7b0 + 3027 - 0x1383);
}
