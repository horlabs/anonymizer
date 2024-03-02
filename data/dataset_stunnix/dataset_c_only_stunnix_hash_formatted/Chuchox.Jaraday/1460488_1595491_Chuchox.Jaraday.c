
#include <stdio.h>

int main(void) {
  int zfd70ae7d46, za90330d5db, z60c4d776ef, min, zd3dcecf3f7;
  int ze3f3eb7658, z6af49e4083;
  int cos, zf01e82e3ad, zb4071aa5a8;
  scanf("\x25\x64"
        "\n",
        &zfd70ae7d46);
  for (ze3f3eb7658 = (0xc69 + 1206 - 0x111e); ze3f3eb7658 <= zfd70ae7d46;
       ze3f3eb7658++) {
    zb4071aa5a8 = (0xa0d + 3747 - 0x18b0);
    scanf("\x25\x64", &za90330d5db);
    scanf("\x25\x64", &z60c4d776ef);
    scanf("\x25\x64", &min);
    for (z6af49e4083 = (0x8cc + 964 - 0xc8f); z6af49e4083 <= za90330d5db;
         z6af49e4083++) {
      scanf("\x25\x64", &zd3dcecf3f7);
      cos = zd3dcecf3f7 / (0x63d + 5903 - 0x1d49);
      zf01e82e3ad = zd3dcecf3f7 % (0x503 + 2679 - 0xf77);
      if (cos == (0xe9b + 5941 - 0x25d0)) {
        if ((zf01e82e3ad >= min) && (zf01e82e3ad <= (0xc07 + 1454 - 0x11b4))) {
          zb4071aa5a8++;
        } else if ((zf01e82e3ad >= min) &&
                   (zf01e82e3ad == (0x678 + 7058 - 0x2208)) && (z60c4d776ef)) {
          zb4071aa5a8++;
          z60c4d776ef--;
        }
      } else if (cos >= min) {
        zb4071aa5a8++;
      } else if ((cos + (0x1b35 + 1448 - 0x20dc)) == min) {
        if (zf01e82e3ad) {
          zb4071aa5a8++;
        } else if (z60c4d776ef) {
          zb4071aa5a8++;
          z60c4d776ef--;
        }
      } else if ((cos + (0xc7 + 6958 - 0x1bf3)) == min) {
        if ((zf01e82e3ad == (0x1c10 + 1343 - 0x214d)) && (z60c4d776ef)) {
          zb4071aa5a8++;
          z60c4d776ef--;
        }
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           ze3f3eb7658, zb4071aa5a8);
  }
}
