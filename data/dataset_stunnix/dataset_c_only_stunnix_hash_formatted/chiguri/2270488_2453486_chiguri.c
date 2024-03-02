
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int z4b50e003e3(int *z331d9c75cb) {
  int z2706490551, zae4bb8908e;
  int z3a81657fd6;
  for (z2706490551 = (0xdc9 + 2609 - 0x17fa);
       z2706490551 < (0xa2c + 2740 - 0x14dc); ++z2706490551) {
    z3a81657fd6 = (0x1d2d + 2349 - 0x2659);
    for (zae4bb8908e = (0x10cc + 4378 - 0x21e6);
         zae4bb8908e < (0x1585 + 1664 - 0x1c01); ++zae4bb8908e) {
      if (!z331d9c75cb[z2706490551 * (0xbf3 + 5958 - 0x2335) + zae4bb8908e]) {
        z3a81657fd6 = (0x62 + 7233 - 0x1ca3);
        break;
      }
    }
    if (z3a81657fd6)
      return (0x1653 + 2853 - 0x2177);
  }
  for (z2706490551 = (0x1356 + 893 - 0x16d3);
       z2706490551 < (0x1600 + 703 - 0x18bb); ++z2706490551) {
    z3a81657fd6 = (0xd11 + 5499 - 0x228b);
    for (zae4bb8908e = (0x112 + 5659 - 0x172d);
         zae4bb8908e < (0x12e9 + 2997 - 0x1e9a); ++zae4bb8908e) {
      if (!z331d9c75cb[zae4bb8908e * (0xc19 + 4553 - 0x1dde) + z2706490551]) {
        z3a81657fd6 = (0x5fd + 3286 - 0x12d3);
        break;
      }
    }
    if (z3a81657fd6)
      return (0x1a22 + 3222 - 0x26b7);
  }
  z3a81657fd6 = (0x10d7 + 37 - 0x10fb);
  for (z2706490551 = (0x1077 + 109 - 0x10e4);
       z2706490551 < (0xb9d + 2188 - 0x1425); ++z2706490551) {
    if (!z331d9c75cb[z2706490551 * (0xa71 + 4352 - 0x1b6d) + z2706490551]) {
      z3a81657fd6 = (0x1005 + 3408 - 0x1d55);
      break;
    }
  }
  if (z3a81657fd6)
    return (0xcdd + 1477 - 0x12a1);
  for (z2706490551 = (0xca9 + 3786 - 0x1b73);
       z2706490551 < (0x7ef + 3783 - 0x16b2); ++z2706490551) {
    z3a81657fd6 = (0xbdb + 5977 - 0x2333);
    if (!z331d9c75cb[z2706490551 * (0x809 + 1946 - 0xf9f) +
                     ((0x13a4 + 3030 - 0x1f77) - z2706490551)]) {
      z3a81657fd6 = (0x1b25 + 329 - 0x1c6e);
      break;
    }
  }
  return z3a81657fd6;
}
int main(void) {
  int zeb07cf5080;
  int z2706490551, zae4bb8908e, z5675c3e350;
  char zf2d33ff303[(0xb6d + 3227 - 0x1802)];
  int X[(0xb22 + 6704 - 0x254e)][(0x363 + 839 - 0x6a6)];
  int zcc7537cac1[(0x175b + 2942 - 0x22d5)][(0x1442 + 3592 - 0x2246)];
  int z1e668fc8d6;
  int z737797237a;
  scanf("\x25\x64", &zeb07cf5080);
  for (z2706490551 = (0x44a + 265 - 0x552); z2706490551 <= zeb07cf5080;
       ++z2706490551) {
    gets(zf2d33ff303);
    z1e668fc8d6 = (0x3c7 + 1384 - 0x92f);
    z737797237a = (0x3dc + 8989 - 0x26f9);
    for (zae4bb8908e = (0x215 + 4429 - 0x1362);
         zae4bb8908e < (0x17c2 + 2076 - 0x1fda); ++zae4bb8908e) {
      gets(zf2d33ff303);
      for (z5675c3e350 = (0x462 + 6747 - 0x1ebd);
           z5675c3e350 < (0x1cc0 + 1544 - 0x22c4); ++z5675c3e350) {
        if (zf2d33ff303[z5675c3e350] == ((char)(0x717 + 1754 - 0xd99))) {
          X[zae4bb8908e][z5675c3e350] = (0x217 + 8402 - 0x22e8);
          zcc7537cac1[zae4bb8908e][z5675c3e350] = (0xd4b + 6330 - 0x2605);
        } else if (zf2d33ff303[z5675c3e350] ==
                   ((char)(0xa2a + 6420 - 0x22ef))) {
          X[zae4bb8908e][z5675c3e350] = (0x305 + 5229 - 0x1772);
          zcc7537cac1[zae4bb8908e][z5675c3e350] = (0x685 + 6898 - 0x2176);
        } else if (zf2d33ff303[z5675c3e350] == ((char)(0x59d + 1613 - 0xb96))) {
          X[zae4bb8908e][z5675c3e350] = (0x1aca + 2950 - 0x264f);
          zcc7537cac1[zae4bb8908e][z5675c3e350] = (0x1570 + 1956 - 0x1d13);
        } else {
          X[zae4bb8908e][z5675c3e350] = (0x510 + 209 - 0x5e1);
          zcc7537cac1[zae4bb8908e][z5675c3e350] = (0x6b5 + 4603 - 0x18b0);
          z1e668fc8d6 = (0xbdb + 6616 - 0x25b2);
        }
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", z2706490551);
    if (z4b50e003e3((int *)X)) {
      printf("\x58\x20\x77\x6f\x6e"
             "\n");
    } else if (z4b50e003e3((int *)zcc7537cac1)) {
      printf("\x4f\x20\x77\x6f\x6e"
             "\n");
    } else if (z1e668fc8d6) {
      printf("\x47\x61\x6d\x65\x20\x68\x61\x73\x20\x6e\x6f\x74\x20\x63\x6f\x6d"
             "\x70\x6c\x65\x74\x65\x64"
             "\n");
    } else {
      printf("\x44\x72\x61\x77"
             "\n");
    }
  }
  return (0x90d + 2092 - 0x1139);
}
