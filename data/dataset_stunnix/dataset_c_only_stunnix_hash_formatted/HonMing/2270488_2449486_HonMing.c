
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int z617a63ce66, z512576dfef;
  int za9c8d70949, zb107e9ea3f, z53232675c4;
  int z018041f6ba;
  int z8edd0f742a;
  int zf179b507d4, z687a6b8c6c, z8aea228b74;
  int zeb3fefa1fc, za711a85b87;
  int max;
  int zdc6ee9b515[(0x187a + 946 - 0x1b64)][(0x1117 + 3088 - 0x1c5f)];
  int z123835e7dd[(0x3fb + 6482 - 0x1c85)][(0x4c3 + 2110 - 0xc39)];
  unsigned long long z8aa1925396;
  scanf("\x25\x64", &z8edd0f742a);
  for (za9c8d70949 = (0xfad + 2003 - 0x177f); za9c8d70949 <= z8edd0f742a;
       za9c8d70949++) {
    memset(z123835e7dd, (0x694 + 7760 - 0x24e4),
           (0x392 + 2433 - 0xc4b) * (0x241b + 831 - 0x2692));
    scanf("\x25\x64\x25\x64", &zeb3fefa1fc, &za711a85b87);
    for (z617a63ce66 = (0xa62 + 4530 - 0x1c14); z617a63ce66 < zeb3fefa1fc;
         z617a63ce66++) {
      for (z512576dfef = (0x1d24 + 1354 - 0x226e); z512576dfef < za711a85b87;
           z512576dfef++) {
        scanf("\x25\x64", &zdc6ee9b515[z617a63ce66][z512576dfef]);
        z123835e7dd[z617a63ce66][z512576dfef] = (0x319 + 146 - 0x2e3);
      }
    }
    for (z617a63ce66 = (0x87f + 2161 - 0x10f0); z617a63ce66 < zeb3fefa1fc;
         z617a63ce66++) {
      max = (0x1eab + 1083 - 0x22e6);
      for (z512576dfef = (0x73d + 6148 - 0x1f41); z512576dfef < za711a85b87;
           z512576dfef++) {
        if (zdc6ee9b515[z617a63ce66][z512576dfef] > max)
          max = zdc6ee9b515[z617a63ce66][z512576dfef];
      }
      for (z512576dfef = (0xfed + 2792 - 0x1ad5); z512576dfef < za711a85b87;
           z512576dfef++) {
        if (max < z123835e7dd[z617a63ce66][z512576dfef])
          z123835e7dd[z617a63ce66][z512576dfef] = max;
      }
    }
    for (z617a63ce66 = (0x11f5 + 17 - 0x1206); z617a63ce66 < za711a85b87;
         z617a63ce66++) {
      max = (0x5a6 + 5117 - 0x19a3);
      for (z512576dfef = (0x3b + 2758 - 0xb01); z512576dfef < zeb3fefa1fc;
           z512576dfef++) {
        if (zdc6ee9b515[z512576dfef][z617a63ce66] > max)
          max = zdc6ee9b515[z512576dfef][z617a63ce66];
      }
      for (z512576dfef = (0xc59 + 4629 - 0x1e6e); z512576dfef < zeb3fefa1fc;
           z512576dfef++) {
        if (max < z123835e7dd[z512576dfef][z617a63ce66])
          z123835e7dd[z512576dfef][z617a63ce66] = max;
      }
    }
    for (z617a63ce66 = (0x1e6 + 7814 - 0x206c); z617a63ce66 < zeb3fefa1fc;
         z617a63ce66++) {
      for (z512576dfef = (0x1a0a + 2815 - 0x2509); z512576dfef < za711a85b87;
           z512576dfef++)
        if (z123835e7dd[z617a63ce66][z512576dfef] !=
            zdc6ee9b515[z617a63ce66][z512576dfef])
          break;
      if (z512576dfef != za711a85b87)
        break;
    }
    if (z617a63ce66 != zeb3fefa1fc)
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x4e\x4f"
             "\n",
             za9c8d70949);
    else
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x59\x45\x53"
             "\n",
             za9c8d70949);
  }
}
