
#include <stdio.h>

char zf53156ea17[(0xd9 + 1505 - 0x6b0)][(0x9e6 + 5444 - 0x1f20)];
int z65beb54ce8(int zf8882ab6bb) {
  int ze414543e11;
  for (ze414543e11 = (0x139 + 1437 - 0x6d6);
       ze414543e11 < (0x1e3 + 7171 - 0x1de2); ze414543e11++) {
    int z8b7206e1d2;
    for (z8b7206e1d2 = (0x10cb + 3552 - 0x1eab);
         z8b7206e1d2 < (0xa00 + 5207 - 0x1e53); z8b7206e1d2++) {
      if (zf53156ea17[ze414543e11][z8b7206e1d2] != zf8882ab6bb &&
          zf53156ea17[ze414543e11][z8b7206e1d2] !=
              ((char)(0x1f40 + 1701 - 0x2591))) {
        break;
      }
    }
    if (z8b7206e1d2 >= (0x1c8 + 8158 - 0x21a2))
      return (0xb05 + 3658 - 0x194e);
    for (z8b7206e1d2 = (0x533 + 3492 - 0x12d7);
         z8b7206e1d2 < (0xacf + 1301 - 0xfe0); z8b7206e1d2++) {
      if (zf53156ea17[z8b7206e1d2][ze414543e11] != zf8882ab6bb &&
          zf53156ea17[z8b7206e1d2][ze414543e11] !=
              ((char)(0x61 + 2259 - 0x8e0))) {
        break;
      }
    }
    if (z8b7206e1d2 >= (0x66b + 512 - 0x867))
      return (0x24 + 4464 - 0x1193);
  }
  for (ze414543e11 = (0xf9 + 5108 - 0x14ed);
       ze414543e11 < (0x15f8 + 3535 - 0x23c3); ze414543e11++) {
    if (zf53156ea17[ze414543e11][ze414543e11] != zf8882ab6bb &&
        zf53156ea17[ze414543e11][ze414543e11] !=
            ((char)(0x13cd + 3893 - 0x22ae))) {
      break;
    }
  }
  if (ze414543e11 >= (0x8ba + 842 - 0xc00))
    return (0x722 + 5717 - 0x1d76);
  for (ze414543e11 = (0x2097 + 1522 - 0x2689);
       ze414543e11 < (0xc13 + 1583 - 0x123e); ze414543e11++) {
    if (zf53156ea17[ze414543e11][(0x7f5 + 6584 - 0x21aa) - ze414543e11] !=
            zf8882ab6bb &&
        zf53156ea17[ze414543e11][(0xf7 + 1733 - 0x7b9) - ze414543e11] !=
            ((char)(0x13b9 + 3202 - 0x1fe7))) {
      break;
    }
  }
  if (ze414543e11 >= (0x157 + 9440 - 0x2633))
    return (0x1b56 + 1100 - 0x1fa1);
  return (0x237 + 3352 - 0xf4f);
}
int ze5ead95351(void) {
  int ze414543e11;
  for (ze414543e11 = (0x931 + 1946 - 0x10cb);
       ze414543e11 < (0x1854 + 1865 - 0x1f99); ze414543e11++) {
    int z8b7206e1d2;
    for (z8b7206e1d2 = (0x24b + 3062 - 0xe41);
         z8b7206e1d2 < (0xfab + 3786 - 0x1e71); z8b7206e1d2++) {
      if (zf53156ea17[ze414543e11][z8b7206e1d2] ==
          ((char)(0x1058 + 4599 - 0x2221)))
        return (0x11b + 4919 - 0x1452);
    }
  }
  return (0xcfd + 1484 - 0x12c8);
}
int z09ca795d54(void) {
  if (z65beb54ce8(((char)(0x1e3d + 955 - 0x21a0))))
    return (0xb83 + 700 - 0xe3f);
  if (z65beb54ce8(((char)(0x102d + 4685 - 0x222b))))
    return (0xbf + 6865 - 0x1b8f);
  if (ze5ead95351())
    return (0x18f + 1753 - 0x866);
  return (0x881 + 869 - 0xbe3);
}
int main() {
  int zaa791f9988, ze700fa1184 = (0x1812 + 3407 - 0x2561);
  for (scanf("\x25\x64"
             "\n",
             &zaa791f9988);
       zaa791f9988; zaa791f9988--) {
    int ze414543e11;
    int zad0b608bda;
    for (ze414543e11 = (0x6f9 + 5852 - 0x1dd5);
         ze414543e11 < (0xdf8 + 6188 - 0x261f); ze414543e11++) {
      fgets(zf53156ea17[ze414543e11], (0xd2 + 4931 - 0x140b), stdin);
    }
    zad0b608bda = z09ca795d54();
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", ++ze700fa1184);
    switch (zad0b608bda) {
    case (0x1bb5 + 1758 - 0x2293):
      puts("\x58\x20\x77\x6f\x6e");
      break;
    case (0x1e67 + 596 - 0x20ba):
      puts("\x4f\x20\x77\x6f\x6e");
      break;
    case (0x4e8 + 773 - 0x7eb):
      puts("\x44\x72\x61\x77");
      break;
    case (0x134a + 4893 - 0x2664):
      puts("\x47\x61\x6d\x65\x20\x68\x61\x73\x20\x6e\x6f\x74\x20\x63\x6f\x6d"
           "\x70\x6c\x65\x74\x65\x64");
      break;
    default:
      break;
    }
  }
  return (0xa2a + 3048 - 0x1612);
}
