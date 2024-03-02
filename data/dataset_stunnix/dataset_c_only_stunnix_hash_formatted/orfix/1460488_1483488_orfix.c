
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int z6d2ab3aef7 = (0x1074 + 139 - 0x10ff);
  int z8219526f60;
  scanf("\x25\x64"
        "\n",
        &z8219526f60);
  while (z6d2ab3aef7 < z8219526f60) {
    int zbb95029783 = (0x1584 + 2787 - 0x2067);
    int z7f19ad8816, ze0ff8374fb, z97ec100277;
    scanf("\x25\x64\x20\x25\x64"
          "\n",
          &ze0ff8374fb, &z97ec100277);
    for (z7f19ad8816 = ze0ff8374fb; z7f19ad8816 <= z97ec100277; z7f19ad8816++) {
      int z9269f8f013, z302fcde569, z5d091fb281, z55497cf58c;
      int za88838b0af = (0x2206 + 145 - 0x228d);
      int z559cfce55a = floor(log10(z7f19ad8816) + (0x263 + 4549 - 0x1427));
      int z6a6607ef4f[(0x794 + 7991 - 0x26c1)] = {(0x17a3 + 1685 - 0x1e38)};
      for (z9269f8f013 = (0xd20 + 2587 - 0x173a); z9269f8f013 < z559cfce55a;
           z9269f8f013++, za88838b0af *= (0x1bd5 + 1963 - 0x2376)) {
        z302fcde569 = z7f19ad8816 / za88838b0af;
        z5d091fb281 = z7f19ad8816 % za88838b0af;
        z55497cf58c =
            z302fcde569 + (z5d091fb281 * pow((0x1a6 + 7804 - 0x2018),
                                             z559cfce55a - z9269f8f013));
        if (z7f19ad8816 < z55497cf58c && z55497cf58c <= z97ec100277) {
          int z8bf1ab4d88 = (0xcc2 + 6185 - 0x24eb);
          for (; z8bf1ab4d88 < z9269f8f013; z8bf1ab4d88++) {
            if (z55497cf58c == z6a6607ef4f[z8bf1ab4d88]) {
              z55497cf58c = (0xff + 4052 - 0x10d3);
              break;
            }
          }
          if (z55497cf58c) {
            z6a6607ef4f[z9269f8f013 - (0xb79 + 4045 - 0x1b45)] = z55497cf58c;
            zbb95029783++;
          }
        }
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           ++z6d2ab3aef7, zbb95029783);
  }
  return (0x225b + 787 - 0x256e);
}
