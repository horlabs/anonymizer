
#include <stdio.h>
#include <string.h>

int x[2000010];
int main() {
  int zabff863ebf, zdb3b99a4ea, z060892d318, z997307b5f6, z0fb15d26d5,
      zf34ec1a207, flag, z96f8523b28, z31eb6b4055, z0247453738, z8799fd5f8c;
  freopen("\x43\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x69\x6e",
          "\x72", stdin);
  freopen("\x43\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x6f\x75\x74",
          "\x77", stdout);
  scanf("\x25\x64", &zdb3b99a4ea);
  for (zabff863ebf = (0x58c + 1751 - 0xc62); zabff863ebf <= zdb3b99a4ea;
       zabff863ebf++) {
    scanf("\x25\x64\x25\x64", &z060892d318, &z997307b5f6);
    memset(x, (0x23b6 + 398 - 0x2544), sizeof(x));
    z8799fd5f8c = (0xdcc + 5 - 0xdd1);
    z96f8523b28 = (0x1939 + 1705 - 0x1fe1);
    for (z0fb15d26d5 = (0x11cf + 4086 - 0x21c4);
         z0fb15d26d5 < (0x115 + 6225 - 0x195c); z0fb15d26d5++) {
      z96f8523b28 *= (0x12cc + 838 - 0x1608);
      if (z060892d318 / z96f8523b28 == (0x22fa + 1002 - 0x26e4))
        break;
    }
    z96f8523b28 /= (0x1a5c + 169 - 0x1afb);
    flag = z0fb15d26d5;
    for (z0fb15d26d5 = z060892d318; z0fb15d26d5 <= z997307b5f6; z0fb15d26d5++) {
      int zb9c8e70cc7 = (0x1881 + 2999 - 0x2437);
      z31eb6b4055 = z0fb15d26d5;
      x[z31eb6b4055] = (0x1508 + 2721 - 0x1fa8);
      for (zf34ec1a207 = (0x61 + 9234 - 0x2473); zf34ec1a207 < flag;
           zf34ec1a207++) {
        z0247453738 = z96f8523b28 * (z31eb6b4055 % (0xa1b + 1509 - 0xff6)) +
                      z31eb6b4055 / (0x4ff + 4769 - 0x1796);
        if (z0247453738 == z31eb6b4055) {
          break;
        }
        if (z0247453738 <= z997307b5f6 && z0247453738 >= z060892d318) {
          if (!x[z0247453738]) {
            zb9c8e70cc7++;
          }
          x[z0247453738] = (0x3a2 + 8537 - 0x24fa);
        }
        z31eb6b4055 = z0247453738;
      }
      z8799fd5f8c += (zb9c8e70cc7 - (0x2da + 5488 - 0x1849)) * zb9c8e70cc7 /
                     (0xe4d + 3599 - 0x1c5a);
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           zabff863ebf, z8799fd5f8c);
  }
  return (0x1c6 + 7854 - 0x2074);
}
