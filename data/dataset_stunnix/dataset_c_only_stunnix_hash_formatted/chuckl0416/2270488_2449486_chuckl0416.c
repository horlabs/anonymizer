
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int zbd664bc0d8, z656bc05dfe;
int za1e274d0a5[(0x118b + 2209 - 0x19b4)][(0x245 + 5858 - 0x18af)];
int z2c3d5d22be, zd71f4224fa, Min, z8a03dc11a5, z1929d7c8fe, zf935b68be6;
int z73dbe69da1[(0x729 + 5021 - 0x1a4e)];
int z4621f9f69c[(0x795 + 5726 - 0x1d7b)];
int x, y;
int z9fc6e1e9d8() {
  zf935b68be6 = (0xfeb + 6291 - 0x2496);
  Min = (0xf12 + 4633 - 0x1d43);
  z8a03dc11a5 = (0x17d3 + 4431 - 0x253a);
  z1929d7c8fe = (0x7f3 + 5132 - 0x1817);
  for (y = (0xe61 + 2089 - 0x168a); y < z2c3d5d22be; y++)
    if (z4621f9f69c[y] < Min) {
      zf935b68be6 = z4621f9f69c[y];
      for (x = (0xd60 + 4604 - 0x1f5c); x < zd71f4224fa; x++) {
        if (za1e274d0a5[y][x] == z4621f9f69c[y])
          continue;
        else
          break;
      }
      if (x == zd71f4224fa) {
        Min = z4621f9f69c[y];
        z8a03dc11a5 = y;
        z1929d7c8fe = (0xd96 + 2964 - 0x1542);
      }
    }
  for (x = (0x1a8b + 2025 - 0x2274); x < zd71f4224fa; x++)
    if (z73dbe69da1[x] < Min) {
      zf935b68be6 = z73dbe69da1[x];
      for (y = (0x207 + 1364 - 0x75b); y < z2c3d5d22be; y++) {
        if (za1e274d0a5[y][x] == z73dbe69da1[x])
          continue;
        else
          break;
      }
      if (y == z2c3d5d22be) {
        Min = z73dbe69da1[x];
        z8a03dc11a5 = (0x187a + 3655 - 0x22d9);
        z1929d7c8fe = x;
      }
    }
  if (z1929d7c8fe == (0xcfa + 2900 - 0x1466))
    if (z8a03dc11a5 == (0x1b68 + 1307 - 0x1c9b))
      return (0xa22 + 2365 - 0x135f);
  if (z8a03dc11a5 < (0x639 + 5171 - 0x1684))
    if (zf935b68be6 != z4621f9f69c[z8a03dc11a5])
      return (0x2151 + 700 - 0x240d);
  if (z1929d7c8fe < (0xeca + 3626 - 0x190c))
    if (zf935b68be6 != z73dbe69da1[z1929d7c8fe])
      return (0xa0 + 7349 - 0x1d55);
  if (z8a03dc11a5 < (0x672 + 3945 - 0x11f3)) {
    z2c3d5d22be--;
    for (x = (0x3ec + 1301 - 0x901); x < zd71f4224fa; x++)
      za1e274d0a5[z8a03dc11a5][x] = za1e274d0a5[z2c3d5d22be][x];
    z4621f9f69c[z8a03dc11a5] = z4621f9f69c[z2c3d5d22be];
    for (x = (0x12b1 + 3408 - 0x2001); x < zd71f4224fa; x++) {
      z73dbe69da1[x] = (0x76d + 702 - 0x643);
      for (y = (0xe4d + 3705 - 0x1cc6); y < z2c3d5d22be; y++)
        if (za1e274d0a5[y][x] < z73dbe69da1[x])
          z73dbe69da1[x] = za1e274d0a5[y][x];
    }
    return (0x60 + 1589 - 0x694);
  }
  if (z1929d7c8fe < (0x2099 + 824 - 0x1fe9)) {
    zd71f4224fa--;
    for (y = (0x2c5 + 8527 - 0x2414); y < z2c3d5d22be; y++)
      za1e274d0a5[y][z1929d7c8fe] = za1e274d0a5[y][zd71f4224fa];
    z73dbe69da1[z1929d7c8fe] = z73dbe69da1[zd71f4224fa];
    for (y = (0x407 + 2669 - 0xe74); y < z2c3d5d22be; y++) {
      z4621f9f69c[y] = (0x251a + 1210 - 0x25ec);
      for (x = (0x3e3 + 1576 - 0xa0b); x < zd71f4224fa; x++)
        if (za1e274d0a5[y][x] < z4621f9f69c[y])
          z4621f9f69c[y] = za1e274d0a5[y][x];
    }
    return (0x37a + 840 - 0x6c1);
  }
}
int main() {
  freopen("\x42\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x69\x6e",
          "\x72", stdin);
  freopen("\x42\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x6f\x75\x74",
          "\x77", stdout);
  scanf("\x25\x64", &zbd664bc0d8);
  for (z656bc05dfe = (0xc87 + 295 - 0xdad); z656bc05dfe <= zbd664bc0d8;
       z656bc05dfe++) {
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", z656bc05dfe);
    scanf("\x25\x64\x25\x64", &z2c3d5d22be, &zd71f4224fa);
    for (y = (0x812 + 1656 - 0xe8a); y < z2c3d5d22be; y++)
      for (x = (0x17a6 + 2723 - 0x2249); x < zd71f4224fa; x++)
        scanf("\x25\x64", &za1e274d0a5[y][x]);
    for (y = (0x11bd + 1464 - 0x1775); y < z2c3d5d22be; y++) {
      z4621f9f69c[y] = (0x7fb + 3554 - 0x11f5);
      for (x = (0x174 + 8833 - 0x23f5); x < zd71f4224fa; x++)
        if (za1e274d0a5[y][x] < z4621f9f69c[y])
          z4621f9f69c[y] = za1e274d0a5[y][x];
    }
    for (x = (0x1639 + 1634 - 0x1c9b); x < zd71f4224fa; x++) {
      z73dbe69da1[x] = (0x891 + 6091 - 0x1c74);
      for (y = (0x3c9 + 6382 - 0x1cb7); y < z2c3d5d22be; y++)
        if (za1e274d0a5[y][x] < z73dbe69da1[x])
          z73dbe69da1[x] = za1e274d0a5[y][x];
    }
    while (z2c3d5d22be && zd71f4224fa) {
      if (z9fc6e1e9d8())
        continue;
      else
        break;
    }
    if (z2c3d5d22be && zd71f4224fa)
      printf("\x4e\x4f"
             "\n");
    else
      printf("\x59\x45\x53"
             "\n");
  }
  return (0xac1 + 7178 - 0x26cb);
}
