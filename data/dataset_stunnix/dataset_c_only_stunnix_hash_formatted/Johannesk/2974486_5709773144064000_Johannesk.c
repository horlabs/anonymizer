
#include <assert.h>
#include <stdio.h>
#include <string.h>

void z5bf3d6fa0d(int zbc1df7118a, double C, double F, double X) {
  double z6a838438a8 = (0x3cf + 785 - 0x6e0),
         zbe52bc02e8 = (0xaa3 + 1822 - 0x11bf);
  while ((X / zbe52bc02e8) > (X / (zbe52bc02e8 + F) + (C / zbe52bc02e8))) {
    z6a838438a8 = z6a838438a8 + C / zbe52bc02e8;
    zbe52bc02e8 = zbe52bc02e8 + F;
  }
  z6a838438a8 = z6a838438a8 + X / zbe52bc02e8;
  printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x2e\x37\x6c\x66"
         "\n",
         zbc1df7118a, z6a838438a8);
}
int main(int za3fac7b6f6, char **z55a4889989) {
  int z6a838438a8, z01fe4c613c;
  double C, F, X;
  assert(scanf("\x25\x64\x20", &z6a838438a8) == (0x1de2 + 1879 - 0x2538));
  for (z01fe4c613c = (0x1e97 + 1193 - 0x233f); z01fe4c613c <= z6a838438a8;
       z01fe4c613c++) {
    assert(scanf("\x25\x6c\x66\x20\x25\x6c\x66\x20\x25\x6c\x66\x20", &C, &F,
                 &X) == (0x145f + 4138 - 0x2486));
    z5bf3d6fa0d(z01fe4c613c, C, F, X);
  }
  return (0xbd9 + 99 - 0xc3c);
}
