
#include <math.h>
#include <stdio.h>
#include <string.h>

int z0c33aba876[10000001];
void z19e0b34c92() {
  int zffddaa500b[(0x159c + 1813 - 0x1c9d)], z28ed3c8eb1, flag;
  long long zf89081b705;
  freopen("\x43\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x69\x6e\x2e\x74\x78\x74",
          "\x72", stdin);
  freopen("\x43\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x6f\x75\x74\x2e\x74\x78\x74",
          "\x77", stdout);
  memset(z0c33aba876, (0x963 + 3223 - 0x15fa), sizeof(z0c33aba876));
  for (int z707e79ea35 = (0x336 + 6122 - 0x1b20); z707e79ea35 < 10000001;
       z707e79ea35++) {
    zf89081b705 = z707e79ea35 * z707e79ea35;
    z28ed3c8eb1 = (0x177 + 5191 - 0x15be);
    while (zf89081b705 != (0x968 + 7195 - 0x2583)) {
      zffddaa500b[z28ed3c8eb1] = zf89081b705 % (0x1108 + 394 - 0x1288);
      zf89081b705 = zf89081b705 / (0x119d + 1290 - 0x169d);
      z28ed3c8eb1++;
    }
    flag = (0x3af + 4794 - 0x1668);
    for (int zfee898249b = (0xb9 + 4026 - 0x1073); zfee898249b < z28ed3c8eb1;
         zfee898249b++) {
      if (zffddaa500b[zfee898249b] !=
          zffddaa500b[z28ed3c8eb1 - zfee898249b - (0x49b + 21 - 0x4af)]) {
        flag = (0x3f6 + 3456 - 0x1176);
        break;
      }
    }
    zf89081b705 = z707e79ea35;
    z28ed3c8eb1 = (0x198 + 9530 - 0x26d2);
    while (zf89081b705 != (0xff6 + 3303 - 0x1cdd)) {
      zffddaa500b[z28ed3c8eb1] = zf89081b705 % (0xbc2 + 1052 - 0xfd4);
      zf89081b705 = zf89081b705 / (0xec3 + 1076 - 0x12ed);
      z28ed3c8eb1++;
    }
    for (int zfee898249b = (0x118c + 1855 - 0x18cb); zfee898249b < z28ed3c8eb1;
         zfee898249b++) {
      if (zffddaa500b[zfee898249b] !=
          zffddaa500b[z28ed3c8eb1 - zfee898249b - (0x18b + 7567 - 0x1f19)]) {
        flag = (0x425 + 4225 - 0x14a6);
        break;
      }
    }
    if (flag) {
      z0c33aba876[z707e79ea35] = (0x55 + 3058 - 0xc46);
    }
  }
  for (int z707e79ea35 = (0x1a25 + 409 - 0x1bbd); z707e79ea35 < 10000001;
       z707e79ea35++) {
    z0c33aba876[z707e79ea35] =
        z0c33aba876[z707e79ea35 - (0x1ed4 + 315 - 0x200e)] +
        z0c33aba876[z707e79ea35];
  }
}
int main() {
  long long zcb92188625, zf817e765cb;
  int zd4fd83f1f1;
  z19e0b34c92();
  scanf("\x25\x64", &zd4fd83f1f1);
  for (int zfb9b375068 = (0x1a25 + 3165 - 0x2681); zfb9b375068 <= zd4fd83f1f1;
       zfb9b375068++) {
    scanf("\x25\x6c\x6c\x64\x25\x6c\x6c\x64", &zcb92188625, &zf817e765cb);
    int z8100d45986 = (int)sqrt(zcb92188625);
    int z7881b3c3a8 = (int)sqrt(zf817e765cb);
    if (z8100d45986 * z8100d45986 == zcb92188625)
      z8100d45986--;
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           zfb9b375068, z0c33aba876[z7881b3c3a8] - z0c33aba876[z8100d45986]);
  }
  return (0xc4b + 4154 - 0x1c85);
}
