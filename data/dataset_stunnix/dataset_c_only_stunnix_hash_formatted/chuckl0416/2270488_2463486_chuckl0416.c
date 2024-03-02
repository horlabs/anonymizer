
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int z4c46861b14, zab0be65738;
int z29494bcefd, z68754d3b08, zc722ce12be, zef47bd12c8;
int zf4eb7e8980[(0x1805 + 2257 - 0x20cc)] = {
    (0x1aa2 + 176 - 0x1b51),  (0x13a0 + 3713 - 0x221d),
    (0x1061 + 3770 - 0x1f12), (0x13a8 + 3156 - 0x1f83),
    (0xdff + 2932 - 0x178f),  (0x1eeb + 2940 - 0x25b7)};
int main() {
  freopen("\x43\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x69\x6e",
          "\x72", stdin);
  freopen("\x43\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x6f\x75\x74",
          "\x77", stdout);
  scanf("\x25\x64", &z4c46861b14);
  for (zab0be65738 = (0x959 + 5010 - 0x1cea); zab0be65738 <= z4c46861b14;
       zab0be65738++) {
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", zab0be65738);
    scanf("\x25\x64\x25\x64", &z29494bcefd, &z68754d3b08);
    for (zc722ce12be = (0x997 + 6986 - 0x24e1);
         zf4eb7e8980[zc722ce12be] < z29494bcefd; zc722ce12be++)
      ;
    for (zef47bd12c8 = zc722ce12be; zf4eb7e8980[zef47bd12c8] <= z68754d3b08;
         zef47bd12c8++)
      ;
    printf("\x25\x64"
           "\n",
           zef47bd12c8 - zc722ce12be);
  }
  return (0x59a + 672 - 0x83a);
}
