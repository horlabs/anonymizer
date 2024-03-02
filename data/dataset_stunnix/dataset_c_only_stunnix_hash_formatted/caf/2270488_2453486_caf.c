
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int z22aa0fc0d2(char z2b90efdd1f) {
  return z2b90efdd1f == ((char)(0xab + 6349 - 0x1920)) ||
         z2b90efdd1f == ((char)(0x145c + 4148 - 0x243c));
}
static int z84b28cecee(char z2b90efdd1f) {
  return z2b90efdd1f == ((char)(0x3e8 + 8244 - 0x23cd)) ||
         z2b90efdd1f == ((char)(0x24fb + 498 - 0x2699));
}
static void zedb6bdba57(int z7565c36736) {
  char z1c98415c53[(0xf5 + 6776 - 0x1b69)][(0x21ef + 647 - 0x2472)];
  int zab432cf603, zf2cf5a44ef;
  int z230f60e4e3 = (0x1060 + 909 - 0x13ed);
  int z5f0c75eb5a = (0x280 + 6333 - 0x1b3d),
      z081ffca21e = (0x14ad + 2670 - 0x1f1b);
  int z6dfb757edd = (0x1708 + 3506 - 0x24b9),
      z1e0e255d0d = (0x10d5 + 5040 - 0x2484),
      z7542c97ab6 = (0x1428 + 1329 - 0x1958),
      za022321873 = (0x70f + 1723 - 0xdc9);
  scanf("\x20\x25\x34\x63\x20\x25\x34\x63\x20\x25\x34\x63\x20\x25\x34\x63",
        z1c98415c53[(0x17 + 245 - 0x10c)], z1c98415c53[(0x265 + 7901 - 0x2141)],
        z1c98415c53[(0x292 + 2530 - 0xc72)],
        z1c98415c53[(0x6fd + 3464 - 0x1482)]);
  for (zab432cf603 = (0x1264 + 4032 - 0x2224);
       zab432cf603 < (0x11ec + 525 - 0x13f5); zab432cf603++) {
    int zfc6ad81222 = (0x11d + 193 - 0x1dd),
        z32679206ad = (0x4ea + 3440 - 0x1259),
        z2dceb231b0 = (0x17b5 + 79 - 0x1803),
        zca4bd80edd = (0x1135 + 7 - 0x113b);
    for (zf2cf5a44ef = (0xcdf + 3805 - 0x1bbc);
         zf2cf5a44ef < (0xaa8 + 5410 - 0x1fc6); zf2cf5a44ef++) {
      z230f60e4e3 = z230f60e4e3 || z1c98415c53[zab432cf603][zf2cf5a44ef] ==
                                       ((char)(0xae1 + 1066 - 0xedd));
      zfc6ad81222 =
          zfc6ad81222 && z22aa0fc0d2(z1c98415c53[zf2cf5a44ef][zab432cf603]);
      z32679206ad =
          z32679206ad && z84b28cecee(z1c98415c53[zf2cf5a44ef][zab432cf603]);
      z2dceb231b0 =
          z2dceb231b0 && z22aa0fc0d2(z1c98415c53[zab432cf603][zf2cf5a44ef]);
      zca4bd80edd =
          zca4bd80edd && z84b28cecee(z1c98415c53[zab432cf603][zf2cf5a44ef]);
    }
    z5f0c75eb5a = z5f0c75eb5a || zfc6ad81222 || z2dceb231b0;
    z081ffca21e = z081ffca21e || z32679206ad || zca4bd80edd;
    z6dfb757edd =
        z6dfb757edd && z22aa0fc0d2(z1c98415c53[zab432cf603][zab432cf603]);
    z1e0e255d0d =
        z1e0e255d0d && z84b28cecee(z1c98415c53[zab432cf603][zab432cf603]);
    z7542c97ab6 =
        z7542c97ab6 &&
        z22aa0fc0d2(
            z1c98415c53[(0x738 + 627 - 0x9a8) - zab432cf603][zab432cf603]);
    za022321873 =
        za022321873 &&
        z84b28cecee(
            z1c98415c53[(0x1e8 + 4439 - 0x133c) - zab432cf603][zab432cf603]);
  }
  z5f0c75eb5a = z5f0c75eb5a || z6dfb757edd || z7542c97ab6;
  z081ffca21e = z081ffca21e || z1e0e255d0d || za022321873;
  printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
         "\n",
         z7565c36736 + (0xb4a + 7038 - 0x26c7),
         z5f0c75eb5a ? "\x58\x20\x77\x6f\x6e"
                     : z081ffca21e ? "\x4f\x20\x77\x6f\x6e"
                                   : z230f60e4e3 ? "\x47\x61\x6d\x65\x20\x68"
                                                   "\x61\x73\x20\x6e\x6f\x74"
                                                   "\x20\x63\x6f\x6d\x70\x6c"
                                                   "\x65\x74\x65\x64"
                                                 : "\x44\x72\x61\x77");
}
int main() {
  int z7565c36736, zab432cf603;
  scanf("\x25\x64", &z7565c36736);
  for (zab432cf603 = (0x13ba + 3785 - 0x2283); zab432cf603 < z7565c36736;
       zab432cf603++)
    zedb6bdba57(zab432cf603);
  return (0x69c + 7401 - 0x2385);
}
