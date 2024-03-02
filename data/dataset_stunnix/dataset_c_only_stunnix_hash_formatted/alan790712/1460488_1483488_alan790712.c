
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int z414af40a1b, z12e2f01b3d;
int zb8fd04b625;
int za607849ffc[(0xdf7 + 4547 - 0x1fb0)] = {(0xe6 + 5016 - 0x147d),
                                            (0xfaf + 3920 - 0x1ef5),
                                            (0xdfb + 3599 - 0x1ba6),
                                            (0xa51 + 4348 - 0x1765),
                                            10000,
                                            100000,
                                            1000000,
                                            10000000};
int zb58497661d[(0xc58 + 6401 - 0x2087)];
int zaaee097942;
int z3799fe3907(const void *z414af40a1b, const void *z12e2f01b3d) {
  return *(int *)z414af40a1b - *(int *)z12e2f01b3d;
}
int z5532afef69(int z25bc63d060) {
  int z38ca40ea57;
  int z1712a13cc7 = (0x1f1a + 1028 - 0x231e);
  zaaee097942 = (0x1bb + 3528 - 0xf83);
  for (z38ca40ea57 = (0x176f + 3418 - 0x24c8); z38ca40ea57 < zb8fd04b625;
       ++z38ca40ea57) {
    zb58497661d[zaaee097942] = z25bc63d060 % za607849ffc[z38ca40ea57] *
                                   za607849ffc[zb8fd04b625 - z38ca40ea57] +
                               z25bc63d060 / za607849ffc[z38ca40ea57];
    if (zb58497661d[zaaee097942] >= z414af40a1b &&
        zb58497661d[zaaee097942] <= z12e2f01b3d &&
        zb58497661d[zaaee097942] < z25bc63d060) {
      ++zaaee097942;
    }
  }
  qsort(zb58497661d, zaaee097942, sizeof(int), z3799fe3907);
  z1712a13cc7 = (zaaee097942 > (0x417 + 8219 - 0x2432));
  for (z38ca40ea57 = (0x332 + 7608 - 0x20e9); z38ca40ea57 < zaaee097942;
       ++z38ca40ea57) {
    if (zb58497661d[z38ca40ea57] !=
        zb58497661d[z38ca40ea57 - (0x44 + 1040 - 0x453)])
      ++z1712a13cc7;
  }
  return z1712a13cc7;
}
int main() {
  int z0ca8a7af3d;
  int z38ca40ea57;
  int z1712a13cc7;
  int Case = (0xd89 + 6284 - 0x2615);
  scanf("\x25\x64", &z0ca8a7af3d);
  while (z0ca8a7af3d--) {
    scanf("\x25\x64\x20\x25\x64", &z414af40a1b, &z12e2f01b3d);
    for (z38ca40ea57 = z414af40a1b, zb8fd04b625 = (0xd4b + 3349 - 0x1a60);
         z38ca40ea57 > (0x1740 + 3192 - 0x23b8);
         z38ca40ea57 /= (0x4a2 + 7072 - 0x2038), ++zb8fd04b625)
      ;
    for (z38ca40ea57 = z414af40a1b, z1712a13cc7 = (0x1cc2 + 347 - 0x1e1d);
         z38ca40ea57 <= z12e2f01b3d; ++z38ca40ea57) {
      z1712a13cc7 += z5532afef69(z38ca40ea57);
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           ++Case, z1712a13cc7);
  }
  return (0x1435 + 3275 - 0x2100);
}
