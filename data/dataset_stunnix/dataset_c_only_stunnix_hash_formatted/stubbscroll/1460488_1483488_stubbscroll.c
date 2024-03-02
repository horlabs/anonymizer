
#include <stdio.h>
#include <string.h>

int z402945b209(int zfee2a21f3b, int za39d7f0613) {
  char za623542c56[(0x37d + 3423 - 0x10d2)],
      z8ef6a2c36a[(0xe5d + 1714 - 0x1505)];
  int z50617140d2, zfee8d5257f, zce04380474;
  sprintf(za623542c56, "\x25\x64", zfee2a21f3b);
  sprintf(z8ef6a2c36a, "\x25\x64", za39d7f0613);
  if (strlen(za623542c56) != strlen(z8ef6a2c36a))
    return (0x7aa + 6067 - 0x1f5d);
  zfee8d5257f = strlen(za623542c56);
  for (z50617140d2 = (0x311 + 6133 - 0x1b05); za623542c56[z50617140d2];
       z50617140d2++) {
    for (zce04380474 = (0xc3a + 5789 - 0x22d7); za623542c56[zce04380474];
         zce04380474++)
      if (za623542c56[zce04380474] !=
          z8ef6a2c36a[(z50617140d2 + zce04380474) % zfee8d5257f])
        goto z63e1b89d41;
    return (0x530 + 6352 - 0x1dff);
  z63e1b89d41:;
  }
  return (0xfc + 246 - 0x1f2);
}
int main() {
  int z1a74b48315, zd76c28e4a6 = (0x8e7 + 7409 - 0x25d7), zfee2a21f3b,
                   za39d7f0613, z50617140d2, zce04380474, z6557bd4039;
  scanf("\x25\x64", &z1a74b48315);
  while (z1a74b48315--) {
    scanf("\x25\x64\x20\x25\x64", &zfee2a21f3b, &za39d7f0613);
    for (z6557bd4039 = (0x4cc + 1773 - 0xbb9), z50617140d2 = zfee2a21f3b;
         z50617140d2 <= za39d7f0613; z50617140d2++)
      for (zce04380474 = z50617140d2 + (0x179c + 3715 - 0x261e);
           zce04380474 <= za39d7f0613; zce04380474++)
        if (z402945b209(z50617140d2, zce04380474))
          z6557bd4039++;
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           zd76c28e4a6++, z6557bd4039);
  }
  return (0x173b + 957 - 0x1af8);
}
