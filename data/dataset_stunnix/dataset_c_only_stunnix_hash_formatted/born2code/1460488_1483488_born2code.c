
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long int zbd529bf999(unsigned long int z142c9d4d72, int z6c157c0979) {
  unsigned long int x, zaf398628b8, za2b7773797;
  x = pow((0x2374 + 787 - 0x267d), z6c157c0979 - (0x3ad + 1003 - 0x797));
  zaf398628b8 = z142c9d4d72 % x;
  za2b7773797 = z142c9d4d72 / x;
  zaf398628b8 = zaf398628b8 * (0x103 + 6331 - 0x19b4) + za2b7773797;
  return zaf398628b8;
}
int zba18b72082(unsigned long int z142c9d4d72) {
  int z6c157c0979 = (0x4df + 7901 - 0x23bc);
  while (z142c9d4d72) {
    z6c157c0979++;
    z142c9d4d72 /= (0x241 + 1138 - 0x6a9);
  }
  return z6c157c0979;
}
int main() {
  unsigned long int zd95d10ecdb, zc610709b13, zb3bf4cf25e, za5855da15a,
      z142c9d4d72;
  unsigned long int z543499b2a0, z4c465d3cc7, z10612f7fb3, z6c157c0979,
      zaf398628b8;
  scanf("\x25\x6c\x64", &zd95d10ecdb);
  for (z543499b2a0 = (0x206 + 7098 - 0x1dbf); z543499b2a0 <= zd95d10ecdb;
       z543499b2a0++) {
    scanf("\x25\x6c\x64\x25\x6c\x64", &zc610709b13, &zb3bf4cf25e);
    z6c157c0979 = zba18b72082(zc610709b13);
    z10612f7fb3 = (0x1282 + 889 - 0x15fb);
    for (za5855da15a = zc610709b13 + (0x999 + 3708 - 0x1814);
         za5855da15a <= zb3bf4cf25e; za5855da15a++) {
      for (zaf398628b8 = zc610709b13; zaf398628b8 < za5855da15a;
           zaf398628b8++) {
        z142c9d4d72 = zbd529bf999(zaf398628b8, z6c157c0979);
        z4c465d3cc7 = (0x819 + 2912 - 0x1379);
        while (z142c9d4d72 != za5855da15a &&
               z4c465d3cc7 < z6c157c0979 - (0x22 + 1362 - 0x573)) {
          z142c9d4d72 = zbd529bf999(z142c9d4d72, z6c157c0979);
          z4c465d3cc7++;
        }
        if (z4c465d3cc7 < z6c157c0979 - (0x25 + 6024 - 0x17ac)) {
          z10612f7fb3++;
        }
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x6c\x64\x3a\x20\x25\x6c\x64"
           "\n",
           z543499b2a0, z10612f7fb3);
  }
  return (0x1d + 1504 - 0x5fd);
}
