
#include <stdio.h>
#include <string.h>

int z275454584d[(0x10c8 + 1079 - 0x14ef)];
int main() {
  freopen("\x41\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x69\x6e\x2e\x74\x78\x74",
          "\x72", stdin);
  freopen("\x41\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x6f\x75\x74\x2e\x74\x78\x74",
          "\x77", stdout);
  int z770f2123df, zb52cae7d8a, z2025336c30, zdac50d88f9, z66ee37dc76,
      z8992ef2879;
  scanf("\x25\x64", &zb52cae7d8a);
  for (z770f2123df = (0xe8a + 6166 - 0x269f); z770f2123df <= zb52cae7d8a;
       z770f2123df++) {
    memset(z275454584d, (0xcf5 + 1162 - 0x117f), sizeof(z275454584d));
    scanf("\x25\x64", &z2025336c30);
    for (int z9b6e2337d4 = (0x202f + 21 - 0x2044);
         z9b6e2337d4 < (0x1e11 + 477 - 0x1fea); z9b6e2337d4++) {
      for (int zd5da372b09 = (0x40 + 2693 - 0xac5);
           zd5da372b09 < (0x811 + 5164 - 0x1c39); zd5da372b09++) {
        scanf("\x25\x64", &z66ee37dc76);
        if (z9b6e2337d4 == z2025336c30 - (0x1d61 + 1877 - 0x24b5)) {
          z275454584d[z66ee37dc76 - (0x12c4 + 3542 - 0x2099)]++;
        }
      }
    }
    scanf("\x25\x64", &zdac50d88f9);
    for (int z9b6e2337d4 = (0x934 + 4621 - 0x1b41);
         z9b6e2337d4 < (0x18 + 4218 - 0x108e); z9b6e2337d4++) {
      for (int zd5da372b09 = (0x208a + 463 - 0x2259);
           zd5da372b09 < (0x17b0 + 3726 - 0x263a); zd5da372b09++) {
        scanf("\x25\x64", &z66ee37dc76);
        if (z9b6e2337d4 == zdac50d88f9 - (0x1678 + 825 - 0x19b0)) {
          z275454584d[z66ee37dc76 - (0xa5b + 4478 - 0x1bd8)]++;
        }
      }
    }
    z8992ef2879 = (0x618 + 1747 - 0xceb);
    for (int z9b6e2337d4 = (0x25b2 + 160 - 0x2652);
         z9b6e2337d4 < (0x2135 + 1293 - 0x2632); z9b6e2337d4++) {
      if (z275454584d[z9b6e2337d4] == (0x12e6 + 745 - 0x15cd) &&
          z8992ef2879 == (0x26 + 468 - 0x1fa)) {
        z8992ef2879 = z9b6e2337d4 + (0xd76 + 680 - 0x101d);
      } else if (z275454584d[z9b6e2337d4] == (0x17cc + 3848 - 0x26d2) &&
                 z8992ef2879 != (0x1d1a + 1224 - 0x21e2)) {
        z8992ef2879 = -(0x1258 + 4696 - 0x24af);
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", z770f2123df);
    if (z8992ef2879 == (0x871 + 1915 - 0xfec)) {
      printf("\x56\x6f\x6c\x75\x6e\x74\x65\x65\x72\x20\x63\x68\x65\x61\x74\x65"
             "\x64\x21"
             "\n");
    } else if (z8992ef2879 == -(0x178b + 2937 - 0x2303)) {
      printf("\x42\x61\x64\x20\x6d\x61\x67\x69\x63\x69\x61\x6e\x21"
             "\n");
    } else {
      printf("\x25\x64"
             "\n",
             z8992ef2879);
    }
  }
}
