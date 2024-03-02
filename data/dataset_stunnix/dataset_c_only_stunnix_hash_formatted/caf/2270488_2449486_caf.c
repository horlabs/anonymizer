
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void zf1857179b0(int z4d2228aca1) {
  int zee5580d457, z9417e6fa0a;
  int z39dd2ee136[(0xadd + 5430 - 0x1faf)][(0x9c8 + 7326 - 0x2602)];
  int zd99664b364, zfa583fbe51;
  int z4a526df0e0 = (0x13b + 4287 - 0x11f9);
  scanf("\x25\x64\x25\x64", &zee5580d457, &z9417e6fa0a);
  for (zd99664b364 = (0x1612 + 1979 - 0x1dcd); zd99664b364 < zee5580d457;
       zd99664b364++)
    for (zfa583fbe51 = (0xf0 + 7336 - 0x1d98); zfa583fbe51 < z9417e6fa0a;
         zfa583fbe51++)
      scanf("\x25\x64", &z39dd2ee136[zd99664b364][zfa583fbe51]);
  for (zd99664b364 = (0x12eb + 2859 - 0x1e16); zd99664b364 < zee5580d457;
       zd99664b364++) {
    for (zfa583fbe51 = (0x57a + 1894 - 0xce0); zfa583fbe51 < z9417e6fa0a;
         zfa583fbe51++) {
      int za5199f2eda;
      for (za5199f2eda = (0x1079 + 3258 - 0x1d33); za5199f2eda < zee5580d457;
           za5199f2eda++) {
        if (z39dd2ee136[zd99664b364][zfa583fbe51] <
            z39dd2ee136[za5199f2eda][zfa583fbe51]) {
          int zd04abf92ee;
          for (zd04abf92ee = (0x791 + 2789 - 0x1276); zd04abf92ee < z9417e6fa0a;
               zd04abf92ee++) {
            if (z39dd2ee136[zd99664b364][zfa583fbe51] <
                z39dd2ee136[zd99664b364][zd04abf92ee])
              goto z97aa99a1c7;
          }
          break;
        }
      }
    }
  }
  z4a526df0e0 = (0x1065 + 3798 - 0x1f3b);
z97aa99a1c7:
  printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
         "\n",
         z4d2228aca1 + (0x17f + 3079 - 0xd85),
         z4a526df0e0 ? "\x4e\x4f" : "\x59\x45\x53");
}
int main() {
  int z4d2228aca1, zd99664b364;
  scanf("\x25\x64", &z4d2228aca1);
  for (zd99664b364 = (0x1e6a + 461 - 0x2037); zd99664b364 < z4d2228aca1;
       zd99664b364++)
    zf1857179b0(zd99664b364);
  return (0x1170 + 3958 - 0x20e6);
}
