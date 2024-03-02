
#include <stdio.h>

int main() {
  int zffc7d5f120, zbf4fb436a8, z3e029dfa1e, zc1df073d3c, z0a06fc0faf,
      zbd59c555c1, z6caa0b2ff0, flag;
  int z7558e6afdd[(0x146b + 2101 - 0x1c20)][(0x2a9 + 9438 - 0x2707)];
  scanf("\x25\x64", &zbf4fb436a8);
  for (zffc7d5f120 = (0x1bea + 2320 - 0x24f9); zffc7d5f120 <= zbf4fb436a8;
       zffc7d5f120++) {
    scanf("\x25\x64\x20\x25\x64", &z3e029dfa1e, &zc1df073d3c);
    for (z0a06fc0faf = (0xe3d + 1867 - 0x1588); z0a06fc0faf < z3e029dfa1e;
         z0a06fc0faf++)
      for (zbd59c555c1 = (0x919 + 3673 - 0x1772); zbd59c555c1 < zc1df073d3c;
           zbd59c555c1++)
        scanf("\x25\x64", &z7558e6afdd[z0a06fc0faf][zbd59c555c1]);
    flag = (0xbc3 + 1423 - 0x1152);
    for (z0a06fc0faf = (0xa3f + 5171 - 0x1e72); z0a06fc0faf < z3e029dfa1e;
         z0a06fc0faf++) {
      for (zbd59c555c1 = (0x9f6 + 6164 - 0x220a); zbd59c555c1 < zc1df073d3c;
           zbd59c555c1++) {
        flag = (0x2297 + 484 - 0x247b);
        for (z6caa0b2ff0 = (0x1589 + 3655 - 0x23d0); z6caa0b2ff0 < z3e029dfa1e;
             z6caa0b2ff0++)
          if (z7558e6afdd[z6caa0b2ff0][zbd59c555c1] >
              z7558e6afdd[z0a06fc0faf][zbd59c555c1]) {
            flag++;
            break;
          }
        for (z6caa0b2ff0 = (0x11d3 + 1765 - 0x18b8); z6caa0b2ff0 < zc1df073d3c;
             z6caa0b2ff0++)
          if (z7558e6afdd[z0a06fc0faf][z6caa0b2ff0] >
              z7558e6afdd[z0a06fc0faf][zbd59c555c1]) {
            flag++;
            break;
          }
        if (flag >= (0x1623 + 1265 - 0x1b12))
          goto za830c27a7f;
      }
    }
  za830c27a7f:
    if (z0a06fc0faf == z3e029dfa1e && zbd59c555c1 == zc1df073d3c)
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x59\x45\x53"
             "\n",
             zffc7d5f120);
    else
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x4e\x4f"
             "\n",
             zffc7d5f120);
  }
}
