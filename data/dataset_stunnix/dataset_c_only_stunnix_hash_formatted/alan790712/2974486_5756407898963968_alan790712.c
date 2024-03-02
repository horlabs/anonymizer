
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int z1831ad414b, z5fcab70dc7;
int z87d3033a5c[(0x10ec + 859 - 0x1445)][(0x51f + 6964 - 0x204e)];
int z3e9348e7ca[(0x1a70 + 2957 - 0x25fb)];
int main() {
  int zffeb45659f, z18bc6ae7c1, z210680be09;
  int zac0e1c9ffc;
  scanf("\x25\x64", &z5fcab70dc7);
  for (z1831ad414b = (0xfe0 + 2967 - 0x1b76); z1831ad414b <= z5fcab70dc7;
       ++z1831ad414b) {
    for (zffeb45659f = (0x39b + 7657 - 0x2184);
         zffeb45659f < (0x15b2 + 4040 - 0x2578); ++zffeb45659f) {
      scanf("\x25\x64", &z3e9348e7ca[zffeb45659f]);
      for (z18bc6ae7c1 = (0x1001 + 5604 - 0x25e4);
           z18bc6ae7c1 <= (0xaad + 4038 - 0x1a6f); ++z18bc6ae7c1) {
        for (z210680be09 = (0x1c5 + 5531 - 0x175f);
             z210680be09 <= (0xd86 + 6480 - 0x26d2); ++z210680be09) {
          if (z18bc6ae7c1 == z3e9348e7ca[zffeb45659f])
            scanf("\x25\x64", &z87d3033a5c[zffeb45659f][z210680be09]);
          else
            scanf("\x25\x2a\x64");
        }
      }
    }
    for (zffeb45659f = (0xf28 + 5154 - 0x2349),
        zac0e1c9ffc = -(0x3ac + 4764 - 0x1647);
         zffeb45659f <= (0x6d + 762 - 0x363); ++zffeb45659f) {
      for (z18bc6ae7c1 = (0x21cc + 722 - 0x249d);
           z18bc6ae7c1 <= (0x155f + 2194 - 0x1ded); ++z18bc6ae7c1) {
        if (z87d3033a5c[(0x23d0 + 678 - 0x2676)][zffeb45659f] ==
            z87d3033a5c[(0x218 + 7220 - 0x1e4b)][z18bc6ae7c1]) {
          if (zac0e1c9ffc == -(0xe86 + 4121 - 0x1e9e)) {
            zac0e1c9ffc = z87d3033a5c[(0x1055 + 582 - 0x129b)][zffeb45659f];
          } else {
            break;
          }
        }
      }
      if (z18bc6ae7c1 <= (0xc3c + 2580 - 0x164c))
        break;
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", z1831ad414b);
    if (zac0e1c9ffc != -(0x774 + 1803 - 0xe7e) &&
        zffeb45659f > (0xc94 + 3921 - 0x1be1)) {
      printf("\x25\x64"
             "\n",
             zac0e1c9ffc);
    } else if (zac0e1c9ffc != -(0xf36 + 5883 - 0x2630) &&
               zffeb45659f <= (0x2f1 + 6798 - 0x1d7b)) {
      printf("\x42\x61\x64\x20\x6d\x61\x67\x69\x63\x69\x61\x6e\x21"
             "\n");
    } else {
      printf("\x56\x6f\x6c\x75\x6e\x74\x65\x65\x72\x20\x63\x68\x65\x61\x74\x65"
             "\x64\x21"
             "\n");
    }
  }
  return (0x3dc + 643 - 0x65f);
}
