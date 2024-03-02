
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int z4c6b3bdfb8, z729ecc8a4b;
  int zc2d7465fbc, za7001e00a4, z9c232e1638;
  int z0c08825807;
  int z727fafdda6;
  int z6bde048d5d, z24e007eaa4, z10409a7fa6;
  int z4893310ea7, z67849e7ea2;
  int max;
  unsigned long long z6ecabb71af[10000];
  int z2bf7fa835a;
  unsigned long long z68def0e071;
  unsigned long long z27d8b0a199, zba0e38978c;
  char line[(0x8eb + 7491 - 0x2566)];
  z729ecc8a4b = (0x1131 + 1901 - 0x189e);
  for (z68def0e071 = (0x1131 + 3947 - 0x209b); z68def0e071 <= 10000000;
       z68def0e071++) {
    sprintf(line, "\x25\x6c\x6c\x75", z68def0e071);
    for (z4c6b3bdfb8 = (0xfdf + 2174 - 0x185d);
         z4c6b3bdfb8 < strlen(line) / (0x233d + 329 - 0x2484); z4c6b3bdfb8++) {
      if (line[z4c6b3bdfb8] !=
          line[strlen(line) - (0x816 + 7374 - 0x24e3) - z4c6b3bdfb8])
        break;
    }
    if (z4c6b3bdfb8 != strlen(line) / (0x700 + 5187 - 0x1b41))
      continue;
    sprintf(line, "\x25\x6c\x6c\x75", z68def0e071 * z68def0e071);
    for (z4c6b3bdfb8 = (0x3f1 + 7925 - 0x22e6);
         z4c6b3bdfb8 < strlen(line) / (0x1c15 + 1771 - 0x22fe); z4c6b3bdfb8++) {
      if (line[z4c6b3bdfb8] !=
          line[strlen(line) - (0xfb8 + 3142 - 0x1bfd) - z4c6b3bdfb8])
        break;
    }
    if (z4c6b3bdfb8 == strlen(line) / (0x6b8 + 2791 - 0x119d))
      z6ecabb71af[z729ecc8a4b++] = z68def0e071 * z68def0e071;
  }
  scanf("\x25\x64", &z727fafdda6);
  for (zc2d7465fbc = (0x779 + 3465 - 0x1501); zc2d7465fbc <= z727fafdda6;
       zc2d7465fbc++) {
    z2bf7fa835a = (0x1160 + 2565 - 0x1b65);
    scanf("\x25\x6c\x6c\x75\x25\x6c\x6c\x75", &z27d8b0a199, &zba0e38978c);
    for (z4c6b3bdfb8 = (0x121d + 4578 - 0x23ff); z4c6b3bdfb8 < z729ecc8a4b;
         z4c6b3bdfb8++) {
      if (z6ecabb71af[z4c6b3bdfb8] >= z27d8b0a199 &&
          z6ecabb71af[z4c6b3bdfb8] <= zba0e38978c)
        z2bf7fa835a++;
      if (z6ecabb71af[z4c6b3bdfb8] > zba0e38978c)
        break;
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           zc2d7465fbc, z2bf7fa835a);
  }
}
