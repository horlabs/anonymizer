
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void z62a4fcfb45(int z38abf08ce2) {
  int z11e1d64bd8;
  int zd825cff593, z8665ee3635, zc41f2f0666;
  int z8d3c54cd42, z4a0bffa39d;
  int y = (0xa08 + 1459 - 0xfbb);
  scanf("\x25\x64\x20\x25\x64\x20\x25\x64", &zd825cff593, &z8665ee3635,
        &zc41f2f0666);
  z8d3c54cd42 =
      zc41f2f0666 > (0xe11 + 610 - 0x1073)
          ? (0xf8c + 1665 - 0x160a) * zc41f2f0666 - (0x105f + 2102 - 0x1893)
          : (0x5f3 + 2487 - 0xfaa);
  z4a0bffa39d =
      zc41f2f0666 > (0xc + 993 - 0x3ec)
          ? (0x15d6 + 931 - 0x1976) * zc41f2f0666 - (0x174f + 2090 - 0x1f75)
          : zc41f2f0666;
  for (z11e1d64bd8 = (0x333 + 1129 - 0x79c); z11e1d64bd8 < zd825cff593;
       z11e1d64bd8++) {
    int zae04b75012;
    scanf("\x25\x64", &zae04b75012);
    if (zc41f2f0666 > (0x40c + 6863 - 0x1ed1))
      continue;
    if (zae04b75012 >= z8d3c54cd42) {
      y++;
    } else if (z8665ee3635 > (0x442 + 5565 - 0x19ff) &&
               zae04b75012 >= z4a0bffa39d) {
      y++;
      z8665ee3635--;
    }
  }
  printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
         "\n",
         z38abf08ce2 + (0x4a1 + 7068 - 0x203c), y);
}
int main() {
  int z38abf08ce2, z11e1d64bd8;
  scanf("\x25\x64", &z38abf08ce2);
  for (z11e1d64bd8 = (0x21a + 8533 - 0x236f); z11e1d64bd8 < z38abf08ce2;
       z11e1d64bd8++)
    z62a4fcfb45(z11e1d64bd8);
  return (0x160f + 3355 - 0x232a);
}
