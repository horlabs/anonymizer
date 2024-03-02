
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char z04529119b4[(0xfd7 + 1472 - 0x158d)];
int z6161ffb5d4(int zca6e9ec82b) {
  int z1ae7cae96d, z99e9865bc6;
  sprintf(z04529119b4, "\x25\x64", zca6e9ec82b);
  z1ae7cae96d = strlen(z04529119b4) - (0xf71 + 5477 - 0x24d5);
  for (z99e9865bc6 = (0x139 + 3408 - 0xe89);
       z99e9865bc6 <= z1ae7cae96d - z99e9865bc6; ++z99e9865bc6) {
    if (z04529119b4[z99e9865bc6] != z04529119b4[z1ae7cae96d - z99e9865bc6])
      return (0x14f4 + 452 - 0x16b8);
  }
  return (0x1165 + 5131 - 0x256f);
}
int main(void) {
  int zf79930e448;
  int z8e34fdec2f, zbb6b7df2bb;
  int z861e20808d, zee81e0c168;
  int z99e9865bc6, za53bbed0b9, z63b5b3c815;
  int zc9787f4e07;
  scanf("\x25\x64", &zf79930e448);
  for (z99e9865bc6 = (0x6cb + 6232 - 0x1f22); z99e9865bc6 <= zf79930e448;
       ++z99e9865bc6) {
    scanf("\x25\x64\x20\x25\x64", &z8e34fdec2f, &zbb6b7df2bb);
    zc9787f4e07 = (0x1062 + 1466 - 0x161c);
    z861e20808d = (int)sqrt((double)z8e34fdec2f);
    zee81e0c168 = (int)sqrt((double)zbb6b7df2bb);
    for (za53bbed0b9 = z861e20808d; za53bbed0b9 <= zee81e0c168; ++za53bbed0b9) {
      if (z6161ffb5d4(za53bbed0b9)) {
        z63b5b3c815 = za53bbed0b9 * za53bbed0b9;
        if (z8e34fdec2f <= z63b5b3c815 && z63b5b3c815 <= zbb6b7df2bb &&
            z6161ffb5d4(z63b5b3c815)) {
          ++zc9787f4e07;
        }
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z99e9865bc6, zc9787f4e07);
  }
  return (0xedb + 4907 - 0x2206);
}
