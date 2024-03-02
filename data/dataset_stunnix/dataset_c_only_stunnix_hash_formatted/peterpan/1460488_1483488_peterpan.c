
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int z6eb6fb0930, z818e85f7f3, zf133df3462, za25f3a97c9, za275a41b4e,
      z1a5493b473, z17d662f0d7, zb3a8e7a5c0, zc75931ce37,
      z336f75b234[(0xa08 + 4426 - 0x1b48)], z9e9e187c51, z85432f9c17;
  char z7c9d83488d[(0xc11 + 1087 - 0x103c)];
  scanf("\x25\x64", &z6eb6fb0930);
  for (z818e85f7f3 = (0x144d + 2582 - 0x1e62); z818e85f7f3 <= z6eb6fb0930;
       z818e85f7f3++) {
    scanf("\x25\x64", &zf133df3462);
    scanf("\x25\x64", &za25f3a97c9);
    sprintf(z7c9d83488d, "\x25\x64\x25\x64", zf133df3462, zf133df3462);
    zb3a8e7a5c0 = strlen(z7c9d83488d) / (0x1dc3 + 399 - 0x1f50);
    za275a41b4e = (0x90f + 2857 - 0x1438);
    for (z1a5493b473 = zf133df3462; z1a5493b473 < za25f3a97c9; z1a5493b473++) {
      z9e9e187c51 = (0x12c6 + 713 - 0x158f);
      for (zc75931ce37 = (0x796 + 5606 - 0x1d7b); zc75931ce37 < zb3a8e7a5c0;
           zc75931ce37++) {
        z7c9d83488d[zc75931ce37 + zb3a8e7a5c0] = (0x131 + 7195 - 0x1d4c);
        sscanf(z7c9d83488d + zc75931ce37, "\x25\x64", &z17d662f0d7);
        z7c9d83488d[zc75931ce37 + zb3a8e7a5c0] = z7c9d83488d[zc75931ce37];
        if (z1a5493b473 < z17d662f0d7 && z17d662f0d7 <= za25f3a97c9) {
          for (z85432f9c17 = (0xa03 + 62 - 0xa41); z85432f9c17 < z9e9e187c51;
               z85432f9c17++)
            if (z336f75b234[z9e9e187c51] == z17d662f0d7)
              break;
          if (z85432f9c17 == z9e9e187c51) {
            z336f75b234[z9e9e187c51++] = z17d662f0d7;
            za275a41b4e++;
          }
        }
      }
      for (zc75931ce37 = zb3a8e7a5c0 - (0x7b1 + 5638 - 0x1db6);
           zc75931ce37 >= (0x747 + 2474 - 0x10f1); zc75931ce37--) {
        if (z7c9d83488d[zc75931ce37] == ((char)(0xcda + 1701 - 0x1346)))
          z7c9d83488d[zc75931ce37] = z7c9d83488d[zc75931ce37 + zb3a8e7a5c0] =
              ((char)(0x386 + 1930 - 0xae0));
        else {
          z7c9d83488d[zc75931ce37]++;
          z7c9d83488d[zc75931ce37 + zb3a8e7a5c0]++;
          break;
        }
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\r\n",
           z818e85f7f3, za275a41b4e);
  }
  return (0x2d6 + 1620 - 0x92a);
}
