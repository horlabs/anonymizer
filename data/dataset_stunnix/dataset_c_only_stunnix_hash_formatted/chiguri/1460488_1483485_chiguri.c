
#include <stdio.h>

const char zaa9ac2f011[] = {(0xee8 + 2808 - 0x1967),  (0x46b + 1365 - 0x958),
                            (0x161b + 2149 - 0x1e1b), (0x1502 + 4346 - 0x2589),
                            (0x789 + 7505 - 0x246b),  (0x7a9 + 7546 - 0x24c0),
                            (0x3d8 + 8062 - 0x22e0),  (0x55d + 5577 - 0x1aae),
                            (0x251 + 9490 - 0x26ff),  (0x15b8 + 1405 - 0x1ac0),
                            (0xe65 + 4550 - 0x1fc2),  (0x16d7 + 2733 - 0x211d),
                            (0x18d + 2686 - 0xb9f),   (0x15d5 + 1671 - 0x1bfa),
                            (0x6f7 + 3933 - 0x15e9),  (0xbfd + 524 - 0xd97),
                            (0x4b1 + 8003 - 0x237a),  (0x2b1 + 1588 - 0x871),
                            (0x418 + 5379 - 0x18ad),  (0x1c6 + 7554 - 0x1ed1),
                            (0x240f + 409 - 0x253e),  (0x74 + 55 - 0x3b),
                            (0xdf6 + 5567 - 0x234f),  (0x407 + 6343 - 0x1c61),
                            (0x218f + 1415 - 0x26b5), (0x1276 + 2330 - 0x1b1f)};
int main(void) {
  int z125cc0a18b;
  char z70d41763c1[(0x25db + 314 - 0x26af)];
  int z974c34e932, zdef98a90ef;
  fgets(z70d41763c1, (0x1cd + 5994 - 0x192d), stdin);
  sscanf(z70d41763c1, "\x25\x64", &z125cc0a18b);
  for (z974c34e932 = (0x1661 + 2511 - 0x202f); z974c34e932 <= z125cc0a18b;
       ++z974c34e932) {
    gets(z70d41763c1);
    for (zdef98a90ef = (0x1688 + 913 - 0x1a19);
         z70d41763c1[zdef98a90ef] != '\n' && z70d41763c1[zdef98a90ef] != '\0';
         ++zdef98a90ef) {
      if (z70d41763c1[zdef98a90ef] == ((char)(0x4cb + 5067 - 0x1876)))
        continue;
      z70d41763c1[zdef98a90ef] = zaa9ac2f011[z70d41763c1[zdef98a90ef] -
                                             ((char)(0xdbc + 1217 - 0x121c))];
    }
    z70d41763c1[zdef98a90ef] = '\0';
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
           "\n",
           z974c34e932, z70d41763c1);
  }
  return (0x294 + 6949 - 0x1db9);
}
