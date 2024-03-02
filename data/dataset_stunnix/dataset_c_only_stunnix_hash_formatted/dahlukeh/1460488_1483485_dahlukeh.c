
#include <stdio.h>
#include <stdlib.h>

void zcfb2c0dead();
char zdca3ab6064[] = {
    ((char)(0xb6f + 3567 - 0x18e5)),  ((char)(0x785 + 1989 - 0xee2)),
    ((char)(0x1274 + 4 - 0x1213)),    ((char)(0x1532 + 189 - 0x157c)),
    ((char)(0x1163 + 1899 - 0x185f)), ((char)(0xc69 + 951 - 0xfbd)),
    ((char)(0xe22 + 3562 - 0x1b96)),  ((char)(0x121b + 1135 - 0x1612)),
    ((char)(0xcc8 + 157 - 0xd01)),    ((char)(0x9c + 1744 - 0x6f7)),
    ((char)(0x1a35 + 2924 - 0x2538)), ((char)(0x632 + 4695 - 0x1822)),
    ((char)(0x1111 + 2310 - 0x19ab)), ((char)(0x1a7b + 1055 - 0x1e38)),
    ((char)(0xc33 + 78 - 0xc16)),     ((char)(0x11a5 + 1595 - 0x176e)),
    ((char)(0x8c3 + 7422 - 0x2547)),  ((char)(0x6eb + 7884 - 0x2543)),
    ((char)(0xf3f + 1855 - 0x1610)),  ((char)(0x5e1 + 4029 - 0x1527)),
    ((char)(0x91d + 3775 - 0x1772)),  ((char)(0x1477 + 2278 - 0x1ced)),
    ((char)(0x4af + 8015 - 0x2398)),  ((char)(0x135 + 6993 - 0x1c19)),
    ((char)(0x1b4b + 2756 - 0x25ae)), ((char)(0x1e2f + 2194 - 0x2650))};
int main() {
  int z11fac29223;
  freopen("\x69\x6e\x2e\x74\x78\x74", "\x72", stdin);
  freopen("\x6f\x75\x74\x2e\x74\x78\x74", "\x77", stdout);
  scanf("\x25\x64\x20", &z11fac29223);
  int zb9ab10c1bc;
  for (zb9ab10c1bc = (0x63b + 5445 - 0x1b80); zb9ab10c1bc < z11fac29223;
       zb9ab10c1bc++) {
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
           zb9ab10c1bc + (0xa2b + 4735 - 0x1ca9));
    zcfb2c0dead();
  }
}
void zcfb2c0dead() {
  char line[(0x1024 + 986 - 0xc2e)];
  char z25577617f0;
  int zb9ab10c1bc = (0x749 + 3506 - 0x14fb);
  scanf("\x25\x63", &z25577617f0);
  while (z25577617f0 != '\n') {
    line[zb9ab10c1bc] = z25577617f0;
    zb9ab10c1bc++;
    scanf("\x25\x63", &z25577617f0);
  }
  line[zb9ab10c1bc] = '\0';
  for (zb9ab10c1bc = (0xa4a + 5747 - 0x20bd); line[zb9ab10c1bc] != '\0';
       zb9ab10c1bc++) {
    if (line[zb9ab10c1bc] >= ((char)(0xe37 + 6439 - 0x26fd)) &&
        line[zb9ab10c1bc] <= ((char)(0xaa1 + 2788 - 0x150b))) {
      printf("\x25\x63",
             zdca3ab6064[line[zb9ab10c1bc] - ((char)(0x2ff + 9151 - 0x265d))]);
    } else {
      printf("\x20");
    }
  }
  printf("\n");
}
