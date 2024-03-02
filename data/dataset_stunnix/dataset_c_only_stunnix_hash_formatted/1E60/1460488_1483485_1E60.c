
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char z9026ec99fe[(0x1a51 + 2761 - 0x24b6) * (0x1237 + 1167 - 0x16c1)];
  int zea30ab0cab[(0x3f + 936 - 0x3cd)] = {
      (0x890 + 754 - 0xb6a),    (0x657 + 7813 - 0x24d5),
      (0x1e97 + 1994 - 0x265d), (0x678 + 3436 - 0x13d2),
      (0x59b + 4720 - 0x17fd),  (0x8c8 + 3249 - 0x1577),
      (0x24da + 488 - 0x26ad),  (0xd96 + 2840 - 0x1897),
      (0x122c + 2713 - 0x1cc2), (0x959 + 3411 - 0x1698),
      (0x1950 + 2386 - 0x229a), (0x1131 + 3606 - 0x1f41),
      (0x2ab + 3567 - 0x108f),  (0x2323 + 497 - 0x2513),
      (0x1516 + 858 - 0x1866),  (0xd22 + 5376 - 0x2211),
      (0x119 + 2108 - 0x93c),   (0x1979 + 1659 - 0x1fe1),
      (0x5c4 + 4799 - 0x1876),  (0x83c + 7108 - 0x23ea),
      (0x647 + 104 - 0x6a6),    (0xf52 + 3700 - 0x1db7),
      (0xd1d + 828 - 0x1054),   (0x1ad1 + 726 - 0x1d9b),
      (0x6bb + 6836 - 0x216f),  (0xc67 + 1794 - 0x1359),
  };
  int zb22bd3994e;
  int z275dab1542;
  scanf("\x25\x64"
        "\n",
        &zb22bd3994e);
  for (z275dab1542 = (0xf9d + 3812 - 0x1e80); z275dab1542 <= zb22bd3994e;
       z275dab1542++) {
    memset(z9026ec99fe, (0x10aa + 2423 - 0x1a21), sizeof(z9026ec99fe));
    scanf("\x25\x5b\x61\x2d\x7a\x20\x5d"
          "\n",
          z9026ec99fe);
    int z99b1ac16f7 = (0x282 + 964 - 0x646);
    while (z9026ec99fe[z99b1ac16f7] != '\0') {
      if (z9026ec99fe[z99b1ac16f7] != ((char)(0x1d1 + 1215 - 0x670))) {
        z9026ec99fe[z99b1ac16f7] = ((char)(0x1543 + 4319 - 0x25c1)) +
                                   zea30ab0cab[z9026ec99fe[z99b1ac16f7] -
                                               ((char)(0x245d + 183 - 0x24b3))];
      }
      z99b1ac16f7++;
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
           "\n",
           z275dab1542, z9026ec99fe);
  }
  return (0x1dc8 + 634 - 0x2042);
}
