
#include <stdio.h>

int zfc9d260dee[(0x144a + 3970 - 0x235e)][(0x732 + 5164 - 0x1af0)],
    zae161d7b5a[(0x1ac9 + 239 - 0x1b4a)][(0xd5c + 618 - 0xf58)];
int zc3bfd50cea[(0x8d7 + 612 - 0xacd)], ze9de72dab9[(0x95a + 625 - 0xb5d)];
int z2cbc661ac7[(0x282 + 8146 - 0x2178)][(0x1719 + 3959 - 0x268d)];
int min(int z0b61761c59, int z2a912e1981) {
  return z0b61761c59 < z2a912e1981 ? z0b61761c59 : z2a912e1981;
}
int max(int z0b61761c59, int z2a912e1981) {
  return z0b61761c59 > z2a912e1981 ? z0b61761c59 : z2a912e1981;
}
int main() {
  int zd55d70ec2a, zb604cde8f6 = (0x131 + 2965 - 0xcc5);
  int z0e2a4f7b8e = (0x21db + 1318 - 0x2701),
      z1d8fabcc31 = (0x13bb + 4028 - 0x2376);
  int flag, z2c3190518d, za509bd7d14, z4d7279b89f, za83d73f955, zee31d6c470,
      zdcdb8bf879;
  freopen("\x42\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x69\x6e",
          "\x72", stdin);
  freopen("\x42\x5f\x6f\x75\x74\x2e\x74\x78\x74", "\x77", stdout);
  scanf("\x25\x64", &zd55d70ec2a);
  while (zd55d70ec2a--) {
    scanf("\x25\x64\x25\x64", &z2c3190518d, &za509bd7d14);
    for (z4d7279b89f = (0x1a3 + 6162 - 0x19b5); z4d7279b89f < z2c3190518d;
         z4d7279b89f++)
      zc3bfd50cea[z4d7279b89f] = (0xdd8 + 3400 - 0x1b20);
    for (za83d73f955 = (0xaeb + 6054 - 0x2291); za83d73f955 < za509bd7d14;
         za83d73f955++)
      ze9de72dab9[za83d73f955] = (0x1385 + 3538 - 0x2157);
    for (z4d7279b89f = (0x1bfb + 1832 - 0x2323); z4d7279b89f < z2c3190518d;
         z4d7279b89f++)
      for (za83d73f955 = (0x1d50 + 414 - 0x1eee); za83d73f955 < za509bd7d14;
           za83d73f955++)
        scanf("\x25\x64", &zfc9d260dee[z4d7279b89f][za83d73f955]),
            zc3bfd50cea[z4d7279b89f] =
                max(zc3bfd50cea[z4d7279b89f],
                    zfc9d260dee[z4d7279b89f][za83d73f955]),
            ze9de72dab9[za83d73f955] =
                max(ze9de72dab9[za83d73f955],
                    zfc9d260dee[z4d7279b89f][za83d73f955]);
    zee31d6c470 = (0x135f + 3687 - 0x21c6);
    for (z4d7279b89f = (0x1363 + 4296 - 0x242b); z4d7279b89f < z2c3190518d;
         z4d7279b89f++)
      z2cbc661ac7[zee31d6c470][(
          0xad3 + 2169 - 0x134c)] = zc3bfd50cea[z4d7279b89f],
                         z2cbc661ac7[zee31d6c470][(0xf28 + 3918 - 0x1e75)] =
                             z4d7279b89f,
                         z2cbc661ac7[zee31d6c470][(0x1b26 + 2662 - 0x258a)] =
                             z0e2a4f7b8e,
                         zee31d6c470++;
    for (z4d7279b89f = (0x174 + 5331 - 0x1647); z4d7279b89f < za509bd7d14;
         z4d7279b89f++)
      z2cbc661ac7[zee31d6c470][(
          0x127b + 4798 - 0x2539)] = ze9de72dab9[z4d7279b89f],
                          z2cbc661ac7[zee31d6c470][(0x1513 + 2207 - 0x1db1)] =
                              z4d7279b89f,
                          z2cbc661ac7[zee31d6c470][(0x247 + 5725 - 0x18a2)] =
                              z1d8fabcc31,
                          zee31d6c470++;
    for (z4d7279b89f = (0x1bca + 1061 - 0x1fef); z4d7279b89f < zee31d6c470;
         z4d7279b89f++)
      for (za83d73f955 = (0x784 + 7298 - 0x2406); za83d73f955 < z4d7279b89f;
           za83d73f955++)
        if (z2cbc661ac7[z4d7279b89f][(0x1084 + 4934 - 0x23ca)] <
            z2cbc661ac7[za83d73f955][(0xbd9 + 2990 - 0x1787)])
          (zdcdb8bf879 = z2cbc661ac7[z4d7279b89f][(0x15f7 + 1376 - 0x1b57)],
           z2cbc661ac7[z4d7279b89f][(0x39c + 1803 - 0xaa7)] =
               z2cbc661ac7[za83d73f955][(0x24d4 + 43 - 0x24ff)],
           z2cbc661ac7[za83d73f955][(0x143c + 348 - 0x1598)] = zdcdb8bf879),
              (zdcdb8bf879 = z2cbc661ac7[z4d7279b89f][(0xb46 + 6866 - 0x2617)],
               z2cbc661ac7[z4d7279b89f][(0x1d0f + 900 - 0x2092)] =
                   z2cbc661ac7[za83d73f955][(0x1aeb + 929 - 0x1e8b)],
               z2cbc661ac7[za83d73f955][(0x96d + 6770 - 0x23de)] = zdcdb8bf879),
              (zdcdb8bf879 = z2cbc661ac7[z4d7279b89f][(0x8d6 + 6748 - 0x2330)],
               z2cbc661ac7[z4d7279b89f][(0x254 + 8548 - 0x23b6)] =
                   z2cbc661ac7[za83d73f955][(0x7a0 + 3379 - 0x14d1)],
               z2cbc661ac7[za83d73f955][(0x246a + 271 - 0x2577)] = zdcdb8bf879);
    for (z4d7279b89f = (0x639 + 1110 - 0xa8f); z4d7279b89f < z2c3190518d;
         z4d7279b89f++)
      for (za83d73f955 = (0x920 + 1773 - 0x100d); za83d73f955 < za509bd7d14;
           za83d73f955++)
        zae161d7b5a[z4d7279b89f][za83d73f955] = (0x1e64 + 1029 - 0x2205);
    for (z4d7279b89f = zee31d6c470 - (0xc56 + 4923 - 0x1f90);
         z4d7279b89f >= (0xacd + 4459 - 0x1c38); z4d7279b89f--) {
      if (z2cbc661ac7[z4d7279b89f][(0xb1a + 2894 - 0x1666)] == z0e2a4f7b8e)
        for (za83d73f955 = (0x78b + 6806 - 0x2221); za83d73f955 < za509bd7d14;
             za83d73f955++)
          zae161d7b5a[z2cbc661ac7[z4d7279b89f][(0x49c + 353 - 0x5fc)]]
                     [za83d73f955] =
                         z2cbc661ac7[z4d7279b89f][(0x24a + 8068 - 0x21ce)];
      else
        for (za83d73f955 = (0x6d4 + 2579 - 0x10e7); za83d73f955 < z2c3190518d;
             za83d73f955++)
          zae161d7b5a[za83d73f955]
                     [z2cbc661ac7[z4d7279b89f][(0x1a4c + 247 - 0x1b42)]] =
                         z2cbc661ac7[z4d7279b89f][(0x1cb1 + 2486 - 0x2667)];
    }
    flag = (0x12a0 + 4431 - 0x23ef);
    for (z4d7279b89f = (0x19b + 6617 - 0x1b74); z4d7279b89f < z2c3190518d;
         z4d7279b89f++)
      for (za83d73f955 = (0x5f6 + 102 - 0x65c); za83d73f955 < za509bd7d14;
           za83d73f955++)
        if (zfc9d260dee[z4d7279b89f][za83d73f955] !=
            zae161d7b5a[z4d7279b89f][za83d73f955])
          flag = (0x8e4 + 4399 - 0x1a12);
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
           "\n",
           zb604cde8f6++, flag ? "\x4e\x4f" : "\x59\x45\x53");
  }
  return (0x67c + 6484 - 0x1fd0);
}
