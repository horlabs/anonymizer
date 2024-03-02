
#include <stdio.h>

int main() {
  int z0571186acc;
  int z6abf5d3aff;
  double z7bf283c978, f, x;
  double z03cfe62aa5;
  double zb3dccfd8b5, ze3143433ff;
  int z2b3dbf8204;
  fscanf(stdin,
         "\x25\x64"
         "\n",
         &z0571186acc);
  for (z6abf5d3aff = (0x1d1a + 1879 - 0x2471); z6abf5d3aff < z0571186acc;
       z6abf5d3aff++) {
    fscanf(stdin,
           "\x25\x6c\x66\x20\x25\x6c\x66\x20\x25\x6c\x66"
           "\n",
           &z7bf283c978, &f, &x);
    z03cfe62aa5 = (0x2025 + 980 - 0x23f9);
    z2b3dbf8204 = (0x247 + 9261 - 0x2674);
    while ((0x631 + 3632 - 0x1460)) {
      zb3dccfd8b5 =
          z03cfe62aa5 + x / (f * z2b3dbf8204 + (0x42d + 5504 - 0x19ab));
      z03cfe62aa5 += z7bf283c978 / (f * z2b3dbf8204 + (0x1e82 + 851 - 0x21d3));
      z2b3dbf8204++;
      ze3143433ff =
          z03cfe62aa5 + x / (f * z2b3dbf8204 + (0x6e1 + 1894 - 0xe45));
      if (zb3dccfd8b5 <= ze3143433ff)
        break;
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
           z6abf5d3aff + (0x44a + 894 - 0x7c7));
    printf("\x25\x2e\x37\x66"
           "\n",
           zb3dccfd8b5);
  }
  return (0x1096 + 3714 - 0x1f18);
}
