
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *zc2be8749d9, *zde0567ed11;
int zb766881d22[(0x70f + 4926 - 0x1a45)], z317643060f[(0x57c + 5121 - 0x1975)],
    zd59b223b36;
long long int zf4fd3e32dc[(0x13ac + 2813 - 0x1ea2)], z90f4f438c6;
int z9f41bb2d57(long long int zbd6f447d65) {
  int ze52b72d935 = (0x4fb + 7233 - 0x213c);
  while (zbd6f447d65 > (0x1358 + 1264 - 0x1848)) {
    ze52b72d935++;
    zbd6f447d65 /= (0x5b3 + 4151 - 0x15e0);
  }
  return (ze52b72d935 - (0x143 + 86 - 0x198));
}
void z8b52d0262b(long long int zbd6f447d65) {
  int z76fc250038, z608fd90f0a;
  for (z76fc250038 = zd59b223b36; z76fc250038 >= (0xd02 + 2147 - 0x1565);
       z76fc250038--) {
    zb766881d22[z76fc250038] = zbd6f447d65 % (0x6ab + 5563 - 0x1c5c);
    zbd6f447d65 /= (0x262 + 2629 - 0xc9d);
  }
}
long long int get() {
  long long int z76fc250038 = (0xff3 + 3551 - 0x1dd2);
  int zbd6f447d65;
  for (zbd6f447d65 = (0xba1 + 1964 - 0x134d); zbd6f447d65 <= zd59b223b36;
       zbd6f447d65++) {
    z76fc250038 += z317643060f[zbd6f447d65];
    z76fc250038 = z76fc250038 * (0xb07 + 2429 - 0x147a);
  }
  z76fc250038 /= (0x695 + 6061 - 0x1e38);
  return (z76fc250038);
}
int z23f6a35c87(long long int z76fc250038) {
  int zbd6f447d65;
  for (zbd6f447d65 = (0x178f + 1502 - 0x1d6d); zbd6f447d65 <= zd59b223b36;
       zbd6f447d65++) {
    if (zb766881d22[zbd6f447d65] != z317643060f[zbd6f447d65])
      return ((0xfd8 + 720 - 0x12a8));
  }
  return ((0xfc + 3433 - 0xe64));
}
void z9974c68617() {
  int zbd6f447d65, z76fc250038, z608fd90f0a;
  zbd6f447d65 = z317643060f[zd59b223b36];
  for (z76fc250038 = (zd59b223b36 - (0x334 + 5293 - 0x17e0));
       z76fc250038 >= (0x1aa0 + 866 - 0x1e02); z76fc250038--)
    z317643060f[z76fc250038 + (0x1a7f + 1397 - 0x1ff3)] =
        z317643060f[z76fc250038];
  z317643060f[(0xb07 + 5483 - 0x2072)] = zbd6f447d65;
}
int za3d8886ee3(long long int zbd6f447d65, long long int zfbe6fa4294,
                long long int z59a2b623bc) {
  if (zb766881d22[(0x2fd + 66 - 0x33f)] == (0x1967 + 2691 - 0x23ea))
    return ((0x16d8 + 1528 - 0x1cd0));
  int z76fc250038, z608fd90f0a = (0x325 + 3462 - 0x10ab);
  for (z76fc250038 = (0x1c8f + 940 - 0x203b); z76fc250038 <= zd59b223b36;
       z76fc250038++)
    z317643060f[z76fc250038] = zb766881d22[z76fc250038];
  int z38ae1c00e4;
  long long int f;
  z90f4f438c6 = -(0xbc9 + 1022 - 0xfc6);
  for (z76fc250038 = (0xf59 + 1795 - 0x165b); z76fc250038 <= zd59b223b36;
       z76fc250038++) {
    z9974c68617();
    f = get();
    for (z38ae1c00e4 = (0x150c + 3610 - 0x2326); z38ae1c00e4 <= z90f4f438c6;
         z38ae1c00e4++) {
      if (zf4fd3e32dc[z38ae1c00e4] == f)
        goto z6b532ef827;
    }
    if ((f > zbd6f447d65) && (f >= zfbe6fa4294) && (f <= z59a2b623bc)) {
      z608fd90f0a++;
      z90f4f438c6++;
      zf4fd3e32dc[z90f4f438c6] = f;
    }
  z6b532ef827:
    z608fd90f0a += (0x1b99 + 2109 - 0x23d6);
  }
  return (z608fd90f0a);
}
void Main() {
  long long int zfbe6fa4294, z59a2b623bc, zbd6f447d65;
  long int ze52b72d935 = (0x352 + 931 - 0x6f5), z608fd90f0a;
  fscanf(zc2be8749d9, "\x25\x6c\x6c\x64", &zfbe6fa4294);
  fscanf(zc2be8749d9, "\x25\x6c\x6c\x64", &z59a2b623bc);
  zd59b223b36 = z9f41bb2d57(zfbe6fa4294);
  if (zd59b223b36 == (0x67a + 3514 - 0x1434))
    goto z1d67aab123;
  for (zbd6f447d65 = zfbe6fa4294; zbd6f447d65 <= z59a2b623bc; zbd6f447d65++) {
    z8b52d0262b(zbd6f447d65);
    z608fd90f0a = za3d8886ee3(zbd6f447d65, zfbe6fa4294, z59a2b623bc);
    ze52b72d935 += z608fd90f0a;
    if (z608fd90f0a > (0x98d + 6043 - 0x2128))
      printf("\x25\x6c\x6c\x64\x3a\x25\x6c\x64"
             "\t",
             zbd6f447d65, z608fd90f0a);
  }
z1d67aab123:
  fprintf(zde0567ed11, "\x25\x6c\x64", ze52b72d935);
}
int main() {
  zc2be8749d9 = fopen("\x2f\x68\x6f\x6d\x65\x2f\x76\x69\x76\x65\x6b\x2f\x44\x65"
                      "\x73\x6b\x74\x6f\x70\x2f\x73\x2e\x69\x6e",
                      "\x72");
  zde0567ed11 = fopen("\x2f\x68\x6f\x6d\x65\x2f\x76\x69\x76\x65\x6b\x2f\x44\x65"
                      "\x73\x6b\x74\x6f\x70\x2f\x73\x2e\x6f\x75\x74",
                      "\x77");
  int z3634018554, zbd6f447d65;
  char zcc3f8e17ef;
  fscanf(zc2be8749d9, "\x25\x64", &z3634018554);
  for (zbd6f447d65 = (0x1f73 + 713 - 0x223b); zbd6f447d65 <= z3634018554;
       zbd6f447d65++) {
    fprintf(zde0567ed11, "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
            zbd6f447d65);
    Main();
    zcc3f8e17ef = '\n';
    fputc(zcc3f8e17ef, zde0567ed11);
  }
  return ((0x425 + 4608 - 0x1624));
}
