
#include <stdio.h>

int x[(0x4f8 + 6899 - 0x1fd1)] = {
    (0x149d + 1241 - 0x195e), (0xa6d + 4056 - 0x1a3e),
    (0x134 + 3710 - 0xfae),   (0x47a + 5485 - 0x19d5),
    (0x690 + 7895 - 0x2559),  (0x1dcd + 996 - 0x21af),
    (0x391 + 3593 - 0x1185),  (0x1a8 + 5725 - 0x17ee),
    (0x9af + 1925 - 0x1131),  (0x1cc2 + 544 - 0x1ece),
    (0x17df + 1935 - 0x1f66), (0x1446 + 1813 - 0x1b55),
    (0x6c6 + 4422 - 0x1801),  (0xbb2 + 1341 - 0x10ee),
    (0x3f0 + 8096 - 0x2386),  (0x16a0 + 586 - 0x18d9),
    (0x132a + 5080 - 0x26e9), (0x938 + 6060 - 0x20d1),
    (0x712 + 5309 - 0x1bc2),  (0xf76 + 1700 - 0x1604),
    (0xaf1 + 5233 - 0x1f59),  (0x6d5 + 7757 - 0x2513),
    (0xcd3 + 311 - 0xe05),    (0x932 + 4899 - 0x1c49),
    (0x1e32 + 566 - 0x2068),  (0x1931 + 2353 - 0x2252)};
char z335ed284c5[(0xe8d + 118 - 0xe3b)];
int main() {
  freopen("\x41\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x69\x6e",
          "\x72", stdin);
  freopen("\x41\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x6f\x75\x74",
          "\x77", stdout);
  int zf49610a412, zdaaffae5e3, z560be1719a;
  scanf("\x25\x64", &zdaaffae5e3);
  getchar();
  for (zf49610a412 = (0x414 + 8552 - 0x257b); zf49610a412 <= zdaaffae5e3;
       zf49610a412++) {
    gets(z335ed284c5);
    for (z560be1719a = (0x1bdf + 347 - 0x1d3a);
         z335ed284c5[z560be1719a] != (0xe08 + 55 - 0xe3f); z560be1719a++) {
      if (z335ed284c5[z560be1719a] == ((char)(0x8a + 9485 - 0x2577)))
        continue;
      z335ed284c5[z560be1719a] =
          x[z335ed284c5[z560be1719a] - ((char)(0x16e5 + 3107 - 0x22a7))] +
          ((char)(0x6e8 + 8286 - 0x26e5));
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
           "\n",
           zf49610a412, z335ed284c5);
  }
}
