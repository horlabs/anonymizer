
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  freopen("\x42\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x69\x6e",
          "\x72", stdin);
  int zf6dcaf0c9c = (0x19f7 + 1447 - 0x1f9e);
  int z18692edd1e;
  scanf("\x25\x64"
        "\n",
        &z18692edd1e);
  while (zf6dcaf0c9c < z18692edd1e) {
    int zb2c8c2cfc9, zb911b8e1b4;
    int zeccb85e4ca, zee7c60b966;
    int z719236c675[(0xb3b + 6386 - 0x23ca)][(0x14c8 + 2790 - 0x1f4b)];
    int z29781c85bc = (0x11f + 3967 - 0x109d);
    scanf("\x25\x64\x20\x25\x64"
          "\n",
          &zb2c8c2cfc9, &zb911b8e1b4);
    for (zeccb85e4ca = (0x979 + 6513 - 0x22ea); zeccb85e4ca < zb2c8c2cfc9;
         zeccb85e4ca++) {
      for (zee7c60b966 = (0x77a + 3778 - 0x163c); zee7c60b966 < zb911b8e1b4;
           zee7c60b966++) {
        scanf("\x25\x64", &z719236c675[zeccb85e4ca][zee7c60b966]);
      }
      getchar();
    }
    for (zeccb85e4ca = (0x9f1 + 1701 - 0x1096);
         zeccb85e4ca < zb2c8c2cfc9 && z29781c85bc == (0x3cc + 5603 - 0x19ae);
         zeccb85e4ca++) {
      for (zee7c60b966 = (0x101a + 2223 - 0x18c9);
           zee7c60b966 < zb911b8e1b4 && z29781c85bc == (0xc1c + 1699 - 0x12be);
           zee7c60b966++) {
        int z1680ac9512 = (0x91b + 6093 - 0x20e7);
        int zcfbc4030d1 = (0x1ff + 8034 - 0x2160);
        int z579bbf8dbe, z688b3a61a1;
        for (z579bbf8dbe = (0xa74 + 3164 - 0x16d0); z579bbf8dbe < zb2c8c2cfc9;
             z579bbf8dbe++) {
          if (z719236c675[z579bbf8dbe][zee7c60b966] >
              z719236c675[zeccb85e4ca][zee7c60b966])
            z1680ac9512 = (0xae1 + 5784 - 0x2179);
        }
        for (z688b3a61a1 = (0x63c + 4441 - 0x1795); z688b3a61a1 < zb911b8e1b4;
             z688b3a61a1++) {
          if (z719236c675[zeccb85e4ca][z688b3a61a1] >
              z719236c675[zeccb85e4ca][zee7c60b966])
            zcfbc4030d1 = (0x6d0 + 1337 - 0xc09);
        }
        if (z1680ac9512 == (0x140b + 3190 - 0x2081) &&
            zcfbc4030d1 == (0x128 + 5486 - 0x1696))
          z29781c85bc = (0xf12 + 271 - 0x1021);
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
           "\n",
           ++zf6dcaf0c9c, z29781c85bc ? "\x59\x45\x53" : "\x4e\x4f");
  }
  return (0x8b4 + 1517 - 0xea1);
}
