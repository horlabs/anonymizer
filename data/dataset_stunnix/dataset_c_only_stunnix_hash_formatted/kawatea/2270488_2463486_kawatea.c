
#include <stdio.h>

int z9f42b76190(long long x) {
  int za9ff3cf68a, z7891ac6f4d;
  int z1f9fdf85d3[(0x898 + 2020 - 0x1068)];
  for (za9ff3cf68a = (0x1f55 + 1498 - 0x252f); x > (0x19cd + 909 - 0x1d5a);
       za9ff3cf68a++) {
    z1f9fdf85d3[za9ff3cf68a] = x % (0x484 + 145 - 0x50b);
    x /= (0x2012 + 397 - 0x2195);
  }
  for (z7891ac6f4d = (0x1772 + 1573 - 0x1d97);
       z7891ac6f4d < za9ff3cf68a / (0xd78 + 4773 - 0x201b); z7891ac6f4d++) {
    if (z1f9fdf85d3[z7891ac6f4d] !=
        z1f9fdf85d3[za9ff3cf68a - z7891ac6f4d - (0x975 + 4909 - 0x1ca1)])
      return (0x2cd + 3114 - 0xef7);
  }
  return (0x20d0 + 1083 - 0x250a);
}
int main() {
  int zabc210b3f6 = (0x5aa + 4948 - 0x18fe), z45b0fd808f, za9ff3cf68a;
  long long z1f9fdf85d3[(0xca3 + 2481 - 0x15f0)];
  for (za9ff3cf68a = (0x9d7 + 1147 - 0xe51); za9ff3cf68a <= 10000000;
       za9ff3cf68a++) {
    if (z9f42b76190(za9ff3cf68a) &&
        z9f42b76190((long long)za9ff3cf68a * za9ff3cf68a))
      z1f9fdf85d3[zabc210b3f6++] = (long long)za9ff3cf68a * za9ff3cf68a;
  }
  scanf("\x25\x64", &z45b0fd808f);
  for (za9ff3cf68a = (0x133b + 112 - 0x13ab); za9ff3cf68a < z45b0fd808f;
       za9ff3cf68a++) {
    int z23d5bc217d = (0x8b7 + 428 - 0xa63), z7891ac6f4d;
    long long x, y;
    scanf("\x25\x6c\x6c\x64\x20\x25\x6c\x6c\x64", &x, &y);
    for (z7891ac6f4d = (0x18d5 + 632 - 0x1b4d); z7891ac6f4d < zabc210b3f6;
         z7891ac6f4d++) {
      if (z1f9fdf85d3[z7891ac6f4d] >= x && z1f9fdf85d3[z7891ac6f4d] <= y)
        z23d5bc217d++;
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           za9ff3cf68a + (0x18c6 + 3045 - 0x24aa), z23d5bc217d);
  }
  return (0x3f6 + 2864 - 0xf26);
}
