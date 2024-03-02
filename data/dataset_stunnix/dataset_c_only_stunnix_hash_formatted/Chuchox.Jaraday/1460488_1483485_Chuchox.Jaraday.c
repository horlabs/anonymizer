
#include <stdio.h>

int main(void) {
  int z607751aabb[] = {
      ((char)(0x1117 + 1004 - 0x148a)), ((char)(0xe4b + 2722 - 0x1885)),
      ((char)(0x89c + 480 - 0xa17)),    ((char)(0x1b41 + 717 - 0x1d9b)),
      ((char)(0xe25 + 1505 - 0x1397)),  ((char)(0x2cf + 4296 - 0x1334)),
      ((char)(0x17e2 + 159 - 0x180b)),  ((char)(0x18af + 1517 - 0x1e24)),
      ((char)(0xe9a + 218 - 0xf10)),    ((char)(0xba4 + 261 - 0xc34)),
      ((char)(0x6e1 + 4797 - 0x1935)),  ((char)(0xf93 + 36 - 0xf50)),
      ((char)(0x102c + 2054 - 0x17c6)), ((char)(0x2207 + 929 - 0x2546)),
      ((char)(0x1531 + 1371 - 0x1a21)), ((char)(0xb33 + 1215 - 0xf80)),
      ((char)(0x130f + 1610 - 0x18df)), ((char)(0x783 + 4155 - 0x174a)),
      ((char)(0x957 + 5938 - 0x201b)),  ((char)(0x81d + 147 - 0x839)),
      ((char)(0xbd0 + 2233 - 0x141f)),  ((char)(0x1893 + 2717 - 0x22c0)),
      ((char)(0x1b81 + 2532 - 0x24ff)), ((char)(0x787 + 6276 - 0x1f9e)),
      ((char)(0x21bc + 213 - 0x2230)),  ((char)(0x6fd + 469 - 0x861))};
  int zfa9f4d3bb5;
  int z3393ba8565, z45b9797790;
  z3393ba8565 = (0xdec + 88 - 0xe44);
  while ((zfa9f4d3bb5 = getchar()) != '\n') {
    z3393ba8565 *= (0x8a + 890 - 0x3fa);
    z3393ba8565 += zfa9f4d3bb5 - ((char)(0x17ed + 615 - 0x1a24));
  }
  for (z45b9797790 = (0x56c + 439 - 0x722); z45b9797790 <= z3393ba8565;
       z45b9797790++) {
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", z45b9797790);
    while (((zfa9f4d3bb5 = getchar()) != '\n') && (zfa9f4d3bb5 != EOF)) {
      if (zfa9f4d3bb5 == ((char)(0x37d + 3719 - 0x11e4))) {
        putchar(zfa9f4d3bb5);
      } else {
        putchar(z607751aabb[zfa9f4d3bb5 - ((char)(0x19fd + 1545 - 0x1fa5))]);
      }
    }
    putchar(zfa9f4d3bb5);
  }
  return (0x130d + 4718 - 0x257b);
}
