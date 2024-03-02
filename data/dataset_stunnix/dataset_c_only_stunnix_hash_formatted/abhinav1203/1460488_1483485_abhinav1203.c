
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *zc23c62be18;
  zc23c62be18 = (char *)malloc(sizeof(char) * (0x12cb + 3607 - 0x206a));
  char zffe7823f56,
      zf8346111b0[(0xe19 + 1489 - 0x13d0)] = {
          ((char)(0x501 + 3003 - 0x1043)),  ((char)(0x146b + 474 - 0x15dd)),
          ((char)(0xea6 + 2537 - 0x182a)),  ((char)(0x1342 + 42 - 0x12f9)),
          ((char)(0x18ba + 3164 - 0x24a7)), ((char)(0xccf + 3473 - 0x19fd)),
          ((char)(0x1534 + 3592 - 0x22c6)), ((char)(0x318 + 1680 - 0x930)),
          ((char)(0x1c32 + 1545 - 0x21d7)), ((char)(0x665 + 4647 - 0x1817)),
          ((char)(0x4aa + 4461 - 0x15ae)),  ((char)(0x5cc + 6288 - 0x1df5)),
          ((char)(0x7b9 + 52 - 0x781)),     ((char)(0xdf3 + 2610 - 0x17c3)),
          ((char)(0xd55 + 1398 - 0x1260)),  ((char)(0xce0 + 3193 - 0x18e7)),
          ((char)(0xa36 + 2586 - 0x13d6)),  ((char)(0x10bf + 1602 - 0x168d)),
          ((char)(0x510 + 7206 - 0x20c8)),  ((char)(0x8e0 + 6477 - 0x21b6)),
          ((char)(0x1d20 + 2215 - 0x255d)), ((char)(0x198a + 379 - 0x1a95)),
          ((char)(0x1c2f + 806 - 0x1eef)),  ((char)(0x15b5 + 2265 - 0x1e21)),
          ((char)(0x173d + 367 - 0x184b)),  ((char)(0x42c + 3190 - 0x1031))};
  int zd0f95f47f4, z9bb882124b = (0x678 + 2550 - 0x106d), z88ad99764d;
  scanf("\x25\x64", &zd0f95f47f4);
  zffe7823f56 = getchar();
  while (zd0f95f47f4--) {
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", z9bb882124b);
    while ((zffe7823f56 = getchar()) != '\r' && zffe7823f56 != '\0' &&
           zffe7823f56 != '\t' && zffe7823f56 != '\n') {
      if (zffe7823f56 >= ((char)(0xe6b + 6217 - 0x2653)) &&
          zffe7823f56 <= ((char)(0x316 + 5113 - 0x1695)))
        printf("\x25\x63", zf8346111b0[(int)zffe7823f56 -
                                       (int)((char)(0x1fcd + 742 - 0x2252))]);
      else
        printf("\x20");
    }
    printf("\n");
    z9bb882124b++;
  }
}
