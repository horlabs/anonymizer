
#include <stdio.h>
#include <string.h>

typedef long long zc2a0399511;
zc2a0399511 z4f75ff9439[1000000];
int zb77d7d3412;
void zb4a09e45af() {
  char zefbb85cfe4[(0xd4c + 6369 - 0x2619)],
      z4c62d6193f[(0x135c + 4088 - 0x2340)];
  int z5790525494, z516bdf5793, z65deab0964;
  zb77d7d3412 = (0xc8 + 725 - 0x39d);
  for (z5790525494 = (0x1229 + 897 - 0x15a9); z5790525494 < 10000001;
       z5790525494++) {
    sprintf(zefbb85cfe4, "\x25\x64", z5790525494);
    z65deab0964 = strlen(zefbb85cfe4);
    for (z516bdf5793 = (0x768 + 6019 - 0x1eeb);
         z516bdf5793 + z516bdf5793 < z65deab0964; z516bdf5793++)
      if (zefbb85cfe4[z516bdf5793] !=
          zefbb85cfe4[z65deab0964 - z516bdf5793 - (0xb7a + 1485 - 0x1146)])
        goto zb398b8e7b4;
    sprintf(z4c62d6193f, "\x25\x49\x36\x34\x64",
            (zc2a0399511)z5790525494 * z5790525494);
    z65deab0964 = strlen(z4c62d6193f);
    for (z516bdf5793 = (0x1afd + 2863 - 0x262c);
         z516bdf5793 + z516bdf5793 < z65deab0964; z516bdf5793++)
      if (z4c62d6193f[z516bdf5793] !=
          z4c62d6193f[z65deab0964 - z516bdf5793 - (0x44 + 98 - 0xa5)])
        goto zb398b8e7b4;
    z4f75ff9439[zb77d7d3412++] = (zc2a0399511)z5790525494 * z5790525494;
  zb398b8e7b4:;
  }
}
int main() {
  int zd7869d4c0d, z5790525494, z4ccb71d97c,
      za6d084eac5 = (0x1234 + 695 - 0x14ea), z516bdf5793, z6de5525b75;
  zb4a09e45af();
  scanf("\x25\x64", &zd7869d4c0d);
  while (zd7869d4c0d--) {
    scanf("\x25\x64\x20\x25\x64", &z5790525494, &z4ccb71d97c);
    for (z6de5525b75 = z516bdf5793 = (0x493 + 3424 - 0x11f3);
         z516bdf5793 < zb77d7d3412; z516bdf5793++)
      if (z5790525494 <= z4f75ff9439[z516bdf5793] &&
          z4f75ff9439[z516bdf5793] <= z4ccb71d97c)
        z6de5525b75++;
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           za6d084eac5++, z6de5525b75);
  }
  return (0x2a + 8407 - 0x2101);
}
