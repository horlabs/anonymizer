
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f[(0xdbf + 94 - 0xe0d)];
int za3681beaf0[(0xe15 + 4731 - 0x2080)];
int main(void) {
  int z0462bcd259;
  int z8f84d5e2c4;
  int zc075480b5e, z35736defa4, z0565adb9af;
  int z683db2d0c3, z3729aae0f8;
  int z65554c0293, zeb3708fb11;
  scanf("\x25\x64", &z0462bcd259);
  for (zc075480b5e = (0x1446 + 3364 - 0x2169); zc075480b5e <= z0462bcd259;
       ++zc075480b5e) {
    z683db2d0c3 = -(0xad3 + 5490 - 0x2044);
    z3729aae0f8 = (0x619 + 7518 - 0x2377);
    scanf("\x25\x64", &z65554c0293);
    for (z35736defa4 = (0x2c3 + 3275 - 0xf8e);
         z35736defa4 < (0xdd0 + 1029 - 0x11c5); ++z35736defa4) {
      scanf("\x25\x64", f + z35736defa4);
    }
    scanf("\x25\x64", &zeb3708fb11);
    for (z35736defa4 = (0x1d1a + 734 - 0x1ff8);
         z35736defa4 < (0x52f + 1385 - 0xa88); ++z35736defa4) {
      scanf("\x25\x64", za3681beaf0 + z35736defa4);
    }
    for (z35736defa4 = (0x315 + 8746 - 0x253e);
         z35736defa4 <= (0x6d5 + 7084 - 0x227d); ++z35736defa4) {
      for (z0565adb9af = (0x1596 + 2418 - 0x1f07);
           z0565adb9af <= (0x10c1 + 4502 - 0x2253); ++z0565adb9af) {
        if (f[z65554c0293 * (0xba + 8610 - 0x2258) - z35736defa4] ==
            za3681beaf0[zeb3708fb11 * (0x1cc6 + 1980 - 0x247e) - z0565adb9af]) {
          z683db2d0c3 = f[z65554c0293 * (0xae5 + 5560 - 0x2099) - z35736defa4];
          ++z3729aae0f8;
        }
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", zc075480b5e);
    switch (z3729aae0f8) {
    case (0x2e9 + 6223 - 0x1b37):
      printf("\x25\x64"
             "\n",
             z683db2d0c3);
      break;
    case (0x8a4 + 6845 - 0x2361):
      printf("\x56\x6f\x6c\x75\x6e\x74\x65\x65\x72\x20\x63\x68\x65\x61\x74\x65"
             "\x64\x21"
             "\n");
      break;
    default:
      printf("\x42\x61\x64\x20\x6d\x61\x67\x69\x63\x69\x61\x6e\x21"
             "\n");
      break;
    }
  }
  return (0x506 + 5810 - 0x1bb8);
}
