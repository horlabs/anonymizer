
#include <stdio.h>

void zf70af8ebac() {
  double C, F, X, z0de6a1ebd0 = 1e100, z4a53a98ed4,
                  zc68e304ccb = (0xb00 + 1928 - 0x1286);
  int z50d3331102;
  scanf("\x25\x6c\x66\x20\x25\x6c\x66\x20\x25\x6c\x66", &C, &F, &X);
  z4a53a98ed4 = (0x90d + 3974 - 0x1893);
  z0de6a1ebd0 = X / zc68e304ccb;
  for (z50d3331102 = (0x1420 + 235 - 0x150a); z50d3331102 < 2000000000;
       z50d3331102++) {
    z4a53a98ed4 += C / zc68e304ccb;
    zc68e304ccb += F;
    if (z0de6a1ebd0 <= z4a53a98ed4 + X / zc68e304ccb)
      break;
    z0de6a1ebd0 = z4a53a98ed4 + X / zc68e304ccb;
  }
  printf("\x25\x2e\x31\x30\x66"
         "\n",
         z0de6a1ebd0);
  return;
}
int main() {
  int z8778d5d762, z7ac082ac55 = (0x1235 + 4124 - 0x2250);
  scanf("\x25\x64", &z8778d5d762);
  while (z8778d5d762--)
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", z7ac082ac55++),
        zf70af8ebac();
  return (0x1335 + 4978 - 0x26a7);
}
