
#include <stdio.h>

char zd17634eba9[(0x98 + 3642 - 0xecd)][(0x939 + 4235 - 0x19bf)];
int flag;
int zac54f2b741(char za3633fe2b1) {
  int z7fbdb12e2b, z6979f72581,
      zc294ec24dd[(0x64a + 6685 - 0x2063)] = {(0xda9 + 4035 - 0x1d6c)},
                                  z714628dbe9[(0x596 + 6838 - 0x2048)] = {
                                      (0xd62 + 3766 - 0x1c18)};
  int z596cbf77c6 = (0x1659 + 3192 - 0x22d1),
      z5b658ebdf3 = (0x1931 + 1986 - 0x20f3);
  for (z7fbdb12e2b = (0x60d + 4846 - 0x18fb);
       z7fbdb12e2b < (0xaba + 1960 - 0x125e); z7fbdb12e2b++) {
    if (zd17634eba9[z7fbdb12e2b][z7fbdb12e2b] == za3633fe2b1 ||
        zd17634eba9[z7fbdb12e2b][z7fbdb12e2b] ==
            ((char)(0x210f + 1577 - 0x26e4)))
      z596cbf77c6++;
    if (zd17634eba9[z7fbdb12e2b][(0x18a1 + 580 - 0x1ae2) - z7fbdb12e2b] ==
            za3633fe2b1 ||
        zd17634eba9[z7fbdb12e2b][(0x9c9 + 1684 - 0x105a) - z7fbdb12e2b] ==
            ((char)(0x1425 + 223 - 0x14b0)))
      z5b658ebdf3++;
    for (z6979f72581 = (0x491 + 5201 - 0x18e2);
         z6979f72581 < (0x95d + 3057 - 0x154a); z6979f72581++) {
      if (zd17634eba9[z7fbdb12e2b][z6979f72581] == za3633fe2b1 ||
          zd17634eba9[z7fbdb12e2b][z6979f72581] ==
              ((char)(0x190a + 3446 - 0x262c)))
        z714628dbe9[z7fbdb12e2b]++;
      if (zd17634eba9[z6979f72581][z7fbdb12e2b] == za3633fe2b1 ||
          zd17634eba9[z6979f72581][z7fbdb12e2b] ==
              ((char)(0x16b6 + 1024 - 0x1a62)))
        zc294ec24dd[z7fbdb12e2b]++;
    }
  }
  for (z7fbdb12e2b = (0x12e8 + 4094 - 0x22e6);
       z7fbdb12e2b < (0x1479 + 992 - 0x1855); z7fbdb12e2b++)
    if (z714628dbe9[z7fbdb12e2b] == (0x109f + 4749 - 0x2328) ||
        zc294ec24dd[z7fbdb12e2b] == (0x710 + 1850 - 0xe46))
      return (0x9ad + 4638 - 0x1bca);
  if (z596cbf77c6 == (0x9a9 + 4302 - 0x1a73) ||
      z5b658ebdf3 == (0xab7 + 1545 - 0x10bc))
    return (0x1ded + 362 - 0x1f56);
  return (0x69a + 1816 - 0xdb2);
}
int z113a35a480() {
  int z7fbdb12e2b, z6979f72581, flag = (0x91a + 5208 - 0x1d72);
  for (z7fbdb12e2b = (0x1f05 + 541 - 0x2122);
       z7fbdb12e2b < (0x37a + 4056 - 0x134e); z7fbdb12e2b++)
    for (z6979f72581 = (0x855 + 3673 - 0x16ae);
         z6979f72581 < (0x1a09 + 1007 - 0x1df4); z6979f72581++)
      flag += (zd17634eba9[z7fbdb12e2b][z6979f72581] ==
               ((char)(0x7a3 + 3908 - 0x16b9)));
  if (zac54f2b741(((char)(0xe34 + 357 - 0xf41))))
    return (0x18e4 + 2586 - 0x22fe);
  if (zac54f2b741(((char)(0x720 + 6939 - 0x21ec))))
    return (0x2649 + 190 - 0x2706);
  if (flag == (0x7d6 + 6430 - 0x20f4))
    return (0x1260 + 4104 - 0x2266);
  return (0x18f3 + 3379 - 0x2623);
}
int main() {
  int zb0cea42bcd, z7fbdb12e2b, ze0e6fa0131 = (0xc28 + 3268 - 0x18eb);
  freopen("\x41\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x69\x6e",
          "\x72", stdin);
  freopen("\x41\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x74\x78\x74",
          "\x77", stdout);
  char z38d12d55d2[][(0x136d + 2958 - 0x1ec9)] = {
      "\x58\x20\x77\x6f\x6e", "\x4f\x20\x77\x6f\x6e", "\x44\x72\x61\x77",
      "\x47\x61\x6d\x65\x20\x68\x61\x73\x20\x6e\x6f\x74\x20\x63\x6f\x6d\x70\x6c"
      "\x65\x74\x65\x64"};
  scanf("\x25\x64", &zb0cea42bcd);
  while (zb0cea42bcd--) {
    for (z7fbdb12e2b = (0x105d + 4065 - 0x203e);
         z7fbdb12e2b < (0x182 + 1286 - 0x684); z7fbdb12e2b++)
      scanf("\x25\x73", zd17634eba9[z7fbdb12e2b]);
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
           "\n",
           ze0e6fa0131++, z38d12d55d2[z113a35a480()]);
  }
  return (0x1390 + 4619 - 0x259b);
}
