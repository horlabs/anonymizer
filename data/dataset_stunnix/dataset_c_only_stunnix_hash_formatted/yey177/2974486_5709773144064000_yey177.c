
#include <stdio.h>

int main() {
  int z58fc51dc87, zeab73b2291;
  double z92401a98c5, f, x, zb0c2d1c3fc, z1e46b6c00b;
  scanf("\x25\x64", &z58fc51dc87);
  for (zeab73b2291 = (0x138c + 2765 - 0x1e58); zeab73b2291 <= z58fc51dc87;
       zeab73b2291++) {
    scanf("\x25\x6c\x66\x25\x6c\x66\x25\x6c\x66", &z92401a98c5, &f, &x);
    zb0c2d1c3fc = 2.0;
    z1e46b6c00b = 0.0;
    while (x * zb0c2d1c3fc < (x - z92401a98c5) * (zb0c2d1c3fc + f)) {
      z1e46b6c00b = z1e46b6c00b + z92401a98c5 / zb0c2d1c3fc;
      zb0c2d1c3fc = zb0c2d1c3fc + f;
    }
    z1e46b6c00b = z1e46b6c00b + x / zb0c2d1c3fc;
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x2e\x37\x6c\x66"
           "\n",
           zeab73b2291, z1e46b6c00b);
  }
  return (0x6a + 7616 - 0x1e2a);
}
