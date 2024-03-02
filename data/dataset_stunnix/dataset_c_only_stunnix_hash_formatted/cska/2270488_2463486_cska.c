
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

char zda5f474f85[(0x7aa + 1109 - 0xb69)], ze552f7728f[(0xe5a + 6325 - 0x2679)];
unsigned long long int z7129acbdb8 = (0x818 + 2721 - 0x12b9);
int z102c55b35f(char *ze06cebafef, char *zaa8c32fedb) {
  int zae27c4b783;
  for (zae27c4b783 = (0xa81 + 4215 - 0x1af8);
       zae27c4b783 < (0xdb8 + 5519 - 0x22b1); zae27c4b783++) {
    if (ze06cebafef[zae27c4b783] > zaa8c32fedb[zae27c4b783])
      return (0x1f13 + 1911 - 0x2689);
    if (ze06cebafef[zae27c4b783] < zaa8c32fedb[zae27c4b783])
      return (0x1449 + 2851 - 0x1f6a);
  }
  return (0x103d + 3690 - 0x1ea7);
}
void z10f1b46b62(char *z1900ef80be, unsigned long long int z2b3d927372) {
  for (int zae27c4b783 = (0xe6d + 2599 - 0x17fe) - (0x755 + 2009 - 0xf2d);
       zae27c4b783 >= (0x1c4c + 226 - 0x1d2e);
       z1900ef80be[zae27c4b783] = z2b3d927372
                                      ? z2b3d927372 % (0xf5a + 5285 - 0x23f5)
                                      : (0x12eb + 937 - 0x1694),
           z2b3d927372 /= (0x841 + 1997 - 0x1004), zae27c4b783--)
    ;
}
void z322abe28bc(char *ze06cebafef, char *z0cf90d64de) {
  int zae27c4b783, z843eadde43, zecf3ac73d2,
      ze76868c9df = (0x99b + 4084 - 0x198f);
  z10f1b46b62(z0cf90d64de, (0x38f + 7865 - 0x2248));
  for (zae27c4b783 = (0xce4 + 5168 - 0x207e) - (0x1145 + 3536 - 0x1f14);
       zae27c4b783 >= (0x1146 + 2078 - 0x1964); zae27c4b783--) {
    for (ze76868c9df = (0x1e38 + 832 - 0x2178), zecf3ac73d2 = zae27c4b783,
        z843eadde43 = (0x679 + 733 - 0x8c0) - (0x26a + 3654 - 0x10af);
         zecf3ac73d2 >= (0x7e0 + 3783 - 0x16a7); zecf3ac73d2--, z843eadde43--) {
      ze76868c9df += z0cf90d64de[zecf3ac73d2] +
                     ze06cebafef[zae27c4b783] * ze06cebafef[z843eadde43];
      z0cf90d64de[zecf3ac73d2] = ze76868c9df % (0xaab + 4746 - 0x1d2b);
      ze76868c9df /= (0x178 + 1852 - 0x8aa);
    }
  }
}
int z9967cd07b9(char *z1900ef80be) {
  int zae27c4b783 = -(0x89f + 3453 - 0x161b);
  while (z1900ef80be[++zae27c4b783] == (0xde6 + 2418 - 0x1758))
    ;
  return (0x615 + 3337 - 0x1288) - zae27c4b783;
}
int zb9100d187f(char *z1900ef80be) {
  int zae27c4b783 = -(0x1c99 + 1343 - 0x21d7), z843eadde43;
  while (z1900ef80be[++zae27c4b783] == (0x38a + 8488 - 0x24b2))
    ;
  for (z843eadde43 = (0x19c9 + 1741 - 0x2000) - (0x1059 + 4269 - 0x2105);
       zae27c4b783 <= z843eadde43 &&
       z1900ef80be[zae27c4b783] == z1900ef80be[z843eadde43];
       zae27c4b783++, z843eadde43--)
    ;
  return zae27c4b783 > z843eadde43;
}
void zf42f653413(char *z1900ef80be, int zecf3ac73d2, int zae27c4b783) {
  static char z51d587030b[(0xc93 + 4250 - 0x1c97)];
  int z843eadde43, z10369bc8f3, z0b6f24c9b4;
  if (zae27c4b783 < ceil((float)zecf3ac73d2 / (0x76 + 1952 - 0x814))) {
    for (z843eadde43 = zae27c4b783 == (0xe5d + 1901 - 0x15ca)
                           ? (0x18f3 + 885 - 0x1c67)
                           : (0x10 + 9456 - 0x2500);
         z843eadde43 < (0x10e4 + 1337 - 0x1613); z843eadde43++) {
      z1900ef80be[(0x570 + 5429 - 0x1a0f) - (0x1112 + 821 - 0x1446) -
                  zae27c4b783] =
          z1900ef80be[(0x12a3 + 3953 - 0x217e) - zecf3ac73d2 + zae27c4b783] =
              z843eadde43;
      zf42f653413(z1900ef80be, zecf3ac73d2,
                  zae27c4b783 + (0xf49 + 653 - 0x11d5));
    }
  } else {
    z322abe28bc(z1900ef80be, z51d587030b);
    if (zb9100d187f(z51d587030b)) {
      z10369bc8f3 = z102c55b35f(zda5f474f85, z51d587030b);
      z0b6f24c9b4 = z102c55b35f(ze552f7728f, z51d587030b);
      if ((z10369bc8f3 == (0x723 + 2371 - 0x1066) ||
           z10369bc8f3 == (0xf6a + 851 - 0x12bb)) &&
          (z0b6f24c9b4 == (0x3b2 + 7443 - 0x20c5) ||
           z0b6f24c9b4 == (0x1470 + 4103 - 0x2476)))
        z7129acbdb8 += (0x2f3 + 2057 - 0xafb);
    }
  }
}
int main(void) {
  char z1900ef80be[(0xf14 + 4854 - 0x2174)] = {(0x129f + 801 - 0x15c0)};
  int zae27c4b783, zecf3ac73d2, z68ec1df1b6;
  unsigned long long int ze06cebafef, zaa8c32fedb;
  FILE *ze26bbe461e = fopen("\x43\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65"
                            "\x6d\x70\x74\x30\x2e\x69\x6e",
                            "\x72"),
       *zad515f0f03 = fopen("\x6f\x75\x74\x2e\x74\x78\x74", "\x77");
  fscanf(ze26bbe461e, "\x25\x64", &z68ec1df1b6);
  for (zecf3ac73d2 = (0x3b7 + 2624 - 0xdf7); zecf3ac73d2 < z68ec1df1b6;
       zecf3ac73d2++) {
    fscanf(ze26bbe461e, "\x25\x6c\x6c\x75\x25\x6c\x6c\x75", &ze06cebafef,
           &zaa8c32fedb);
    z10f1b46b62(zda5f474f85, ze06cebafef);
    z10f1b46b62(ze552f7728f, zaa8c32fedb);
    z7129acbdb8 = (0x663 + 5477 - 0x1bc8);
    for (zae27c4b783 = ceil(z9967cd07b9(zda5f474f85) / 2.0);
         zae27c4b783 <= ceil(z9967cd07b9(ze552f7728f) / 2.0); zae27c4b783++) {
      z10f1b46b62(z1900ef80be, (0x186f + 1368 - 0x1dc7));
      zf42f653413(z1900ef80be, zae27c4b783, (0x12d5 + 3353 - 0x1fee));
    }
    fprintf(zad515f0f03,
            "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x6c\x6c\x75"
            "\n",
            zecf3ac73d2 + (0x24af + 309 - 0x25e3), z7129acbdb8);
  }
  fclose(ze26bbe461e);
  fclose(zad515f0f03);
  return (0x1276 + 5031 - 0x261d);
}
