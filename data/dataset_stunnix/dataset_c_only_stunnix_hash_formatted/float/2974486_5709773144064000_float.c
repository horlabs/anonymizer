
#include <stdio.h>
#include <stdlib.h>

int main() {
  int zc91eb414d4, z1821ba645b;
  double C, F, X, z23eb8c2605, time, z1f69b4d9d1, z8945da6026;
  scanf("\x25\x64", &zc91eb414d4);
  for (z1821ba645b = (0xc2a + 1547 - 0x1234); z1821ba645b <= zc91eb414d4;
       z1821ba645b++) {
    scanf("\x25\x6c\x66\x20\x25\x6c\x66\x20\x25\x6c\x66", &C, &F, &X);
    z23eb8c2605 = (0x46 + 8998 - 0x236a);
    time = (0xd3c + 2960 - 0x18cc);
    z1f69b4d9d1 = (0x6fc + 502 - 0x8f2);
    z8945da6026 = (0x884 + 6539 - 0x220f);
    do {
      time = z8945da6026 + X / z23eb8c2605;
      z1f69b4d9d1 = z8945da6026 + C / z23eb8c2605 + X / (z23eb8c2605 + F);
      z8945da6026 += C / z23eb8c2605;
      z23eb8c2605 += F;
    } while (time > z1f69b4d9d1);
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x2e\x37\x6c\x66"
           "\n",
           z1821ba645b, time);
  }
  return (0x14e1 + 3494 - 0x2287);
}
