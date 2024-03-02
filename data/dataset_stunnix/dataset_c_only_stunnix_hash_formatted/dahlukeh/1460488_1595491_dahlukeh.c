
#include <stdio.h>
#include <stdlib.h>

int z8c948d16d0;
int z729c8f756e[(0x2030 + 1026 - 0x204a)];
int z4d9868f243;
int z5640a038cb;
void z007e8a7936();
int z519b311523(int zdf4d008775);
int z216c101a91(int zdf4d008775);
int main() {
  int zbd92384fe8;
  freopen("\x69\x6e\x2e\x74\x78\x74", "\x72", stdin);
  freopen("\x6f\x75\x74\x2e\x74\x78\x74", "\x77", stdout);
  scanf("\x25\x64\x20", &zbd92384fe8);
  int z003cecbf98;
  for (z003cecbf98 = (0x1200 + 2929 - 0x1d71); z003cecbf98 < zbd92384fe8;
       z003cecbf98++) {
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
           z003cecbf98 + (0x2301 + 470 - 0x24d6));
    z007e8a7936();
  }
}
void z007e8a7936() {
  scanf("\x25\x64\x20\x25\x64\x20\x25\x64\x20", &z8c948d16d0, &z5640a038cb,
        &z4d9868f243);
  int z003cecbf98;
  for (z003cecbf98 = (0xf63 + 5146 - 0x237d); z003cecbf98 < z8c948d16d0;
       z003cecbf98++) {
    scanf("\x25\x64\x20", &z729c8f756e[z003cecbf98]);
  }
  int zbd7ace872a = (0x1eb + 3080 - 0xdf3);
  for (z003cecbf98 = (0x1597 + 3843 - 0x249a); z003cecbf98 < z8c948d16d0;
       z003cecbf98++) {
    if (z519b311523(z729c8f756e[z003cecbf98])) {
      zbd7ace872a++;
    } else {
      if (z5640a038cb > (0xbd1 + 4888 - 0x1ee9) &&
          z216c101a91(z729c8f756e[z003cecbf98])) {
        zbd7ace872a++;
        z5640a038cb--;
      }
    }
  }
  printf("\x25\x64"
         "\n",
         zbd7ace872a);
}
int z519b311523(int zdf4d008775) {
  int rem = zdf4d008775 % (0xaf + 1425 - 0x63d);
  int zdfd6f246f4 = zdf4d008775 / (0xea8 + 5792 - 0x2545);
  if (rem > (0x413 + 3977 - 0x139c)) {
    zdfd6f246f4++;
  }
  return zdfd6f246f4 >= z4d9868f243;
}
int z216c101a91(int zdf4d008775) {
  int rem = zdf4d008775 % (0x1f0b + 1264 - 0x23f8);
  int zdfd6f246f4 = zdf4d008775 / (0x1561 + 2926 - 0x20cc);
  if (rem == (0x4f5 + 3618 - 0x1315)) {
    zdfd6f246f4 += (0x15a7 + 1163 - 0x1a30);
  } else {
    if (rem == (0xb11 + 4215 - 0x1b87) ||
        zdf4d008775 > (0x284 + 3801 - 0x115d)) {
      zdfd6f246f4++;
    }
  }
  return zdfd6f246f4 >= z4d9868f243;
}
