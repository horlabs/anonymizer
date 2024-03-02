
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int z2fca7ebe83, z582643e868;
  int zd571ccbb6c, zd9a11a1b47, zeda05dce82;
  int z355cb4032d;
  int zcdd70a9597;
  char z40bef21951[(0x1bda + 1122 - 0x2032)][(0x1558 + 3272 - 0x2216)];
  int z095a918785, zf9d449762f, zc0932829f0;
  double ze9ad743f22, f, x, z9e87d541cc;
  double z17c2343a52;
  unsigned long long z6564aa1793;
  scanf("\x25\x64", &zcdd70a9597);
  for (zd571ccbb6c = (0xd67 + 366 - 0xed4); zd571ccbb6c <= zcdd70a9597;
       zd571ccbb6c++) {
    scanf("\x25\x6c\x66\x25\x6c\x66\x25\x6c\x66", &ze9ad743f22, &f, &x);
    z17c2343a52 = (0x2d0 + 610 - 0x532);
    z9e87d541cc = 2.0;
    if (x <= ze9ad743f22) {
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x2e\x30\x37\x6c\x66"
             "\n",
             zd571ccbb6c, x / z9e87d541cc);
      continue;
    }
    while (z17c2343a52 + x / z9e87d541cc >
           z17c2343a52 + ze9ad743f22 / z9e87d541cc + x / (z9e87d541cc + f)) {
      z17c2343a52 += ze9ad743f22 / z9e87d541cc;
      z9e87d541cc += f;
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x2e\x30\x37\x6c\x66"
           "\n",
           zd571ccbb6c, z17c2343a52 + x / z9e87d541cc);
  }
}
