
#include <stdio.h>

double zfae3a6de8f(double z27b54f1a07, double f, double x) {
  double zd9f1ae88a2 = (0x19f1 + 3292 - 0x26cb),
         za1f98d1104 = (0x49a + 7613 - 0x2257);
  double zfa4e249789, z140923dcc6;
  while ((0x123c + 3157 - 0x1e90)) {
    zfa4e249789 = x / zd9f1ae88a2;
    z140923dcc6 = z27b54f1a07 / zd9f1ae88a2 + x / (zd9f1ae88a2 + f);
    if (z140923dcc6 > zfa4e249789) {
      za1f98d1104 += zfa4e249789;
      break;
    }
    za1f98d1104 += z27b54f1a07 / zd9f1ae88a2;
    zd9f1ae88a2 += f;
  }
  return za1f98d1104;
}
int main() {
  int z32a617776d = (0x5d9 + 2755 - 0x109b), zd451a8fad1;
  double z27b54f1a07, f, x;
  freopen("\x42\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x69\x6e",
          "\x72", stdin);
  freopen("\x42\x2d\x73\x6d\x61\x6c\x6c\x2d\x6f\x75\x74\x2e\x74\x78\x74",
          "\x77", stdout);
  scanf("\x25\x64", &zd451a8fad1);
  while (zd451a8fad1--) {
    scanf("\x25\x6c\x66\x25\x6c\x66\x25\x6c\x66", &z27b54f1a07, &f, &x);
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x2e\x37\x6c\x66"
           "\n",
           z32a617776d++, zfae3a6de8f(z27b54f1a07, f, x));
  }
  return (0x9ca + 4439 - 0x1b21);
}
