
#include <stdio.h>

char zb6f757a955[] = "\x79\x68\x65\x73\x6f\x63\x76\x78\x64\x75\x69\x67\x6c\x62"
                     "\x6b\x72\x7a\x74\x6e\x77\x6a\x70\x66\x6d\x61\x71";
int main() {
  int z5014140921;
  scanf("\x25\x64\x20", &z5014140921);
  for (int z154ad18727 = (0x17c0 + 2148 - 0x2023); z154ad18727 <= z5014140921;
       z154ad18727++) {
    char zbc7de00674[(0xe23 + 160 - 0xe5e)];
    gets(zbc7de00674);
    for (int z5c49acab93 = (0xbdb + 2025 - 0x13c4); zbc7de00674[z5c49acab93];
         z5c49acab93++)
      if (zbc7de00674[z5c49acab93] >= ((char)(0x1101 + 5708 - 0x26ec)) &&
          zbc7de00674[z5c49acab93] <= ((char)(0x5a6 + 6363 - 0x1e07)))
        zbc7de00674[z5c49acab93] = zb6f757a955[zbc7de00674[z5c49acab93] -
                                               ((char)(0x768 + 6328 - 0x1fbf))];
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
           "\n",
           z154ad18727, zbc7de00674);
  }
  return (0x1a55 + 342 - 0x1bab);
}
