
#include <stdio.h>

int main() {
  int z8cd5fbd37b, zfa257cf6bb;
  scanf("\x25\x64", &z8cd5fbd37b);
  for (zfa257cf6bb = (0xad8 + 5137 - 0x1ee8); zfa257cf6bb <= z8cd5fbd37b;
       ++zfa257cf6bb) {
    char zd81937b9fd;
    int zaacadc11eb, z6659e065d8;
    int z9e8db1122d[(0x20ab + 242 - 0x2199)] = {},
                                    za9a9c8aebe[(0x39d + 592 - 0x5e9)] = {},
                                    z8ad43f5601[(0x78 + 6923 - 0x1b81)] = {};
    int z98605c5fde[(0x1785 + 2684 - 0x21fd)] = {},
                                     zaf35a110fe[(0x1254 + 2295 - 0x1b47)] = {},
                                     z2b3f97c870[(0xe77 + 3593 - 0x1c7e)] = {};
    int z9bbd0b447c[(0x879 + 4069 - 0x185a)] = {},
                                    z55991ac164[(0x9cf + 2745 - 0x1484)] = {},
                                    za5b5f81f35[(0x54f + 1301 - 0xa62)] = {};
    int z85686821ac = (0x6e9 + 92 - 0x745);
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", zfa257cf6bb);
    getchar();
    for (zaacadc11eb = (0xec6 + 5607 - 0x24ad);
         zaacadc11eb < (0x57f + 4303 - 0x164a); ++zaacadc11eb) {
      for (z6659e065d8 = (0x1a01 + 2972 - 0x259d);
           z6659e065d8 < (0x1e25 + 1519 - 0x2410); ++z6659e065d8) {
        zd81937b9fd = getchar();
        switch (zd81937b9fd) {
        case ((char)(0x142b + 4756 - 0x2691)):
          z85686821ac = (0x1cef + 1759 - 0x23cd);
          break;
        case ((char)(0x10bf + 538 - 0x1281)):
          ++z9e8db1122d[zaacadc11eb];
          ++za9a9c8aebe[z6659e065d8];
          if (zaacadc11eb == z6659e065d8)
            ++z8ad43f5601[(0x674 + 2486 - 0x102a)];
          if (zaacadc11eb + z6659e065d8 == (0x702 + 4785 - 0x19b0))
            ++z8ad43f5601[(0x14ab + 661 - 0x173f)];
          break;
        case ((char)(0x139d + 877 - 0x16bb)):
          ++z98605c5fde[zaacadc11eb];
          ++zaf35a110fe[z6659e065d8];
          if (zaacadc11eb == z6659e065d8)
            ++z2b3f97c870[(0x17b1 + 3246 - 0x245f)];
          if (zaacadc11eb + z6659e065d8 == (0x958 + 5640 - 0x1f5d))
            ++z2b3f97c870[(0x1884 + 2232 - 0x213b)];
          break;
        case ((char)(0xf73 + 3702 - 0x1d95)):
          ++z9bbd0b447c[zaacadc11eb];
          ++z55991ac164[z6659e065d8];
          if (zaacadc11eb == z6659e065d8)
            ++za5b5f81f35[(0x1a7c + 3019 - 0x2647)];
          if (zaacadc11eb + z6659e065d8 == (0xf96 + 5988 - 0x26f7))
            ++za5b5f81f35[(0x17c9 + 2963 - 0x235b)];
          break;
        }
      }
      getchar();
    }
    for (zaacadc11eb = (0x32b + 5567 - 0x18ea);
         zaacadc11eb < (0x1a46 + 1045 - 0x1e57); ++zaacadc11eb) {
      if (z9e8db1122d[zaacadc11eb] + z9bbd0b447c[zaacadc11eb] ==
          (0x1d1f + 2190 - 0x25a9)) {
        puts("\x58\x20\x77\x6f\x6e");
        break;
      }
      if (z98605c5fde[zaacadc11eb] + z9bbd0b447c[zaacadc11eb] ==
          (0x3bd + 6262 - 0x1c2f)) {
        puts("\x4f\x20\x77\x6f\x6e");
        break;
      }
      if (za9a9c8aebe[zaacadc11eb] + z55991ac164[zaacadc11eb] ==
          (0xa53 + 7290 - 0x26c9)) {
        puts("\x58\x20\x77\x6f\x6e");
        break;
      }
      if (zaf35a110fe[zaacadc11eb] + z55991ac164[zaacadc11eb] ==
          (0x1b34 + 1559 - 0x2147)) {
        puts("\x4f\x20\x77\x6f\x6e");
        break;
      }
      if (zaacadc11eb < (0x14fa + 4552 - 0x26c0)) {
        if (z8ad43f5601[zaacadc11eb] + za5b5f81f35[zaacadc11eb] ==
            (0x1814 + 496 - 0x1a00)) {
          puts("\x58\x20\x77\x6f\x6e");
          break;
        }
        if (z2b3f97c870[zaacadc11eb] + za5b5f81f35[zaacadc11eb] ==
            (0xcf5 + 2809 - 0x17ea)) {
          puts("\x4f\x20\x77\x6f\x6e");
          break;
        }
      }
    }
    if (zaacadc11eb == (0xb7b + 2918 - 0x16dd)) {
      puts(z85686821ac ? "\x47\x61\x6d\x65\x20\x68\x61\x73\x20\x6e\x6f\x74\x20"
                         "\x63\x6f\x6d\x70\x6c\x65\x74\x65\x64"
                       : "\x44\x72\x61\x77");
    }
  }
  return (0x85d + 6829 - 0x230a);
}
