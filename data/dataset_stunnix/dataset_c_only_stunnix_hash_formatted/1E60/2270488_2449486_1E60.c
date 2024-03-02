
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int z050edf4278, char **zf7f3c5c8f0) {
  int z163481ccfa, zc283efbf71;
  int z4547aa10ea, z4e11bb3ba3;
  int x, y;
  scanf("\x25\x64"
        "\n",
        &zc283efbf71);
  for (z163481ccfa = (0xf71 + 4023 - 0x1f27); z163481ccfa <= zc283efbf71;
       z163481ccfa++) {
    scanf("\x25\x64\x20\x25\x64"
          "\n",
          &z4e11bb3ba3, &z4547aa10ea);
    int z16ef6af5d2[z4547aa10ea][z4e11bb3ba3],
        zccb4bd82c0[z4547aa10ea][z4e11bb3ba3];
    for (y = (0x1c10 + 1204 - 0x20c4); y < z4e11bb3ba3; y++) {
      for (x = (0x1c4 + 6224 - 0x1a14); x < z4547aa10ea; x++) {
        scanf("\x25\x64\x20", &z16ef6af5d2[x][y]);
        zccb4bd82c0[x][y] = (0xb4a + 6534 - 0x246c);
      }
    }
    for (y = (0xec5 + 3572 - 0x1cb9); y < z4e11bb3ba3; y++) {
      int ze2901672d4 = (0x122 + 4412 - 0x125e);
      for (x = (0xdfa + 5995 - 0x2565); x < z4547aa10ea; x++) {
        if (ze2901672d4 < z16ef6af5d2[x][y]) {
          ze2901672d4 = z16ef6af5d2[x][y];
        }
      }
      for (x = (0x105c + 4432 - 0x21ac); x < z4547aa10ea; x++) {
        if (ze2901672d4 < zccb4bd82c0[x][y]) {
          zccb4bd82c0[x][y] = ze2901672d4;
        }
      }
    }
    for (x = (0xb56 + 4722 - 0x1dc8); x < z4547aa10ea; x++) {
      int ze2901672d4 = (0x12cd + 2416 - 0x1c3d);
      for (y = (0x1ed7 + 1975 - 0x268e); y < z4e11bb3ba3; y++) {
        if (ze2901672d4 < z16ef6af5d2[x][y]) {
          ze2901672d4 = z16ef6af5d2[x][y];
        }
      }
      for (y = (0x1fb9 + 800 - 0x22d9); y < z4e11bb3ba3; y++) {
        if (ze2901672d4 < zccb4bd82c0[x][y]) {
          zccb4bd82c0[x][y] = ze2901672d4;
        }
      }
    }
    int za92f88d110 = (0xb13 + 1592 - 0x114a);
    for (y = (0x118b + 3362 - 0x1ead); y < z4e11bb3ba3; y++) {
      for (x = (0x206 + 7134 - 0x1de4); x < z4547aa10ea; x++) {
        if (zccb4bd82c0[x][y] != z16ef6af5d2[x][y])
          za92f88d110 = (0x8b5 + 5044 - 0x1c69);
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
           "\n",
           z163481ccfa, (za92f88d110) ? "\x59\x45\x53" : "\x4e\x4f");
  }
  return (0x89d + 715 - 0xb68);
}
