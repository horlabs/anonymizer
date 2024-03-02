
#include <stdio.h>

char z953c336e54[] = {
    ((char)(0x71f + 8017 - 0x25f7)),  ((char)(0x37d + 3374 - 0x1043)),
    ((char)(0x1af + 7358 - 0x1e08)),  ((char)(0x181 + 6363 - 0x19e9)),
    ((char)(0xa10 + 968 - 0xd69)),    ((char)(0x256 + 4073 - 0x11dc)),
    ((char)(0x4cb + 4849 - 0x1746)),  ((char)(0x1e17 + 340 - 0x1ef3)),
    ((char)(0xb0a + 4361 - 0x1baf)),  ((char)(0x228f + 198 - 0x22e0)),
    ((char)(0xa48 + 4133 - 0x1a04)),  ((char)(0x1878 + 1644 - 0x1e7d)),
    ((char)(0x1ea5 + 1161 - 0x22c2)), ((char)(0x1f04 + 1236 - 0x2376)),
    ((char)(0x1f1d + 1588 - 0x24e6)), ((char)(0xb5d + 3946 - 0x1a55)),
    ((char)(0x30b + 7410 - 0x1f83)),  ((char)(0x79c + 4704 - 0x1988)),
    ((char)(0x6c9 + 806 - 0x981)),    ((char)(0xc05 + 473 - 0xd67)),
    ((char)(0x2f4 + 5266 - 0x171c)),  ((char)(0x5d4 + 5029 - 0x1909)),
    ((char)(0x433 + 4629 - 0x15e2)),  ((char)(0x1c55 + 515 - 0x1deb)),
    ((char)(0x1506 + 864 - 0x1805)),  ((char)(0x335 + 886 - 0x63a))};
int main() {
  int zb83e0d57b8;
  int z1294881b43;
  char zed3c6b1e79[(0x6e7 + 1580 - 0xc93)];
  char *z46dd29b101;
  fscanf(stdin,
         "\x25\x64"
         "\n",
         &zb83e0d57b8);
  for (z1294881b43 = (0xb11 + 2705 - 0x15a2); z1294881b43 < zb83e0d57b8;
       z1294881b43++) {
    fgets(zed3c6b1e79, (0x48f + 375 - 0x58e), stdin);
    fprintf(stdout, "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
            z1294881b43 + (0xfe6 + 2985 - 0x1b8e));
    z46dd29b101 = zed3c6b1e79;
    while (*z46dd29b101) {
      if (*z46dd29b101 == ((char)(0x17f5 + 455 - 0x199c)))
        fprintf(stdout, "\x20");
      else if ((*z46dd29b101 >= ((char)(0x2f5 + 7482 - 0x1fce))) &&
               (*z46dd29b101 <= ((char)(0x3e4 + 5254 - 0x17f0)))) {
        fprintf(stdout, "\x25\x63",
                z953c336e54[*z46dd29b101 - ((char)(0xaf5 + 3442 - 0x1806))]);
      }
      z46dd29b101++;
    }
    fprintf(stdout, "\n");
  }
  return (0x177 + 8784 - 0x23c7);
}
