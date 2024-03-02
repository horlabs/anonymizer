
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *z6135111cb8, *ze76a11babc;
char zf4bebc4fa8[(0xf65 + 5965 - 0x2698)];
void z2990c5b11d() {
  zf4bebc4fa8[(0x2613 + 85 - 0x2668)] = ((char)(0x761 + 63 - 0x727));
  zf4bebc4fa8[(0x1669 + 1818 - 0x1d82)] = ((char)(0x722 + 7491 - 0x23f7));
  zf4bebc4fa8[(0x1884 + 2706 - 0x2314)] = ((char)(0x367 + 289 - 0x422));
  zf4bebc4fa8[(0xca0 + 4687 - 0x1eec)] = ((char)(0x16c1 + 3499 - 0x2403));
  zf4bebc4fa8[(0x1f4a + 1922 - 0x26c8)] = ((char)(0x1b1d + 924 - 0x1e56));
  zf4bebc4fa8[(0x10c + 169 - 0x1b0)] = ((char)(0xdc9 + 5321 - 0x221b));
  zf4bebc4fa8[(0xf56 + 1670 - 0x15d6)] = ((char)(0xd6d + 3037 - 0x18de));
  zf4bebc4fa8[(0x1b3b + 715 - 0x1dff)] = ((char)(0xddf + 197 - 0xe42));
  zf4bebc4fa8[(0xe06 + 5809 - 0x24af)] = ((char)(0x52b + 6958 - 0x1fee));
  zf4bebc4fa8[(0x4ff + 3922 - 0x1448)] = ((char)(0x158 + 3687 - 0xf4a));
  zf4bebc4fa8[(0x1231 + 959 - 0x15e6)] = ((char)(0x2003 + 564 - 0x21c8));
  zf4bebc4fa8[(0x311 + 4779 - 0x15b1)] = ((char)(0xcf0 + 6179 - 0x24a6));
  zf4bebc4fa8[(0x1b68 + 774 - 0x1e62)] = ((char)(0xa54 + 1014 - 0xdd2));
  zf4bebc4fa8[(0x6bc + 2666 - 0x1119)] = ((char)(0xac + 178 - 0xeb));
  zf4bebc4fa8[(0x1525 + 342 - 0x166d)] = ((char)(0x115d + 5536 - 0x2698));
  zf4bebc4fa8[(0x911 + 4221 - 0x197f)] = ((char)(0xd9a + 632 - 0xf9c));
  zf4bebc4fa8[(0x2100 + 1533 - 0x26ed)] = ((char)(0xf99 + 1130 - 0x1389));
  zf4bebc4fa8[(0x5cc + 2412 - 0xf27)] = ((char)(0xbfa + 2080 - 0x13aa));
  zf4bebc4fa8[(0x14 + 2425 - 0x97b)] = ((char)(0x41f + 1370 - 0x915));
  zf4bebc4fa8[(0x1141 + 2939 - 0x1ca9)] = ((char)(0x414 + 6694 - 0x1dc8));
  zf4bebc4fa8[(0x440 + 8009 - 0x2375)] = ((char)(0x234 + 5269 - 0x165f));
  zf4bebc4fa8[(0xd59 + 3523 - 0x1b07)] = ((char)(0x16c7 + 3275 - 0x232b));
  zf4bebc4fa8[(0x509 + 8647 - 0x26ba)] = ((char)(0x1986 + 2484 - 0x22c6));
  zf4bebc4fa8[(0x5a5 + 7345 - 0x223f)] = ((char)(0x803 + 5102 - 0x1b89));
  zf4bebc4fa8[(0x1097 + 4596 - 0x2273)] = ((char)(0xb2d + 1051 - 0xee7));
  zf4bebc4fa8[(0x14d5 + 2843 - 0x1fd7)] = ((char)(0x554 + 1388 - 0xa4f));
}
char zc002b256de(char z3d1e34eb98) {
  int z8c555da0a9;
  for (z8c555da0a9 = (0xd14 + 1429 - 0x12a9);
       z8c555da0a9 < (0x2024 + 1121 - 0x246b); z8c555da0a9++) {
    if (zf4bebc4fa8[z8c555da0a9] == z3d1e34eb98)
      return (z8c555da0a9 + ((char)(0xdd5 + 2842 - 0x188e)));
  }
  return (((char)(0xd89 + 4099 - 0x1d6c)));
}
void Main() {
  char z3d1e34eb98, z1473ee5d6f, z06a832e142[(0x183a + 1190 - 0x1aec)],
      z50f9270804 = (0x101a + 1012 - 0x140e);
  int z8c555da0a9;
  z3d1e34eb98 = fgetc(z6135111cb8);
  while (z3d1e34eb98 != '\n') {
    z06a832e142[z50f9270804++] = z3d1e34eb98;
    z3d1e34eb98 = fgetc(z6135111cb8);
  }
  for (z8c555da0a9 = (0x5cb + 4584 - 0x17b3); z8c555da0a9 < z50f9270804;
       z8c555da0a9++)
    z06a832e142[z8c555da0a9] = zc002b256de(z06a832e142[z8c555da0a9]);
  z06a832e142[z50f9270804] = '\0';
  fprintf(ze76a11babc, "\x25\x73", z06a832e142);
}
int main() {
  z6135111cb8 = fopen("\x2f\x68\x6f\x6d\x65\x2f\x76\x69\x76\x65\x6b\x2f\x44\x65"
                      "\x73\x6b\x74\x6f\x70\x2f\x73\x2e\x69\x6e",
                      "\x72");
  ze76a11babc = fopen("\x2f\x68\x6f\x6d\x65\x2f\x76\x69\x76\x65\x6b\x2f\x44\x65"
                      "\x73\x6b\x74\x6f\x70\x2f\x73\x2e\x6f\x75\x74",
                      "\x77");
  int zcee0e861c9, z8c555da0a9;
  char z3d1e34eb98;
  z2990c5b11d();
  fscanf(z6135111cb8, "\x25\x64", &zcee0e861c9);
  while (fgetc(z6135111cb8) != '\n')
    ;
  for (z8c555da0a9 = (0x827 + 7065 - 0x23bf); z8c555da0a9 <= zcee0e861c9;
       z8c555da0a9++) {
    fprintf(ze76a11babc, "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
            z8c555da0a9);
    Main();
    z3d1e34eb98 = '\n';
    fputc(z3d1e34eb98, ze76a11babc);
    printf("\x25\x64", z8c555da0a9);
  }
  return ((0x1cfc + 905 - 0x2084));
}
