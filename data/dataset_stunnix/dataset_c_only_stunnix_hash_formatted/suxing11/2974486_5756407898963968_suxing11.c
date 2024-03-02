
#include <stdio.h>
#include <string.h>

int za17d35b4c1[(0x37f + 7791 - 0x21e9)][(0x64 + 7238 - 0x1ca0)]
               [(0x1d07 + 2575 - 0x270c)];
int zd516dc0d47[(0x5c + 1011 - 0x43b)];
int main() {
  int zcfb6992d92, z1c7b958770 = (0x5f6 + 2632 - 0x103d);
  int zad5070e2fd, z2f223cf6cd, zb0f7d335c0, zca503d42cf;
  freopen("\x41\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x69\x6e",
          "\x72", stdin);
  freopen("\x41\x5f\x6f\x75\x74\x2e\x74\x78\x74", "\x77", stdout);
  scanf("\x25\x64", &zcfb6992d92);
  while (zcfb6992d92--) {
    memset(zd516dc0d47, (0x3c5 + 6539 - 0x1d50), sizeof(zd516dc0d47));
    scanf("\x25\x64", &zb0f7d335c0);
    for (zad5070e2fd = (0x1f53 + 1076 - 0x2386);
         zad5070e2fd <= (0x4cc + 7303 - 0x214f); zad5070e2fd++)
      for (z2f223cf6cd = (0xab2 + 302 - 0xbdf);
           z2f223cf6cd <= (0x1dc6 + 2341 - 0x26e7); z2f223cf6cd++)
        scanf("\x25\x64",
              &za17d35b4c1[(0x1644 + 48 - 0x1674)][zad5070e2fd][z2f223cf6cd]);
    for (zad5070e2fd = (0x878 + 6377 - 0x2160);
         zad5070e2fd <= (0x15b6 + 2685 - 0x202f); zad5070e2fd++)
      zd516dc0d47[za17d35b4c1[(0x2b3 + 8736 - 0x24d3)][zb0f7d335c0]
                             [zad5070e2fd]] = (0xc49 + 3660 - 0x1a94);
    scanf("\x25\x64", &zca503d42cf);
    for (zad5070e2fd = (0x2059 + 1530 - 0x2652);
         zad5070e2fd <= (0x6e1 + 2772 - 0x11b1); zad5070e2fd++)
      for (z2f223cf6cd = (0x94c + 6332 - 0x2207);
           z2f223cf6cd <= (0x857 + 5279 - 0x1cf2); z2f223cf6cd++)
        scanf("\x25\x64",
              &za17d35b4c1[(0x11e4 + 2701 - 0x1c70)][zad5070e2fd][z2f223cf6cd]);
    int z4a81c485b5 = (0x18cd + 3191 - 0x2544);
    for (zad5070e2fd = (0x2228 + 399 - 0x23b6);
         zad5070e2fd <= (0x1082 + 631 - 0x12f5); zad5070e2fd++)
      if (zd516dc0d47[za17d35b4c1[(0x5f5 + 7175 - 0x21fb)][zca503d42cf]
                                 [zad5070e2fd]])
        if (z4a81c485b5 != (0x873 + 6560 - 0x2213))
          z4a81c485b5 = -(0x375 + 6461 - 0x1cb1);
        else
          z4a81c485b5 =
              za17d35b4c1[(0x1eb3 + 824 - 0x21ea)][zca503d42cf][zad5070e2fd];
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", z1c7b958770++);
    if (z4a81c485b5 == -(0x16d8 + 1379 - 0x1c3a))
      puts("\x42\x61\x64\x20\x6d\x61\x67\x69\x63\x69\x61\x6e\x21");
    else if (z4a81c485b5 == (0x125b + 1259 - 0x1746))
      puts("\x56\x6f\x6c\x75\x6e\x74\x65\x65\x72\x20\x63\x68\x65\x61\x74\x65"
           "\x64\x21");
    else
      printf("\x25\x64"
             "\n",
             z4a81c485b5);
  }
  return (0x1e00 + 1930 - 0x258a);
}
