
#include <stdio.h>

char z03c5718b10[(0xdba + 1059 - 0x11d9)][(0x12db + 4091 - 0x22d1)];
int z4a05399214(char zeb232c95f8) {
  int z4095faf67d;
  z4095faf67d = (0x90a + 2868 - 0x143e);
  for (int z6f99a7484e = (0x436 + 7745 - 0x2277);
       z6f99a7484e < (0x916 + 952 - 0xcca); z6f99a7484e++)
    z4095faf67d += (z03c5718b10[z6f99a7484e][z6f99a7484e] == zeb232c95f8 ||
                    z03c5718b10[z6f99a7484e][z6f99a7484e] ==
                        ((char)(0xeb + 6072 - 0x184f)));
  if (z4095faf67d == (0x17e5 + 2126 - 0x202f))
    return (0x4b1 + 2668 - 0xf1c);
  z4095faf67d = (0x12a4 + 1043 - 0x16b7);
  for (int z6f99a7484e = (0x9d9 + 2321 - 0x12ea);
       z6f99a7484e < (0x440 + 8162 - 0x241e); z6f99a7484e++)
    z4095faf67d +=
        (z03c5718b10[z6f99a7484e][(0x3fb + 7242 - 0x2042) - z6f99a7484e] ==
             zeb232c95f8 ||
         z03c5718b10[z6f99a7484e][(0x7f + 7384 - 0x1d54) - z6f99a7484e] ==
             ((char)(0xc7c + 1611 - 0x1273)));
  if (z4095faf67d == (0x126b + 3981 - 0x21f4))
    return (0x5d5 + 3102 - 0x11f2);
  for (int z6f99a7484e = (0x1504 + 1399 - 0x1a7b);
       z6f99a7484e < (0x6bf + 7693 - 0x24c8); z6f99a7484e++) {
    z4095faf67d = (0x1b3 + 3750 - 0x1059);
    for (int zfcc20e7b13 = (0x609 + 1975 - 0xdc0);
         zfcc20e7b13 < (0xb63 + 3357 - 0x187c); zfcc20e7b13++)
      z4095faf67d += (z03c5718b10[z6f99a7484e][zfcc20e7b13] == zeb232c95f8 ||
                      z03c5718b10[z6f99a7484e][zfcc20e7b13] ==
                          ((char)(0x7cb + 2355 - 0x10aa)));
    if (z4095faf67d == (0x1067 + 2375 - 0x19aa))
      return (0x252 + 7929 - 0x214a);
    z4095faf67d = (0xc46 + 874 - 0xfb0);
    for (int zfcc20e7b13 = (0xdd9 + 4462 - 0x1f47);
         zfcc20e7b13 < (0x1ab8 + 3104 - 0x26d4); zfcc20e7b13++)
      z4095faf67d += (z03c5718b10[zfcc20e7b13][z6f99a7484e] == zeb232c95f8 ||
                      z03c5718b10[zfcc20e7b13][z6f99a7484e] ==
                          ((char)(0x553 + 2722 - 0xfa1)));
    if (z4095faf67d == (0x10d6 + 2087 - 0x18f9))
      return (0xee9 + 1959 - 0x168f);
  }
  return (0x5e9 + 2790 - 0x10cf);
}
int main() {
  int zcdd6634c3a;
  scanf("\x25\x64", &zcdd6634c3a);
  for (int ze76267726e = (0x79 + 5434 - 0x15b2); ze76267726e <= zcdd6634c3a;
       ze76267726e++) {
    for (int z6f99a7484e = (0x7bd + 7254 - 0x2413);
         z6f99a7484e < (0x1183 + 1466 - 0x1739); z6f99a7484e++)
      scanf("\x25\x73", &z03c5718b10[z6f99a7484e]);
    const char *z7705c7b862 = "\x44\x72\x61\x77";
    if (z4a05399214(((char)(0x576 + 7834 - 0x23b8))))
      z7705c7b862 = "\x58\x20\x77\x6f\x6e";
    else if (z4a05399214(((char)(0x12b + 2100 - 0x910))))
      z7705c7b862 = "\x4f\x20\x77\x6f\x6e";
    else {
      int z4095faf67d = (0x489 + 2607 - 0xeb8);
      for (int z6f99a7484e = (0x482 + 4941 - 0x17cf);
           z6f99a7484e < (0x24b8 + 279 - 0x25cb); z6f99a7484e++)
        for (int zfcc20e7b13 = (0x32a + 5830 - 0x19f0);
             zfcc20e7b13 < (0x1b69 + 2772 - 0x2639); zfcc20e7b13++)
          if (z03c5718b10[z6f99a7484e][zfcc20e7b13] ==
              ((char)(0x1703 + 3499 - 0x2480)))
            z4095faf67d++;
      if (z4095faf67d > (0x382 + 1662 - 0xa00))
        z7705c7b862 = "\x47\x61\x6d\x65\x20\x68\x61\x73\x20\x6e\x6f\x74\x20\x63"
                      "\x6f\x6d\x70\x6c\x65\x74\x65\x64";
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
           "\n",
           ze76267726e, z7705c7b862);
  }
}
