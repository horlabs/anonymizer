
#include <stdio.h>

int z3ffc9c30e9[(0x1998 + 1264 - 0x1e24)][(0x16d6 + 3448 - 0x23ea)];
int za4bb127f43, zb4c5af2665;
int z15334dcbe6() {
  for (int zdec1399bfa = (0x1550 + 1104 - 0x19a0); zdec1399bfa < za4bb127f43;
       zdec1399bfa++)
    for (int z1faf1cce0c = (0x16a + 9447 - 0x2651); z1faf1cce0c < zb4c5af2665;
         z1faf1cce0c++) {
      int z24c6fb5e41 = (0xb9d + 2853 - 0x16c1);
      for (int z251b250116 = (0x732 + 409 - 0x8cb);
           z24c6fb5e41 && z251b250116 < za4bb127f43; z251b250116++)
        if (z3ffc9c30e9[z251b250116][z1faf1cce0c] >
            z3ffc9c30e9[zdec1399bfa][z1faf1cce0c])
          z24c6fb5e41 = (0x123 + 5443 - 0x1666);
      if (z24c6fb5e41)
        continue;
      z24c6fb5e41 = (0xaf7 + 6550 - 0x248c);
      for (int z251b250116 = (0x2c + 53 - 0x61);
           z24c6fb5e41 && z251b250116 < zb4c5af2665; z251b250116++)
        if (z3ffc9c30e9[zdec1399bfa][z251b250116] >
            z3ffc9c30e9[zdec1399bfa][z1faf1cce0c])
          z24c6fb5e41 = (0x192 + 4673 - 0x13d3);
      if (z24c6fb5e41)
        continue;
      return (0x17e7 + 3812 - 0x26cb);
    }
  return (0x84a + 5517 - 0x1dd6);
}
int main() {
  int ze9a561e753;
  scanf("\x25\x64", &ze9a561e753);
  for (int z73a4239b03 = (0x11b8 + 710 - 0x147d); z73a4239b03 <= ze9a561e753;
       z73a4239b03++) {
    scanf("\x25\x64\x20\x25\x64", &za4bb127f43, &zb4c5af2665);
    for (int zdec1399bfa = (0x52c + 165 - 0x5d1); zdec1399bfa < za4bb127f43;
         zdec1399bfa++)
      for (int z1faf1cce0c = (0x15e6 + 2364 - 0x1f22);
           z1faf1cce0c < zb4c5af2665; z1faf1cce0c++)
        scanf("\x25\x64", &z3ffc9c30e9[zdec1399bfa][z1faf1cce0c]);
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
           "\n",
           z73a4239b03, z15334dcbe6() ? "\x59\x45\x53" : "\x4e\x4f");
  }
  return (0x437 + 6365 - 0x1d14);
}
