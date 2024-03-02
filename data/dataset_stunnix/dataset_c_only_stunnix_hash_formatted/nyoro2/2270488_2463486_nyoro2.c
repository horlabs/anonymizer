
#include <stdio.h>

int main() {
  int z7c783456a5;
  int z2febc93e03;
  long long z2b93743af0;
  long long z1fc4aea9a0;
  long long z52c23ad87a;
  long z132c51f79c;
  long z0e822c7297;
  long z6d53b0dbdc;
  char z3eaf317c5d[(0x574 + 7870 - 0x2422)];
  int zff36a79735, zb2d0cacde9;
  int z47d46f23be, z69e0e2d403;
  int z714da1e161;
  fscanf(stdin,
         "\x25\x64"
         "\n",
         &z2febc93e03);
  for (z7c783456a5 = (0x6ec + 3349 - 0x1401); z7c783456a5 < z2febc93e03;
       z7c783456a5++) {
    fscanf(stdin, "\x25\x6c\x6c\x64\x20\x25\x6c\x6c\x64", &z2b93743af0,
           &z1fc4aea9a0);
    fprintf(stdout, "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
            z7c783456a5 + (0x7bf + 1291 - 0xcc9));
    z0e822c7297 = sqrt((double)z2b93743af0) - (0x295 + 3270 - 0xf5a);
    z6d53b0dbdc = sqrt((double)z1fc4aea9a0) - (0x98 + 8382 - 0x2155);
    z52c23ad87a = z0e822c7297 + (0x9d8 + 2845 - 0x14f4);
    z52c23ad87a = z52c23ad87a * z52c23ad87a;
    if (z52c23ad87a < z2b93743af0) {
      z0e822c7297++;
      z52c23ad87a +=
          (z0e822c7297 * (0x1034 + 3345 - 0x1d43) + (0x4ea + 758 - 0x7df));
    }
    z714da1e161 = (0xddc + 3223 - 0x1a73);
    for (z132c51f79c = z0e822c7297 + (0x12b9 + 3584 - 0x20b8);
         z132c51f79c <= z6d53b0dbdc + (0x98b + 2478 - 0x1338); z132c51f79c++) {
      sprintf(z3eaf317c5d, "\x25\x6c\x6c\x64", z52c23ad87a);
      zb2d0cacde9 = strlen(z3eaf317c5d);
      for (zff36a79735 = (0x13a + 4897 - 0x145b);
           zff36a79735 < zb2d0cacde9 / (0x1f95 + 136 - 0x201b); zff36a79735++) {
        if (z3eaf317c5d[zff36a79735] !=
            z3eaf317c5d[zb2d0cacde9 - zff36a79735 - (0x1c63 + 607 - 0x1ec1)])
          break;
      }
      if (zff36a79735 >= zb2d0cacde9 / (0x15c5 + 4178 - 0x2615)) {
        sprintf(z3eaf317c5d, "\x25\x6c\x64", z132c51f79c);
        z69e0e2d403 = strlen(z3eaf317c5d);
        for (z47d46f23be = (0xd05 + 5507 - 0x2288);
             z47d46f23be < z69e0e2d403 / (0x1f0b + 1070 - 0x2337);
             z47d46f23be++) {
          if (z3eaf317c5d[z47d46f23be] !=
              z3eaf317c5d[z69e0e2d403 - z47d46f23be - (0x4ec + 6996 - 0x203f)])
            break;
        }
        if (z47d46f23be >= z69e0e2d403 / (0x178 + 6222 - 0x19c4)) {
          z714da1e161++;
        }
      }
      z52c23ad87a +=
          (z132c51f79c * (0x5eb + 8193 - 0x25ea) + (0xbdf + 5135 - 0x1fed));
    }
    fprintf(stdout, "\x25\x64", z714da1e161);
    fprintf(stdout, "\n");
  }
  return (0xc59 + 5004 - 0x1fe5);
}
