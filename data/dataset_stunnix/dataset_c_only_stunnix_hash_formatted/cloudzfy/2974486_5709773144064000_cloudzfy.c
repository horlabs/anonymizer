
#include <stdio.h>
#include <string.h>

int main() {
  freopen("\x42\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x69\x6e\x2e\x74\x78\x74",
          "\x72", stdin);
  freopen("\x42\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x6f\x75\x74\x2e\x74\x78\x74",
          "\x77", stdout);
  int z667ebe44cb, ze3d9e61001;
  double C, F, X, z741dd0d54b, z6612c80adc, zf605ccb760;
  scanf("\x25\x64", &ze3d9e61001);
  for (z667ebe44cb = (0xa84 + 707 - 0xd46); z667ebe44cb <= ze3d9e61001;
       z667ebe44cb++) {
    scanf("\x25\x6c\x66\x25\x6c\x66\x25\x6c\x66", &C, &F, &X);
    z741dd0d54b = (0xf20 + 3202 - 0x1ba2);
    zf605ccb760 = (0xfac + 2924 - 0x1b18);
    z6612c80adc = (0xc98 + 820 - 0xfca);
    while ((0x42 + 6606 - 0x1a0f)) {
      if (zf605ccb760 + C >= X) {
        z741dd0d54b += (X - zf605ccb760) / z6612c80adc;
        break;
      }
      z741dd0d54b += C / z6612c80adc;
      zf605ccb760 += C;
      if ((X - zf605ccb760 + C) / (z6612c80adc + F) <
          (X - zf605ccb760) / z6612c80adc) {
        zf605ccb760 -= C;
        z6612c80adc += F;
      } else {
        z741dd0d54b += (X - zf605ccb760) / z6612c80adc;
        break;
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x2e\x37\x66"
           "\n",
           z667ebe44cb, z741dd0d54b);
  }
  return (0x117 + 5931 - 0x1842);
}
