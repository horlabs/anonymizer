
#include <stdio.h>
#include <stdlib.h>

void z4046d151a6();
int z58be2d7ccd, z9fa55ee71a;
int z3779480505[(0x34f + 3707 - 0x1166)][(0x1516 + 1710 - 0x1b60)];
int z302ba8e490(int y, int x);
int main() {
  freopen("\x62\x69\x6e\x2e\x74\x78\x74", "\x72", stdin);
  freopen("\x62\x6f\x75\x74\x2e\x74\x78\x74", "\x77", stdout);
  int z5dbf013251;
  scanf("\x25\x64\x20", &z5dbf013251);
  int zcdd9763d3e;
  for (zcdd9763d3e = (0x1e55 + 335 - 0x1fa4); zcdd9763d3e < z5dbf013251;
       zcdd9763d3e++) {
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
           zcdd9763d3e + (0xc21 + 6514 - 0x2592));
    z4046d151a6();
  }
  return (0xe2f + 5266 - 0x22c1);
}
void z4046d151a6() {
  int zcdd9763d3e, z1d1170a680;
  scanf("\x25\x64\x20\x25\x64\x20", &z58be2d7ccd, &z9fa55ee71a);
  for (zcdd9763d3e = (0x1caf + 1885 - 0x240c); zcdd9763d3e < z58be2d7ccd;
       zcdd9763d3e++) {
    for (z1d1170a680 = (0xcb9 + 3796 - 0x1b8d); z1d1170a680 < z9fa55ee71a;
         z1d1170a680++) {
      scanf("\x25\x64\x20", &z3779480505[zcdd9763d3e][z1d1170a680]);
    }
  }
  for (zcdd9763d3e = (0x1fc8 + 1107 - 0x241b); zcdd9763d3e < z58be2d7ccd;
       zcdd9763d3e++) {
    for (z1d1170a680 = (0xe9c + 1915 - 0x1617); z1d1170a680 < z9fa55ee71a;
         z1d1170a680++) {
      if (!z302ba8e490(zcdd9763d3e, z1d1170a680)) {
        printf("\x4e\x4f"
               "\n");
        return;
      }
    }
  }
  printf("\x59\x45\x53"
         "\n");
}
int z302ba8e490(int y, int x) {
  int zf5bcfbfd38 = z3779480505[y][x];
  int zcdd9763d3e;
  int z8ad6b7ad8a = (0x1bd2 + 2707 - 0x2664);
  for (zcdd9763d3e = (0xe58 + 633 - 0x10d1);
       zcdd9763d3e < z58be2d7ccd && z8ad6b7ad8a; zcdd9763d3e++) {
    if (z3779480505[zcdd9763d3e][x] > zf5bcfbfd38) {
      z8ad6b7ad8a = (0xda8 + 4176 - 0x1df8);
    }
  }
  if (z8ad6b7ad8a) {
    return (0x588 + 524 - 0x793);
  }
  z8ad6b7ad8a = (0x300 + 5037 - 0x16ac);
  for (zcdd9763d3e = (0xa3f + 2718 - 0x14dd);
       zcdd9763d3e < z9fa55ee71a && z8ad6b7ad8a; zcdd9763d3e++) {
    if (z3779480505[y][zcdd9763d3e] > zf5bcfbfd38) {
      z8ad6b7ad8a = (0x676 + 6952 - 0x219e);
    }
  }
  return z8ad6b7ad8a;
}
