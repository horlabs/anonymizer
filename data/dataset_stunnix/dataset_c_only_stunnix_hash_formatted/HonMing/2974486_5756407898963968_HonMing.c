
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int z2a48cd1227, zf94064bf50;
  int z7d49dfcb4f, z802ec4feee, zf92b6d7179;
  int zefa281a86c;
  int z36c9cc3557;
  int z1d0fb3e82c[(0x1a10 + 986 - 0x1de0)][(0xa0c + 1681 - 0x1093)];
  int z9b455bb497, zfd2d6f432d, z9299ea21c6;
  int zbcfd08ee1d, z66a385c06e;
  int z3383698831[(0x7bf + 4877 - 0x1ac2)];
  int z79fb5d5753[(0x3d8 + 1836 - 0xafa)];
  int zc71393629c;
  int z9477f59cbb;
  unsigned long long z67ca3b6456;
  scanf("\x25\x64", &z36c9cc3557);
  for (z7d49dfcb4f = (0xd6f + 5303 - 0x2225); z7d49dfcb4f <= z36c9cc3557;
       z7d49dfcb4f++) {
    scanf("\x25\x64", &zbcfd08ee1d);
    for (z2a48cd1227 = (0xbe7 + 644 - 0xe6b);
         z2a48cd1227 < (0x96f + 325 - 0xab0); z2a48cd1227++)
      for (zf94064bf50 = (0x2e6 + 8394 - 0x23b0);
           zf94064bf50 < (0xdb5 + 2728 - 0x1859); zf94064bf50++) {
        scanf("\x25\x64", &z1d0fb3e82c[z2a48cd1227][zf94064bf50]);
        if (z2a48cd1227 == zbcfd08ee1d - (0x990 + 2053 - 0x1194))
          z3383698831[zf94064bf50] = z1d0fb3e82c[z2a48cd1227][zf94064bf50];
      }
    scanf("\x25\x64", &z66a385c06e);
    for (z2a48cd1227 = (0xd85 + 1774 - 0x1473);
         z2a48cd1227 < (0x981 + 1100 - 0xdc9); z2a48cd1227++)
      for (zf94064bf50 = (0x333 + 3343 - 0x1042);
           zf94064bf50 < (0x117 + 2719 - 0xbb2); zf94064bf50++) {
        scanf("\x25\x64", &z1d0fb3e82c[z2a48cd1227][zf94064bf50]);
        if (z2a48cd1227 == z66a385c06e - (0xaea + 3901 - 0x1a26))
          z79fb5d5753[zf94064bf50] = z1d0fb3e82c[z2a48cd1227][zf94064bf50];
      }
    zc71393629c = (0x1aa + 6742 - 0x1c00);
    z9477f59cbb = -(0x943 + 1155 - 0xdc5);
    for (z2a48cd1227 = (0x3a + 1117 - 0x497);
         z2a48cd1227 < (0x311 + 518 - 0x513); z2a48cd1227++) {
      for (zf94064bf50 = (0x15c9 + 1265 - 0x1aba);
           zf94064bf50 < (0x15c8 + 3500 - 0x2370); zf94064bf50++) {
        if (z3383698831[z2a48cd1227] == z79fb5d5753[zf94064bf50]) {
          z9477f59cbb = z3383698831[z2a48cd1227];
          zc71393629c++;
          break;
        }
      }
    }
    if (zc71393629c == (0xec6 + 5036 - 0x2272))
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x56\x6f\x6c\x75\x6e\x74"
             "\x65\x65\x72\x20\x63\x68\x65\x61\x74\x65\x64\x21"
             "\n",
             z7d49dfcb4f);
    else if (zc71393629c == (0x1ecb + 1813 - 0x25df))
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
             "\n",
             z7d49dfcb4f, z9477f59cbb);
    else
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x42\x61\x64\x20\x6d\x61"
             "\x67\x69\x63\x69\x61\x6e\x21"
             "\n",
             z7d49dfcb4f);
  }
}
