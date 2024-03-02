
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char zac29b3c64a(char x) {
  switch (x) {
  case ((char)(0xcd + 3369 - 0xd95)):
    return ((char)(0x639 + 3671 - 0x1417));
  case ((char)(0xad8 + 7208 - 0x269e)):
    return ((char)(0x991 + 4114 - 0x193b));
  case ((char)(0x7b3 + 263 - 0x857)):
    return ((char)(0xcea + 5215 - 0x20e4));
  case ((char)(0x10e1 + 5702 - 0x26c3)):
    return ((char)(0x33b + 8361 - 0x2371));
  case ((char)(0x1f9f + 44 - 0x1f66)):
    return ((char)(0x713 + 399 - 0x833));
  case ((char)(0x46b + 7842 - 0x22a7)):
    return ((char)(0x9e0 + 1255 - 0xe64));
  case ((char)(0x44f + 4621 - 0x15f5)):
    return ((char)(0x8bd + 2499 - 0x120a));
  case ((char)(0x1d47 + 1505 - 0x22c0)):
    return ((char)(0x63f + 3908 - 0x150b));
  case ((char)(0x85f + 1857 - 0xf37)):
    return ((char)(0x695 + 4598 - 0x1827));
  case ((char)(0x16dc + 2961 - 0x2203)):
    return ((char)(0x2b8 + 2494 - 0xc01));
  case ((char)(0xe43 + 3040 - 0x19b8)):
    return ((char)(0xdfa + 4879 - 0x20a0));
  case ((char)(0x2261 + 978 - 0x25c7)):
    return ((char)(0xef1 + 62 - 0xec8));
  case ((char)(0xbb + 8821 - 0x22c3)):
    return ((char)(0x5e2 + 973 - 0x943));
  case ((char)(0x378 + 4378 - 0x1424)):
    return ((char)(0xfca + 1661 - 0x15e5));
  case ((char)(0x1d0 + 5981 - 0x18be)):
    return ((char)(0x1476 + 3696 - 0x227b));
  case ((char)(0xab2 + 2269 - 0x131f)):
    return ((char)(0x1a9b + 1442 - 0x1fcb));
  case ((char)(0x2076 + 552 - 0x222d)):
    return ((char)(0xd09 + 4014 - 0x1c3d));
  case ((char)(0xb60 + 6484 - 0x2442)):
    return ((char)(0xb1 + 6426 - 0x1957));
  case ((char)(0x1509 + 1752 - 0x1b6e)):
    return ((char)(0xe7d + 244 - 0xf03));
  case ((char)(0x21c3 + 1118 - 0x25ad)):
    return ((char)(0x1636 + 682 - 0x1869));
  case ((char)(0x11c6 + 1093 - 0x1596)):
    return ((char)(0x1f6f + 65 - 0x1f46));
  case ((char)(0x1333 + 2182 - 0x1b43)):
    return ((char)(0x73a + 3463 - 0x1451));
  case ((char)(0x864 + 2268 - 0x10c9)):
    return ((char)(0x109b + 2583 - 0x1a4c));
  case ((char)(0x466 + 4377 - 0x1507)):
    return ((char)(0xddf + 3222 - 0x1a08));
  case ((char)(0x519 + 3339 - 0x11ab)):
    return ((char)(0x5d8 + 3133 - 0x11b4));
  case ((char)(0x1a32 + 2166 - 0x222e)):
    return ((char)(0x381 + 1271 - 0x807));
  }
  return ((char)(0xff + 1446 - 0x685));
}
int main() {
  int zd386c76bae, zde7b313181, zb7a96b72ec, z2e933dacb3;
  char zca2a9fe06e[(0x3f8 + 2922 - 0xe9a)],
      zead8b400d8[(0xf67 + 3522 - 0x1c61)];
  scanf("\x25\x64", &zd386c76bae);
  scanf("\x25\x2a\x63");
  for (zde7b313181 = (0x215f + 967 - 0x2525); zde7b313181 <= zd386c76bae;
       zde7b313181++) {
    gets(zca2a9fe06e);
    for (zb7a96b72ec = (0x943 + 4145 - 0x1974);
         zca2a9fe06e[zb7a96b72ec] != '\0'; zb7a96b72ec++) {
      zead8b400d8[zb7a96b72ec] = zac29b3c64a(zca2a9fe06e[zb7a96b72ec]);
    }
    zead8b400d8[zb7a96b72ec] = '\0';
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
           "\n",
           zde7b313181, zead8b400d8);
  }
  return (0x137 + 7312 - 0x1dc7);
}
