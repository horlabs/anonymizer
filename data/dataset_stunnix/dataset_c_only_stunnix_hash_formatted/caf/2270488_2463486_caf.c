
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int z0ce6b2dbfe(int z3467bef64d) {
  if (z3467bef64d < (0x130 + 1263 - 0x615))
    return (0xb8f + 1148 - 0x100a);
  if (z3467bef64d < (0xd02 + 6206 - 0x24dc))
    return (z3467bef64d % (0xded + 2929 - 0x1953)) == (0x18f + 7845 - 0x2034);
  if (z3467bef64d < (0x1c07 + 1049 - 0x1c38))
    return (z3467bef64d / (0xd78 + 3460 - 0x1a98)) ==
           (z3467bef64d % (0x14ec + 618 - 0x174c));
  return (0x5f + 3937 - 0xfc0);
}
int z7dd476a722(int z3467bef64d) {
  int z1ea0185ee7 = sqrt(z3467bef64d);
  if (z1ea0185ee7 * z1ea0185ee7 == z3467bef64d)
    return z1ea0185ee7;
  return (0x5ca + 3426 - 0x132c);
}
void ze1eafba272(int z07ba9d1930) {
  int z02f4f5c5a3, z49cd7fa50d;
  int z9c533cbec4;
  int z3467bef64d = (0x505 + 1624 - 0xb5d);
  scanf("\x25\x64\x25\x64", &z02f4f5c5a3, &z49cd7fa50d);
  for (z9c533cbec4 = z02f4f5c5a3; z9c533cbec4 <= z49cd7fa50d; z9c533cbec4++) {
    int z1ea0185ee7;
    if (z0ce6b2dbfe(z9c533cbec4) && (z1ea0185ee7 = z7dd476a722(z9c533cbec4)) &&
        z0ce6b2dbfe(z1ea0185ee7))
      z3467bef64d++;
  }
  printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
         "\n",
         z07ba9d1930 + (0x1020 + 5704 - 0x2667), z3467bef64d);
}
int main() {
  int z07ba9d1930, z9c533cbec4;
  scanf("\x25\x64", &z07ba9d1930);
  for (z9c533cbec4 = (0xb1 + 5809 - 0x1762); z9c533cbec4 < z07ba9d1930;
       z9c533cbec4++)
    ze1eafba272(z9c533cbec4);
  return (0x132 + 8774 - 0x2378);
}
