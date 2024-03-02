
#include <stdio.h>
#include <string.h>

int z220849e6b8;
int z1decb8a962;
int z877f251364(int z8918e693f8) {
  int za456eece9c = (0x1f38 + 1468 - 0x24f4);
  int z9eeee66257 = z8918e693f8;
  while ((0x8f3 + 2200 - 0x118a)) {
    z9eeee66257 = z9eeee66257 / z220849e6b8 +
                  (z9eeee66257 % z220849e6b8) * (0x678 + 687 - 0x91d);
    if (z8918e693f8 == z9eeee66257)
      break;
    if (z9eeee66257 > z1decb8a962)
      continue;
    if (z8918e693f8 < z9eeee66257)
      ++za456eece9c;
  }
  return za456eece9c;
}
int main(void) {
  int z1f48929cfb, z9e2c24d368;
  int zf9d528fc68, z0d60f4daf7;
  int za456eece9c;
  scanf("\x25\x64", &z1f48929cfb);
  for (zf9d528fc68 = (0x16ca + 363 - 0x1834); zf9d528fc68 <= z1f48929cfb;
       ++zf9d528fc68) {
    za456eece9c = (0xe41 + 1560 - 0x1459);
    scanf("\x25\x64\x20\x25\x64", &z9e2c24d368, &z1decb8a962);
    z220849e6b8 = (0x47c + 526 - 0x689);
    for (z0d60f4daf7 = z9e2c24d368 / (0x197f + 2242 - 0x2237);
         z0d60f4daf7 > (0xa8d + 1615 - 0x10dc);
         z0d60f4daf7 /= (0x1519 + 3995 - 0x24aa)) {
      z220849e6b8 *= (0x1a56 + 1990 - 0x2212);
    }
    for (z0d60f4daf7 = z9e2c24d368; z0d60f4daf7 < z1decb8a962; ++z0d60f4daf7) {
      za456eece9c += z877f251364(z0d60f4daf7);
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           zf9d528fc68, za456eece9c);
  }
  return (0x113d + 2067 - 0x1950);
}
