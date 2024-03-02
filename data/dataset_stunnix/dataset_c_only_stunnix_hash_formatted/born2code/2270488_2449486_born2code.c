
#include <stdio.h>
#include <stdlib.h>

int z099b921535(
    int ze62347c53e[(0x9e6 + 3382 - 0x16b8)][(0xfa0 + 782 - 0x124a)],
    int zc8285d4d8e[(0xd80 + 1971 - 0x14cf)][(0x110 + 6789 - 0x1b31)],
    int zefbdfb7572, int z20a343494f) {
  int zccf79bdfc7, z2dde312459;
  for (zccf79bdfc7 = (0x73 + 2520 - 0xa4b); zccf79bdfc7 < zefbdfb7572;
       zccf79bdfc7++)
    for (z2dde312459 = (0x1a1 + 822 - 0x4d7); z2dde312459 < z20a343494f;
         z2dde312459++) {
      if (ze62347c53e[zccf79bdfc7][z2dde312459] !=
          zc8285d4d8e[zccf79bdfc7][z2dde312459])
        return (0x823 + 1721 - 0xedc);
    }
  return (0x186 + 3629 - 0xfb2);
}
int main() {
  int zcf776cb973, z5792192c33, zefbdfb7572, z20a343494f, zccf79bdfc7,
      z2dde312459, max = (0x466 + 6339 - 0x1d29), x;
  int ze62347c53e[(0x22e5 + 39 - 0x22a8)][(0x397 + 4428 - 0x147f)],
      zc8285d4d8e[(0x2460 + 45 - 0x2429)][(0x111b + 924 - 0x1453)];
  z5792192c33 = (0x821 + 892 - 0xb9c);
  for (scanf("\x25\x64", &zcf776cb973); z5792192c33 <= zcf776cb973;
       z5792192c33++) {
    scanf("\x25\x64\x25\x64", &zefbdfb7572, &z20a343494f);
    for (zccf79bdfc7 = (0x1261 + 2336 - 0x1b81); zccf79bdfc7 < zefbdfb7572;
         zccf79bdfc7++)
      for (z2dde312459 = (0xa1 + 4087 - 0x1098); z2dde312459 < z20a343494f;
           z2dde312459++) {
        scanf("\x25\x64", &ze62347c53e[zccf79bdfc7][z2dde312459]);
        if (ze62347c53e[zccf79bdfc7][z2dde312459] > max)
          max = ze62347c53e[zccf79bdfc7][z2dde312459];
      }
    for (zccf79bdfc7 = (0x2f1 + 3361 - 0x1012); zccf79bdfc7 < zefbdfb7572;
         zccf79bdfc7++)
      for (z2dde312459 = (0x16c + 9141 - 0x2521); z2dde312459 < z20a343494f;
           z2dde312459++)
        zc8285d4d8e[zccf79bdfc7][z2dde312459] = max;
    for (zccf79bdfc7 = (0xe54 + 3457 - 0x1bd5); zccf79bdfc7 < zefbdfb7572;
         zccf79bdfc7++) {
      x = ze62347c53e[zccf79bdfc7][(0x272 + 2673 - 0xce3)];
      {
        z2dde312459 = (0x732 + 6771 - 0x21a4);
        while (ze62347c53e[zccf79bdfc7][z2dde312459] == x &&
               z2dde312459 < z20a343494f) {
          z2dde312459++;
        }
        if (z2dde312459 == z20a343494f)
          for (z2dde312459 = (0xa51 + 5175 - 0x1e88); z2dde312459 < z20a343494f;
               z2dde312459++)
            zc8285d4d8e[zccf79bdfc7][z2dde312459] = x;
      }
    }
    for (z2dde312459 = (0x80c + 1965 - 0xfb9); z2dde312459 < z20a343494f;
         z2dde312459++) {
      x = ze62347c53e[(0x18b + 4532 - 0x133f)][z2dde312459];
      {
        zccf79bdfc7 = (0x2051 + 1493 - 0x2625);
        while (ze62347c53e[zccf79bdfc7][z2dde312459] == x &&
               zccf79bdfc7 < zefbdfb7572)
          zccf79bdfc7++;
        if (zccf79bdfc7 == zefbdfb7572)
          for (zccf79bdfc7 = (0x12c1 + 3824 - 0x21b1);
               zccf79bdfc7 < zefbdfb7572; zccf79bdfc7++)
            zc8285d4d8e[zccf79bdfc7][z2dde312459] = x;
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", z5792192c33);
    if (z099b921535(ze62347c53e, zc8285d4d8e, zefbdfb7572, z20a343494f)) {
      printf("\x59\x45\x53"
             "\n");
    } else
      printf("\x4e\x4f"
             "\n");
  }
  return (0x40 + 6714 - 0x1a7a);
}
