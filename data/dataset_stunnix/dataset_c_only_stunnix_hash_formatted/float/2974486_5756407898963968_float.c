
#include <stdio.h>
#include <stdlib.h>

int z2b484f9a44(const void *z30f0f2ae42, const void *z7f4f5e96bb) {
  return *(int *)z30f0f2ae42 - *(int *)z7f4f5e96bb;
}
int main() {
  int zaa7e4fa318, z2d7eabf4b2, zbdb7511dee, z10fabe7aa0, za2c30f5980,
      zd798fd428f;
  int zb90165355c[(0x9bc + 2823 - 0x14bb)], zf8fee7ad9b, zcee4fb30c5;
  scanf("\x25\x64", &zaa7e4fa318);
  for (z2d7eabf4b2 = (0x15e4 + 3925 - 0x2538); z2d7eabf4b2 <= zaa7e4fa318;
       z2d7eabf4b2++) {
    zf8fee7ad9b = (0xfd3 + 3685 - 0x1e38);
    scanf("\x25\x64", &zbdb7511dee);
    for (z10fabe7aa0 = (0xdf5 + 5005 - 0x2181);
         z10fabe7aa0 <= (0x2224 + 638 - 0x249e); z10fabe7aa0++) {
      if (z10fabe7aa0 == zbdb7511dee) {
        scanf("\x25\x64\x20\x25\x64\x20\x25\x64\x20\x25\x64",
              &zb90165355c[(0x1b + 7279 - 0x1c8a)],
              &zb90165355c[(0xfdc + 2963 - 0x1b6e)],
              &zb90165355c[(0x2bf + 5448 - 0x1805)],
              &zb90165355c[(0xa2d + 2323 - 0x133d)]);
      } else {
        scanf("\x25\x64\x20\x25\x64\x20\x25\x64\x20\x25\x64", &za2c30f5980,
              &za2c30f5980, &za2c30f5980, &za2c30f5980);
      }
    }
    scanf("\x25\x64", &zbdb7511dee);
    for (z10fabe7aa0 = (0xb49 + 2064 - 0x1358);
         z10fabe7aa0 <= (0x16fc + 2045 - 0x1ef5); z10fabe7aa0++) {
      if (z10fabe7aa0 == zbdb7511dee) {
        scanf("\x25\x64\x20\x25\x64\x20\x25\x64\x20\x25\x64",
              &zb90165355c[(0x558 + 4010 - 0x14fe)],
              &zb90165355c[(0xb3 + 7561 - 0x1e37)],
              &zb90165355c[(0x1c0d + 1818 - 0x2321)],
              &zb90165355c[(0x822 + 5308 - 0x1cd7)]);
      } else {
        scanf("\x25\x64\x20\x25\x64\x20\x25\x64\x20\x25\x64", &za2c30f5980,
              &za2c30f5980, &za2c30f5980, &za2c30f5980);
      }
    }
    qsort(zb90165355c, (0x1383 + 1881 - 0x1ad4), sizeof(int), z2b484f9a44);
    for (zd798fd428f = (0x41f + 624 - 0x68e);
         zd798fd428f < (0x606 + 4256 - 0x169e); zd798fd428f++) {
      if (zb90165355c[zd798fd428f] ==
          zb90165355c[zd798fd428f - (0x1726 + 2159 - 0x1f94)]) {
        zf8fee7ad9b++;
        zcee4fb30c5 = zb90165355c[zd798fd428f];
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", z2d7eabf4b2);
    switch (zf8fee7ad9b) {
    case (0x7e2 + 6428 - 0x20fd):
      printf("\x25\x64"
             "\n",
             zcee4fb30c5);
      break;
    case (0xa90 + 924 - 0xe2c):
      printf("\x56\x6f\x6c\x75\x6e\x74\x65\x65\x72\x20\x63\x68\x65\x61\x74\x65"
             "\x64\x21"
             "\n");
      break;
    default:
      printf("\x42\x61\x64\x20\x6d\x61\x67\x69\x63\x69\x61\x6e\x21"
             "\n");
      break;
    }
  }
  return (0xefc + 4654 - 0x212a);
}
