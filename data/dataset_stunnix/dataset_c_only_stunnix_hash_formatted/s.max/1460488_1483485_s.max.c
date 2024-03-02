
#include <stdio.h>

int main() {
  char z2b27372bfd[(0x1934 + 1502 - 0x1ee0)] =
      "\x79\x68\x65\x73\x6f\x63\x76\x78\x64\x75\x69\x67\x6c\x62\x6b\x72\x7a\x74"
      "\x6e\x77\x6a\x70\x66\x6d\x61\x71";
  char z6b69ba9ec4[(0x1b4f + 3190 - 0x23dd)];
  int zbf32acbbbe, z46ff536865;
  fgets(z6b69ba9ec4, (0x11b9 + 478 - 0xfaf), stdin);
  sscanf(z6b69ba9ec4, "\x25\x64", &zbf32acbbbe);
  for (z46ff536865 = (0x717 + 7573 - 0x24ab); z46ff536865 <= zbf32acbbbe;
       z46ff536865++) {
    int z69666d3d3b;
    fgets(z6b69ba9ec4, (0x133a + 2871 - 0x1a89), stdin);
    for (z69666d3d3b = (0x2643 + 189 - 0x2700); z6b69ba9ec4[z69666d3d3b];
         z69666d3d3b++)
      if (z6b69ba9ec4[z69666d3d3b] != ((char)(0x14dd + 4499 - 0x2650)) &&
          z6b69ba9ec4[z69666d3d3b] != '\n')
        z6b69ba9ec4[z69666d3d3b] = z2b27372bfd[z6b69ba9ec4[z69666d3d3b] -
                                               ((char)(0x556 + 4291 - 0x15b8))];
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73", z46ff536865,
           z6b69ba9ec4);
  }
  return (0xbe2 + 5175 - 0x2019);
}
