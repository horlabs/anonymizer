
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int zdb7f888098(unsigned long z09232cf7fa) {
  char z8b580c4227[(0x16d + 9227 - 0x2514)];
  int z58af6dbdf6, z404e9b8eae, zb1b9a52e22;
  sprintf(z8b580c4227, "\x25\x6c\x75\x20", z09232cf7fa);
  z404e9b8eae = strlen(z8b580c4227) - (0xc61 + 3781 - 0x1b25);
  zb1b9a52e22 = z404e9b8eae / (0x788 + 4203 - 0x17f1);
  for (z58af6dbdf6 = (0xa51 + 4211 - 0x1ac4); z58af6dbdf6 < zb1b9a52e22;
       z58af6dbdf6++) {
    if (z8b580c4227[z58af6dbdf6] !=
        z8b580c4227[z404e9b8eae - (0x1893 + 2118 - 0x20d8) - z58af6dbdf6])
      return (0x7f6 + 2789 - 0x12db);
  }
  return (0x1092 + 109 - 0x10fe);
}
int main(int z2f813f13d3, char **zde5cb9206b) {
  int z9e0ecee5be, z58af6dbdf6, z770d847701;
  char line[(0x9a5 + 5849 - 0x2074)];
  unsigned long z8b43469106, zee881ef314, zeb245eb67e, z47de9a0542, z5ce124e12a;
  assert(scanf("\x25\x64\x20", &z9e0ecee5be) == (0x1ac7 + 1139 - 0x1f39));
  for (z58af6dbdf6 = (0x80a + 1185 - 0xcaa); z58af6dbdf6 <= z9e0ecee5be;
       z58af6dbdf6++) {
    z770d847701 = (0x40f + 1017 - 0x808);
    assert(scanf("\x25\x6c\x75\x20\x25\x6c\x75\x20", &z8b43469106,
                 &zee881ef314) == (0x19e6 + 1254 - 0x1eca));
    zeb245eb67e = ceil(sqrt(z8b43469106));
    z47de9a0542 = floor(sqrt(zee881ef314));
    for (z5ce124e12a = zeb245eb67e; z5ce124e12a <= z47de9a0542; z5ce124e12a++) {
      if (zdb7f888098(z5ce124e12a) && zdb7f888098(z5ce124e12a * z5ce124e12a))
        z770d847701++;
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z58af6dbdf6, z770d847701);
  }
  return (0x1c04 + 203 - 0x1ccf);
}
