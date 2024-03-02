
#include <math.h>
#include <stdio.h>

int main(void) {
  int z0ca8fd6507, min, max, z9d7ec9cc8e, z7eb319c4cf;
  int zc167dd9d7f, z11573b7b72, zfc261eac8b;
  int z1f5e0957a8, zaed4b41683, z8a9300719d;
  int z58290be289, z45b939140f, zfcc68b4720;
  int z8dac2e195d[(0x525 + 83 - 0x56e)];
  scanf("\x25\x64", &z0ca8fd6507);
  for (z1f5e0957a8 = (0x7c1 + 3561 - 0x15a9); z1f5e0957a8 <= z0ca8fd6507;
       z1f5e0957a8++) {
    scanf("\x25\x64", &min);
    scanf("\x25\x64", &max);
    zaed4b41683 = max;
    zc167dd9d7f = (0x16b8 + 816 - 0x19e8);
    z11573b7b72 = (0x15f9 + 75 - 0x1643);
    while (zaed4b41683) {
      zaed4b41683 /= (0x124a + 796 - 0x155c);
      zc167dd9d7f++;
      z11573b7b72 *= (0x130d + 4349 - 0x2400);
    }
    z11573b7b72 /= (0x123 + 8527 - 0x2268);
    z8a9300719d = (0x3a9 + 822 - 0x6df);
    for (z9d7ec9cc8e = min; z9d7ec9cc8e < max; z9d7ec9cc8e++) {
      z7eb319c4cf = z9d7ec9cc8e;
      z58290be289 = zfcc68b4720 = (0x209f + 243 - 0x2192);
      for (zaed4b41683 = (0xeb7 + 990 - 0x1294); zaed4b41683 < zc167dd9d7f;
           zaed4b41683++) {
        zfc261eac8b = z7eb319c4cf % (0x1be7 + 2340 - 0x2501);
        z7eb319c4cf /= (0x80c + 2344 - 0x112a);
        z7eb319c4cf += (zfc261eac8b * z11573b7b72);
        if ((z9d7ec9cc8e < z7eb319c4cf) && (z7eb319c4cf <= max)) {
          z45b939140f = (0x1c9 + 2509 - 0xb95);
          for (z58290be289 = (0xff + 8642 - 0x22c1); z58290be289 < zfcc68b4720;
               z58290be289++) {
            if (z7eb319c4cf == z8dac2e195d[z58290be289]) {
              z45b939140f = (0x7fc + 3009 - 0x13bd);
            }
          }
          if (z45b939140f) {
            z8dac2e195d[zfcc68b4720] = z7eb319c4cf;
            zfcc68b4720++;
            z8a9300719d++;
          }
        }
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z1f5e0957a8, z8a9300719d);
  }
  return (0x11b4 + 747 - 0x149f);
}
