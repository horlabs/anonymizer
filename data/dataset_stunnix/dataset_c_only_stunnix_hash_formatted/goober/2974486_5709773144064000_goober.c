
#include <stdio.h>

int main() {
  int zce81c47da3;
  scanf("\x25\x64", &zce81c47da3);
  for (int z29a9f43849 = (0x1a38 + 71 - 0x1a7e); z29a9f43849 <= zce81c47da3;
       z29a9f43849++) {
    double C, F, X;
    scanf("\x25\x6c\x66\x20\x25\x6c\x66\x20\x25\x6c\x66", &C, &F, &X);
    double z6708736e79 = (0x135 + 6528 - 0x1ab3);
    double za759455b1b = X / z6708736e79;
    double z367d75b41f = (0xb93 + 6342 - 0x2459);
    for (;;) {
      z367d75b41f += C / z6708736e79;
      z6708736e79 += F;
      if (za759455b1b <= z367d75b41f + X / z6708736e79)
        break;
      else
        za759455b1b = z367d75b41f + X / z6708736e79;
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x2e\x37\x6c\x66"
           "\n",
           z29a9f43849, za759455b1b);
  }
  return (0xd3 + 6366 - 0x19b1);
}
