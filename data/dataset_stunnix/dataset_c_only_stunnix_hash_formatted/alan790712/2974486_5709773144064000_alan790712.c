
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int zad3eb5a134, z0e76168775;
double C, F, X;
double z53f21a891e(double z1cab9eb4db, double z282c6b3443) {
  double z65ef4fa724;
  int zc982c9b7ca, z57bc470b0d;
  double zb5051fff62;
  double z836c29abc8 = z282c6b3443;
  while (z1cab9eb4db + 1e-8 <= z282c6b3443) {
    z65ef4fa724 = (z1cab9eb4db + z282c6b3443) / (0x1398 + 675 - 0x1639);
    for (z57bc470b0d = (0xf80 + 3931 - 0x1edb);; ++z57bc470b0d) {
      for (zc982c9b7ca = zb5051fff62 = (0x50d + 8666 - 0x26e7);
           zc982c9b7ca < z57bc470b0d; ++zc982c9b7ca) {
        zb5051fff62 += C / (2.0 + F * zc982c9b7ca);
      }
      if ((zb5051fff62 >= z65ef4fa724) ||
          (z65ef4fa724 - zb5051fff62) * (2.0 + F * z57bc470b0d) >= X) {
        break;
      }
    }
    if (zb5051fff62 >= z65ef4fa724) {
      z1cab9eb4db = z65ef4fa724 + 1e-8;
    } else {
      if (z65ef4fa724 < z836c29abc8)
        z836c29abc8 = z65ef4fa724;
      z282c6b3443 = z65ef4fa724 - 1e-8;
    }
  }
  return z836c29abc8;
}
int main() {
  scanf("\x25\x64", &z0e76168775);
  for (zad3eb5a134 = (0xca3 + 2859 - 0x17cd); zad3eb5a134 <= z0e76168775;
       ++zad3eb5a134) {
    scanf("\x25\x6c\x66\x20\x25\x6c\x66\x20\x25\x6c\x66", &C, &F, &X);
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x2e\x37\x6c\x66"
           "\n",
           zad3eb5a134, z53f21a891e(0.0, X / 2.0));
  }
  return (0x12e9 + 5046 - 0x269f);
}
