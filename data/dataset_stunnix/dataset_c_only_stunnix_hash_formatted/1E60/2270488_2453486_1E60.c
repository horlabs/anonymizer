
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int zfb8e363dc2(
    char z507b1c3f28[(0x377 + 731 - 0x64e)][(0x849 + 6366 - 0x2123)],
    char zf0761a2d53) {
  int x, y;
  for (y = (0x68d + 6459 - 0x1fc8); y < (0x1020 + 4711 - 0x2283); y++) {
    for (x = (0xac + 9086 - 0x242a); x < (0xa8 + 5776 - 0x1734); x++) {
      if (z507b1c3f28[x][y] != ((char)(0x91 + 5231 - 0x14ac)) &&
          z507b1c3f28[x][y] != zf0761a2d53)
        break;
    }
    if (x == (0xb09 + 541 - 0xd22))
      return (0x166d + 1644 - 0x1cd8);
  }
  for (x = (0x1b5 + 3965 - 0x1132); x < (0x1d33 + 1490 - 0x2301); x++) {
    for (y = (0x47a + 7393 - 0x215b); y < (0x193 + 6865 - 0x1c60); y++) {
      if (z507b1c3f28[x][y] != ((char)(0x1426 + 3923 - 0x2325)) &&
          z507b1c3f28[x][y] != zf0761a2d53)
        break;
    }
    if (y == (0x1230 + 1468 - 0x17e8))
      return (0x467 + 431 - 0x615);
  }
  for (x = (0x20f4 + 1514 - 0x26de); x < (0x71b + 5194 - 0x1b61); x++) {
    if (z507b1c3f28[x][x] != ((char)(0x8f4 + 6692 - 0x22c4)) &&
        z507b1c3f28[x][x] != zf0761a2d53)
      break;
  }
  if (x == (0x7e3 + 6938 - 0x22f9))
    return (0xcef + 4001 - 0x1c8f);
  for (x = (0xe6d + 806 - 0x1193); x < (0xc1a + 1452 - 0x11c2); x++) {
    if (z507b1c3f28[x][(0x1492 + 2523 - 0x1e6a) - x] !=
            ((char)(0x100d + 2669 - 0x1a26)) &&
        z507b1c3f28[x][(0x394 + 6868 - 0x1e65) - x] != zf0761a2d53)
      break;
  }
  if (x == (0x33b + 6469 - 0x1c7c))
    return (0x1184 + 5177 - 0x25bc);
  return (0x9ed + 1209 - 0xea6);
}
int main(int zc542fa1bf9, char **z66e8e5b653) {
  int zfe361a6cb1, z1d40b90939;
  int x, y;
  scanf("\x25\x64"
        "\n",
        &z1d40b90939);
  for (zfe361a6cb1 = (0x1490 + 4250 - 0x2529); zfe361a6cb1 <= z1d40b90939;
       zfe361a6cb1++) {
    char z507b1c3f28[(0x5c1 + 5228 - 0x1a29)][(0x17e8 + 3505 - 0x2595)];
    for (y = (0x56d + 3897 - 0x14a6); y < (0x7df + 839 - 0xb22); y++) {
      for (x = (0xa52 + 51 - 0xa85); x < (0xce7 + 1284 - 0x11e7); x++) {
        scanf("\x25\x63\x20", &z507b1c3f28[x][y]);
      }
    }
    int z0c627e036e = (0xfb1 + 4185 - 0x200a);
    for (y = (0x3b + 6810 - 0x1ad5); y < (0x1726 + 3444 - 0x2496); y++) {
      for (x = (0x10d2 + 378 - 0x124c); x < (0x11e8 + 3108 - 0x1e08); x++) {
        if (z507b1c3f28[x][y] == ((char)(0xbfd + 269 - 0xcdc)))
          z0c627e036e = (0x2076 + 780 - 0x2381);
      }
    }
    char z8acb61f82e[(0x711 + 4043 - 0x1678)];
    int z3b98bee478 = zfb8e363dc2(z507b1c3f28, ((char)(0x10d3 + 562 - 0x12ad))),
        zaf8b870aee = zfb8e363dc2(z507b1c3f28, ((char)(0x1da2 + 119 - 0x1dca)));
    assert(!(z3b98bee478 && zaf8b870aee));
    if (z3b98bee478) {
      sprintf(z8acb61f82e, "\x58\x20\x77\x6f\x6e");
    } else if (zaf8b870aee) {
      sprintf(z8acb61f82e, "\x4f\x20\x77\x6f\x6e");
    } else {
      if (z0c627e036e) {
        sprintf(z8acb61f82e, "\x47\x61\x6d\x65\x20\x68\x61\x73\x20\x6e\x6f\x74"
                             "\x20\x63\x6f\x6d\x70\x6c\x65\x74\x65\x64");
      } else {
        sprintf(z8acb61f82e, "\x44\x72\x61\x77");
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
           "\n",
           zfe361a6cb1, z8acb61f82e);
  }
  return (0xcb + 7691 - 0x1ed6);
}
