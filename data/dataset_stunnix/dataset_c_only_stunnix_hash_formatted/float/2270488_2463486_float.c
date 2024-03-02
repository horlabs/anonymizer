
#include <stdio.h>
#include <string.h>

int main() {
  int z41b9959919[(0xe60 + 3629 - 0x188d)],
      z8b4795de36[(0x1b0b + 1847 - 0x1e42)];
  int zc94738b3b1, z1121ddfd80, zb1126f35af, z51ab95e2b9, z4a7fc8a56f;
  memset(z41b9959919, sizeof(z41b9959919), (0x1a1a + 815 - 0x1d49));
  memset(z8b4795de36, sizeof(z8b4795de36), (0x1c5d + 20 - 0x1c71));
  z41b9959919[(0x8cb + 4500 - 0x1a5e)] = (0x1d1 + 6487 - 0x1b27);
  z41b9959919[(0xa80 + 105 - 0xae5)] = (0x28d + 1641 - 0x8f5);
  z41b9959919[(0x170c + 148 - 0x1797)] = (0x5b4 + 2399 - 0xf12);
  z41b9959919[(0xf68 + 5596 - 0x24cb)] = (0x1819 + 188 - 0x18d4);
  z41b9959919[(0xe18 + 3008 - 0x17f4)] = (0x82c + 1112 - 0xc83);
  for (zb1126f35af = (0x158a + 2659 - 0x1fec);
       zb1126f35af < (0x10a6 + 3875 - 0x1bc9); zb1126f35af++)
    z8b4795de36[zb1126f35af] =
        z8b4795de36[zb1126f35af - (0x1ea5 + 335 - 0x1ff3)] +
        z41b9959919[zb1126f35af];
  scanf("\x25\x64", &zc94738b3b1);
  for (z1121ddfd80 = (0x1cf3 + 979 - 0x20c5); z1121ddfd80 <= zc94738b3b1;
       z1121ddfd80++) {
    scanf("\x25\x64\x20\x25\x64", &z51ab95e2b9, &z4a7fc8a56f);
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z1121ddfd80,
           z8b4795de36[z4a7fc8a56f] -
               z8b4795de36[z51ab95e2b9 - (0x55a + 3235 - 0x11fc)]);
  }
  return (0xa28 + 81 - 0xa79);
}
