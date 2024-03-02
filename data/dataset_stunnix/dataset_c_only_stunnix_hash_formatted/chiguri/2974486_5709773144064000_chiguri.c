
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long double z8e9b039acb[100000];
double z23de4a3912, f, x;
int main(void) {
  int ze3aad85872;
  int z17579a5a89;
  int z0ecb7a288f;
  int z714b01b06f;
  scanf("\x25\x64", &ze3aad85872);
  for (z17579a5a89 = (0x1a9b + 2707 - 0x252d); z17579a5a89 <= ze3aad85872;
       ++z17579a5a89) {
    double z9377bb9dfe = 2.0;
    double z2195fe54ac;
    scanf("\x25\x6c\x66\x20\x25\x6c\x66\x20\x25\x6c\x66", &z23de4a3912, &f, &x);
    z8e9b039acb[(0x98f + 109 - 0x9fc)] = 0.0;
    z2195fe54ac = x / (0x1034 + 1719 - 0x16e9);
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", z17579a5a89);
    for (z714b01b06f = (0xeff + 1834 - 0x1628); z714b01b06f < 100000;
         ++z714b01b06f) {
      double ze4a2e65232;
      z8e9b039acb[z714b01b06f] =
          z23de4a3912 / z9377bb9dfe +
          z8e9b039acb[z714b01b06f - (0xa39 + 5853 - 0x2115)];
      if (z8e9b039acb[z714b01b06f] > z2195fe54ac) {
        break;
      }
      z9377bb9dfe = 2.0 + f * z714b01b06f;
      ze4a2e65232 = z8e9b039acb[z714b01b06f] + x / z9377bb9dfe;
      if (ze4a2e65232 < z2195fe54ac)
        z2195fe54ac = ze4a2e65232;
    }
    printf("\x25\x6c\x6c\x66"
           "\n",
           z2195fe54ac);
  }
  return (0x1731 + 2411 - 0x209c);
}
