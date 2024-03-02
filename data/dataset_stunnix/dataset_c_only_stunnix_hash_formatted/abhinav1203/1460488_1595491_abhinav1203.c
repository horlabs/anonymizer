
#include <stdio.h>

int z00a13b3301[(0x1109 + 5512 - 0x2628)];
int main() {
  int z1e22c2b933, z449d32098c, zb87b14ae22, zef0b8759cd, z3e328d27ab,
      z6b67f7fb57, z8c9697f238 = (0x767 + 7620 - 0x252a);
  scanf("\x25\x64", &z6b67f7fb57);
  while (z6b67f7fb57--) {
    scanf("\x25\x64\x20\x25\x64\x20\x25\x64", &z1e22c2b933, &z449d32098c,
          &zb87b14ae22);
    for (zef0b8759cd = (0x1fe4 + 218 - 0x20be); zef0b8759cd < z1e22c2b933;
         zef0b8759cd++)
      scanf("\x25\x64", &z00a13b3301[zef0b8759cd]);
    z3e328d27ab = (0x609 + 7455 - 0x2328);
    for (zef0b8759cd = (0x14b3 + 2978 - 0x2055); zef0b8759cd < z1e22c2b933;
         zef0b8759cd++) {
      if ((z00a13b3301[zef0b8759cd] + (0x1524 + 173 - 0x15cf)) /
              (0x1d8 + 6873 - 0x1cae) >=
          zb87b14ae22)
        z3e328d27ab++;
      else if ((z00a13b3301[zef0b8759cd] + (0x1ac1 + 1376 - 0x201f)) /
                       (0x1a97 + 2827 - 0x259f) ==
                   (zb87b14ae22 - (0x18a5 + 192 - 0x1964)) &&
               z449d32098c > (0x3a9 + 7326 - 0x2047) &&
               z00a13b3301[zef0b8759cd] > (0x272 + 4886 - 0x1587) &&
               z00a13b3301[zef0b8759cd] % (0x13d3 + 605 - 0x162d) !=
                   (0x1f66 + 441 - 0x211e)) {
        z3e328d27ab++;
        z449d32098c--;
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z8c9697f238, z3e328d27ab);
    z8c9697f238++;
  }
  return (0x73a + 88 - 0x792);
}
