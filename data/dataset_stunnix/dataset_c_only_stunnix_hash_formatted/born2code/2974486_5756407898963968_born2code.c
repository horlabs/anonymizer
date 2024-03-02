
#include <stdio.h>

void za48438648c(int z3ce4ea2b83[(0x132c + 4679 - 0x256f)],
                 int z56cfb3f9e1[(0xf82 + 2150 - 0x17e4)]) {
  int z82bc072c68, z784bc91372, ze59c741c24,
      zade0f5ed39 = (0x1696 + 2104 - 0x1ece), x, y;
  for (z82bc072c68 = (0x718 + 254 - 0x816); z82bc072c68 < (0x51f + 812 - 0x847);
       z82bc072c68++) {
    x = z3ce4ea2b83[z82bc072c68];
    for (z784bc91372 = (0xe84 + 6137 - 0x267d);
         z784bc91372 < (0x9dd + 7014 - 0x253f); z784bc91372++) {
      if (x == z56cfb3f9e1[z784bc91372]) {
        y = x;
        zade0f5ed39++;
      }
    }
  }
  if (zade0f5ed39 == (0x164b + 3843 - 0x254d))
    printf("\x25\x64", y);
  if (zade0f5ed39 > (0xf4f + 3268 - 0x1c12))
    printf("\x42\x61\x64\x20\x6d\x61\x67\x69\x63\x69\x61\x6e\x21");
  if (zade0f5ed39 == (0x511 + 6573 - 0x1ebe))
    printf("\x56\x6f\x6c\x75\x6e\x74\x65\x65\x72\x20\x63\x68\x65\x61\x74\x65"
           "\x64\x21");
}
int main() {
  int z57a087df19, z5227862bdf, z6e3953ad56,
      z3ce4ea2b83[(0x195 + 6512 - 0x1b01)],
      z56cfb3f9e1[(0x75d + 6882 - 0x223b)], z1fdaae1c5a, z784bc91372,
      ze59c741c24, zc484489d68, z82bc072c68;
  scanf("\x25\x64", &z57a087df19);
  for (z1fdaae1c5a = (0x35f + 4456 - 0x14c6); z1fdaae1c5a <= z57a087df19;
       z1fdaae1c5a++) {
    scanf("\x25\x64", &z5227862bdf);
    ze59c741c24 = (0x180f + 79 - 0x185e);
    for (z82bc072c68 = (0x4c6 + 6933 - 0x1fdb);
         z82bc072c68 < (0x206 + 4282 - 0x12bc); z82bc072c68++) {
      for (z784bc91372 = (0x1eea + 1564 - 0x2506);
           z784bc91372 < (0x4b9 + 809 - 0x7de); z784bc91372++) {
        scanf("\x25\x64", &zc484489d68);
        if (z82bc072c68 == z5227862bdf - (0x101 + 7111 - 0x1cc7)) {
          z3ce4ea2b83[ze59c741c24++] = zc484489d68;
        }
      }
    }
    scanf("\x25\x64", &z5227862bdf);
    ze59c741c24 = (0xae0 + 3172 - 0x1744);
    for (z82bc072c68 = (0x1041 + 1986 - 0x1803);
         z82bc072c68 < (0x1f36 + 835 - 0x2275); z82bc072c68++) {
      for (z784bc91372 = (0x392 + 7215 - 0x1fc1);
           z784bc91372 < (0x7ca + 3725 - 0x1653); z784bc91372++) {
        scanf("\x25\x64", &zc484489d68);
        if (z82bc072c68 == z5227862bdf - (0x24b1 + 430 - 0x265e)) {
          z56cfb3f9e1[ze59c741c24++] = zc484489d68;
        }
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", z1fdaae1c5a);
    za48438648c(z3ce4ea2b83, z56cfb3f9e1);
    printf("\n");
  }
  return (0xe47 + 1039 - 0x1256);
}
