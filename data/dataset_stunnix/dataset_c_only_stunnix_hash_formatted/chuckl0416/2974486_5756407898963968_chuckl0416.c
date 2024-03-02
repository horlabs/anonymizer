
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int z2aed20437f, zc8348d0b50;
int z354be31634;
int ze71ae13e52[(0x86c + 3860 - 0x1776)][(0x1ad3 + 258 - 0x1bcb)];
int za89757333e[(0x993 + 6568 - 0x2327)];
int zc7682684e8, x, y, z80b6257aae;
int z6970314e7d() {
  z80b6257aae = (0x16f9 + 3263 - 0x23b8);
  for (zc7682684e8 = (0x2bc + 3001 - 0xe74);
       zc7682684e8 <= (0xfca + 4877 - 0x22c7); zc7682684e8++) {
    if (za89757333e[zc7682684e8] == (0x2ec + 2583 - 0xd01)) {
      if (z80b6257aae)
        return (0x10e8 + 2125 - 0x1935);
      z80b6257aae = zc7682684e8;
    }
  }
  return (0xad6 + 2063 - 0x12e4);
}
int main() {
  freopen("\x41\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x69\x6e",
          "\x72", stdin);
  freopen("\x41\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x6f\x75\x74",
          "\x77", stdout);
  scanf("\x25\x64", &z2aed20437f);
  for (zc8348d0b50 = (0x2186 + 49 - 0x21b6); zc8348d0b50 <= z2aed20437f;
       zc8348d0b50++) {
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", zc8348d0b50);
    memset(za89757333e, (0xeea + 650 - 0x1174), sizeof(za89757333e));
    for (zc7682684e8 = (0x387 + 3877 - 0x12ac);
         zc7682684e8 < (0x1ad4 + 2039 - 0x22c9); zc7682684e8++) {
      scanf("\x25\x64", &z354be31634);
      for (y = (0x17d6 + 1801 - 0x1ede); y <= (0x981 + 1820 - 0x1099); y++)
        for (x = (0x518 + 4592 - 0x1708); x < (0xa37 + 7031 - 0x25aa); x++)
          scanf("\x25\x64", &ze71ae13e52[y][x]);
      for (x = (0xef4 + 966 - 0x12ba); x < (0x625 + 643 - 0x8a4); x++)
        za89757333e[ze71ae13e52[z354be31634][x]]++;
    }
    if (!z6970314e7d())
      puts("\x42\x61\x64\x20\x6d\x61\x67\x69\x63\x69\x61\x6e\x21");
    else {
      if (z80b6257aae)
        printf("\x25\x64"
               "\n",
               z80b6257aae);
      else
        puts("\x56\x6f\x6c\x75\x6e\x74\x65\x65\x72\x20\x63\x68\x65\x61\x74\x65"
             "\x64\x21");
    }
  }
  return (0x139c + 3101 - 0x1fb9);
}
