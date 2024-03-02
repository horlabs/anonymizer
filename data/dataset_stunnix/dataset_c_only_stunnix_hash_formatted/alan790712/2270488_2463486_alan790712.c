
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int z898a1af5f9, z1549c8a199;
char z7dc229fb97[10000001] = {(0x91f + 3821 - 0x180c)};
char z2ab5ee1efb[(0x1c12 + 274 - 0x1852)];
int main() {
  int z662abfeec9, z6222fffa3a;
  int z7649c3227f, z72a02444e6, zc5dd60292a;
  long long int zdb46503377;
  int z70f998dc8c = (0x1a56 + 566 - 0x1c8c);
  for (z7649c3227f = (0x92b + 2631 - 0x1371); z7649c3227f < 10000001;
       ++z7649c3227f) {
    sprintf(z2ab5ee1efb, "\x25\x64", z7649c3227f);
    for (z72a02444e6 = (0x1591 + 2833 - 0x20a2),
        zc5dd60292a = strlen(z2ab5ee1efb) - (0x2d9 + 4588 - 0x14c4);
         z72a02444e6 < zc5dd60292a &&
         z2ab5ee1efb[z72a02444e6] == z2ab5ee1efb[zc5dd60292a];
         ++z72a02444e6, --zc5dd60292a)
      ;
    if (z72a02444e6 >= zc5dd60292a)
      z7dc229fb97[z7649c3227f] = (0x47b + 913 - 0x80b);
  }
  scanf("\x25\x64", &z6222fffa3a);
  for (z662abfeec9 = (0xdc4 + 4180 - 0x1e17); z662abfeec9 <= z6222fffa3a;
       ++z662abfeec9) {
    z70f998dc8c = (0x84b + 304 - 0x97b);
    scanf("\x25\x6c\x6c\x64\x20\x25\x6c\x6c\x64", &z898a1af5f9, &z1549c8a199);
    for (zdb46503377 = (long long int)(sqrt(z898a1af5f9));
         zdb46503377 * zdb46503377 <= z1549c8a199; ++zdb46503377) {
      if (zdb46503377 * zdb46503377 < z898a1af5f9)
        continue;
      if (z7dc229fb97[zdb46503377]) {
        sprintf(z2ab5ee1efb, "\x25\x6c\x6c\x64", zdb46503377 * zdb46503377);
        for (z72a02444e6 = (0x121f + 142 - 0x12ad),
            zc5dd60292a = strlen(z2ab5ee1efb) - (0x73 + 2066 - 0x884);
             z72a02444e6 < zc5dd60292a &&
             z2ab5ee1efb[z72a02444e6] == z2ab5ee1efb[zc5dd60292a];
             ++z72a02444e6, --zc5dd60292a)
          ;
        if (z72a02444e6 >= zc5dd60292a) {
          ++z70f998dc8c;
        }
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", z662abfeec9);
    printf("\x25\x64"
           "\n",
           z70f998dc8c);
  }
  return (0xb28 + 2772 - 0x15fc);
}
