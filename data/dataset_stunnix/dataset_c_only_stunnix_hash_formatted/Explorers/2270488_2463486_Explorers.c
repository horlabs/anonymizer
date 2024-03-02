
#include <math.h>
#include <stdio.h>

int main() {
  int zafab28baea;
  int zc5954f1d42[(0x1bb + 2484 - 0xb0b)] = {(0x1e65 + 819 - 0x2198)};
  int z8fb082c464, z517b5f24cd, zb0554b2830, z03d661731a, zd86b8418fc;
  scanf("\x25\x64", &zafab28baea);
  for (z03d661731a = (0x10ef + 721 - 0x13c0); z03d661731a < zafab28baea;
       z03d661731a++) {
    scanf("\x25\x64\x20\x25\x64", &z8fb082c464, &z517b5f24cd);
    for (zd86b8418fc = z8fb082c464; zd86b8418fc <= z517b5f24cd; zd86b8418fc++) {
      if (z651c091578(zd86b8418fc) == (0xa90 + 594 - 0xce2))
        continue;
      if ((zb0554b2830 = z1153e85f7d(zd86b8418fc)) == (0x17c2 + 383 - 0x1941))
        continue;
      if (z651c091578(zb0554b2830) != (0x1599 + 3650 - 0x23db))
        zc5954f1d42[z03d661731a]++;
    }
  }
  for (z03d661731a = (0x126d + 151 - 0x1304); z03d661731a < zafab28baea;
       z03d661731a++)
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z03d661731a + (0x3d6 + 3752 - 0x127d), zc5954f1d42[z03d661731a]);
}
int z651c091578(int z65a7847443) {
  int z7dc592f6e9 = (0x596 + 8502 - 0x26cc);
  int zb593c5cae0 = z65a7847443;
  while (zb593c5cae0 != (0xea + 3991 - 0x1081)) {
    z7dc592f6e9 = z7dc592f6e9 * (0x1312 + 3037 - 0x1ee5) +
                  (zb593c5cae0 % (0x106f + 933 - 0x140a));
    zb593c5cae0 /= (0x1ec2 + 1583 - 0x24e7);
  }
  if (z7dc592f6e9 == z65a7847443)
    return (0x18e2 + 3564 - 0x26cd);
  else
    return (0xadf + 7184 - 0x26ef);
}
int z1153e85f7d(int z65a7847443) {
  double zb1da58dc35, ze4a85f1dc1;
  zb1da58dc35 = sqrt(z65a7847443);
  ze4a85f1dc1 = zb1da58dc35 - (int)zb1da58dc35;
  if (ze4a85f1dc1 == 0.0)
    return zb1da58dc35;
  else
    return (0x147c + 180 - 0x1530);
}
