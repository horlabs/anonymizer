
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const char z32444e6db4[(0x1a + 9298 - 0x2452)] = {
    ((char)(0x151f + 3740 - 0x2342)), ((char)(0x100f + 416 - 0x1147)),
    ((char)(0x978 + 1360 - 0xe63)),   ((char)(0xf46 + 5239 - 0x234a)),
    ((char)(0x2e2 + 4732 - 0x14ef)),  ((char)(0xd69 + 5328 - 0x21d6)),
    ((char)(0x275 + 3858 - 0x1111)),  ((char)(0x20dd + 911 - 0x23f4)),
    ((char)(0x1936 + 1846 - 0x2008)), ((char)(0x1d15 + 800 - 0x1fc0)),
    ((char)(0x1bcb + 725 - 0x1e37)),  ((char)(0x193 + 9303 - 0x2583)),
    ((char)(0x127f + 311 - 0x134a)),  ((char)(0x14e7 + 1902 - 0x1bf3)),
    ((char)(0x2230 + 1196 - 0x2671)), ((char)(0x168f + 1096 - 0x1a65)),
    ((char)(0xeac + 829 - 0x116f)),   ((char)(0xff7 + 1901 - 0x16f0)),
    ((char)(0x1527 + 1182 - 0x1957)), ((char)(0x80d + 2276 - 0x107a)),
    ((char)(0xc65 + 2262 - 0x14d1)),  ((char)(0x1533 + 466 - 0x1695)),
    ((char)(0x400 + 2028 - 0xb86)),   ((char)(0xe26 + 5150 - 0x21d7)),
    ((char)(0x73f + 5295 - 0x1b8d)),  ((char)(0xaad + 2543 - 0x142b))};
int main() {
  int z3935e7a763;
  int z050a5f3b55 = (0x112d + 4433 - 0x227e);
  for (scanf("\x25\x64"
             "\n",
             &z3935e7a763);
       z3935e7a763; z3935e7a763--, z050a5f3b55++) {
    static char z2487c89807[(0x6a5 + 5867 - 0x1cc8)];
    int z5b0b75de8d = (0x1641 + 1827 - 0x1d64);
    int z2760cc78da = (0xcdf + 6571 - 0x268a);
    fgets(z2487c89807, (0xea6 + 1160 - 0x1266), stdin);
    z5b0b75de8d = strlen(z2487c89807);
    while (z5b0b75de8d &&
           !isprint(z2487c89807[z5b0b75de8d - (0xf62 + 5473 - 0x24c2)]))
      z2487c89807[--z5b0b75de8d] = (0xe79 + 1268 - 0x136d);
    for (z2760cc78da = (0x190 + 6737 - 0x1be1); z2760cc78da < z5b0b75de8d;
         z2760cc78da++) {
      if (z2487c89807[z2760cc78da] == ((char)(0x7b3 + 3717 - 0x1618)))
        continue;
      z2487c89807[z2760cc78da] = z32444e6db4[z2487c89807[z2760cc78da] -
                                             ((char)(0x642 + 4349 - 0x16de))];
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
           "\n",
           z050a5f3b55 + (0x1a24 + 2694 - 0x24a9), z2487c89807);
  }
  return (0x2 + 7132 - 0x1bde);
}
