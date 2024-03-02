
#include <stdio.h>

int main() {
  int z968a6b3441, z28e127b80c;
  scanf("\x25\x64", &z968a6b3441);
  for (z28e127b80c = (0x1211 + 176 - 0x12c0); z28e127b80c <= z968a6b3441;
       ++z28e127b80c) {
    double z18974dcb3c, f, x, za1f1991d7a = 2.0, z566b0e8b05 = 0.0;
    scanf("\x25\x6c\x66\x25\x6c\x66\x25\x6c\x66", &z18974dcb3c, &f, &x);
    while ((0xab4 + 3542 - 0x1889)) {
      if (x / za1f1991d7a <= z18974dcb3c / za1f1991d7a + x / (za1f1991d7a + f))
        break;
      else
        z566b0e8b05 += z18974dcb3c / za1f1991d7a, za1f1991d7a += f;
    }
    z566b0e8b05 += x / za1f1991d7a;
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x2e\x37\x66"
           "\n",
           z28e127b80c, z566b0e8b05);
  }
  return (0x9ac + 6600 - 0x2374);
}
