
#include <stdio.h>
#include <string.h>

int main() {
  int zf239e3d5fe, z556565fe33 = (0x1e42 + 76 - 0x1e8e);
  for (scanf("\x25\x64", &zf239e3d5fe); zf239e3d5fe; zf239e3d5fe--) {
    int z0d7ed61242, z334e1556a5;
    static int z9ada061905[(0x1822 + 1028 - 0x1c22)][(0xb97 + 4360 - 0x1c9b)],
        ze852fb9397[(0xe2d + 3127 - 0x1a60)][(0x8db + 426 - 0xa81)];
    static int zcad17ba5f9[(0x89c + 6762 - 0x22f6)];
    int z703a425abe;
    int z8f9ef67f32;
    scanf("\x25\x64", &z0d7ed61242);
    for (z8f9ef67f32 = (0x122f + 2833 - 0x1d40);
         z8f9ef67f32 < (0x4f7 + 6369 - 0x1dd4); z8f9ef67f32++) {
      int z1f2451816b;
      for (z1f2451816b = (0x45a + 2271 - 0xd39);
           z1f2451816b < (0xa54 + 506 - 0xc4a); z1f2451816b++) {
        scanf("\x25\x64", z9ada061905[z8f9ef67f32] + z1f2451816b);
      }
    }
    scanf("\x25\x64", &z334e1556a5);
    for (z8f9ef67f32 = (0x6b8 + 4495 - 0x1847);
         z8f9ef67f32 < (0x1246 + 374 - 0x13b8); z8f9ef67f32++) {
      int z1f2451816b;
      for (z1f2451816b = (0x416 + 4826 - 0x16f0);
           z1f2451816b < (0x5e3 + 740 - 0x8c3); z1f2451816b++) {
        scanf("\x25\x64", ze852fb9397[z8f9ef67f32] + z1f2451816b);
      }
    }
    memset(zcad17ba5f9, (0x151 + 778 - 0x45b), sizeof(zcad17ba5f9));
    for (z8f9ef67f32 = (0x1c65 + 2726 - 0x270b);
         z8f9ef67f32 < (0x12ab + 3513 - 0x2060); z8f9ef67f32++) {
      zcad17ba5f9[z9ada061905[z0d7ed61242 - (0x91d + 4966 - 0x1c82)]
                             [z8f9ef67f32] -
                  (0x45f + 7514 - 0x21b8)]++;
      zcad17ba5f9[ze852fb9397[z334e1556a5 - (0x267b + 26 - 0x2694)]
                             [z8f9ef67f32] -
                  (0x2140 + 1002 - 0x2529)]++;
    }
    z703a425abe = -(0xb8a + 6476 - 0x24d5);
    for (z8f9ef67f32 = (0x1223 + 5203 - 0x2676);
         z8f9ef67f32 < (0x200f + 987 - 0x23da); z8f9ef67f32++) {
      if (zcad17ba5f9[z8f9ef67f32] == (0x92a + 1303 - 0xe3f)) {
        if (z703a425abe != -(0x11f3 + 2688 - 0x1c72)) {
          z703a425abe = -(0x349 + 6269 - 0x1bc4);
          break;
        }
        z703a425abe = z8f9ef67f32;
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", ++z556565fe33);
    if (z703a425abe == -(0xa96 + 2637 - 0x14e2))
      puts("\x56\x6f\x6c\x75\x6e\x74\x65\x65\x72\x20\x63\x68\x65\x61\x74\x65"
           "\x64\x21");
    else if (z703a425abe == -(0x26f + 3573 - 0x1062))
      puts("\x42\x61\x64\x20\x6d\x61\x67\x69\x63\x69\x61\x6e\x21");
    else
      printf("\x25\x64"
             "\n",
             z703a425abe + (0x980 + 7398 - 0x2665));
  }
  return (0x1270 + 4257 - 0x2311);
}
