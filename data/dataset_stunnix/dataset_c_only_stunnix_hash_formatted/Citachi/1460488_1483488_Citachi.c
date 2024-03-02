
#include <stdio.h>

int main() {
  unsigned int z6041e909ea, z3fc0194bdb, z0a1d8a1afa,
      zf244e5c88f = (0x679 + 2592 - 0x1099),
      z3318afec20 = (0x823 + 5652 - 0x1e37),
      z21ff714a1b = (0x537 + 2358 - 0xe6d), z04b7cc4acc,
      zd11b0533ad = (0x1dba + 1487 - 0x2388), ze30612080e,
      z5f24d8d1e8 = (0x32b + 3357 - 0x1047), z68d80f6f76;
  FILE *zbcf416c599, *zbd3d7d15d0;
  zbcf416c599 = fopen("\x43\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70"
                      "\x74\x32\x2e\x69\x6e",
                      "\x72");
  zbd3d7d15d0 = fopen("\x6f\x75\x74\x70\x75\x74\x2e\x74\x78\x74", "\x77");
  fscanf(zbcf416c599, "\x25\x64", &z68d80f6f76);
  while (z5f24d8d1e8 <= z68d80f6f76) {
    fscanf(zbcf416c599, "\x25\x64\x20\x25\x64", &z6041e909ea, &z3fc0194bdb);
    z0a1d8a1afa = z6041e909ea;
    while (z0a1d8a1afa != (0x30f + 6733 - 0x1d5c)) {
      z21ff714a1b++;
      z0a1d8a1afa = z0a1d8a1afa / (0x1491 + 1404 - 0x1a03);
    }
    while (z6041e909ea < z3fc0194bdb) {
      z04b7cc4acc = z21ff714a1b;
      zf244e5c88f = z6041e909ea;
      while (z04b7cc4acc != (0x9c8 + 627 - 0xc3b)) {
        zd11b0533ad = (0x4bb + 3614 - 0x12d8);
        for (ze30612080e = (0x155c + 422 - 0x1701);
             ze30612080e <= z21ff714a1b - (0x72d + 5466 - 0x1c86);
             ze30612080e++)
          zd11b0533ad = zd11b0533ad * (0x13bc + 208 - 0x1482);
        zf244e5c88f = zf244e5c88f / (0x4a9 + 8539 - 0x25fa) +
                      (zf244e5c88f % (0x10d3 + 768 - 0x13c9)) * zd11b0533ad;
        z04b7cc4acc--;
        if (zf244e5c88f <= z3fc0194bdb && zf244e5c88f > z6041e909ea) {
          z3318afec20++;
        }
      }
      z6041e909ea++;
    }
    fprintf(zbd3d7d15d0,
            "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
            "\n",
            z5f24d8d1e8, z3318afec20);
    z5f24d8d1e8++;
    z3318afec20 = (0x129 + 4628 - 0x133d);
    z21ff714a1b = (0x605 + 4387 - 0x1728);
  }
  fclose(zbcf416c599);
  fclose(zbd3d7d15d0);
  return (0x19a1 + 3302 - 0x2687);
}
