
#include <stdio.h>

int zb347a5c1aa(int z4af0f85578) {
  int z6c0e517bd3;
  int zd1355e1e3d = (0x1dc + 4316 - 0x12b8);
  while (z4af0f85578 > (0x10d + 3640 - 0xf45)) {
    z4af0f85578 /= (0x1efa + 950 - 0x22a6);
    zd1355e1e3d++;
  }
  return zd1355e1e3d;
}
void zde2f4fa87e(int z4af0f85578, int *zbe03dfa0da, int zeba4fdd9db) {
  int z6c0e517bd3;
  for (z6c0e517bd3 = zeba4fdd9db - (0x6bf + 5656 - 0x1cd6);
       z6c0e517bd3 >= (0x1bf8 + 539 - 0x1e13); z6c0e517bd3--) {
    zbe03dfa0da[z6c0e517bd3] = z4af0f85578 % (0x365 + 4694 - 0x15b1);
    z4af0f85578 /= (0x279 + 7949 - 0x217c);
  }
}
int zaf83f544d5(int *z18d5154d4b, int *zbbc991b1ee, int zeba4fdd9db) {
  int z6c0e517bd3;
  for (z6c0e517bd3 = (0x134f + 1073 - 0x1780); z6c0e517bd3 < zeba4fdd9db;
       z6c0e517bd3++) {
    if (z18d5154d4b[z6c0e517bd3] > zbbc991b1ee[z6c0e517bd3])
      return (0x1ec + 2161 - 0xa5c);
    else if (z18d5154d4b[z6c0e517bd3] < zbbc991b1ee[z6c0e517bd3])
      return -(0x244 + 4068 - 0x1227);
  }
  return (0x1f75 + 245 - 0x206a);
}
void ze7f5cc79e9(int *zbe03dfa0da, int zeba4fdd9db) {
  int z6c0e517bd3;
  for (z6c0e517bd3 = (0x45f + 4457 - 0x15c8); z6c0e517bd3 < zeba4fdd9db;
       z6c0e517bd3++) {
    fputc(((char)(0x1a6 + 9093 - 0x24fb)) + zbe03dfa0da[z6c0e517bd3], stderr);
  }
}
int main() {
  int z60e0ddbc6f;
  int z6c0e517bd3, zef3450a5ea, zae9b63eab4, z6131db32b6, z4af0f85578;
  int za7d51dcf1a, zd804d779bb;
  int zd1355e1e3d;
  int zb8812eb30f, z80152b243c;
  int z32a70febf4;
  int z40650d3aae[(0x16c6 + 3473 - 0x2447)];
  int z0a8a3102d0[(0xaf9 + 2515 - 0x14bc)];
  int zbdb3d9c97f[(0xda8 + 3652 - 0x1bdc)];
  int z3c58dfba38[(0xf32 + 3826 - 0x1e14)];
  fscanf(stdin,
         "\x25\x64"
         "\n",
         &z60e0ddbc6f);
  for (z6c0e517bd3 = (0x5cf + 7874 - 0x2491); z6c0e517bd3 < z60e0ddbc6f;
       z6c0e517bd3++) {
    fscanf(stdin,
           "\x25\x64\x20\x25\x64"
           "\n",
           &za7d51dcf1a, &zd804d779bb);
    z32a70febf4 = zb347a5c1aa(za7d51dcf1a);
    zde2f4fa87e(za7d51dcf1a, zbdb3d9c97f, z32a70febf4);
    zde2f4fa87e(zd804d779bb, z3c58dfba38, z32a70febf4);
    zb8812eb30f = (0x1946 + 63 - 0x1985);
    z80152b243c = (0x17d4 + 2881 - 0x2315);
    for (zef3450a5ea = za7d51dcf1a; zef3450a5ea <= zd804d779bb; zef3450a5ea++) {
      zde2f4fa87e(zef3450a5ea, z40650d3aae, z32a70febf4);
      for (z4af0f85578 = (0x86a + 4411 - 0x19a4);
           z4af0f85578 <= (z32a70febf4 / (0x531 + 8624 - 0x26df));
           z4af0f85578++) {
        int zde82ae34fe = z4af0f85578;
        if (z40650d3aae[z4af0f85578] == (0x8fc + 440 - 0xab4))
          continue;
        for (z6131db32b6 = (0x1cd5 + 214 - 0x1dab); z6131db32b6 < z32a70febf4;
             z6131db32b6++) {
          z0a8a3102d0[z6131db32b6] = z40650d3aae[zde82ae34fe++];
          if (zde82ae34fe >= z32a70febf4)
            zde82ae34fe = (0x2249 + 1048 - 0x2661);
        }
        if (zaf83f544d5(z40650d3aae, z0a8a3102d0, z32a70febf4) !=
            (0xe18 + 1205 - 0x12cd)) {
          if ((zaf83f544d5(z0a8a3102d0, zbdb3d9c97f, z32a70febf4) >=
               (0x16d6 + 1584 - 0x1d06)) &&
              (zaf83f544d5(z0a8a3102d0, z3c58dfba38, z32a70febf4) <=
               (0x309 + 8191 - 0x2308))) {
            if (z4af0f85578 * (0x50f + 3048 - 0x10f5) == z32a70febf4) {
              zb8812eb30f++;
            } else {
              z80152b243c++;
            }
          }
        }
      }
    }
    zd1355e1e3d = zb8812eb30f / (0x1392 + 2499 - 0x1d53) + z80152b243c;
    fprintf(stdout,
            "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
            "\n",
            z6c0e517bd3 + (0x2215 + 715 - 0x24df), zd1355e1e3d);
  }
  return (0x141d + 1541 - 0x1a22);
}
