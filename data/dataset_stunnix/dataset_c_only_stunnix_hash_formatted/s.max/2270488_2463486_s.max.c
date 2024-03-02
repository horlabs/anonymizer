
#include <math.h>
#include <stdio.h>

int z07919691d9[10000000 + (0x6f + 8941 - 0x235b)];
int ze3b50ea185(long long z665c123d73) {
  int zc30d0b6491[(0xf7b + 2448 - 0x1523)];
  int z9b8d760f2c = (0x4fc + 7016 - 0x2064), zdbea37a12b;
  while (z665c123d73) {
    zc30d0b6491[z9b8d760f2c++] = z665c123d73 % (0x307 + 7833 - 0x2196);
    z665c123d73 /= (0xf9f + 5866 - 0x267f);
  }
  for (zdbea37a12b = (0x128d + 3035 - 0x1e68);
       (0xfa4 + 3348 - 0x1cb6) * zdbea37a12b <
       z9b8d760f2c - (0x76 + 8970 - 0x237f);
       zdbea37a12b++)
    if (zc30d0b6491[zdbea37a12b] !=
        zc30d0b6491[z9b8d760f2c - zdbea37a12b - (0x1c8 + 6597 - 0x1b8c)])
      return (0x6a2 + 4555 - 0x186d);
  return (0xe0f + 33 - 0xe2f);
}
int main() {
  long long zdbea37a12b;
  int zd02754ce76 = (0x110 + 6526 - 0x1a8e);
  z07919691d9[(0xbed + 199 - 0xcb4)] = (0x9fd + 2711 - 0x1494);
  for (zdbea37a12b = (0xc29 + 4070 - 0x1c0e); zdbea37a12b <= 10000000;
       zdbea37a12b++) {
    if (ze3b50ea185(zdbea37a12b) && ze3b50ea185(zdbea37a12b * zdbea37a12b)) {
      zd02754ce76++;
    }
    z07919691d9[zdbea37a12b] = zd02754ce76;
  }
  int ze17747cdb1, zf969affa13;
  scanf("\x25\x64", &zf969affa13);
  for (ze17747cdb1 = (0x16b0 + 4138 - 0x26d9); ze17747cdb1 <= zf969affa13;
       ze17747cdb1++) {
    long long z665c123d73, z37b4353593;
    scanf("\x25\x6c\x6c\x64\x20\x25\x6c\x6c\x64", &z665c123d73, &z37b4353593);
    z665c123d73 = sqrt(z665c123d73 - (0xb17 + 2572 - 0x1522));
    z37b4353593 = sqrt(z37b4353593);
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           ze17747cdb1, z07919691d9[z37b4353593] - z07919691d9[z665c123d73]);
  }
  return (0xb90 + 683 - 0xe3b);
}
