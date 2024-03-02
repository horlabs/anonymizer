
#include <stdio.h>

void z2e2157f95d(int *z820136789a) {
  int z4a9527626f, z4087f6635a;
  int zd6cc886597, z989d2d4f2e;
  scanf("\x25\x64", &zd6cc886597);
  zd6cc886597--;
  for (z4a9527626f = (0x1202 + 1183 - 0x16a1);
       z4a9527626f < (0x1ec2 + 162 - 0x1f60); z4a9527626f++)
    for (z4087f6635a = (0x493 + 4122 - 0x14ad);
         z4087f6635a < (0x10ef + 5148 - 0x2507); z4087f6635a++) {
      scanf("\x25\x64", &z989d2d4f2e);
      if (zd6cc886597 == z4a9527626f)
        z820136789a[z989d2d4f2e]++;
    }
}
int main() {
  int z1e03557793, z1f0345c781;
  scanf("\x25\x64", &z1f0345c781);
  for (z1e03557793 = (0x5b0 + 820 - 0x8e3); z1e03557793 <= z1f0345c781;
       z1e03557793++) {
    int z820136789a[(0x137f + 4197 - 0x23d3)] = {(0x98b + 3282 - 0x165d)};
    z2e2157f95d(z820136789a);
    z2e2157f95d(z820136789a);
    int z4a9527626f, zd6cc886597, zcce5de061b = (0x1622 + 1886 - 0x1d80);
    for (z4a9527626f = (0xb75 + 3944 - 0x1adc);
         z4a9527626f <= (0x13b5 + 1947 - 0x1b40); z4a9527626f++)
      if (z820136789a[z4a9527626f] == (0xcbc + 1682 - 0x134c)) {
        zd6cc886597 = z4a9527626f;
        zcce5de061b++;
      }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", z1e03557793);
    if (zcce5de061b == (0xc3b + 5877 - 0x2330))
      printf("\x56\x6f\x6c\x75\x6e\x74\x65\x65\x72\x20\x63\x68\x65\x61\x74\x65"
             "\x64\x21");
    if (zcce5de061b == (0x5a1 + 6785 - 0x2021))
      printf("\x25\x64", zd6cc886597);
    if (zcce5de061b > (0x11f + 8576 - 0x229e))
      printf("\x42\x61\x64\x20\x6d\x61\x67\x69\x63\x69\x61\x6e\x21");
    printf("\n");
  }
  return (0x121b + 1183 - 0x16ba);
}
