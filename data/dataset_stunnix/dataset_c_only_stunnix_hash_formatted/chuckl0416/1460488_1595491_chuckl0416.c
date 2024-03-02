
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void z59d0501a4c(int z62456e1769[], int zd3a87eb967, int zd76302e915,
                 int z7e0e8f35b9) {
  int z48ee3e64c9 = zd76302e915 - zd3a87eb967 + (0x14a + 3584 - 0xf49);
  int z5d18b7cc5a = z7e0e8f35b9 - zd76302e915;
  int z6d8dd2c44e[z48ee3e64c9 + (0xd79 + 1251 - 0x125b)],
      z902c470969[z5d18b7cc5a + (0x47 + 3354 - 0xd60)];
  int za5d93e7bcc, z5709a5ddff, z61e2a92ab9;
  for (za5d93e7bcc = (0x14a3 + 2609 - 0x1ed4); za5d93e7bcc < z48ee3e64c9;
       za5d93e7bcc++)
    z6d8dd2c44e[za5d93e7bcc] = z62456e1769[zd3a87eb967 + za5d93e7bcc];
  for (z5709a5ddff = (0x391 + 8027 - 0x22ec); z5709a5ddff < z5d18b7cc5a;
       z5709a5ddff++)
    z902c470969[z5709a5ddff] =
        z62456e1769[zd76302e915 + z5709a5ddff + (0x295 + 5314 - 0x1756)];
  za5d93e7bcc = (0x1b30 + 832 - 0x1e70);
  z5709a5ddff = (0xbaa + 6769 - 0x261b);
  for (z61e2a92ab9 = zd3a87eb967; z61e2a92ab9 <= z7e0e8f35b9; z61e2a92ab9++) {
    if (za5d93e7bcc < z48ee3e64c9 && z5709a5ddff < z5d18b7cc5a) {
      if (z6d8dd2c44e[za5d93e7bcc] <= z902c470969[z5709a5ddff]) {
        z62456e1769[z61e2a92ab9] = z6d8dd2c44e[za5d93e7bcc];
        za5d93e7bcc++;
      } else {
        z62456e1769[z61e2a92ab9] = z902c470969[z5709a5ddff];
        z5709a5ddff++;
      }
    } else if (za5d93e7bcc < z48ee3e64c9) {
      z62456e1769[z61e2a92ab9] = z6d8dd2c44e[za5d93e7bcc];
      za5d93e7bcc++;
    } else {
      z62456e1769[z61e2a92ab9] = z902c470969[z5709a5ddff];
      z5709a5ddff++;
    }
  }
}
void zd178b5c049(int z62456e1769[], int zd3a87eb967, int z7e0e8f35b9) {
  if (zd3a87eb967 < z7e0e8f35b9) {
    int zd76302e915 = (zd3a87eb967 + z7e0e8f35b9) / (0x10e9 + 1024 - 0x14e7);
    zd178b5c049(z62456e1769, zd3a87eb967, zd76302e915);
    zd178b5c049(z62456e1769, zd76302e915 + (0x405 + 658 - 0x696), z7e0e8f35b9);
    z59d0501a4c(z62456e1769, zd3a87eb967, zd76302e915, z7e0e8f35b9);
  }
}
int main() {
  FILE *z85879531f1, *z4cbe04a836;
  z85879531f1 = freopen("\x42\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d"
                        "\x70\x74\x30\x2e\x69\x6e",
                        "\x72", stdin);
  z4cbe04a836 = freopen("\x42\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d"
                        "\x70\x74\x30\x2e\x6f\x75\x74",
                        "\x77", stdout);
  int zc69532bcbd, zc22a816e6f, za5d93e7bcc;
  scanf("\x25\x64", &zc69532bcbd);
  int z47ab619eb4, za164049950, zb46fa68812, zd4c176b554, zcb2edf2763[100000],
      z7bc3de5515;
  for (zc22a816e6f = (0x522 + 458 - 0x6eb); zc22a816e6f <= zc69532bcbd;
       zc22a816e6f++) {
    zd4c176b554 = (0x1470 + 2005 - 0x1c45);
    scanf("\x25\x64\x25\x64\x25\x64", &z47ab619eb4, &za164049950, &zb46fa68812);
    for (za5d93e7bcc = (0x3c + 7592 - 0x1de4); za5d93e7bcc < z47ab619eb4;
         za5d93e7bcc++)
      scanf("\x25\x64", &zcb2edf2763[za5d93e7bcc]);
    zd178b5c049(zcb2edf2763, (0xa33 + 3288 - 0x170b),
                z47ab619eb4 - (0x10ff + 1401 - 0x1677));
    for (za5d93e7bcc = z47ab619eb4 - (0x124f + 3704 - 0x20c6);
         za5d93e7bcc >= (0x12e9 + 1679 - 0x1978); za5d93e7bcc--) {
      if (zcb2edf2763[za5d93e7bcc] == (0x1c03 + 987 - 0x1fde)) {
        if (zb46fa68812 == (0x4fb + 3242 - 0x11a5))
          zd4c176b554++;
        continue;
      }
      if ((zcb2edf2763[za5d93e7bcc] % (0xac + 1131 - 0x514)) ==
          (0x137a + 3003 - 0x1f35)) {
        z7bc3de5515 = zcb2edf2763[za5d93e7bcc] / (0x13f3 + 1702 - 0x1a96);
        if (z7bc3de5515 >= zb46fa68812) {
          zd4c176b554++;
        } else if (za164049950) {
          z7bc3de5515++;
          if (z7bc3de5515 >= zb46fa68812) {
            zd4c176b554++;
            za164049950--;
          }
        }
        continue;
      }
      if ((zcb2edf2763[za5d93e7bcc] % (0xd65 + 5183 - 0x21a1)) ==
          (0x7a6 + 4133 - 0x17ca)) {
        z7bc3de5515 = (zcb2edf2763[za5d93e7bcc] + (0x703 + 6901 - 0x21f6)) /
                      (0x1e11 + 68 - 0x1e52);
        if (z7bc3de5515 >= zb46fa68812)
          zd4c176b554++;
        continue;
      }
      if ((zcb2edf2763[za5d93e7bcc] % (0x17f8 + 1395 - 0x1d68)) ==
          (0x51c + 6570 - 0x1ec4)) {
        z7bc3de5515 = (zcb2edf2763[za5d93e7bcc] + (0x1468 + 790 - 0x177d)) /
                      (0xa05 + 250 - 0xafc);
        if (z7bc3de5515 >= zb46fa68812) {
          zd4c176b554++;
        } else if (za164049950) {
          z7bc3de5515++;
          if (z7bc3de5515 >= zb46fa68812) {
            zd4c176b554++;
            za164049950--;
          }
        }
        continue;
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           zc22a816e6f, zd4c176b554);
  }
  fclose(z85879531f1);
  fclose(z4cbe04a836);
  return (0x105a + 5280 - 0x24fa);
}
