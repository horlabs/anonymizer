
#include <stdio.h>

int main() {
  int zf39deae69c, z1fe5689a7f;
  scanf("\x25\x64", &zf39deae69c);
  for (z1fe5689a7f = (0x43c + 3427 - 0x119e); z1fe5689a7f <= zf39deae69c;
       z1fe5689a7f++) {
    int z7af918dad2, z9b5c936b53, z37631b8ffb,
        z2521e47c23 = (0xbe5 + 5731 - 0x2248),
        z3c8bc0bf31 = (0x4da + 2659 - 0xf3d);
    scanf("\x25\x64\x20\x25\x64\x20\x25\x64", &z7af918dad2, &z9b5c936b53,
          &z37631b8ffb);
    while (z7af918dad2--) {
      int zcc15823cd0, z1c611b3e0a;
      scanf("\x25\x64", &z1c611b3e0a);
      zcc15823cd0 =
          (z1c611b3e0a + (0x3b3 + 3344 - 0x10c1)) / (0xc9b + 4929 - 0x1fd9);
      if (z1c611b3e0a > (0x12ab + 263 - 0x1396) ||
          z1c611b3e0a < (0x8c0 + 1029 - 0xcc3)) {
        if (zcc15823cd0 >= z37631b8ffb)
          z3c8bc0bf31++;
        continue;
      }
      if (zcc15823cd0 >= z37631b8ffb)
        z3c8bc0bf31++;
      else if (zcc15823cd0 + (0x11c + 1741 - 0x7e8) >= z37631b8ffb &&
               (z1c611b3e0a % (0x9a6 + 7018 - 0x250d)) !=
                   (0x484 + 3854 - 0x1391))
        z2521e47c23++;
    }
    if (z2521e47c23 >= z9b5c936b53)
      z3c8bc0bf31 += z9b5c936b53;
    else
      z3c8bc0bf31 += z2521e47c23;
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z1fe5689a7f, z3c8bc0bf31);
  }
  return (0x122a + 3922 - 0x217c);
}
