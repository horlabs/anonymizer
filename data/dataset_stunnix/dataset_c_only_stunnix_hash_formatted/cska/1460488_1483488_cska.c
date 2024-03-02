
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int zcc6efb0c18(int);
int zcb9236e2f4(int, int);
int main(void) {
  int zb720da0170, z8634506207, z665c8f004b, z09f7c502a9, zf441e01143,
      z3f57a8cd72, z0c139097d0[(0x4d5 + 4359 - 0x15d4)], z5d0de6fd15,
      z09adb6ed0c, zc6b6165aa9, z190cb761a7, zbb3a1cc29a;
  FILE *z5d931692a1 = fopen("\x43\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65"
                            "\x6d\x70\x74\x30\x2e\x69\x6e",
                            "\x72"),
       *z924921b836 = fopen("\x6f\x75\x74\x2e\x74\x78\x74", "\x77");
  fscanf(z5d931692a1, "\x25\x64", &zc6b6165aa9);
  for (zb720da0170 = (0xd08 + 3240 - 0x19b0); zb720da0170 < zc6b6165aa9;
       zb720da0170++) {
    fscanf(z5d931692a1,
           "\x25\x64\x25\x64"
           "\n",
           &z190cb761a7, &zbb3a1cc29a);
    for (z3f57a8cd72 = (0x897 + 4261 - 0x193c),
        z09f7c502a9 = zcc6efb0c18(z190cb761a7), z5d0de6fd15 = z190cb761a7;
         z5d0de6fd15 < zbb3a1cc29a; z5d0de6fd15++)
      for (zf441e01143 = (0x1126 + 5191 - 0x256d),
          z8634506207 = (0x669 + 6772 - 0x20dc);
           z8634506207 < z09f7c502a9; z8634506207++) {
        z09adb6ed0c =
            z5d0de6fd15 % zcb9236e2f4((0x5dd + 193 - 0x694), z8634506207) *
                zcb9236e2f4((0xc34 + 6519 - 0x25a1),
                            z09f7c502a9 - z8634506207) +
            z5d0de6fd15 / zcb9236e2f4((0x5a3 + 5336 - 0x1a71), z8634506207);
        if (z09adb6ed0c > z5d0de6fd15 && z09adb6ed0c <= zbb3a1cc29a) {
          for (z665c8f004b = (0x649 + 8374 - 0x26ff);
               z665c8f004b < zf441e01143 &&
               z0c139097d0[z665c8f004b] != z09adb6ed0c;
               z665c8f004b++)
            ;
          if (z665c8f004b == zf441e01143)
            z0c139097d0[zf441e01143++] = z09adb6ed0c,
            z3f57a8cd72 += (0x5d2 + 4336 - 0x16c1);
        }
      }
    fprintf(z924921b836,
            "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
            "\n",
            zb720da0170 + (0xe3f + 2550 - 0x1834), z3f57a8cd72);
  }
  fclose(z5d931692a1);
  fclose(z924921b836);
  return (0x6d6 + 2890 - 0x1220);
}
int zcc6efb0c18(int z5d0de6fd15) {
  return z5d0de6fd15 ? (0x1121 + 2106 - 0x195a) +
                           zcc6efb0c18(z5d0de6fd15 / (0x854 + 4028 - 0x1806))
                     : (0x123c + 227 - 0x131f);
}
int zcb9236e2f4(int z5d0de6fd15, int zf441e01143) {
  int zb720da0170;
  for (zb720da0170 = z5d0de6fd15, z5d0de6fd15 = (0xd8 + 573 - 0x314);
       --zf441e01143 >= (0x1429 + 4241 - 0x24ba); z5d0de6fd15 *= zb720da0170)
    ;
  return z5d0de6fd15;
}
