
#include <stdio.h>

int main(int z1dfe52e21e, char *z892e13e4a0[]) {
  FILE *z552ae6f845, *z6c8e0be7ab;
  z552ae6f845 = (z1dfe52e21e <= (0x71c + 1892 - 0xe7f))
                    ? fopen("\x69\x6e\x70\x75\x74\x2e\x74\x78\x74", "\x72\x2b")
                    : fopen(z892e13e4a0[(0xc5a + 5087 - 0x2038)], "\x72\x2b");
  z6c8e0be7ab = fopen("\x6f\x75\x74\x70\x75\x74\x2e\x74\x78\x74", "\x77\x2b");
  if (z552ae6f845) {
    int z08c89800c2;
    int z6876bb1b10;
    int za90f24902a, z8949996339;
    fscanf(z552ae6f845, "\x25\x64", &z08c89800c2);
    for (z6876bb1b10 = (0x4e8 + 6776 - 0x1f60); z6876bb1b10 < z08c89800c2;
         z6876bb1b10++) {
      int z18f4b2f38c;
      int zaa6bb98202[(0x27f + 8741 - 0x24a0)],
          z69c5f5d55d[(0x13 + 8690 - 0x2201)], z709b25ce69;
      int z43b65120e7 = -(0x536 + 8118 - 0x24eb),
          index = -(0x18eb + 1198 - 0x1d98);
      long long z9ab12ee3ff = (0x3fa + 5400 - 0x1912);
      fscanf(z552ae6f845, "\x25\x64", &z18f4b2f38c);
      for (za90f24902a = (0x5ac + 4006 - 0x1552);
           za90f24902a < (0x1ed5 + 395 - 0x205c); za90f24902a++) {
        if (za90f24902a == z18f4b2f38c - (0xe7 + 6993 - 0x1c37)) {
          fscanf(z552ae6f845, "\x25\x64\x20\x25\x64\x20\x25\x64\x20\x25\x64",
                 &zaa6bb98202[(0xbe9 + 5125 - 0x1fee)],
                 &zaa6bb98202[(0x7cf + 5671 - 0x1df5)],
                 &zaa6bb98202[(0x1787 + 804 - 0x1aa9)],
                 &zaa6bb98202[(0x9b5 + 3570 - 0x17a4)]);
        } else {
          fscanf(z552ae6f845, "\x25\x64\x20\x25\x64\x20\x25\x64\x20\x25\x64",
                 &z709b25ce69, &z709b25ce69, &z709b25ce69, &z709b25ce69);
        }
      }
      fscanf(z552ae6f845, "\x25\x64", &z18f4b2f38c);
      for (za90f24902a = (0x16f9 + 1061 - 0x1b1e);
           za90f24902a < (0x40 + 6859 - 0x1b07); za90f24902a++) {
        if (za90f24902a == z18f4b2f38c - (0x14b5 + 815 - 0x17e3)) {
          fscanf(z552ae6f845, "\x25\x64\x20\x25\x64\x20\x25\x64\x20\x25\x64",
                 &z69c5f5d55d[(0x93a + 1536 - 0xf3a)],
                 &z69c5f5d55d[(0x99 + 8891 - 0x2353)],
                 &z69c5f5d55d[(0xce4 + 3244 - 0x198e)],
                 &z69c5f5d55d[(0x589 + 8364 - 0x2632)]);
        } else {
          fscanf(z552ae6f845, "\x25\x64\x20\x25\x64\x20\x25\x64\x20\x25\x64",
                 &z709b25ce69, &z709b25ce69, &z709b25ce69, &z709b25ce69);
        }
      }
      for (za90f24902a = (0x178c + 2233 - 0x2045);
           za90f24902a < (0x14b9 + 2132 - 0x1d09); za90f24902a++) {
        for (z8949996339 = (0x21ed + 807 - 0x2514);
             z8949996339 < (0x6 + 2488 - 0x9ba); z8949996339++) {
          if (zaa6bb98202[za90f24902a] == z69c5f5d55d[z8949996339]) {
            z43b65120e7++;
            if (index == -(0xb03 + 4574 - 0x1ce0))
              index = za90f24902a;
            else
              break;
          }
        }
        if (z43b65120e7 > (0x123 + 3051 - 0xd0e))
          break;
      }
      fprintf(z6c8e0be7ab, "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
              z6876bb1b10 + (0x16d4 + 4053 - 0x26a8));
      if (z43b65120e7 == (0x1dd0 + 1556 - 0x23e4)) {
        fprintf(z6c8e0be7ab,
                "\x25\x64"
                "\n",
                zaa6bb98202[index]);
      } else if (z43b65120e7 < (0x257 + 769 - 0x558)) {
        fprintf(z6c8e0be7ab,
                "\x25\x73"
                "\n",
                "\x56\x6f\x6c\x75\x6e\x74\x65\x65\x72\x20\x63\x68\x65\x61\x74"
                "\x65\x64\x21");
      } else if (z43b65120e7 > (0xadc + 378 - 0xc56)) {
        fprintf(z6c8e0be7ab,
                "\x25\x73"
                "\n",
                "\x42\x61\x64\x20\x6d\x61\x67\x69\x63\x69\x61\x6e\x21");
      }
    }
  }
  return (0x20d0 + 1391 - 0x263f);
}
