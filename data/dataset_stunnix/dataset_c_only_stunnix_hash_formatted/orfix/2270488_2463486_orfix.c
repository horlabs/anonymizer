
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char z2664f6d070(unsigned long long zbb0939873a) {
  int z95e3ebeab0 = (0x1ecb + 342 - 0x2020);
  char zc7fc095dc7[(0x16c8 + 3742 - 0x2166)] = "";
  if (sprintf(zc7fc095dc7, "\x25\x6c\x6c\x75", zbb0939873a) >
      (0x1a94 + 129 - 0x1b15)) {
    unsigned int ze604ffa2f9 = strlen(zc7fc095dc7);
    for (zbb0939873a = (0x970 + 4316 - 0x1a4c);
         zbb0939873a < (ze604ffa2f9 / (0x13b8 + 1417 - 0x193f)) +
                           (0xa82 + 3128 - 0x16b9) &&
         z95e3ebeab0;
         zbb0939873a++) {
      if (zc7fc095dc7[zbb0939873a] !=
          zc7fc095dc7[ze604ffa2f9 - zbb0939873a - (0x1977 + 2985 - 0x251f)])
        z95e3ebeab0 = (0x1c + 6639 - 0x1a0b);
    }
  }
  return z95e3ebeab0;
}
int main(void) {
  freopen("\x43\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x69\x6e",
          "\x72", stdin);
  int zcf8aa38eb9 = (0x4f8 + 4191 - 0x1557);
  int zea8cc9b69b;
  scanf("\x25\x64"
        "\n",
        &zea8cc9b69b);
  while (zcf8aa38eb9 < zea8cc9b69b) {
    unsigned long long int z83180e9b64 = (0x786 + 802 - 0xaa8);
    unsigned long long int z65564ea317, zc843638074;
    scanf("\x25\x6c\x6c\x75\x20\x25\x6c\x6c\x75"
          "\n",
          &z65564ea317, &zc843638074);
    for (; z65564ea317 <= zc843638074; z65564ea317++) {
      if (z2664f6d070(z65564ea317)) {
        long double zde4254b6e9 = sqrtl(z65564ea317);
        if (zde4254b6e9 - (long long int)zde4254b6e9 < 0.000000000000000001L) {
          if (z2664f6d070((unsigned long long)zde4254b6e9))
            z83180e9b64++;
        }
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x6c\x6c\x75"
           "\n",
           ++zcf8aa38eb9, z83180e9b64);
  }
  return (0xb06 + 3183 - 0x1775);
}
