
#include <stdio.h>

char z253d4e0d07[(0x18c7 + 2681 - 0x233a)][(0x1081 + 3239 - 0x1d22)];
int z5eb2832ddc(int x, int y, int zd3896201c7, int z55fa0fc0b9,
                char z92e512a2f5) {
  int z2f60cb43a0, z881c714276;
  for (z881c714276 = z2f60cb43a0 = (0x1f97 + 682 - 0x2241);
       z2f60cb43a0 < (0x5b4 + 8312 - 0x2628); z2f60cb43a0++) {
    if (z253d4e0d07[x][y] == z92e512a2f5 ||
        z253d4e0d07[x][y] == ((char)(0xabc + 6599 - 0x242f)))
      z881c714276++;
    x += zd3896201c7;
    y += z55fa0fc0b9;
  }
  return z881c714276 == (0x10b4 + 1904 - 0x1820);
}
int z1c97efc3ed(char z92e512a2f5) {
  int z2f60cb43a0;
  for (z2f60cb43a0 = (0x1c75 + 2347 - 0x25a0);
       z2f60cb43a0 < (0x1413 + 2567 - 0x1e16); z2f60cb43a0++) {
    if (z5eb2832ddc((0x5dc + 564 - 0x810), z2f60cb43a0, (0x228 + 8515 - 0x236a),
                    (0x215c + 1145 - 0x25d5), z92e512a2f5))
      return (0x1dff + 544 - 0x201e);
    if (z5eb2832ddc(z2f60cb43a0, (0xe4 + 8702 - 0x22e2),
                    (0xad4 + 5941 - 0x2209), (0x731 + 7223 - 0x2367),
                    z92e512a2f5))
      return (0x11a8 + 3902 - 0x20e5);
  }
  if (z5eb2832ddc((0x31b + 1878 - 0xa71), (0xc66 + 2181 - 0x14eb),
                  (0x1b7a + 2380 - 0x24c5), (0x1090 + 3480 - 0x1e27),
                  z92e512a2f5))
    return (0xf00 + 5870 - 0x25ed);
  if (z5eb2832ddc((0xc7a + 5471 - 0x21d9), (0xc2d + 3707 - 0x1aa5),
                  (0x81a + 6933 - 0x232e), -(0x9e5 + 979 - 0xdb7), z92e512a2f5))
    return (0x16c2 + 3966 - 0x263f);
  return (0xa18 + 3018 - 0x15e2);
}
int main() {
  int z3635a10caf, z2f60cb43a0, ze91b64a369, ze817becf6e,
      zb5c04ecac2 = (0x1cb9 + 1563 - 0x22d3);
  scanf("\x25\x64", &z3635a10caf);
  while (z3635a10caf--) {
    for (z2f60cb43a0 = (0x1668 + 2570 - 0x2072);
         z2f60cb43a0 < (0x178 + 8905 - 0x243d); z2f60cb43a0++)
      scanf("\x25\x73", z253d4e0d07[z2f60cb43a0]);
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", zb5c04ecac2++);
    if (z1c97efc3ed(((char)(0x1d3f + 1439 - 0x228f))))
      puts("\x4f\x20\x77\x6f\x6e");
    else if (z1c97efc3ed(((char)(0x632 + 8445 - 0x26d7))))
      puts("\x58\x20\x77\x6f\x6e");
    else {
      for (z2f60cb43a0 = ze817becf6e = (0x98d + 1806 - 0x109b);
           z2f60cb43a0 < (0xc83 + 1436 - 0x121b); z2f60cb43a0++)
        for (ze91b64a369 = (0xf4b + 5367 - 0x2442);
             ze91b64a369 < (0x130d + 1810 - 0x1a1b); ze91b64a369++)
          if (z253d4e0d07[z2f60cb43a0][ze91b64a369] ==
              ((char)(0xc47 + 2378 - 0x1563)))
            ze817becf6e = (0x3e7 + 6018 - 0x1b68);
      if (ze817becf6e)
        puts("\x47\x61\x6d\x65\x20\x68\x61\x73\x20\x6e\x6f\x74\x20\x63\x6f\x6d"
             "\x70\x6c\x65\x74\x65\x64");
      else
        puts("\x44\x72\x61\x77");
    }
  }
  return (0x56c + 3154 - 0x11be);
}
