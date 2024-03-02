
#include <stdio.h>

int main(int z49c2a19e0b, char *z77e61a5ab4[]) {
  FILE *z9b95784195, *zb60bad8d38;
  z9b95784195 = (z49c2a19e0b <= (0x1b1a + 92 - 0x1b75))
                    ? fopen("\x69\x6e\x70\x75\x74\x2e\x74\x78\x74", "\x72\x2b")
                    : fopen(z77e61a5ab4[(0x1a4 + 4959 - 0x1502)], "\x72\x2b");
  zb60bad8d38 = fopen("\x6f\x75\x74\x70\x75\x74\x2e\x74\x78\x74", "\x77\x2b");
  if (z9b95784195) {
    int z8831e12bdf;
    int z15950a3747;
    int z699451e901, z19288f0052;
    fscanf(z9b95784195, "\x25\x64", &z8831e12bdf);
    for (z15950a3747 = (0x1f0d + 346 - 0x2067); z15950a3747 < z8831e12bdf;
         z15950a3747++) {
      float C, F, X;
      double time = (0x1a6b + 2099 - 0x229e);
      float z7ac5eed45f = (0xb4 + 3028 - 0xc86);
      fscanf(z9b95784195, "\x25\x66\x20\x25\x66\x20\x25\x66", &C, &F, &X);
      while (X) {
        double zd61bf403ae = (0x773 + 6239 - 0x1fd2),
               z32cfec975e = (0x2f3 + 2106 - 0xb2d);
        double z228ccad497 = (0x1a3 + 1910 - 0x919);
        zd61bf403ae = (double)(C / z7ac5eed45f);
        z32cfec975e = (double)(X / z7ac5eed45f);
        if (zd61bf403ae >= z32cfec975e) {
          time += z32cfec975e;
          break;
        }
        z228ccad497 = (double)(X / (z7ac5eed45f + F));
        if ((z32cfec975e + time) <= (time + zd61bf403ae + z228ccad497)) {
          time += z32cfec975e;
          break;
        }
        time += zd61bf403ae;
        z7ac5eed45f += F;
      }
      fprintf(zb60bad8d38,
              "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x2e\x37\x66"
              "\n",
              z15950a3747 + (0x3b0 + 1059 - 0x7d2), time);
    }
  }
  return (0x60c + 1849 - 0xd45);
}
