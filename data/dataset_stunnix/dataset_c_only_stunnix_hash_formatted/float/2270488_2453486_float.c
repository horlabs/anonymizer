
#include <stdio.h>
#include <string.h>

int z7570afa418(char z525b5d3ded) {
  switch (z525b5d3ded) {
  case ((char)(0x3b8 + 2916 - 0xec4)):
    return (0x8ff + 3947 - 0x186a);
    break;
  case ((char)(0xf65 + 978 - 0x12e8)):
    return (0xb87 + 6984 - 0x26ce);
    break;
  case ((char)(0x2bf + 5095 - 0x1652)):
    return (0xa26 + 5904 - 0x2134);
    break;
  case ((char)(0x22f7 + 224 - 0x23a9)):
    return -(0x101 + 4296 - 0x11c8);
    break;
  }
  return -(0x63d + 3444 - 0x13b0);
}
int main() {
  int z30510129d1, z0513254e63, z456f9a75c7, zfa4f59ac22, index, z45101c7037,
      z56c9204878, flag;
  int z616e02e830[(0x154b + 3623 - 0x2368)][(0x2269 + 497 - 0x2457)];
  char z20bc05b07b[(0x1b58 + 1087 - 0x1f92)][(0x826 + 7267 - 0x2484)],
      z525b5d3ded;
  scanf("\x25\x64", &z30510129d1);
  getc(stdin);
  for (z0513254e63 = (0x349 + 4933 - 0x168d); z0513254e63 <= z30510129d1;
       z0513254e63++) {
    flag = (0x67d + 8023 - 0x25d4);
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", z0513254e63);
    if (z0513254e63 > (0x1bdf + 342 - 0x1d34))
      getc(stdin);
    for (z456f9a75c7 = (0x1f2 + 4735 - 0x1471);
         z456f9a75c7 < (0x1b0d + 2207 - 0x23a8); z456f9a75c7++) {
      fgets(z20bc05b07b[z456f9a75c7],
            sizeof(z20bc05b07b[(0x77f + 3771 - 0x163a)]), stdin);
      getc(stdin);
    }
    memset(z616e02e830, (0xdd2 + 6347 - 0x269d), sizeof(z616e02e830));
    for (index = (0xc81 + 3331 - 0x1984); index < (0x2fd + 3820 - 0x11e5);
         index++) {
      for (z45101c7037 = (0x8cc + 2295 - 0x11c3);
           z45101c7037 < (0x2423 + 506 - 0x2619); z45101c7037++) {
        z56c9204878 = z7570afa418(z20bc05b07b[index][z45101c7037]);
        if (z56c9204878 >= (0xd56 + 3644 - 0x1b92))
          z616e02e830[index][z56c9204878]++;
        z56c9204878 = z7570afa418(z20bc05b07b[z45101c7037][index]);
        if (z56c9204878 >= (0x8d + 7547 - 0x1e08))
          z616e02e830[(0x1c72 + 2515 - 0x2641) + index][z56c9204878]++;
      }
      z56c9204878 = z7570afa418(z20bc05b07b[index][index]);
      if (z56c9204878 >= (0x16ac + 1562 - 0x1cc6))
        z616e02e830[(0xedb + 4634 - 0x20ed)][z56c9204878]++;
      z56c9204878 =
          z7570afa418(z20bc05b07b[index][(0x86a + 5521 - 0x1df8) - index]);
      if (z56c9204878 >= (0x17c4 + 2616 - 0x21fc))
        z616e02e830[(0xe6 + 4436 - 0x1231)][z56c9204878]++;
    }
    for (z45101c7037 = (0x8ed + 6243 - 0x2150);
         z45101c7037 < (0x1120 + 3496 - 0x1ebe); z45101c7037++) {
      if (z616e02e830[z45101c7037][(0x1488 + 2533 - 0x1e6d)] +
              z616e02e830[z45101c7037][(0x6f3 + 8096 - 0x2691)] ==
          (0xfff + 2707 - 0x1a8e)) {
        puts("\x58\x20\x77\x6f\x6e");
        flag = (0xcf8 + 5653 - 0x230c);
        break;
      } else if (z616e02e830[z45101c7037][(0x21a0 + 950 - 0x2555)] +
                     z616e02e830[z45101c7037][(0x5c5 + 1833 - 0xcec)] ==
                 (0xaf6 + 3235 - 0x1795)) {
        puts("\x4f\x20\x77\x6f\x6e");
        flag = (0x670 + 4268 - 0x171b);
        break;
      }
    }
    if (flag)
      continue;
    for (z456f9a75c7 = (0x101f + 4116 - 0x2033);
         z456f9a75c7 < (0x11ef + 1006 - 0x15d9) &&
         flag == (0x2eb + 3897 - 0x1224);
         z456f9a75c7++) {
      for (zfa4f59ac22 = (0x478 + 6575 - 0x1e27);
           zfa4f59ac22 < (0x949 + 5618 - 0x1f37); zfa4f59ac22++) {
        if (z20bc05b07b[z456f9a75c7][zfa4f59ac22] ==
            ((char)(0x1bd5 + 889 - 0x1f20))) {
          puts("\x47\x61\x6d\x65\x20\x68\x61\x73\x20\x6e\x6f\x74\x20\x63\x6f"
               "\x6d\x70\x6c\x65\x74\x65\x64");
          flag = (0x139 + 654 - 0x3c6);
          break;
        }
      }
    }
    if (flag)
      continue;
    else
      puts("\x44\x72\x61\x77");
  }
  return (0x3bf + 5995 - 0x1b2a);
}
