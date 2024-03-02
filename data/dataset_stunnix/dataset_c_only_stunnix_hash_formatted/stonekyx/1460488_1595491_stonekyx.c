
#include <stdio.h>
#include <stdlib.h>

int main() {
  int z9c03284932;
  int zc7c676ad7c = (0x285 + 2627 - 0xcc8);
  for (scanf("\x25\x64", &z9c03284932); z9c03284932;
       z9c03284932--, zc7c676ad7c++) {
    int z3f17f5ae22, z409b52f294, z519173f987;
    int z8b1b49e7ae;
    static int z1f6bfbe694[(0x18f1 + 1587 - 0x1e5c)];
    int z87ee54cddf;
    int z8ce450c03c = (0x234 + 3488 - 0xfd4);
    scanf("\x25\x64\x25\x64\x25\x64", &z3f17f5ae22, &z409b52f294, &z519173f987);
    for (z87ee54cddf = (0xa2b + 380 - 0xba7); z87ee54cddf < z3f17f5ae22;
         z87ee54cddf++) {
      scanf("\x25\x64", z1f6bfbe694 + z87ee54cddf);
    }
    z8b1b49e7ae = z409b52f294;
    for (z87ee54cddf = (0x1266 + 1291 - 0x1771); z87ee54cddf < z3f17f5ae22;
         z87ee54cddf++) {
      int z7587775d6e = z1f6bfbe694[z87ee54cddf];
      switch (z7587775d6e % (0x11f0 + 1658 - 0x1867)) {
      case (0xcb9 + 1822 - 0x13d7):
        if (z7587775d6e / (0xc66 + 2274 - 0x1545) >= z519173f987) {
          z8ce450c03c++;
          break;
        } else if (z8b1b49e7ae &&
                   z7587775d6e / (0x105b + 358 - 0x11be) >=
                       (0x33a + 1505 - 0x91a) &&
                   z7587775d6e / (0xafa + 891 - 0xe72) +
                           (0x5fc + 6037 - 0x1d90) >=
                       z519173f987) {
          z8ce450c03c++;
          z8b1b49e7ae--;
          break;
        }
        break;
      case (0x16dc + 3563 - 0x24c6):
        if (z7587775d6e / (0x3d0 + 8198 - 0x23d3) + (0xaa3 + 5984 - 0x2202) >=
            z519173f987)
          z8ce450c03c++;
        break;
      case (0x253 + 6704 - 0x1c81):
        if (z7587775d6e / (0x9b + 853 - 0x3ed) + (0x883 + 7761 - 0x26d3) >=
            z519173f987) {
          z8ce450c03c++;
          break;
        } else if (z8b1b49e7ae && z7587775d6e / (0x1379 + 4724 - 0x25ea) +
                                          (0x1fa + 8433 - 0x22e9) >=
                                      z519173f987) {
          z8ce450c03c++;
          z8b1b49e7ae--;
          break;
        }
        break;
      default:
        fprintf(stderr, "\x54\x68\x69\x73\x20\x73\x68\x6f\x75\x6c\x64\x20\x6e"
                        "\x6f\x74\x20\x68\x61\x70\x70\x65\x6e\x21"
                        "\n");
        exit((0x294 + 7045 - 0x1e18));
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           zc7c676ad7c + (0x115b + 1455 - 0x1709), z8ce450c03c);
  }
  return (0x1004 + 2101 - 0x1839);
}
