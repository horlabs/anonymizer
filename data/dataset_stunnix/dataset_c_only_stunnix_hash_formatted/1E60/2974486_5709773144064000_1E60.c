
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int z216d558bec, char **z558b5237b5) {
  int zf76da8dd96, zc6c1e9c17f;
  scanf("\x25\x64"
        "\n",
        &zc6c1e9c17f);
  for (zf76da8dd96 = (0x1df + 4540 - 0x139a); zf76da8dd96 <= zc6c1e9c17f;
       zf76da8dd96++) {
    double C, F, X;
    double zef7f715fe3 = 0.0;
    double z820c3d1ab3 = 2.0;
    scanf("\x25\x6c\x66\x20\x25\x6c\x66\x20\x25\x6c\x66"
          "\n",
          &C, &F, &X);
    while ((0x1371 + 417 - 0x1511)) {
      double z4b619cb4af;
      double zcc46ec5595, zd4802b8a62;
      z4b619cb4af = X / z820c3d1ab3;
      zcc46ec5595 = C / z820c3d1ab3;
      zd4802b8a62 = X / (z820c3d1ab3 + F);
      if (z4b619cb4af < (zcc46ec5595 + zd4802b8a62)) {
        zef7f715fe3 += z4b619cb4af;
        break;
      }
      z820c3d1ab3 += F;
      zef7f715fe3 += zcc46ec5595;
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x2e\x38\x6c\x66"
           "\n",
           zf76da8dd96, zef7f715fe3);
  }
  return (0x1493 + 2032 - 0x1c83);
}
