
#include <stdio.h>

int main() {
  int zc72b8c1bf6;
  int zd1daf3e89f, z2d4c8a5e84, z515794b393;
  char *z3b9c3af931[(0x1431 + 4725 - 0x2642)];
  int z21192428ba[(0x1626 + 866 - 0x197e)][(0x19b9 + 9 - 0x19b8)];
  int z70a8b9098a, z651f32c399;
  int zab9f96c535 = (0xfb6 + 5071 - 0x2385);
  scanf("\x25\x64", &zc72b8c1bf6);
  for (zd1daf3e89f = (0x2cf + 8702 - 0x24cd); zd1daf3e89f < zc72b8c1bf6;
       zd1daf3e89f++) {
    zab9f96c535 = (0x60c + 5731 - 0x1c6f);
    scanf("\x25\x64\x20\x25\x64", &z70a8b9098a, &z651f32c399);
    for (z515794b393 = (0x66a + 1025 - 0xa6b); z515794b393 < z70a8b9098a;
         z515794b393++) {
      for (z2d4c8a5e84 = (0x4f1 + 104 - 0x559); z2d4c8a5e84 < z651f32c399;
           z2d4c8a5e84++)
        scanf("\x25\x64", &z21192428ba[z515794b393][z2d4c8a5e84]);
    }
    for (z515794b393 = (0xd5c + 4616 - 0x1f64); z515794b393 < z70a8b9098a;
         z515794b393++) {
      for (z2d4c8a5e84 = (0x14e7 + 2529 - 0x1ec8); z2d4c8a5e84 < z651f32c399;
           z2d4c8a5e84++) {
        if (z21192428ba[z515794b393][z2d4c8a5e84] == (0x1834 + 1504 - 0x1e13)) {
          if (zc035bdee92(z515794b393, z2d4c8a5e84, z70a8b9098a, z651f32c399,
                          z21192428ba) == (0x1336 + 4953 - 0x268e) ||
              zbf2e55665a(z515794b393, z2d4c8a5e84, z70a8b9098a, z651f32c399,
                          z21192428ba) == (0x2401 + 746 - 0x26ea))
            continue;
          else {
            zab9f96c535 = (0xeea + 3592 - 0x1cf1);
            break;
          }
        }
      }
      if (zab9f96c535 == (0x337 + 2204 - 0xbd2))
        break;
    }
    if (zab9f96c535 == (0x15b2 + 1894 - 0x1d17))
      z3b9c3af931[zd1daf3e89f] = "\x4e\x4f";
    else
      z3b9c3af931[zd1daf3e89f] = "\x59\x45\x53";
  }
  for (zd1daf3e89f = (0x103c + 1040 - 0x144c); zd1daf3e89f < zc72b8c1bf6;
       zd1daf3e89f++)
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
           "\n",
           zd1daf3e89f + (0x80b + 4235 - 0x1895), z3b9c3af931[zd1daf3e89f]);
}
int zc035bdee92(
    int zdb7ab9d4d9, int zeced4cf9a2, int z70a8b9098a, int z651f32c399,
    int z21192428ba[(0x14f + 1164 - 0x5d1)][(0x1233 + 2371 - 0x1b6c)]) {
  int zd1daf3e89f;
  for (zd1daf3e89f = (0x1c4a + 2727 - 0x26f1); zd1daf3e89f < z651f32c399;
       zd1daf3e89f++) {
    if (z21192428ba[zdb7ab9d4d9][zd1daf3e89f] != (0x5e9 + 6676 - 0x1ffc))
      return (0xbb5 + 672 - 0xe55);
  }
  return (0x143c + 373 - 0x15b0);
}
int zbf2e55665a(
    int zdb7ab9d4d9, int zeced4cf9a2, int z70a8b9098a, int z651f32c399,
    int z21192428ba[(0x1efa + 954 - 0x22aa)][(0x399 + 2868 - 0xec3)]) {
  int zd1daf3e89f;
  for (zd1daf3e89f = (0x1865 + 1555 - 0x1e78); zd1daf3e89f < z70a8b9098a;
       zd1daf3e89f++) {
    if (z21192428ba[zd1daf3e89f][zeced4cf9a2] != (0xc76 + 3320 - 0x196d))
      return (0x40 + 8370 - 0x20f2);
  }
  return (0x15ca + 1734 - 0x1c8f);
}
