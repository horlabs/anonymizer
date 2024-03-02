
#include <math.h>
#include <stdio.h>

int za4b77740f7(long long zd219cffc88);
int main(void) {
  long long z495408f2c8, za6fdd98cec, z3b2986f335, z578b811586;
  long long z857b2b4417, zb6f3f1281d, z1dc963787e, ze7ddd83d99, zf68a849cea;
  scanf("\x25\x49\x36\x34\x64", &z495408f2c8);
  for (za6fdd98cec = (0x1709 + 1219 - 0x1bcb); za6fdd98cec <= z495408f2c8;
       za6fdd98cec++) {
    scanf("\x25\x49\x36\x34\x64\x20\x25\x49\x36\x34\x64", &z857b2b4417,
          &zb6f3f1281d);
    z1dc963787e = sqrt(z857b2b4417);
    ze7ddd83d99 = sqrt(zb6f3f1281d);
    if (z1dc963787e * z1dc963787e < z857b2b4417)
      z1dc963787e++;
    zf68a849cea = (0xd92 + 1857 - 0x14d3);
    for (z3b2986f335 = z1dc963787e; z3b2986f335 <= ze7ddd83d99; z3b2986f335++) {
      if (za4b77740f7(z3b2986f335)) {
        if (za4b77740f7(z3b2986f335 * z3b2986f335)) {
          zf68a849cea++;
        }
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x49\x36\x34\x64\x3a\x20\x25\x49\x36"
           "\x34\x64"
           "\n",
           za6fdd98cec, zf68a849cea);
  }
}
int za4b77740f7(long long zd219cffc88) {
  long long z1ab0d25c00[(0x1292 + 209 - 0x12f5)];
  long long z3b2986f335, zf68a849cea;
  z3b2986f335 = (0x166a + 130 - 0x16ec);
  while (zd219cffc88) {
    z1ab0d25c00[z3b2986f335] = zd219cffc88 % (0x1a9 + 7433 - 0x1ea8);
    zd219cffc88 /= (0x168f + 137 - 0x170e);
    z3b2986f335++;
  }
  zf68a849cea = z3b2986f335 - (0x3e5 + 7770 - 0x223e);
  z3b2986f335 = (0x15f5 + 476 - 0x17d1);
  while (z3b2986f335 <= (zf68a849cea - z3b2986f335)) {
    if (z1ab0d25c00[z3b2986f335] != z1ab0d25c00[zf68a849cea - z3b2986f335]) {
      return ((0xa54 + 5482 - 0x1fbe));
    }
    z3b2986f335++;
  }
  return ((0x1663 + 642 - 0x18e4));
}
