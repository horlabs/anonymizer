
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int ze8c91bb0eb, z1d317d765a, zd4645ec1c6, z913f9e52e7, z467573293e;
  int z6126e3fe08, z96c816df73, zef320b3ca4;
  int z8cf26b7df1;
  int z910bd18b35;
  int zff191b83ca;
  int zc124c46d32;
  scanf("\x25\x64", &ze8c91bb0eb);
  for (z8cf26b7df1 = (0x682 + 80 - 0x6d1); z8cf26b7df1 <= ze8c91bb0eb;
       z8cf26b7df1++) {
    zff191b83ca = (0xa68 + 2608 - 0x1498);
    zc124c46d32 = (0x52b + 6846 - 0x1fe9);
    scanf("\x25\x64\x25\x64\x25\x64", &zd4645ec1c6, &z467573293e, &z913f9e52e7);
    for (z6126e3fe08 = (0x2380 + 700 - 0x263c); z6126e3fe08 < zd4645ec1c6;
         z6126e3fe08++) {
      scanf("\x25\x64", &z910bd18b35);
      if ((z910bd18b35 + (0x1d36 + 2299 - 0x262f)) / (0xf1 + 1759 - 0x7cd) >=
          z913f9e52e7) {
        zff191b83ca++;
      } else if ((z910bd18b35 + (0x3f0 + 205 - 0x4b9)) /
                     (0x5cd + 7035 - 0x2145) >=
                 z913f9e52e7) {
        if (z910bd18b35 == (0x5c8 + 2766 - 0x1096) &&
            z913f9e52e7 != (0x1cf5 + 922 - 0x208f)) {
        } else {
          zc124c46d32++;
        }
      }
    }
    if (z467573293e >= zc124c46d32)
      zff191b83ca += zc124c46d32;
    else
      zff191b83ca += z467573293e;
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z8cf26b7df1, zff191b83ca);
  }
}
