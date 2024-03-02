
#include <limits.h>
#include <stdio.h>

const int z682cdcae02[] = {(0x873 + 543 - 0xa91),
                           (0x146c + 4003 - 0x240d),
                           (0x9fb + 329 - 0xb41),
                           (0x88f + 1828 - 0xfa8),
                           (0x188d + 2822 - 0x237d),
                           (0x829 + 3198 - 0x1442),
                           (0x271 + 5930 - 0x192c),
                           (0xc48 + 6253 - 0x243c),
                           (0xadf + 779 - 0xd20),
                           (0x130f + 36 - 0x125f),
                           (0x13ea + 2263 - 0x18d8),
                           (0x45f + 1538 - 0x60a),
                           (0x143a + 2603 - 0x1693),
                           10001,
                           10101,
                           10201,
                           11011,
                           11111,
                           11211,
                           20002,
                           20102,
                           100001,
                           101101,
                           110011,
                           111111,
                           200002,
                           1000001,
                           1001001,
                           1002001,
                           1010101,
                           1011101,
                           1012101,
                           1100011,
                           1101011,
                           1102011,
                           1110111,
                           1111111,
                           2000002,
                           2001002};
long long z65f18bab23[(0x1842 + 2920 - 0x2346)];
int ze828289921(long long z3b04eda045) {
  int z1313f4e940;
  for (z1313f4e940 = (0x8b8 + 3329 - 0x15b9);
       z1313f4e940 <= sizeof(z682cdcae02) / sizeof(int); z1313f4e940++) {
    if (z65f18bab23[z1313f4e940] > z3b04eda045)
      return z1313f4e940 - (0x59f + 4786 - 0x1850);
  }
  return sizeof(z682cdcae02) / sizeof(int);
}
int main() {
  int zf2a3cd0a6b, z0b7683a973 = (0x20cb + 1477 - 0x2690);
  int z1313f4e940;
  for (z1313f4e940 = (0x2ba + 5044 - 0x166e);
       z1313f4e940 < sizeof(z682cdcae02) / sizeof(int); z1313f4e940++) {
    z65f18bab23[z1313f4e940] =
        (long long)z682cdcae02[z1313f4e940] * z682cdcae02[z1313f4e940];
  }
  z65f18bab23[z1313f4e940] = LLONG_MAX;
  for (scanf("\x25\x64", &zf2a3cd0a6b); zf2a3cd0a6b; zf2a3cd0a6b--) {
    long long z3b04eda045, za9051285ae;
    scanf("\x25\x6c\x6c\x64\x25\x6c\x6c\x64", &z3b04eda045, &za9051285ae);
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           ++z0b7683a973,
           ze828289921(za9051285ae) -
               ze828289921(z3b04eda045 - (0x3d2 + 908 - 0x75d)));
  }
  return (0xc91 + 671 - 0xf30);
}
