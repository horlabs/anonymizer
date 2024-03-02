
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int zc2e39b49ad(int zb13371def0, int z230cadab4f, int za240b36ebc,
                int z6e0a3cde5c, int z929e8026b0) {
  return zb13371def0 == z230cadab4f || zb13371def0 == za240b36ebc ||
         zb13371def0 == z6e0a3cde5c || zb13371def0 == z929e8026b0;
}
void z69a94a47a2(int z02dc4ac943) {
  int zc8212fc5ea;
  int zec6515c2e1;
  int z230cadab4f, za240b36ebc, z6e0a3cde5c, z929e8026b0;
  int z9002760e5f;
  int za1170d77ab = (0x792 + 7399 - 0x2479);
  scanf("\x25\x64", &zec6515c2e1);
  for (zc8212fc5ea = (0xf1d + 4195 - 0x1f7f);
       zc8212fc5ea < (0x1bf + 5958 - 0x1900); zc8212fc5ea++) {
    int zb2b3bc2957, zba56d936e9, z1c3f11d500, zf2e0874ea3;
    scanf("\x25\x64\x20\x25\x64\x20\x25\x64\x20\x25\x64", &zb2b3bc2957,
          &zba56d936e9, &z1c3f11d500, &zf2e0874ea3);
    if (zc8212fc5ea == zec6515c2e1) {
      z230cadab4f = zb2b3bc2957;
      za240b36ebc = zba56d936e9;
      z6e0a3cde5c = z1c3f11d500;
      z929e8026b0 = zf2e0874ea3;
    }
  }
  scanf("\x25\x64", &zec6515c2e1);
  for (zc8212fc5ea = (0x1762 + 149 - 0x17f6);
       zc8212fc5ea < (0x1867 + 559 - 0x1a91); zc8212fc5ea++) {
    int zb2b3bc2957, zba56d936e9, z1c3f11d500, zf2e0874ea3;
    scanf("\x25\x64\x20\x25\x64\x20\x25\x64\x20\x25\x64", &zb2b3bc2957,
          &zba56d936e9, &z1c3f11d500, &zf2e0874ea3);
    if (zc8212fc5ea == zec6515c2e1) {
      if (zc2e39b49ad(z230cadab4f, zb2b3bc2957, zba56d936e9, z1c3f11d500,
                      zf2e0874ea3))
        z9002760e5f = z230cadab4f, za1170d77ab++;
      if (zc2e39b49ad(za240b36ebc, zb2b3bc2957, zba56d936e9, z1c3f11d500,
                      zf2e0874ea3))
        z9002760e5f = za240b36ebc, za1170d77ab++;
      if (zc2e39b49ad(z6e0a3cde5c, zb2b3bc2957, zba56d936e9, z1c3f11d500,
                      zf2e0874ea3))
        z9002760e5f = z6e0a3cde5c, za1170d77ab++;
      if (zc2e39b49ad(z929e8026b0, zb2b3bc2957, zba56d936e9, z1c3f11d500,
                      zf2e0874ea3))
        z9002760e5f = z929e8026b0, za1170d77ab++;
    }
  }
  printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
         z02dc4ac943 + (0x1b8 + 7795 - 0x202a));
  if (za1170d77ab < (0xbaf + 267 - 0xcb9))
    printf("\x56\x6f\x6c\x75\x6e\x74\x65\x65\x72\x20\x63\x68\x65\x61\x74\x65"
           "\x64\x21"
           "\n");
  else if (za1170d77ab > (0x177d + 1757 - 0x1e59))
    printf("\x42\x61\x64\x20\x6d\x61\x67\x69\x63\x69\x61\x6e\x21"
           "\n");
  else
    printf("\x25\x64"
           "\n",
           z9002760e5f);
}
int main() {
  int z02dc4ac943, zc8212fc5ea;
  scanf("\x25\x64", &z02dc4ac943);
  for (zc8212fc5ea = (0x10eb + 1872 - 0x183b); zc8212fc5ea < z02dc4ac943;
       zc8212fc5ea++)
    z69a94a47a2(zc8212fc5ea);
  return (0x1152 + 3894 - 0x2088);
}
