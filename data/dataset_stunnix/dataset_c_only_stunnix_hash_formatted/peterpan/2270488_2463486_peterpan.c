
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

char z109646cfbe[(0x74a + 4256 - 0x17d6)];
int z30573dca4c(int z97b1046717) {
  int zf9ae035a04, z37afcd82c0;
  zf9ae035a04 = (0x229a + 905 - 0x2623);
  while (z97b1046717) {
    z109646cfbe[zf9ae035a04++] = z97b1046717 % (0x18c8 + 104 - 0x1926);
    z97b1046717 /= (0x11af + 100 - 0x1209);
  }
  zf9ae035a04--;
  for (z37afcd82c0 = (0x10f7 + 31 - 0x1116); z37afcd82c0 < zf9ae035a04;
       z37afcd82c0++, zf9ae035a04--)
    if (z109646cfbe[z37afcd82c0] != z109646cfbe[zf9ae035a04])
      return (0x5f4 + 1998 - 0xdc2);
  return (0x538 + 590 - 0x785);
}
int z9f8dea83b9(long long z97b1046717) {
  int zf9ae035a04, z37afcd82c0;
  zf9ae035a04 = (0x5d0 + 795 - 0x8eb);
  while (z97b1046717) {
    z109646cfbe[zf9ae035a04++] = z97b1046717 % (0x1b81 + 250 - 0x1c71);
    z97b1046717 /= (0x1acc + 753 - 0x1db3);
  }
  zf9ae035a04--;
  for (z37afcd82c0 = (0x178 + 2008 - 0x950); z37afcd82c0 < zf9ae035a04;
       z37afcd82c0++, zf9ae035a04--)
    if (z109646cfbe[z37afcd82c0] != z109646cfbe[zf9ae035a04])
      return (0x76 + 4098 - 0x1078);
  return (0x918 + 4765 - 0x1bb4);
}
int main() {
  long long zae8be11281, zf7ad62ffb0;
  int z7e394cf82f, zee990db848, *z669a419355;
  int z8a98aac48d, z2aafdd976b, zf9ae035a04;
  z669a419355 = malloc(10000001 * sizeof(int));
  {
    if (!(z669a419355 != NULL)) {
      fprintf(stderr,
              "\x25\x73"
              "\n",
              "\x4f\x75\x74\x20\x6f\x66\x20\x6d\x65\x6d\x6f\x72\x79\x21");
      exit(-(0x1753 + 2503 - 0x2119));
    }
  };
  z669a419355[(0x696 + 1119 - 0xaf5)] = (0x1a56 + 2399 - 0x23b4);
  for (zf9ae035a04 = (0x4d8 + 2084 - 0xcfb); zf9ae035a04 <= 10000000;
       zf9ae035a04++)
    if (z30573dca4c(zf9ae035a04) &&
        z9f8dea83b9(((long long)zf9ae035a04) * zf9ae035a04))
      z669a419355[zf9ae035a04] =
          z669a419355[zf9ae035a04 - (0x449 + 6422 - 0x1d5e)] +
          (0x17e5 + 1157 - 0x1c69);
    else
      z669a419355[zf9ae035a04] =
          z669a419355[zf9ae035a04 - (0x131a + 644 - 0x159d)];
  scanf("\x25\x64", &z7e394cf82f);
  for (zee990db848 = (0xf9 + 8862 - 0x2396); zee990db848 <= z7e394cf82f;
       zee990db848++) {
    scanf("\x25\x6c\x6c\x64\x20\x25\x6c\x6c\x64", &zae8be11281, &zf7ad62ffb0);
    z8a98aac48d = ceil(sqrt((double)zae8be11281));
    z2aafdd976b = sqrt((double)zf7ad62ffb0);
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           zee990db848,
           z669a419355[z2aafdd976b] -
               z669a419355[z8a98aac48d - (0x404 + 1590 - 0xa39)]);
  }
  return (0xc06 + 1349 - 0x114b);
}
