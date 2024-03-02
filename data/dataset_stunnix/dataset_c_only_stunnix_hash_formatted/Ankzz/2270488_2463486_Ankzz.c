
#include <math.h>
#include <stdio.h>

short z0a46d79df0(long z1a5f36fb86) {
  long z108b4a4119, z3531e64c03 = (0x179a + 3559 - 0x2581);
  z108b4a4119 = z1a5f36fb86;
  while (z108b4a4119 != (0x47c + 6177 - 0x1c9d)) {
    z3531e64c03 = z3531e64c03 * (0xcca + 1704 - 0x1368);
    z3531e64c03 = z3531e64c03 + z108b4a4119 % (0x1f8 + 1754 - 0x8c8);
    z108b4a4119 /= (0xec2 + 5545 - 0x2461);
  }
  return z1a5f36fb86 == z3531e64c03;
}
int z947e36accd(int z2cf9907dc4) {
  int zbf899224b8 = z2cf9907dc4 & (0xe85 + 3053 - 0x1a63);
  if (zbf899224b8 > (0xa60 + 769 - 0xd58))
    return (0x12a0 + 1778 - 0x1992);
  if (zbf899224b8 != (0x19e9 + 1047 - 0x1dfe) &&
      zbf899224b8 != (0x1d3a + 2275 - 0x261a) &&
      zbf899224b8 != (0xf92 + 2038 - 0x1783) &&
      zbf899224b8 != (0xaa + 2298 - 0x99e) &&
      zbf899224b8 != (0x194a + 657 - 0x1bd4) &&
      zbf899224b8 != (0xa23 + 5029 - 0x1dc0)) {
    int z108b4a4119 = (int)floor(sqrt((double)z2cf9907dc4) + 0.5);
    return ((z108b4a4119 * z108b4a4119 == z2cf9907dc4) &&
            z0a46d79df0(z108b4a4119));
  }
  return (0x1b2b + 707 - 0x1dee);
}
int main() {
  int z3ac862069d = -(0x1889 + 1477 - 0x1e4d);
  int zdef8bc276b = (0x156a + 2911 - 0x20c9);
  FILE *z41f0ab56b2 = fopen("\x43\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65"
                            "\x6d\x70\x74\x30\x2e\x69\x6e",
                            "\x72");
  FILE *z6a52a32567 = fopen("\x6f\x75\x74\x70\x75\x74\x2e\x74\x78\x74", "\x77");
  fscanf(z41f0ab56b2, "\x25\x64", &z3ac862069d);
  while (++zdef8bc276b <= z3ac862069d) {
    unsigned long z1a5f36fb86 = (0x46a + 6161 - 0x1c7b),
                  z325996fadd = (0x1ccb + 281 - 0x1de4);
    int z9a33247a61 = (0x1189 + 704 - 0x1449);
    fscanf(z41f0ab56b2, "\x25\x6c\x64\x20\x25\x6c\x64", &z1a5f36fb86,
           &z325996fadd);
    while (z1a5f36fb86 <= z325996fadd) {
      if (z0a46d79df0(z1a5f36fb86)) {
        if (z947e36accd(z1a5f36fb86)) {
          z9a33247a61++;
        }
      }
      z1a5f36fb86++;
    }
    fprintf(z6a52a32567,
            "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
            "\n",
            zdef8bc276b, z9a33247a61);
  }
  fclose(z41f0ab56b2);
  fclose(z6a52a32567);
  return (0x32c + 6351 - 0x1bfb);
}
