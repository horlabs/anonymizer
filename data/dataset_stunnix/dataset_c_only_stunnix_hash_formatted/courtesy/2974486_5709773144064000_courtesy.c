
#include <stdio.h>

int main() {
  int z58492f32fc, z402724d9d0, z23d5711f36, z5cfd35b71b, za66d5d482f;
  double C, F, X, zb3ad36dc37, zc06be6f457, z1c88145888, zd34aadb1ef,
      zef03a930ea;
  scanf("\x25\x64", &z58492f32fc);
  for (za66d5d482f = (0x15f6 + 2014 - 0x1dd3); za66d5d482f <= z58492f32fc;
       za66d5d482f++) {
    scanf("\x25\x6c\x66\x20\x25\x6c\x66\x20\x25\x6c\x66", &C, &F, &X);
    zd34aadb1ef = X / 2.00;
    for (z402724d9d0 = (0x1ac0 + 109 - 0x1b2c);; z402724d9d0++) {
      zef03a930ea = X / ((0x1625 + 1985 - 0x1de4) + z402724d9d0 * F);
      for (z23d5711f36 = (0xa + 8700 - 0x2206); z23d5711f36 < z402724d9d0;
           z23d5711f36++)
        zef03a930ea += C / ((0x8fc + 6893 - 0x23e7) + z23d5711f36 * F);
      if (zef03a930ea > zd34aadb1ef)
        break;
      zd34aadb1ef = zef03a930ea;
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x2e\x37\x6c\x66"
           "\n",
           za66d5d482f, zd34aadb1ef);
  }
}
