
#include <stdio.h>

int main() {
  int zecbbc29b94, zbff2dd159c;
  scanf("\x25\x64", &zecbbc29b94);
  for (zbff2dd159c = (0x2483 + 519 - 0x2689); zbff2dd159c <= zecbbc29b94;
       zbff2dd159c++) {
    int zcf67116d40, za6aad3c1da, zb38dfd6790, z319c70b0af;
    int z34c3bc2b4f[(0x916 + 4014 - 0x1860)][(0xef4 + 4060 - 0x1e6c)];
    int z4093e60d13[(0xa55 + 5479 - 0x1f58)][(0x527 + 5383 - 0x19ca)] = {
        (0x1b96 + 1757 - 0x2273)};
    scanf("\x25\x64\x20\x25\x64", &zcf67116d40, &za6aad3c1da);
    for (zb38dfd6790 = (0x1332 + 1540 - 0x1936); zb38dfd6790 < zcf67116d40;
         zb38dfd6790++)
      for (z319c70b0af = (0x594 + 5412 - 0x1ab8); z319c70b0af < za6aad3c1da;
           z319c70b0af++)
        scanf("\x25\x64", z34c3bc2b4f[zb38dfd6790] + z319c70b0af);
    int max;
    for (zb38dfd6790 = (0xc1 + 9673 - 0x268a); zb38dfd6790 < zcf67116d40;
         zb38dfd6790++) {
      max = (0x10ba + 5047 - 0x2471);
      for (z319c70b0af = (0x1c29 + 2152 - 0x2491); z319c70b0af < za6aad3c1da;
           z319c70b0af++)
        if (z34c3bc2b4f[zb38dfd6790][z319c70b0af] > max)
          max = z34c3bc2b4f[zb38dfd6790][z319c70b0af];
      for (z319c70b0af = (0x899 + 1886 - 0xff7); z319c70b0af < za6aad3c1da;
           z319c70b0af++)
        if (z34c3bc2b4f[zb38dfd6790][z319c70b0af] == max)
          z4093e60d13[zb38dfd6790][z319c70b0af] = (0xabd + 4475 - 0x1c37);
    }
    for (z319c70b0af = (0x21d + 2072 - 0xa35); z319c70b0af < za6aad3c1da;
         z319c70b0af++) {
      max = (0x804 + 5692 - 0x1e40);
      for (zb38dfd6790 = (0xfb8 + 1101 - 0x1405); zb38dfd6790 < zcf67116d40;
           zb38dfd6790++)
        if (z34c3bc2b4f[zb38dfd6790][z319c70b0af] > max)
          max = z34c3bc2b4f[zb38dfd6790][z319c70b0af];
      for (zb38dfd6790 = (0x91d + 3377 - 0x164e); zb38dfd6790 < zcf67116d40;
           zb38dfd6790++)
        if (z34c3bc2b4f[zb38dfd6790][z319c70b0af] == max)
          z4093e60d13[zb38dfd6790][z319c70b0af] = (0x2bf + 8272 - 0x230e);
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", zbff2dd159c);
    for (zb38dfd6790 = (0xbd6 + 5798 - 0x227c); zb38dfd6790 < zcf67116d40;
         zb38dfd6790++) {
      for (z319c70b0af = (0x4bd + 7037 - 0x203a); z319c70b0af < za6aad3c1da;
           z319c70b0af++)
        if (!z4093e60d13[zb38dfd6790][z319c70b0af])
          break;
      if (z319c70b0af < za6aad3c1da)
        break;
    }
    if (zb38dfd6790 == zcf67116d40)
      printf("\x59\x45\x53");
    else
      printf("\x4e\x4f");
    printf("\n");
  }
}
