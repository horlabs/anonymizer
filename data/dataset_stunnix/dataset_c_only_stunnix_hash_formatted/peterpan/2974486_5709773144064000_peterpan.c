
#include <stdio.h>
#include <stdlib.h>

int main() {
  int z51c6ea57ce, za4f4e11f25, zee7563d492, zc1e06a89d3;
  double C, F, X, ze8656cc2b7, z55fffbcb07, z0306890d54, zaaadde1827;
  scanf("\x25\x64", &z51c6ea57ce);
  for (za4f4e11f25 = (0x14f2 + 4516 - 0x2695); za4f4e11f25 <= z51c6ea57ce;
       za4f4e11f25++) {
    scanf("\x25\x6c\x66\x20\x25\x6c\x66\x20\x25\x6c\x66", &C, &F, &X);
    zee7563d492 = (0x34d + 6688 - 0x1d6d);
    z0306890d54 = (0x13a3 + 1022 - 0x17a1);
    z55fffbcb07 = 2.0;
    zaaadde1827 = z0306890d54 + X / z55fffbcb07;
    zc1e06a89d3 = (0x6b3 + 4586 - 0x189d);
    while (zc1e06a89d3 < (0xec3 + 5838 - 0x252d)) {
      z0306890d54 += C / z55fffbcb07;
      zee7563d492++;
      z55fffbcb07 += F;
      ze8656cc2b7 = z0306890d54 + X / z55fffbcb07;
      if (ze8656cc2b7 < zaaadde1827) {
        zaaadde1827 = ze8656cc2b7;
        if (zc1e06a89d3)
          fprintf(stderr, "\x52\x65\x73\x65\x74\x69\x6e\x67\x20\x63\x6f\x75\x6e"
                          "\x74\x65\x72\x2e"
                          "\n");
        zc1e06a89d3 = (0x1682 + 2381 - 0x1fcf);
      } else
        zc1e06a89d3++;
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x2e\x37\x6c\x66"
           "\n",
           za4f4e11f25, zaaadde1827);
  }
  return (0x14c + 6514 - 0x1abe);
}
