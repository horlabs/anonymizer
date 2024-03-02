
#include <stdio.h>

int main() {
  int z8a28c4ef8e, z50261b460f, zebc851bda9, z320085005f,
      z16363fa390[(0xa5f + 1436 - 0xf96)][(0xd49 + 5885 - 0x23e1)], z3b0fc27294,
      z236f0af35d, z360bb5bab4[(0xbf1 + 2016 - 0x136d)],
      zda05206bb8[(0x2433 + 468 - 0x25a3)];
  scanf("\x25\x64", &z8a28c4ef8e);
  for (z50261b460f = (0x1f2f + 1057 - 0x2350); z50261b460f < z8a28c4ef8e;
       z50261b460f++) {
    scanf("\x25\x64\x25\x64", &z3b0fc27294, &z236f0af35d);
    for (zebc851bda9 = (0xe36 + 2771 - 0x1909); zebc851bda9 < z3b0fc27294;
         zebc851bda9++)
      z360bb5bab4[zebc851bda9] = (0x2258 + 435 - 0x240b);
    for (z320085005f = (0x11bf + 4175 - 0x220e); z320085005f < z236f0af35d;
         z320085005f++)
      zda05206bb8[z320085005f] = (0x89f + 2247 - 0x1166);
    for (zebc851bda9 = (0x73 + 7969 - 0x1f94); zebc851bda9 < z3b0fc27294;
         zebc851bda9++) {
      for (z320085005f = (0x1b3 + 7806 - 0x2031); z320085005f < z236f0af35d;
           z320085005f++) {
        scanf("\x25\x64", &z16363fa390[zebc851bda9][z320085005f]);
        if (z16363fa390[zebc851bda9][z320085005f] > z360bb5bab4[zebc851bda9])
          z360bb5bab4[zebc851bda9] = z16363fa390[zebc851bda9][z320085005f];
        if (z16363fa390[zebc851bda9][z320085005f] > zda05206bb8[z320085005f])
          zda05206bb8[z320085005f] = z16363fa390[zebc851bda9][z320085005f];
      }
    }
    for (zebc851bda9 = (0x15b5 + 2231 - 0x1e6c); zebc851bda9 < z3b0fc27294;
         zebc851bda9++) {
      for (z320085005f = (0xf0 + 7843 - 0x1f93); z320085005f < z236f0af35d;
           z320085005f++) {
        if (z16363fa390[zebc851bda9][z320085005f] != z360bb5bab4[zebc851bda9] &&
            z16363fa390[zebc851bda9][z320085005f] != zda05206bb8[z320085005f])
          break;
      }
      if (z320085005f != z236f0af35d)
        break;
    }
    if (zebc851bda9 != z3b0fc27294)
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x4e\x4f"
             "\n",
             z50261b460f + (0x1ff + 5202 - 0x1650));
    else
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x59\x45\x53"
             "\n",
             z50261b460f + (0x17cd + 755 - 0x1abf));
  }
  return (0xbd + 3948 - 0x1029);
}
