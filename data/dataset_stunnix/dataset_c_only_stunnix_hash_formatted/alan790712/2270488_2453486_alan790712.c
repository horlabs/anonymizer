
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char z3223996e5a[(0x1c57 + 60 - 0x1c18)][(0x585 + 6981 - 0x204f)];
int X, zce972d3797;
int x, za7822349d6;
void z567ff07a37(int z2db97c0655, int z66e4ef80e1) {
  if (z3223996e5a[z2db97c0655][z66e4ef80e1] ==
      ((char)(0x291 + 9285 - 0x2687))) {
    ++za7822349d6, x = -(0x1126 + 3987 - 0x1cd1);
  } else if (z3223996e5a[z2db97c0655][z66e4ef80e1] ==
             ((char)(0x2fd + 3840 - 0x11a5))) {
    ++x, za7822349d6 = -(0x1faf + 770 - 0x1ec9);
  } else if (z3223996e5a[z2db97c0655][z66e4ef80e1] ==
             ((char)(0x1999 + 3467 - 0x26d0))) {
    ++x, ++za7822349d6;
  }
}
void za14a282ad5() {
  if (x == (0x5ef + 6055 - 0x1d92))
    X = (0xd82 + 4908 - 0x20ac);
  if (za7822349d6 == (0x523 + 498 - 0x711))
    zce972d3797 = (0x1b63 + 2133 - 0x23b6);
  if (x >= (0x2c9 + 79 - 0x318))
    X |= (0x54f + 324 - 0x692);
  if (za7822349d6 >= (0x95f + 3679 - 0x17be))
    zce972d3797 |= (0xb54 + 1065 - 0xf7c);
}
int main() {
  int zddca9f6434, zd7a8fc00fe;
  int z2db97c0655, z66e4ef80e1;
  scanf("\x25\x64", &zd7a8fc00fe);
  for (zddca9f6434 = (0x640 + 4528 - 0x17ef); zddca9f6434 <= zd7a8fc00fe;
       ++zddca9f6434) {
    for (z2db97c0655 = (0x8a3 + 1566 - 0xec1);
         z2db97c0655 < (0x6ed + 4275 - 0x179c); ++z2db97c0655) {
      scanf("\x25\x73", z3223996e5a[z2db97c0655]);
    }
    X = zce972d3797 = (0x19c + 1523 - 0x78f);
    for (z2db97c0655 = (0x5b7 + 3499 - 0x1362);
         z2db97c0655 < (0x9d7 + 4560 - 0x1ba3); ++z2db97c0655) {
      for (z66e4ef80e1 = x = za7822349d6 = (0x8ef + 3307 - 0x15da);
           z66e4ef80e1 < (0x167a + 86 - 0x16cc); ++z66e4ef80e1) {
        z567ff07a37(z2db97c0655, z66e4ef80e1);
      }
      za14a282ad5();
    }
    for (z2db97c0655 = (0x38a + 7455 - 0x20a9);
         z2db97c0655 < (0xf6d + 1043 - 0x137c); ++z2db97c0655) {
      for (z66e4ef80e1 = x = za7822349d6 = (0x1047 + 5306 - 0x2501);
           z66e4ef80e1 < (0x639 + 5119 - 0x1a34); ++z66e4ef80e1) {
        z567ff07a37(z66e4ef80e1, z2db97c0655);
      }
      za14a282ad5();
    }
    for (z2db97c0655 = z66e4ef80e1 = x = za7822349d6 = (0x915 + 475 - 0xaf0);
         z2db97c0655 < (0xf44 + 1259 - 0x142b); ++z2db97c0655, ++z66e4ef80e1) {
      z567ff07a37(z66e4ef80e1, z2db97c0655);
    }
    za14a282ad5();
    for (z2db97c0655 = (0x3c4 + 3082 - 0xfcb),
        z66e4ef80e1 = x = za7822349d6 = (0x231 + 4513 - 0x13d2);
         z66e4ef80e1 < (0x1616 + 1864 - 0x1d5a); --z2db97c0655, ++z66e4ef80e1) {
      z567ff07a37(z66e4ef80e1, z2db97c0655);
    }
    za14a282ad5();
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", zddca9f6434);
    if (X >= (0xa81 + 4325 - 0x1b64))
      puts("\x58\x20\x77\x6f\x6e");
    if (zce972d3797 >= (0xed7 + 4228 - 0x1f59))
      puts("\x4f\x20\x77\x6f\x6e");
    if (X == (0x260 + 2829 - 0xd6c) && zce972d3797 == (0x147a + 2931 - 0x1fec))
      puts("\x47\x61\x6d\x65\x20\x68\x61\x73\x20\x6e\x6f\x74\x20\x63\x6f\x6d"
           "\x70\x6c\x65\x74\x65\x64");
    if (X == (0xbcc + 5938 - 0x22fe) && zce972d3797 == (0xdf5 + 2937 - 0x196e))
      puts("\x44\x72\x61\x77");
  }
  return (0x933 + 431 - 0xae2);
}
