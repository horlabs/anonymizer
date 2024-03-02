
#include <stdio.h>

int main() {
  int ze44cd641ca;
  int z07455b3d60[(0x258 + 6434 - 0x1b78)];
  int z7c93a4eef5[(0x65 + 8345 - 0x20fc)][(0xcea + 6110 - 0x24c4)]
                 [(0x5aa + 4663 - 0x17dd)];
  int zd581428dae, zddf49ae873, z94262d48ae, z8c92c54298;
  int zadcb4636a5;
  int zb15d750430;
  fscanf(stdin,
         "\x25\x64"
         "\n",
         &ze44cd641ca);
  for (zd581428dae = (0x236 + 5108 - 0x162a); zd581428dae < ze44cd641ca;
       zd581428dae++) {
    for (zddf49ae873 = (0x802 + 5836 - 0x1ece);
         zddf49ae873 < (0x1693 + 2004 - 0x1e65); zddf49ae873++) {
      fscanf(stdin,
             "\x25\x64"
             "\n",
             z07455b3d60 + zddf49ae873);
      for (z94262d48ae = (0x12c5 + 2552 - 0x1cbd);
           z94262d48ae < (0x137a + 2887 - 0x1ebd); z94262d48ae++) {
        fscanf(stdin,
               "\x25\x64\x20\x25\x64\x20\x25\x64\x20\x25\x64"
               "\n",
               z7c93a4eef5[zddf49ae873][z94262d48ae],
               z7c93a4eef5[zddf49ae873][z94262d48ae] + (0x105b + 4446 - 0x21b8),
               z7c93a4eef5[zddf49ae873][z94262d48ae] + (0xe17 + 2021 - 0x15fa),
               z7c93a4eef5[zddf49ae873][z94262d48ae] +
                   (0x189d + 3681 - 0x26fb));
      }
    }
    zadcb4636a5 = (0x419 + 5949 - 0x1b56);
    for (z94262d48ae = (0x12e1 + 3444 - 0x2055);
         z94262d48ae < (0x288 + 2195 - 0xb17); z94262d48ae++) {
      int z36bda8a842;
      z36bda8a842 = z7c93a4eef5[(0xb7d + 1196 - 0x1029)]
                               [z07455b3d60[(0xa82 + 6763 - 0x24ed)] -
                                (0xa87 + 7065 - 0x261f)][z94262d48ae];
      for (z8c92c54298 = (0xe75 + 1611 - 0x14c0);
           z8c92c54298 < (0x15a + 1078 - 0x58c); z8c92c54298++) {
        if (z36bda8a842 == z7c93a4eef5[(0x1ec + 185 - 0x2a4)]
                                      [z07455b3d60[(0xbb6 + 6160 - 0x23c5)] -
                                       (0x9ca + 4091 - 0x19c4)][z8c92c54298]) {
          zb15d750430 = z36bda8a842;
          zadcb4636a5++;
        }
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
           zd581428dae + (0x8b3 + 6964 - 0x23e6));
    switch (zadcb4636a5) {
    case (0x103f + 5048 - 0x23f7):
      printf("\x56\x6f\x6c\x75\x6e\x74\x65\x65\x72\x20\x63\x68\x65\x61\x74\x65"
             "\x64\x21"
             "\n");
      break;
    case (0x1563 + 803 - 0x1885):
      printf("\x25\x64"
             "\n",
             zb15d750430);
      break;
    default:
      printf("\x42\x61\x64\x20\x6d\x61\x67\x69\x63\x69\x61\x6e\x21"
             "\n");
      break;
    }
  }
  return (0x7ed + 5788 - 0x1e89);
}
