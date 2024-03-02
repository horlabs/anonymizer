
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long z84483dac30(long zcabbe291b7) {
  long z5dd061b29f;
  for (z5dd061b29f = (0x1d5d + 2340 - 0x2680);
       zcabbe291b7 >= (0x130 + 8266 - 0x2170);
       zcabbe291b7 /= (0x2e5 + 1038 - 0x6e9),
      z5dd061b29f *= (0xe62 + 5351 - 0x233f))
    ;
  return z5dd061b29f;
}
long z0184572fcf(long zb3b135441a, long z93841ba1cd) {
  return zb3b135441a / (0x3f1 + 7185 - 0x1ff8) +
         z93841ba1cd * (zb3b135441a % (0x110f + 1972 - 0x18b9));
}
long zedd98ac300(long zcabbe291b7, long z06d7d19408, long z6a31a6131a) {
  const long z93841ba1cd = z84483dac30(zcabbe291b7);
  long z72743d40d2 = (0xa3 + 3318 - 0xd99);
  long zb3b135441a;
  for (zb3b135441a = z0184572fcf(z6a31a6131a, z93841ba1cd);
       zb3b135441a != z6a31a6131a;
       zb3b135441a = z0184572fcf(zb3b135441a, z93841ba1cd)) {
    if (zb3b135441a <= z06d7d19408 && zb3b135441a > z6a31a6131a) {
      z72743d40d2++;
      fprintf(stderr,
              "\x28\x25\x6c\x64\x2c\x20\x25\x6c\x64\x29"
              "\n",
              z6a31a6131a, zb3b135441a);
    }
  }
  return z72743d40d2;
}
void z03d59ad6f3(int z27a9f3b1d2) {
  long zcabbe291b7, z06d7d19408, z93bd94beff;
  long z72743d40d2 = (0x15ab + 1260 - 0x1a97);
  scanf("\x25\x6c\x64\x20\x25\x6c\x64", &zcabbe291b7, &z06d7d19408);
  for (z93bd94beff = zcabbe291b7; z93bd94beff <= z06d7d19408; z93bd94beff++)
    z72743d40d2 += zedd98ac300(zcabbe291b7, z06d7d19408, z93bd94beff);
  printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x6c\x64"
         "\n",
         z27a9f3b1d2 + (0x12a2 + 3864 - 0x21b9), z72743d40d2);
}
int main() {
  int z27a9f3b1d2, z93bd94beff;
  scanf("\x25\x64", &z27a9f3b1d2);
  for (z93bd94beff = (0x2a9 + 3214 - 0xf37); z93bd94beff < z27a9f3b1d2;
       z93bd94beff++)
    z03d59ad6f3(z93bd94beff);
  return (0x159c + 1827 - 0x1cbf);
}
