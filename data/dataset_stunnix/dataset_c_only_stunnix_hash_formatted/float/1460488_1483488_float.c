
#include <stdio.h>
#include <stdlib.h>

int z3b198eac88(int zac99da614f) {
  int x = (0xfa8 + 5672 - 0x25cf);
  while (zac99da614f / x >= (0xd98 + 5298 - 0x2240))
    x *= (0xb0c + 681 - 0xdab);
  while (zac99da614f % (0x362 + 1088 - 0x798) == (0xd28 + 4019 - 0x1cdb))
    zac99da614f = zac99da614f / (0x18ca + 2811 - 0x23bb);
  zac99da614f = zac99da614f / (0xc98 + 3660 - 0x1ada) +
                (zac99da614f % (0xa58 + 7299 - 0x26d1)) * x;
  return zac99da614f;
}
int main() {
  int zbd077cef73, z9a85ae5efb, z60e9fc6754, z0c69a6f52b, zdabdd2676f,
      zcbf472185a, zfa6d113fa0;
  scanf("\x25\x64", &zbd077cef73);
  for (z0c69a6f52b = (0x589 + 4954 - 0x18e2); z0c69a6f52b <= zbd077cef73;
       z0c69a6f52b++) {
    scanf("\x25\x64\x20\x25\x64", &z9a85ae5efb, &z60e9fc6754);
    zfa6d113fa0 = (0x22d + 411 - 0x3c8);
    for (zdabdd2676f = z9a85ae5efb; zdabdd2676f <= z60e9fc6754; zdabdd2676f++) {
      zcbf472185a = zdabdd2676f;
      do {
        zcbf472185a = z3b198eac88(zcbf472185a);
        if (zcbf472185a > zdabdd2676f && zcbf472185a >= z9a85ae5efb &&
            zcbf472185a <= z60e9fc6754)
          zfa6d113fa0++;
      } while (zcbf472185a != zdabdd2676f);
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z0c69a6f52b, zfa6d113fa0);
  }
  return (0x3b7 + 3488 - 0x1157);
}
