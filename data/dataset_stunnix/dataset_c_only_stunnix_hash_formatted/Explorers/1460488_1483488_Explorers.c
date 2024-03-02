
#include <math.h>
#include <stdio.h>

int main() {
  int z219c8e40d5, z615a591cec, z887bb430a9, z35ab49459d,
      z80620043e2[(0x1d8 + 8437 - 0x229b)] = {(0x967 + 2774 - 0x143d)};
  long z55f7ddf045, z8b26ec41cf, z9ab2f57213, z577f24c0ce, z65aa90de6e,
      remainder, ze76599b7e6, z37995fe761;
  scanf("\x25\x64", &z219c8e40d5);
  for (z615a591cec = (0x1b08 + 680 - 0x1db0); z615a591cec < z219c8e40d5;
       z615a591cec++) {
    scanf("\x25\x6c\x64\x20\x25\x6c\x64", &z55f7ddf045, &z8b26ec41cf);
    z887bb430a9 = z306c3c71c0(z55f7ddf045);
    for (z9ab2f57213 = z55f7ddf045; z9ab2f57213 < z8b26ec41cf; z9ab2f57213++) {
      for (z35ab49459d = z887bb430a9 - (0x1082 + 3170 - 0x1ce3);
           z35ab49459d >= (0xb07 + 6973 - 0x2643); z35ab49459d--) {
        z65aa90de6e = pow((0xff1 + 1795 - 0x16ea), z35ab49459d);
        z577f24c0ce = pow((0x863 + 1291 - 0xd64), z887bb430a9 - z35ab49459d);
        ze76599b7e6 = z9ab2f57213 / z577f24c0ce;
        remainder = z9ab2f57213 % z577f24c0ce;
        z37995fe761 = remainder * z65aa90de6e + ze76599b7e6;
        if (z306c3c71c0(z37995fe761) != z887bb430a9)
          continue;
        if (z37995fe761 > z9ab2f57213 && z37995fe761 <= z8b26ec41cf) {
          z80620043e2[z615a591cec]++;
        }
      }
    }
  }
  for (z615a591cec = (0x72d + 7284 - 0x23a1); z615a591cec < z219c8e40d5;
       z615a591cec++) {
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z615a591cec + (0x2073 + 699 - 0x232d), z80620043e2[z615a591cec]);
  }
}
int z306c3c71c0(long za75a75209c) {
  if (za75a75209c < (0x1b8 + 7204 - 0x1dd2))
    return (0x54 + 6196 - 0x1887);
  else
    return (0x23d + 1818 - 0x956) +
           z306c3c71c0(za75a75209c / (0x1d5a + 1816 - 0x2468));
}
