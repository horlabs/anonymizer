
#include <stdio.h>

int main() {
  int z4d4817e18a, z7b4928d4d8, z232f1a1c88, z79a2e2e406,
      zbb9cd2cc91[(0x16db + 3788 - 0x2543)], za00b870d6f, z054182a8d8, x,
      z7e08038580;
  scanf("\x25\x64", &z4d4817e18a);
  for (z7e08038580 = (0x3f0 + 6578 - 0x1da1); z7e08038580 <= z4d4817e18a;
       ++z7e08038580) {
    scanf("\x25\x64\x25\x64\x25\x64", &z7b4928d4d8, &z232f1a1c88, &z79a2e2e406);
    for (za00b870d6f = (0x1c18 + 796 - 0x1f34); za00b870d6f < z7b4928d4d8;
         ++za00b870d6f) {
      scanf("\x25\x64", &x);
      for (z054182a8d8 = za00b870d6f; z054182a8d8 > (0x935 + 1619 - 0xf88);
           --z054182a8d8) {
        if (x <= zbb9cd2cc91[z054182a8d8 - (0x563 + 6578 - 0x1f14)])
          break;
        zbb9cd2cc91[z054182a8d8] =
            zbb9cd2cc91[z054182a8d8 - (0x14b4 + 3965 - 0x2430)];
      }
      zbb9cd2cc91[z054182a8d8] = x;
    }
    for (za00b870d6f = (0x179a + 1795 - 0x1e9d);
         za00b870d6f < z7b4928d4d8 &&
         zbb9cd2cc91[za00b870d6f] >=
             z79a2e2e406 * (0xd63 + 913 - 0x10f1) - (0x1273 + 4530 - 0x2423);
         ++za00b870d6f)
      ;
    for (z054182a8d8 = (0xa9f + 6653 - 0x249c);
         z054182a8d8 < z232f1a1c88 && za00b870d6f + z054182a8d8 < z7b4928d4d8 &&
         zbb9cd2cc91[za00b870d6f + z054182a8d8] >=
             z79a2e2e406 * (0x11f + 1753 - 0x7f5) - (0x1c7d + 568 - 0x1eb1);
         ++z054182a8d8)
      if (z79a2e2e406 == (0xcd8 + 4872 - 0x1fdf) &&
          !zbb9cd2cc91[za00b870d6f + z054182a8d8])
        break;
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z7e08038580, za00b870d6f + z054182a8d8);
  }
  return (0x1d92 + 2064 - 0x25a2);
}
