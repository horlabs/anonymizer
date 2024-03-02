
#include <stdio.h>
#include <string.h>

int main() {
  int z48843972be, z03b9d40450, z14aeb74861, z48735cb06f;
  char za452f32312[(0x950 + 193 - 0x9f7)] = {
      "\x79\x68\x65\x73\x6f\x63\x76\x78\x64\x75\x69\x67\x6c\x62\x6b\x72\x7a\x74"
      "\x6e\x77\x6a\x70\x66\x6d\x61\x71"};
  char z80d3b351b5[(0x66d + 772 - 0x903)];
  scanf("\x25\x64\x25\x2a\x63", &z48843972be);
  for (z14aeb74861 = (0x92 + 3233 - 0xd33); z14aeb74861 < z48843972be;
       z14aeb74861++) {
    fgets(z80d3b351b5, (0x1328 + 3925 - 0x2214), stdin);
    z03b9d40450 = strlen(z80d3b351b5);
    z80d3b351b5[z03b9d40450 - (0x970 + 5781 - 0x2004)] = '\0';
    z03b9d40450--;
    for (z48735cb06f = (0x2e3 + 5111 - 0x16da); z48735cb06f < z03b9d40450;
         z48735cb06f++) {
      if (z80d3b351b5[z48735cb06f] == ((char)(0xb13 + 7017 - 0x265c)))
        continue;
      z80d3b351b5[z48735cb06f] =
          za452f32312[z80d3b351b5[z48735cb06f] - ((char)(0xd6d + 566 - 0xf42))];
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
           "\n",
           z14aeb74861 + (0x337 + 2258 - 0xc08), z80d3b351b5);
  }
  return (0x47d + 2926 - 0xfeb);
}
