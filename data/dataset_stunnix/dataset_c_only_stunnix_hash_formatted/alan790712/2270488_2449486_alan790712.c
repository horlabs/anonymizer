
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int z0979e84cbf, z7e20080821;
int zf3b6d0be08[(0xf02 + 2361 - 0x17c0)][(0x564 + 6864 - 0x1fb9)];
int zda14edf25d;
int main() {
  int zf6b4214bfd, zfad4c462ea;
  int zcfadb12be1, z078a83f597;
  int zad2aac68b7;
  int max;
  scanf("\x25\x64", &zfad4c462ea);
  for (zf6b4214bfd = (0x54 + 2281 - 0x93c); zf6b4214bfd <= zfad4c462ea;
       ++zf6b4214bfd) {
    scanf("\x25\x64\x20\x25\x64", &z0979e84cbf, &z7e20080821);
    memset(zf3b6d0be08, (0xfa + 3396 - 0xe3e), sizeof(zf3b6d0be08));
    for (zcfadb12be1 = max = (0x1477 + 2928 - 0x1fe6);
         zcfadb12be1 <= z0979e84cbf; ++zcfadb12be1) {
      for (z078a83f597 = (0x111d + 4101 - 0x2121); z078a83f597 <= z7e20080821;
           ++z078a83f597) {
        scanf("\x25\x64", &zf3b6d0be08[zcfadb12be1][z078a83f597]);
        if (zf3b6d0be08[zcfadb12be1][z078a83f597] >= max)
          max = zf3b6d0be08[zcfadb12be1][z078a83f597];
      }
    }
    zda14edf25d = (0xda8 + 5156 - 0x21cc);
    for (zcfadb12be1 = (0x1762 + 3413 - 0x24b6);
         zcfadb12be1 <= z0979e84cbf && !zda14edf25d; ++zcfadb12be1) {
      for (z078a83f597 = (0x738 + 5289 - 0x1be0);
           z078a83f597 <= z7e20080821 && !zda14edf25d; ++z078a83f597) {
        for (zad2aac68b7 = (0x3b8 + 2348 - 0xce3);
             zad2aac68b7 <= z7e20080821 &&
             zf3b6d0be08[zcfadb12be1][zad2aac68b7] <=
                 zf3b6d0be08[zcfadb12be1][z078a83f597];
             ++zad2aac68b7)
          ;
        if (zad2aac68b7 > z7e20080821)
          continue;
        for (zad2aac68b7 = (0x1d02 + 2045 - 0x24fe);
             zad2aac68b7 <= z0979e84cbf &&
             zf3b6d0be08[zad2aac68b7][z078a83f597] <=
                 zf3b6d0be08[zcfadb12be1][z078a83f597];
             ++zad2aac68b7)
          ;
        if (zad2aac68b7 <= z0979e84cbf)
          zda14edf25d = (0x584 + 5898 - 0x1c8d);
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", zf6b4214bfd);
    if (!zda14edf25d)
      puts("\x59\x45\x53");
    else
      puts("\x4e\x4f");
  }
  return (0x9a1 + 682 - 0xc4b);
}
