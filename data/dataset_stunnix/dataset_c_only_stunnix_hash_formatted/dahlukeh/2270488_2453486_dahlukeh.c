
#include <stdio.h>
#include <stdlib.h>

void zafb78d965f();
int z3bdc12dfbf(int x, int y, int zd086dbf9a0);
int z29b592d634[(0x12f0 + 2457 - 0x1c85)][(0x113d + 4022 - 0x20ef)];
int z8b23429570[] = {(0x1e0 + 718 - 0x4ae), (0x12fb + 4104 - 0x2302),
                     (0x188a + 3312 - 0x2579), -(0x1632 + 3581 - 0x242e)};
int z3ccc5ed2b6[] = {(0x29f + 5031 - 0x1645), (0x128d + 1895 - 0x19f3),
                     (0x9bb + 4626 - 0x1bcd), (0x327 + 539 - 0x541)};
int main() {
  freopen("\x61\x69\x6e\x2e\x74\x78\x74", "\x72", stdin);
  freopen("\x61\x6f\x75\x74\x2e\x74\x78\x74", "\x77", stdout);
  int zb5e42aa664;
  scanf("\x25\x64\x20", &zb5e42aa664);
  int z77aae42da1;
  for (z77aae42da1 = (0x1da2 + 2139 - 0x25fd); z77aae42da1 < zb5e42aa664;
       z77aae42da1++) {
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
           z77aae42da1 + (0x10a2 + 45 - 0x10ce));
    zafb78d965f();
  }
  return (0xc9a + 544 - 0xeba);
}
void zafb78d965f() {
  int z77aae42da1, zd23e2d4392, z5411323daa;
  int zde28b2c9c7 = (0xb5 + 6759 - 0x1b1b);
  for (z77aae42da1 = (0x1252 + 4126 - 0x2270);
       z77aae42da1 < (0x7ad + 4847 - 0x1a98); z77aae42da1++) {
    for (zd23e2d4392 = (0xdf4 + 6179 - 0x2617);
         zd23e2d4392 < (0x6f9 + 3950 - 0x1663); zd23e2d4392++) {
      char zc0fecd3300;
      int type;
      scanf("\x25\x63\x20", &zc0fecd3300);
      if (zc0fecd3300 == ((char)(0x1207 + 4681 - 0x23f8))) {
        type = (0x811 + 1361 - 0xd62);
      } else if (zc0fecd3300 == ((char)(0x248f + 433 - 0x25f1))) {
        type = (0x199c + 228 - 0x1a7f);
      } else if (zc0fecd3300 == ((char)(0x23a + 1113 - 0x63f))) {
        type = (0x1630 + 3116 - 0x225a);
      } else {
        zde28b2c9c7 = (0xa93 + 649 - 0xd1c);
        type = (0x1ad7 + 2216 - 0x237c);
      }
      z29b592d634[z77aae42da1][zd23e2d4392] = type;
    }
  }
  for (z77aae42da1 = (0x334 + 2273 - 0xc15);
       z77aae42da1 < (0x1bfa + 60 - 0x1c32); z77aae42da1++) {
    for (zd23e2d4392 = (0xa30 + 4008 - 0x19d8);
         zd23e2d4392 < (0x941 + 3786 - 0x1807); zd23e2d4392++) {
      for (z5411323daa = (0x429 + 14 - 0x437);
           z5411323daa < (0x6f + 306 - 0x19d); z5411323daa++) {
        int za7c0f303f1 = z3bdc12dfbf(zd23e2d4392, z77aae42da1, z5411323daa);
        if (za7c0f303f1 == (0x14dc + 79 - 0x152b)) {
          printf("\x58\x20\x77\x6f\x6e"
                 "\n");
          return;
        } else if (za7c0f303f1 == (0x67f + 5574 - 0x1c44)) {
          printf("\x4f\x20\x77\x6f\x6e"
                 "\n");
          return;
        }
      }
    }
  }
  if (zde28b2c9c7) {
    printf("\x44\x72\x61\x77"
           "\n");
  } else {
    printf("\x47\x61\x6d\x65\x20\x68\x61\x73\x20\x6e\x6f\x74\x20\x63\x6f\x6d"
           "\x70\x6c\x65\x74\x65\x64"
           "\n");
  }
}
int z3bdc12dfbf(int x, int y, int zd086dbf9a0) {
  int z77aae42da1;
  int z6b8b8ad446 = (0x60b + 7060 - 0x219d);
  for (z77aae42da1 = (0x23 + 9072 - 0x2393);
       z77aae42da1 < (0x257c + 48 - 0x25a8); z77aae42da1++) {
    if (x >= (0xff9 + 1960 - 0x179d) || y >= (0x851 + 5949 - 0x1f8a) ||
        x < (0x11e4 + 4619 - 0x23ef) || y < (0x960 + 6642 - 0x2352)) {
      return (0x21f3 + 689 - 0x24a2);
    }
    if (z29b592d634[y][x] == (0x128a + 527 - 0x1496)) {
      return (0x6fb + 731 - 0x9d4);
    }
    if (z29b592d634[y][x] != (0x1f5c + 1525 - 0x254f)) {
      if (z6b8b8ad446 == (0x1107 + 4639 - 0x2324) ||
          z6b8b8ad446 == z29b592d634[y][x]) {
        z6b8b8ad446 = z29b592d634[y][x];
      } else {
        return (0xdf6 + 1414 - 0x137a);
      }
    }
    x += z8b23429570[zd086dbf9a0];
    y += z3ccc5ed2b6[zd086dbf9a0];
  }
  return z6b8b8ad446;
}
