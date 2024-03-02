
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int zc1a492767a = (0x813 + 6182 - 0x2039);
  int zcbafe86da9;
  scanf("\x25\x64"
        "\n",
        &zcbafe86da9);
  while (zc1a492767a < zcbafe86da9) {
    int zcd6b83ad9a = (0xb78 + 1748 - 0x124c);
    int z22547f6ba7 = (0x1021 + 3478 - 0x1db7);
    int zf4993e56e6 = (0x10e0 + 2087 - 0x1907);
    double zd755723206 = (0x1f22 + 1362 - 0x2474);
    double za027f20ddc;
    double z842f808366;
    scanf("\x25\x64\x20\x25\x64\x20\x25\x6c\x66", &zcd6b83ad9a, &zf4993e56e6,
          &zd755723206);
    while (zcd6b83ad9a--) {
      double zae4a848da7;
      double max, zbc60598615;
      scanf("\x25\x6c\x66", &za027f20ddc);
      if (za027f20ddc < zd755723206)
        continue;
      z842f808366 = za027f20ddc / (0x1a0a + 423 - 0x1bae);
      zae4a848da7 = z842f808366 - floor(z842f808366);
      z842f808366 = floor(z842f808366);
      if (zae4a848da7 == (0xb8f + 4265 - 0x1c38)) {
        max = z842f808366;
        zbc60598615 = z842f808366 + (0x274 + 8509 - 0x23b0);
      } else if (zae4a848da7 <= 0.5) {
        max = z842f808366 + (0x19dc + 1006 - 0x1dc9);
        zbc60598615 = max;
      } else if (zae4a848da7 >= 0.5) {
        max = z842f808366 + (0x35c + 8693 - 0x2550);
        zbc60598615 = z842f808366 + (0x4d4 + 6644 - 0x1ec6);
      }
      if (max >= zd755723206) {
        z22547f6ba7++;
      } else if (zf4993e56e6 > (0x160b + 1817 - 0x1d24) &&
                 zbc60598615 >= zd755723206) {
        z22547f6ba7++;
        zf4993e56e6--;
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           ++zc1a492767a, z22547f6ba7);
  }
  return (0x17b5 + 3750 - 0x265b);
}
