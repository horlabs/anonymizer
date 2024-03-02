
#include <stdio.h>

int main() {
  int z4e5d0b4998;
  int z6ac2c51df4, z42cd0e530b;
  int z0551053a51, ze078c8a327, zb267af1355;
  int z177db8a592;
  int z4db409879f;
  int z2873705ba9;
  int zc05bada011;
  fscanf(stdin,
         "\x25\x64"
         "\n",
         &z4e5d0b4998);
  for (z6ac2c51df4 = (0x15d7 + 345 - 0x1730); z6ac2c51df4 < z4e5d0b4998;
       z6ac2c51df4++) {
    fscanf(stdin, "\x25\x64\x20\x25\x64\x20\x25\x64", &z0551053a51,
           &ze078c8a327, &zb267af1355);
    zc05bada011 = (0x785 + 2118 - 0xfcb);
    for (z42cd0e530b = (0x5cc + 868 - 0x930); z42cd0e530b < z0551053a51;
         z42cd0e530b++) {
      fscanf(stdin, "\x25\x64", &z177db8a592);
      z4db409879f =
          (z177db8a592 + (0x10dd + 5152 - 0x24fb)) / (0x1a84 + 46 - 0x1aaf);
      if (z4db409879f >= zb267af1355) {
        zc05bada011++;
      } else if (ze078c8a327 > (0x172 + 3 - 0x175)) {
        if (((z177db8a592 % (0x1d33 + 2462 - 0x26ce)) !=
             (0x12bb + 4665 - 0x24f3)) &&
            (z4db409879f != (0xa58 + 2812 - 0x1554))) {
          z2873705ba9 = z4db409879f + (0x5aa + 3572 - 0x139d);
          if (z2873705ba9 >= zb267af1355) {
            zc05bada011++;
            ze078c8a327--;
          }
        }
      }
    }
    fprintf(stdout,
            "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
            "\n",
            z6ac2c51df4 + (0xb8d + 4506 - 0x1d26), zc05bada011);
  }
  return (0x102 + 4338 - 0x11f4);
}
