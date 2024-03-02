
#include <stdio.h>

int z08fa20b8ad[(0xac8 + 944 - 0xe12)][(0x10b9 + 1412 - 0x15d7)];
int main() {
  int z92dc3a79f9, z93c5bedee9, z5a9fe2f294, z371078b1f2, z2fe23f116e,
      zdfeb01527c, x, max, min, f;
  scanf("\x25\x64", &z92dc3a79f9);
  for (x = (0x255d + 227 - 0x263f); x <= z92dc3a79f9; x++) {
    scanf("\x25\x64\x25\x64", &z93c5bedee9, &z5a9fe2f294);
    for (z371078b1f2 = (0xcc5 + 4285 - 0x1d82); z371078b1f2 < z93c5bedee9;
         z371078b1f2++)
      for (z2fe23f116e = (0x743 + 4838 - 0x1a29); z2fe23f116e < z5a9fe2f294;
           z2fe23f116e++)
        scanf("\x25\x64", &z08fa20b8ad[z371078b1f2][z2fe23f116e]);
    f = (0x137f + 4811 - 0x2649);
    for (zdfeb01527c = (0x2a1 + 4507 - 0x143b);
         zdfeb01527c <= (0x5eb + 5524 - 0x1b1b); zdfeb01527c++) {
      for (z371078b1f2 = (0x1f52 + 656 - 0x21e2); z371078b1f2 < z93c5bedee9;
           z371078b1f2++) {
        min = (0x8c3 + 1384 - 0xdc6);
        max = (0x71a + 8057 - 0x2693);
        for (z2fe23f116e = (0x113d + 5512 - 0x26c5); z2fe23f116e < z5a9fe2f294;
             z2fe23f116e++) {
          if (z08fa20b8ad[z371078b1f2][z2fe23f116e]) {
            min = (((min) < (z08fa20b8ad[z371078b1f2][z2fe23f116e]))
                       ? (min)
                       : (z08fa20b8ad[z371078b1f2][z2fe23f116e]));
            max = (((max) > (z08fa20b8ad[z371078b1f2][z2fe23f116e]))
                       ? (max)
                       : (z08fa20b8ad[z371078b1f2][z2fe23f116e]));
          }
        }
        if (min == zdfeb01527c && max == zdfeb01527c) {
          for (z2fe23f116e = (0x7f + 6700 - 0x1aab); z2fe23f116e < z5a9fe2f294;
               z2fe23f116e++)
            z08fa20b8ad[z371078b1f2][z2fe23f116e] = (0xa94 + 6626 - 0x2476);
        }
      }
      for (z2fe23f116e = (0x813 + 5378 - 0x1d15); z2fe23f116e < z5a9fe2f294;
           z2fe23f116e++) {
        min = (0x19a + 5353 - 0x161e);
        max = (0x84 + 3476 - 0xe18);
        for (z371078b1f2 = (0x9da + 6977 - 0x251b); z371078b1f2 < z93c5bedee9;
             z371078b1f2++) {
          if (z08fa20b8ad[z371078b1f2][z2fe23f116e]) {
            min = (((min) < (z08fa20b8ad[z371078b1f2][z2fe23f116e]))
                       ? (min)
                       : (z08fa20b8ad[z371078b1f2][z2fe23f116e]));
            max = (((max) > (z08fa20b8ad[z371078b1f2][z2fe23f116e]))
                       ? (max)
                       : (z08fa20b8ad[z371078b1f2][z2fe23f116e]));
          }
        }
        if (min == zdfeb01527c && max == zdfeb01527c) {
          for (z371078b1f2 = (0xd8f + 729 - 0x1068); z371078b1f2 < z93c5bedee9;
               z371078b1f2++)
            z08fa20b8ad[z371078b1f2][z2fe23f116e] = (0x85 + 3751 - 0xf2c);
        }
      }
      for (z371078b1f2 = (0x19d + 7379 - 0x1e70); z371078b1f2 < z93c5bedee9;
           z371078b1f2++)
        for (z2fe23f116e = (0x1b56 + 2154 - 0x23c0); z2fe23f116e < z5a9fe2f294;
             z2fe23f116e++) {
          if (z08fa20b8ad[z371078b1f2][z2fe23f116e] == zdfeb01527c) {
            f = (0xf7c + 1051 - 0x1397);
            goto z4d984ba2a8;
          }
        }
    }
  z4d984ba2a8:
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
           "\n",
           x, f ? "\x59\x45\x53" : "\x4e\x4f");
  }
  return (0x203f + 1460 - 0x25f3);
}
