
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int z826f18ca7c[(0xd19 + 1429 - 0x124a)][(0xa9c + 23 - 0xa4f)];
int z7f5c7e5593, zf8be8c3803;
int zdce97007b9(int x, int y) {
  int zbb155283af, zff02e4f615;
  int zea20bf61ca = z826f18ca7c[x][y];
  int zdf93166ef3 = (0x241c + 590 - 0x2669);
  for (zbb155283af = (0x38a + 1098 - 0x7d4); zbb155283af < z7f5c7e5593;
       ++zbb155283af) {
    if (zea20bf61ca < z826f18ca7c[zbb155283af][y]) {
      zdf93166ef3 = (0x1145 + 700 - 0x1401);
      break;
    }
  }
  if (zdf93166ef3)
    return (0x1a7f + 1709 - 0x212b);
  for (zbb155283af = (0x396 + 8336 - 0x2426); zbb155283af < zf8be8c3803;
       ++zbb155283af) {
    if (zea20bf61ca < z826f18ca7c[x][zbb155283af]) {
      return (0x9cd + 329 - 0xb16);
    }
  }
  return (0x17bf + 3421 - 0x251b);
}
int main(void) {
  int za2bd09780c;
  int zbb155283af, zff02e4f615, zadaa64bab7;
  int zdf93166ef3;
  scanf("\x25\x64", &za2bd09780c);
  for (zbb155283af = (0x14c5 + 3459 - 0x2247); zbb155283af <= za2bd09780c;
       ++zbb155283af) {
    scanf("\x25\x64\x20\x25\x64", &z7f5c7e5593, &zf8be8c3803);
    for (zff02e4f615 = (0x4c3 + 4585 - 0x16ac); zff02e4f615 < z7f5c7e5593;
         ++zff02e4f615) {
      for (zadaa64bab7 = (0x10ac + 2816 - 0x1bac); zadaa64bab7 < zf8be8c3803;
           ++zadaa64bab7) {
        scanf("\x25\x64", &(z826f18ca7c[zff02e4f615][zadaa64bab7]));
      }
    }
    zdf93166ef3 = (0x3ea + 5532 - 0x1985);
    for (zff02e4f615 = (0x43a + 1546 - 0xa44); zff02e4f615 < z7f5c7e5593;
         ++zff02e4f615) {
      for (zadaa64bab7 = (0x16c7 + 2220 - 0x1f73); zadaa64bab7 < zf8be8c3803;
           ++zadaa64bab7) {
        if (!zdce97007b9(zff02e4f615, zadaa64bab7)) {
          zdf93166ef3 = (0x19db + 3112 - 0x2603);
          goto z8fc0a40482;
        }
      }
    }
  z8fc0a40482:
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", zbb155283af);
    if (zdf93166ef3) {
      printf("\x59\x45\x53"
             "\n");
    } else {
      printf("\x4e\x4f"
             "\n");
    }
  }
  return (0xe61 + 6209 - 0x26a2);
}
