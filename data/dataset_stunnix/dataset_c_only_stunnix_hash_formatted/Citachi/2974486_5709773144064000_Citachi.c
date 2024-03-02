
#include <stdio.h>

int main() {
  float C, F, X;
  float time, z452d31e732, x;
  float f, zf17be49c22, zf5a2984dee;
  int zf3169f4902, zb1c8cdcbd7, z7c62f4a121;
  FILE *z4efd5e0319, *z033e734a5a;
  z4efd5e0319 = fopen("\x42\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70"
                      "\x74\x30\x2e\x69\x6e",
                      "\x72");
  z033e734a5a =
      fopen("\x63\x6f\x6f\x6b\x69\x65\x5f\x6f\x75\x74\x2e\x74\x78\x74", "\x77");
  fscanf(z4efd5e0319, "\x25\x64", &z7c62f4a121);
  zb1c8cdcbd7 = (0x1926 + 1305 - 0x1e3e);
  while (zb1c8cdcbd7 <= z7c62f4a121) {
    z452d31e732 = X;
    fscanf(z4efd5e0319, "\x25\x66\x20\x25\x66\x20\x25\x66", &C, &F, &X);
    time = zf17be49c22 = zf5a2984dee = 0.0;
    f = 2.0;
    if (X < C) {
      time = X / f;
    } else {
      x = (0x13bc + 92 - 0x1418);
      time = C / f;
      zf17be49c22 = C / f + X / (f + F);
      x = x + C;
      zf3169f4902 = (0x11b0 + 5227 - 0x261b);
      while (x < X) {
        zf5a2984dee = zf17be49c22;
        f = f + F;
        time = time + C / f;
        zf17be49c22 = time + X / (f + F);
        x = x + C;
        if (zf17be49c22 > zf5a2984dee) {
          time = zf5a2984dee;
          zf3169f4902 = (0x17df + 710 - 0x1aa4);
          break;
        }
      }
      if (!zf3169f4902)
        time = zf17be49c22;
    }
    if (zb1c8cdcbd7 == z7c62f4a121)
      fprintf(z033e734a5a, "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x66",
              zb1c8cdcbd7, time);
    else
      fprintf(z033e734a5a,
              "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x66"
              "\n",
              zb1c8cdcbd7, time);
    zb1c8cdcbd7++;
  }
  fclose(z4efd5e0319);
  fclose(z033e734a5a);
  return (0x1ba4 + 2530 - 0x2586);
}
