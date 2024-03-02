
#include <stdio.h>

int max(int z85ea136d5b, int za1dad543f6) {
  if (z85ea136d5b > za1dad543f6) {
    return z85ea136d5b;
  } else {
    return za1dad543f6;
  }
}
int main() {
  int z6201d7ddd6, z738de0e683, z71ed064a21, zc64e9ad395, z18cd7a7d73,
      zf1b90795c8, zb5394aaf28;
  int z85ea136d5b[(0x109f + 4209 - 0x20ac)];
  int za1dad543f6[(0xd45 + 2982 - 0x18cc)][(0x904 + 367 - 0xa68)] = {
      (0x1575 + 3645 - 0x23b2)};
  int z583dccabe5[(0x14ac + 2993 - 0x1ff8)][(0x106 + 2340 - 0x9c5)];
  for (z18cd7a7d73 = (0x61b + 7822 - 0x24a9);
       z18cd7a7d73 <= (0xea4 + 4674 - 0x20c8); z18cd7a7d73++) {
    for (zf1b90795c8 = (0xd10 + 651 - 0xf9b);
         zf1b90795c8 <= (0xac2 + 4645 - 0x1cdd); zf1b90795c8++) {
      if (z18cd7a7d73 % (0x1ee8 + 78 - 0x1f33) == (0x5 + 1751 - 0x6dc)) {
        if (z18cd7a7d73 / (0xeeb + 4150 - 0x1f1e) >= zf1b90795c8)
          za1dad543f6[z18cd7a7d73][zf1b90795c8] |= (0x1a7b + 1616 - 0x20ca);
      } else {
        for (zb5394aaf28 = (0x549 + 5600 - 0x1b1f);
             zb5394aaf28 >= (0x12bd + 77 - 0x1309); zb5394aaf28--) {
          if (zb5394aaf28 * (0x19c6 + 2294 - 0x22b9) -
                      (0x13ff + 265 - 0x1507) >=
                  z18cd7a7d73 &&
              zb5394aaf28 * (0x1928 + 1699 - 0x1fc8) -
                      (0x1115 + 1133 - 0x1580) <=
                  z18cd7a7d73) {
            if (zb5394aaf28 >= zf1b90795c8)
              za1dad543f6[z18cd7a7d73][zf1b90795c8] |= (0xcf + 6819 - 0x1b71);
            break;
          }
        }
      }
      for (zb5394aaf28 = (0x20ac + 731 - 0x237d);
           zb5394aaf28 >= (0x723 + 727 - 0x9f8); zb5394aaf28--) {
        if (zb5394aaf28 * (0x1c3 + 8968 - 0x24c8) - (0x3f4 + 4097 - 0x13f3) >=
                z18cd7a7d73 &&
            zb5394aaf28 * (0xd7b + 4750 - 0x2006) - (0x137c + 4377 - 0x2491) <=
                z18cd7a7d73) {
          if (zb5394aaf28 >= zf1b90795c8)
            za1dad543f6[z18cd7a7d73][zf1b90795c8] |= (0x8f7 + 2629 - 0x133a);
          break;
        }
      }
    }
  }
  scanf("\x25\x64", &z6201d7ddd6);
  for (z18cd7a7d73 = (0x3e7 + 273 - 0x4f8); z18cd7a7d73 < z6201d7ddd6;
       z18cd7a7d73++) {
    scanf("\x25\x64\x20\x25\x64\x20\x25\x64", &z738de0e683, &z71ed064a21,
          &zc64e9ad395);
    for (zf1b90795c8 = (0x13c7 + 4161 - 0x2408); zf1b90795c8 < z738de0e683;
         zf1b90795c8++)
      scanf("\x25\x64", &z85ea136d5b[zf1b90795c8]);
    for (zf1b90795c8 = (0x12e5 + 1140 - 0x1759); zf1b90795c8 <= z738de0e683;
         zf1b90795c8++) {
      for (zb5394aaf28 = (0x1430 + 3303 - 0x2117); zb5394aaf28 <= z71ed064a21;
           zb5394aaf28++) {
        z583dccabe5[zf1b90795c8][zb5394aaf28] = (0x8a0 + 6784 - 0x2320);
      }
    }
    for (zf1b90795c8 = (0x17c0 + 656 - 0x1a50); zf1b90795c8 < z738de0e683;
         zf1b90795c8++) {
      for (zb5394aaf28 = (0xfa4 + 4539 - 0x215f); zb5394aaf28 < z71ed064a21;
           zb5394aaf28++) {
        if (za1dad543f6[z85ea136d5b[zf1b90795c8]][zc64e9ad395] &
            (0x1869 + 3425 - 0x25c9)) {
          z583dccabe5[zf1b90795c8 + (0xc5d + 4264 - 0x1d04)][zb5394aaf28] = max(
              z583dccabe5[zf1b90795c8 + (0x107d + 3806 - 0x1f5a)][zb5394aaf28],
              z583dccabe5[zf1b90795c8][zb5394aaf28] + (0xa05 + 7129 - 0x25dd));
        } else {
          z583dccabe5[zf1b90795c8 + (0x391 + 8352 - 0x2430)][zb5394aaf28] = max(
              z583dccabe5[zf1b90795c8 + (0x1a2b + 1689 - 0x20c3)][zb5394aaf28],
              z583dccabe5[zf1b90795c8][zb5394aaf28]);
        }
        if (za1dad543f6[z85ea136d5b[zf1b90795c8]][zc64e9ad395] &
            (0x1480 + 4597 - 0x2673)) {
          z583dccabe5[zf1b90795c8 + (0x631 + 7724 - 0x245c)]
                     [zb5394aaf28 + (0x12c0 + 1183 - 0x175e)] =
                         max(z583dccabe5[zf1b90795c8 + (0xc3c + 4204 - 0x1ca7)]
                                        [zb5394aaf28 + (0x8e2 + 6468 - 0x2225)],
                             z583dccabe5[zf1b90795c8][zb5394aaf28] +
                                 (0x59 + 2778 - 0xb32));
        } else {
          z583dccabe5[zf1b90795c8 + (0x1269 + 5058 - 0x262a)]
                     [zb5394aaf28 + (0x2d1 + 5789 - 0x196d)] = max(
                         z583dccabe5[zf1b90795c8 + (0x4e5 + 2109 - 0xd21)]
                                    [zb5394aaf28 + (0x1526 + 3788 - 0x23f1)],
                         z583dccabe5[zf1b90795c8][zb5394aaf28]);
        }
      }
      if (za1dad543f6[z85ea136d5b[zf1b90795c8]][zc64e9ad395] &
          (0x1151 + 3833 - 0x2049)) {
        z583dccabe5[zf1b90795c8 + (0x11ac + 2991 - 0x1d5a)][z71ed064a21] = max(
            z583dccabe5[zf1b90795c8 + (0x101 + 6287 - 0x198f)][z71ed064a21],
            z583dccabe5[zf1b90795c8][z71ed064a21] + (0x1341 + 4935 - 0x2687));
      } else {
        z583dccabe5[zf1b90795c8 + (0x7e0 + 7394 - 0x24c1)][z71ed064a21] =
            max(z583dccabe5[zf1b90795c8 + (0xfb4 + 1740 - 0x167f)][z71ed064a21],
                z583dccabe5[zf1b90795c8][z71ed064a21]);
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z18cd7a7d73 + (0x3bb + 7194 - 0x1fd4),
           z583dccabe5[z738de0e683][z71ed064a21]);
  }
  return (0x4ad + 4316 - 0x1589);
}
