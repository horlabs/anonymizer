
#include <stdio.h>

int main() {
  int zff9be530ce, zb89d1fcb12, ze38e6a0c2d, z0211ea4317, z5961ac391c,
      z7baa1e29e3, z6a47e58786, z42fd1bd165;
  scanf("\x25\x64", &zff9be530ce);
  for (z0211ea4317 = (0x1903 + 3064 - 0x24fa); z0211ea4317 <= zff9be530ce;
       ++z0211ea4317) {
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", z0211ea4317);
    scanf("\x25\x64\x25\x64", &zb89d1fcb12, &ze38e6a0c2d);
    for (z6a47e58786 = (0xba5 + 6458 - 0x24d5); z6a47e58786 <= zb89d1fcb12;
         z6a47e58786 *= (0x1c57 + 203 - 0x1d18))
      ;
    if (z6a47e58786 == (0x1f1 + 6286 - 0x1a75)) {
      puts("\x30");
      continue;
    }
    z6a47e58786 /= (0x1afc + 1921 - 0x2273);
    z42fd1bd165 = (0x11c6 + 5315 - 0x2689);
    for (z5961ac391c = zb89d1fcb12; z5961ac391c < ze38e6a0c2d; ++z5961ac391c) {
      int z7a0d0d6bda = (0x18f2 + 2031 - 0x20e1);
      z7baa1e29e3 = z5961ac391c;
      while ((0x5ac + 234 - 0x695)) {
        z7baa1e29e3 = z7baa1e29e3 % z6a47e58786 * (0x1bb + 9084 - 0x252d) +
                      z7baa1e29e3 / z6a47e58786;
        if (z7baa1e29e3 == z5961ac391c)
          break;
        if (z7baa1e29e3 > z5961ac391c && z7baa1e29e3 <= ze38e6a0c2d)
          ++z42fd1bd165;
      }
    }
    printf("\x25\x64"
           "\n",
           z42fd1bd165);
  }
  return (0xc44 + 2055 - 0x144b);
}
