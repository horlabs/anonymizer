
#include <stdio.h>

int main() {
  int zb768582649, z235b403c45, zcad896a4a9, z0f83eb2d2b, z5f1928aa09,
      zfd10fa567f, z932eec1e0c;
  int z623199b044[(0x5a0 + 2438 - 0xec2)] = {(0x408 + 1638 - 0xa6e)};
  int z06660f2700;
  int z08eedbcd4d;
  scanf("\x25\x64", &zb768582649);
  for (z235b403c45 = (0x1300 + 3514 - 0x20ba); z235b403c45 < zb768582649;
       z235b403c45++) {
    scanf("\x25\x64", &z0f83eb2d2b);
    scanf("\x25\x64", &z5f1928aa09);
    scanf("\x25\x64", &zfd10fa567f);
    for (zcad896a4a9 = (0x1460 + 67 - 0x14a3); zcad896a4a9 < z0f83eb2d2b;
         zcad896a4a9++) {
      scanf("\x25\x64", &z932eec1e0c);
      z06660f2700 = z932eec1e0c / (0x669 + 211 - 0x739);
      z08eedbcd4d = z932eec1e0c % (0x587 + 4613 - 0x1789);
      if (z06660f2700 == (0x1724 + 1936 - 0x1eb4) &&
          z08eedbcd4d == (0x1630 + 368 - 0x17a0) &&
          zfd10fa567f != (0xd1a + 612 - 0xf7e))
        continue;
      if (z06660f2700 >= zfd10fa567f)
        z623199b044[z235b403c45]++;
      else if (z08eedbcd4d == (0x1673 + 3860 - 0x2587) &&
               z5f1928aa09 > (0x185d + 2356 - 0x2191) &&
               z06660f2700 + (0x9df + 6128 - 0x21ce) >= zfd10fa567f &&
               z06660f2700 + (0x1299 + 3870 - 0x21b6) <=
                   (0xb7a + 2482 - 0x1522)) {
        z623199b044[z235b403c45]++;
        z5f1928aa09--;
      } else if (z08eedbcd4d == (0x210c + 1430 - 0x26a1) &&
                 z06660f2700 + (0x1f3b + 1935 - 0x26c9) >= zfd10fa567f &&
                 z06660f2700 + (0xf12 + 2027 - 0x16fc) <=
                     (0x1c0 + 2898 - 0xd08)) {
        z623199b044[z235b403c45]++;
      } else if (z08eedbcd4d == (0xff1 + 371 - 0x1162)) {
        if (z06660f2700 + (0x69c + 5660 - 0x1cb7) >= zfd10fa567f)
          z623199b044[z235b403c45]++;
        else if (z5f1928aa09 > (0x6a1 + 7817 - 0x252a) &&
                 z06660f2700 + (0x1dc + 3886 - 0x1108) >= zfd10fa567f &&
                 z06660f2700 + (0x789 + 3533 - 0x1554) <=
                     (0x6f0 + 2317 - 0xff3)) {
          z5f1928aa09--;
          z623199b044[z235b403c45]++;
        }
      }
    }
  }
  for (z235b403c45 = (0x1032 + 2553 - 0x1a2b); z235b403c45 < zb768582649;
       z235b403c45++) {
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z235b403c45 + (0x158a + 3256 - 0x2241), z623199b044[z235b403c45]);
  }
}
