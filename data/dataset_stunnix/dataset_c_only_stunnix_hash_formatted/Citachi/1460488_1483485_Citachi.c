
#include <stdio.h>

int main() {
  char za08f2fbd18[(0x2334 + 360 - 0x2482)] =
      {((char)(0x877 + 6680 - 0x2216)),  ((char)(0xae2 + 7099 - 0x262f)),
       ((char)(0x1e54 + 2134 - 0x2644)), ((char)(0xe58 + 5807 - 0x249e)),
       ((char)(0x8aa + 4774 - 0x1aed)),  ((char)(0x997 + 4190 - 0x197e)),
       ((char)(0xf5 + 2076 - 0x8a5)),    ((char)(0x1b85 + 2547 - 0x2516)),
       ((char)(0x336 + 2898 - 0xe1d)),   ((char)(0xea + 8573 - 0x21f2)),
       ((char)(0x296 + 8806 - 0x248d)),  ((char)(0x1e18 + 2046 - 0x25a9)),
       ((char)(0xb48 + 2192 - 0x1360)),  ((char)(0xb3 + 8472 - 0x2158)),
       ((char)(0x6db + 2088 - 0xe9e)),   ((char)(0x17d0 + 1493 - 0x1d2f)),
       ((char)(0x11e6 + 3182 - 0x1dda)), ((char)(0x1dc6 + 1913 - 0x24cf)),
       ((char)(0x13f2 + 3571 - 0x2181)), ((char)(0x2238 + 655 - 0x2455)),
       ((char)(0x270 + 3215 - 0xe95)),   ((char)(0x1e0b + 1857 - 0x24e5)),
       ((char)(0x11e9 + 466 - 0x1347)),  ((char)(0x4a2 + 7710 - 0x2258)),
       ((char)(0xf38 + 6149 - 0x26dc)),  ((char)(0x39d + 7362 - 0x1fee))},
                                   z742602f78d, z64739fae1d, zbc35b5d2b9,
                                   zce5fa91598 = (0x54d + 1172 - 0x9e1),
                                   za8bce000f2;
  FILE *zc40a24d491, *z492a127bdd;
  zc40a24d491 = fopen("\x41\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70"
                      "\x74\x31\x2e\x69\x6e",
                      "\x72");
  z492a127bdd = fopen("\x6f\x75\x74\x70\x75\x74\x2e\x74\x78\x74", "\x77");
  fscanf(zc40a24d491, "\x25\x64", &za8bce000f2);
  while ((zbc35b5d2b9 = getc(zc40a24d491)) != EOF) {
    if (zbc35b5d2b9 == '\n') {
      zce5fa91598++;
      if (zce5fa91598 != (0x17a9 + 3677 - 0x2605))
        putc(zbc35b5d2b9, z492a127bdd);
      if (zce5fa91598 != za8bce000f2 + (0x288 + 7516 - 0x1fe3))
        fprintf(z492a127bdd, "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
                zce5fa91598);
    }
    if (zbc35b5d2b9 == ((char)(0xb9 + 2981 - 0xc3e)))
      putc(zbc35b5d2b9, z492a127bdd);
    else {
      for (z742602f78d = (0x57d + 5319 - 0x1a44);
           z742602f78d < (0xd8 + 547 - 0x2e1); z742602f78d++) {
        if (zbc35b5d2b9 == za08f2fbd18[z742602f78d])
          putc((z742602f78d + ((char)(0x72b + 4112 - 0x16da))), z492a127bdd);
      }
    }
  }
  fclose(zc40a24d491);
  fclose(z492a127bdd);
  return (0xd25 + 4240 - 0x1db5);
}
