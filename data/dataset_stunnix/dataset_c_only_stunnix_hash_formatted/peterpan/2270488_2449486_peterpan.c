
#include <stdio.h>
#include <stdlib.h>

void z0cb271c672() {
  while (getchar() != '\n')
    ;
}
int main() {
  int z51ae37e99a, z80286a9dca, za7be3caf6b, z61afa7c50a, z61a94ad940,
      z2e889ca7b3, zaf14d6d2a8;
  int z9cb784d22d[(0x20b2 + 816 - 0x237d)][(0xaba + 4867 - 0x1d58)],
      zeb893424e1[(0x1eeb + 434 - 0x2038)],
      z841c440bb9[(0x867 + 7093 - 0x23b7)];
  scanf("\x25\x64", &z61afa7c50a);
  for (za7be3caf6b = (0x1a1a + 3107 - 0x263c); za7be3caf6b <= z61afa7c50a;
       za7be3caf6b++) {
    scanf("\x25\x64", &z61a94ad940);
    scanf("\x25\x64", &z2e889ca7b3);
    zaf14d6d2a8 = (0x1243 + 4989 - 0x25bf);
    for (z51ae37e99a = (0x718 + 2441 - 0x10a1); z51ae37e99a < z61a94ad940;
         z51ae37e99a++) {
      zeb893424e1[z51ae37e99a] = (0x9b + 9124 - 0x243f);
      for (z80286a9dca = (0x7d4 + 7710 - 0x25f2); z80286a9dca < z2e889ca7b3;
           z80286a9dca++) {
        scanf("\x25\x64", &(z9cb784d22d[z51ae37e99a][z80286a9dca]));
        if (zeb893424e1[z51ae37e99a] < z9cb784d22d[z51ae37e99a][z80286a9dca])
          zeb893424e1[z51ae37e99a] = z9cb784d22d[z51ae37e99a][z80286a9dca];
      }
    }
    for (z80286a9dca = (0x1171 + 3479 - 0x1f08); z80286a9dca < z2e889ca7b3;
         z80286a9dca++) {
      z841c440bb9[z80286a9dca] = (0x46a + 4043 - 0x1435);
      for (z51ae37e99a = (0x1e24 + 345 - 0x1f7d); z51ae37e99a < z61a94ad940;
           z51ae37e99a++)
        if (z841c440bb9[z80286a9dca] < z9cb784d22d[z51ae37e99a][z80286a9dca])
          z841c440bb9[z80286a9dca] = z9cb784d22d[z51ae37e99a][z80286a9dca];
    }
    for (z51ae37e99a = (0x1471 + 2899 - 0x1fc4);
         z51ae37e99a < z61a94ad940 && zaf14d6d2a8; z51ae37e99a++)
      for (z80286a9dca = (0x379 + 2662 - 0xddf); z80286a9dca < z2e889ca7b3;
           z80286a9dca++)
        if (z9cb784d22d[z51ae37e99a][z80286a9dca] < zeb893424e1[z51ae37e99a] &&
            z9cb784d22d[z51ae37e99a][z80286a9dca] < z841c440bb9[z80286a9dca]) {
          zaf14d6d2a8 = (0x11e3 + 2536 - 0x1bcb);
          break;
        }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
           "\n",
           za7be3caf6b, zaf14d6d2a8 ? "\x59\x45\x53" : "\x4e\x4f");
  }
  return (0x89a + 1965 - 0x1047);
}
