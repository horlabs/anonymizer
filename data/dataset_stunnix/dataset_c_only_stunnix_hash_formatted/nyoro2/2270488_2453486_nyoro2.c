
#include <stdio.h>

int main() {
  int z7033a60d34;
  int zc074a68bf1;
  int z27e8d698f6, zb08f8fa7a1;
  int za69a070dd3[(0x23 + 1896 - 0x787)][(0x1c19 + 1238 - 0x20eb)];
  char z9bbe566546[(0x12a + 3616 - 0xf42)];
  int z9831a99a72;
  int z7ce103fd3e;
  int zf5ed3eb82c[(0xa70 + 1337 - 0xf9f)];
  int zc07d669905;
  fscanf(stdin,
         "\x25\x64"
         "\n",
         &z7033a60d34);
  for (zc074a68bf1 = (0x78 + 4799 - 0x1337); zc074a68bf1 < z7033a60d34;
       zc074a68bf1++) {
    zc07d669905 = (0x1508 + 1462 - 0x1abe);
    for (zb08f8fa7a1 = (0x1611 + 354 - 0x1773);
         zb08f8fa7a1 < (0x131 + 4862 - 0x142b); zb08f8fa7a1++) {
      fgets(z9bbe566546, sizeof(z9bbe566546), stdin);
      for (z27e8d698f6 = (0x1282 + 1725 - 0x193f);
           z27e8d698f6 < (0x14f2 + 2862 - 0x201c); z27e8d698f6++) {
        switch (z9bbe566546[z27e8d698f6]) {
        case ((char)(0x4d8 + 5286 - 0x192f)):
          za69a070dd3[zb08f8fa7a1][z27e8d698f6] = (0x1a9b + 403 - 0x1c2d);
          break;
        case ((char)(0xaa1 + 3480 - 0x17e1)):
          za69a070dd3[zb08f8fa7a1][z27e8d698f6] = (0xe55 + 5968 - 0x25a3);
          break;
        case ((char)(0x17ad + 3235 - 0x23fc)):
          za69a070dd3[zb08f8fa7a1][z27e8d698f6] = (0x2465 + 640 - 0x26e2);
          break;
        default:
          za69a070dd3[zb08f8fa7a1][z27e8d698f6] = (0x16d3 + 1951 - 0x1e72);
          zc07d669905 = (0x1a71 + 2834 - 0x2582);
          break;
        }
      }
    }
    fgets(z9bbe566546, sizeof(z9bbe566546), stdin);
    for (z7ce103fd3e = (0x6c4 + 889 - 0xa3d);
         z7ce103fd3e < (0x41f + 1892 - 0xb79); z7ce103fd3e++)
      zf5ed3eb82c[z7ce103fd3e] = (0xad1 + 2247 - 0x1395);
    for (zb08f8fa7a1 = (0x497 + 2741 - 0xf4c);
         zb08f8fa7a1 < (0xdc7 + 6000 - 0x2533); zb08f8fa7a1++) {
      for (z27e8d698f6 = (0x1e13 + 46 - 0x1e41);
           z27e8d698f6 < (0x598 + 3407 - 0x12e3); z27e8d698f6++) {
        zf5ed3eb82c[zb08f8fa7a1] &= za69a070dd3[zb08f8fa7a1][z27e8d698f6];
        zf5ed3eb82c[zb08f8fa7a1 + (0x7f7 + 2603 - 0x121e)] &=
            za69a070dd3[z27e8d698f6][zb08f8fa7a1];
      }
      zf5ed3eb82c[(0x308 + 8280 - 0x2358)] &=
          za69a070dd3[zb08f8fa7a1][zb08f8fa7a1];
      zf5ed3eb82c[(0x131c + 327 - 0x145a)] &=
          za69a070dd3[zb08f8fa7a1][(0x913 + 2365 - 0x124d) - zb08f8fa7a1];
    }
    z9831a99a72 = (0x2270 + 490 - 0x245a);
    for (z7ce103fd3e = (0xd31 + 4743 - 0x1fb8);
         z7ce103fd3e < (0x406 + 7745 - 0x223d); z7ce103fd3e++) {
      z9831a99a72 |= zf5ed3eb82c[z7ce103fd3e];
    }
    fprintf(stdout, "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
            zc074a68bf1 + (0x131c + 4601 - 0x2514));
    if (z9831a99a72 & (0xd55 + 2037 - 0x1549)) {
      fprintf(stdout, "\x4f\x20\x77\x6f\x6e");
    } else if (z9831a99a72 & (0x162 + 6270 - 0x19de)) {
      fprintf(stdout, "\x58\x20\x77\x6f\x6e");
    } else if (zc07d669905) {
      fprintf(stdout, "\x47\x61\x6d\x65\x20\x68\x61\x73\x20\x6e\x6f\x74\x20\x63"
                      "\x6f\x6d\x70\x6c\x65\x74\x65\x64");
    } else {
      fprintf(stdout, "\x44\x72\x61\x77");
    }
    fprintf(stdout, "\n");
  }
  return (0x8ff + 2287 - 0x11ee);
}
