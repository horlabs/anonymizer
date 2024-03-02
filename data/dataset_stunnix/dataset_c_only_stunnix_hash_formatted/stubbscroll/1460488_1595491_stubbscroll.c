
#include <stdio.h>
#include <stdlib.h>

int z273b82e1bd(const void *za29b929738, const void *z1ba38ded84) {
  if (*(int *)za29b929738 > *(int *)z1ba38ded84)
    return -(0x223 + 7034 - 0x1d9c);
  if (*(int *)za29b929738 < *(int *)z1ba38ded84)
    return (0x14a6 + 4122 - 0x24bf);
  return (0x1b95 + 2254 - 0x2463);
}
int main() {
  int z305c3cc5cc, z279b88a5d5 = (0x84d + 4592 - 0x1a3c);
  int z18f87d0b1a, z538befeae9, z696920cd17, z07bdede08c, z0f153b1e8f;
  int z3884e0ffc8, z17361b27c4[(0x2f1 + 3762 - 0x113f)], z00af86342b;
  scanf("\x25\x64", &z305c3cc5cc);
  while (z305c3cc5cc--) {
    scanf("\x25\x64\x20\x25\x64\x20\x25\x64", &z18f87d0b1a, &z538befeae9,
          &z696920cd17);
    for (z3884e0ffc8 = (0xbb9 + 6413 - 0x24c6); z3884e0ffc8 < z18f87d0b1a;
         z3884e0ffc8++)
      scanf("\x25\x64", &z17361b27c4[z3884e0ffc8]);
    qsort(z17361b27c4, z18f87d0b1a, sizeof(int), z273b82e1bd);
    z07bdede08c = z696920cd17 - (0x14e7 + 4188 - 0x2542);
    z0f153b1e8f = z696920cd17 - (0x36f + 1747 - 0xa40);
    if (z07bdede08c < (0x22b5 + 776 - 0x25bd))
      z07bdede08c = (0x333 + 6906 - 0x1e2d);
    if (z0f153b1e8f < (0x2aa + 6944 - 0x1dca))
      z0f153b1e8f = (0x92d + 429 - 0xada);
    for (z00af86342b = z3884e0ffc8 = (0x6c9 + 5435 - 0x1c04);
         z3884e0ffc8 < z18f87d0b1a; z3884e0ffc8++) {
      if (z17361b27c4[z3884e0ffc8] >= z696920cd17 + z07bdede08c + z07bdede08c)
        z00af86342b++;
      else if (z538befeae9 && z17361b27c4[z3884e0ffc8] >=
                                  z696920cd17 + z0f153b1e8f + z0f153b1e8f)
        z00af86342b++, z538befeae9--;
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z279b88a5d5++, z00af86342b);
  }
  return (0x10cd + 1909 - 0x1842);
}
