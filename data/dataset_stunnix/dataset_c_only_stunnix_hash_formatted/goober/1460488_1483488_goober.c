
#include <stdio.h>

int main() {
  int z6a5a201ea9;
  scanf("\x25\x64", &z6a5a201ea9);
  for (int zb669f9a2e5 = (0x191 + 1037 - 0x59d); zb669f9a2e5 <= z6a5a201ea9;
       zb669f9a2e5++) {
    int zc77e88d3c2, za9fef59540;
    scanf("\x25\x64\x20\x25\x64", &zc77e88d3c2, &za9fef59540);
    int zd0d73fd2b3 = (0x118 + 2470 - 0xabe);
    int z137f281165 = (0x23d + 4448 - 0x139c);
    int z33d32034bd = (0xe18 + 3683 - 0x1c7a);
    for (int x = zc77e88d3c2; x >= (0x67a + 4470 - 0x17e6); x++) {
      z137f281165 *= (0x10d8 + 2610 - 0x1b00);
      z33d32034bd++;
      x /= (0xd46 + 2055 - 0x1543);
    }
    for (int z8dbf7d3d29 = zc77e88d3c2; z8dbf7d3d29 <= za9fef59540;
         z8dbf7d3d29++) {
      int z0334dd14b0 = z8dbf7d3d29;
      int zcce2b08f8e[z33d32034bd];
      for (int z3d76a89fd4 = (0x19f8 + 800 - 0x1d18); z3d76a89fd4 < z33d32034bd;
           z3d76a89fd4++) {
        zcce2b08f8e[z3d76a89fd4] = z0334dd14b0;
        z0334dd14b0 = (z0334dd14b0 % (0xc5c + 5273 - 0x20eb)) * z137f281165 +
                      (z0334dd14b0 / (0x1b3c + 2838 - 0x2648));
        if (z0334dd14b0 <= z8dbf7d3d29 || z0334dd14b0 > za9fef59540 ||
            z0334dd14b0 / z137f281165 == (0x231 + 8054 - 0x21a7))
          continue;
        for (int z26e05a9966 = (0x8e1 + 5745 - 0x1f52);
             z26e05a9966 < z3d76a89fd4; z26e05a9966++)
          if (zcce2b08f8e[z26e05a9966] == z0334dd14b0)
            goto z46f9b9d186;
        zd0d73fd2b3++;
      z46f9b9d186:;
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           zb669f9a2e5, zd0d73fd2b3);
  }
  return (0x146a + 3710 - 0x22e8);
}
