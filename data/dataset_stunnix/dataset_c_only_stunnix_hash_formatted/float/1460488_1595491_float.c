
#include <stdio.h>
#include <stdlib.h>

int main() {
  int z6aa308389a, zbaf382a03d, z034a639399, z927caeabd6, z8cfc376ae3,
      zc503cd4609;
  int z0e382005d9, z7fb83b92f4;
  scanf("\x25\x64", &z6aa308389a);
  for (z8cfc376ae3 = (0x374 + 6610 - 0x1d45); z8cfc376ae3 <= z6aa308389a;
       z8cfc376ae3++) {
    z7fb83b92f4 = (0x969 + 2267 - 0x1244);
    scanf("\x25\x64\x20\x25\x64\x20\x25\x64", &zbaf382a03d, &z034a639399,
          &z927caeabd6);
    for (zc503cd4609 = (0xb9b + 5947 - 0x22d6); zc503cd4609 < zbaf382a03d;
         zc503cd4609++) {
      scanf("\x25\x64", &z0e382005d9);
      if (z0e382005d9 == (0x133 + 6765 - 0x1b82)) {
        z7fb83b92f4++;
        continue;
      } else if (z0e382005d9 == (0x1e2c + 2080 - 0x262f) &&
                 z927caeabd6 <= (0x62a + 7529 - 0x238a)) {
        z7fb83b92f4++;
        continue;
      } else if (z0e382005d9 == (0x55a + 2539 - 0xf45)) {
        if (z927caeabd6 == (0x2094 + 1646 - 0x2702))
          z7fb83b92f4++;
        continue;
      }
      switch (z0e382005d9 % (0x221 + 9272 - 0x2656)) {
      case (0x1b5a + 407 - 0x1cf1):
        if (z0e382005d9 / (0x1162 + 5296 - 0x260f) >= z927caeabd6)
          z7fb83b92f4++;
        else if (z0e382005d9 / (0xa6f + 4523 - 0x1c17) +
                         (0x11a8 + 1452 - 0x1753) >=
                     z927caeabd6 &&
                 z034a639399 > (0xa98 + 2724 - 0x153c)) {
          z7fb83b92f4++;
          z034a639399--;
        }
        break;
      case (0x27c + 4101 - 0x1280):
        if (z0e382005d9 / (0x13b4 + 2555 - 0x1dac) >= z927caeabd6 ||
            z0e382005d9 / (0x7c5 + 748 - 0xaae) + (0x1b5c + 2103 - 0x2392) >=
                z927caeabd6)
          z7fb83b92f4++;
        break;
      case (0x13fd + 2396 - 0x1d57):
        if (z0e382005d9 / (0xb84 + 3160 - 0x17d9) >= z927caeabd6 ||
            z0e382005d9 / (0x1f5a + 800 - 0x2277) + (0x1205 + 609 - 0x1465) >=
                z927caeabd6)
          z7fb83b92f4++;
        else if (z0e382005d9 / (0x1195 + 2579 - 0x1ba5) +
                         (0xfb3 + 2237 - 0x186e) >=
                     z927caeabd6 &&
                 z034a639399 > (0x48 + 3193 - 0xcc1)) {
          z7fb83b92f4++;
          z034a639399--;
        }
        break;
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z8cfc376ae3, z7fb83b92f4);
  }
}
