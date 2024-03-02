
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char z29dc1ea72e[(0x154b + 1373 - 0x1a28)],
      za02319e10e[] = {"\x79\x68\x65\x73\x6f\x63\x76\x78\x64\x75\x69\x67\x6c"
                       "\x62\x6b\x72\x7a\x74\x6e\x77\x6a\x70\x66\x6d\x61\x71"};
  int z833f788211, z18c3051e3b, z152249f124;
  FILE *zb31d629842 = fopen("\x41\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65"
                            "\x6d\x70\x74\x30\x2e\x69\x6e",
                            "\x72"),
       *z1e81464274 = fopen("\x6f\x75\x74\x2e\x74\x78\x74", "\x77");
  fscanf(zb31d629842,
         "\x25\x64"
         "\n",
         &z152249f124);
  for (z833f788211 = (0xa50 + 6869 - 0x2525); z833f788211 < z152249f124;
       z833f788211++) {
    fgets(z29dc1ea72e, (0xd1b + 514 - 0xe9d), zb31d629842);
    fprintf(z1e81464274, "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
            z833f788211 + (0x1a71 + 2601 - 0x2499));
    for (z18c3051e3b = (0x830 + 1159 - 0xcb7);
         z29dc1ea72e[z18c3051e3b] != (0x1710 + 1082 - 0x1b4a); z18c3051e3b++)
      fputc(islower(z29dc1ea72e[z18c3051e3b])
                ? za02319e10e[z29dc1ea72e[z18c3051e3b] -
                              ((char)(0x77c + 153 - 0x7b4))]
                : z29dc1ea72e[z18c3051e3b],
            z1e81464274);
  }
  fclose(zb31d629842);
  fclose(z1e81464274);
  return (0xb69 + 5208 - 0x1fc1);
}
