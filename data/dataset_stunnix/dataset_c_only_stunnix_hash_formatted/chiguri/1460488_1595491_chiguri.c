
#include <stdio.h>

char z3c5b85c95c[(0x1947 + 54 - 0x17ed)];
int main(void) {
  int z7f8f94fb61;
  int z13446fe3b2;
  int z3b813f9b78;
  int zbaf19d4982;
  int z066a136f88;
  int z151c444a86;
  int zcfafad9351, z9ba97ecfb4;
  int z24e2a8e4ab;
  scanf("\x25\x64", &z7f8f94fb61);
  for (zcfafad9351 = (0x2133 + 395 - 0x22bd); zcfafad9351 <= z7f8f94fb61;
       ++zcfafad9351) {
    z066a136f88 = (0x1982 + 425 - 0x1b2b);
    z151c444a86 = (0x17b0 + 496 - 0x19a0);
    scanf("\x25\x64\x20\x25\x64\x20\x25\x64", &z13446fe3b2, &z3b813f9b78,
          &zbaf19d4982);
    for (z9ba97ecfb4 = (0x1b18 + 542 - 0x1d36); z9ba97ecfb4 < z13446fe3b2;
         ++z9ba97ecfb4) {
      scanf("\x25\x64", &z24e2a8e4ab);
      if (z24e2a8e4ab == (0x2051 + 1415 - 0x25d8)) {
        if (zbaf19d4982 == (0x6d + 4437 - 0x11c2)) {
          ++z066a136f88;
        }
      } else if (z24e2a8e4ab == (0x9af + 4844 - 0x1c9a)) {
        if (zbaf19d4982 <= (0xa8 + 9227 - 0x24b2)) {
          ++z066a136f88;
        }
      } else if (zbaf19d4982 * (0x137b + 2737 - 0x1e29) -
                     (0x1f25 + 1969 - 0x26d4) <=
                 z24e2a8e4ab) {
        ++z066a136f88;
      } else if (zbaf19d4982 * (0x186 + 6944 - 0x1ca3) -
                     (0xf22 + 2598 - 0x1944) <=
                 z24e2a8e4ab) {
        ++z151c444a86;
      }
    }
    if (z3b813f9b78 > z151c444a86) {
      z066a136f88 += z151c444a86;
    } else {
      z066a136f88 += z3b813f9b78;
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           zcfafad9351, z066a136f88);
  }
  return (0x176 + 3930 - 0x10d0);
}
