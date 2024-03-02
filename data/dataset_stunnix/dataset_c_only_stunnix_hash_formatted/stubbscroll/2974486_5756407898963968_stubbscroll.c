
#include <stdio.h>

int z7ef7ea19b8[(0x37d + 2828 - 0xe85)][(0xcd6 + 4034 - 0x1c94)],
    z6eb136750d[(0x261 + 5730 - 0x18bf)][(0xb8c + 1149 - 0x1005)];
int z06223884be, z4f327fc3a3;
void z8f1d8c70f4() {
  int z7fbfa5c6ba, z8b3f7d285d, z370485a013 = -(0x10a5 + 67 - 0x10e7),
                                z05940590aa;
  scanf("\x25\x64", &z06223884be);
  for (z7fbfa5c6ba = (0x11da + 431 - 0x1389);
       z7fbfa5c6ba < (0x88c + 431 - 0xa37); z7fbfa5c6ba++)
    for (z8b3f7d285d = (0x16bc + 2269 - 0x1f99);
         z8b3f7d285d < (0x1136 + 4017 - 0x20e3); z8b3f7d285d++)
      scanf("\x25\x64", &z7ef7ea19b8[z7fbfa5c6ba][z8b3f7d285d]);
  scanf("\x25\x64", &z4f327fc3a3);
  for (z7fbfa5c6ba = (0xc39 + 47 - 0xc68);
       z7fbfa5c6ba < (0x9bd + 3115 - 0x15e4); z7fbfa5c6ba++)
    for (z8b3f7d285d = (0xa51 + 2857 - 0x157a);
         z8b3f7d285d < (0x1759 + 1354 - 0x1c9f); z8b3f7d285d++)
      scanf("\x25\x64", &z6eb136750d[z7fbfa5c6ba][z8b3f7d285d]);
  for (z05940590aa = (0xba4 + 1837 - 0x12d0);
       z05940590aa < (0x13f1 + 539 - 0x15fb); z05940590aa++) {
    for (z7fbfa5c6ba = (0x1774 + 2818 - 0x2276);
         z7fbfa5c6ba < (0x83b + 477 - 0xa14); z7fbfa5c6ba++)
      if (z7ef7ea19b8[z06223884be - (0x70c + 8003 - 0x264e)][z7fbfa5c6ba] ==
          z05940590aa)
        goto z39050d56d0;
    continue;
  z39050d56d0:
    for (z7fbfa5c6ba = (0x887 + 4267 - 0x1932);
         z7fbfa5c6ba < (0x106d + 5146 - 0x2483); z7fbfa5c6ba++)
      if (z6eb136750d[z4f327fc3a3 - (0x376 + 8314 - 0x23ef)][z7fbfa5c6ba] ==
          z05940590aa)
        goto z497896712f;
    continue;
  z497896712f:
    if (z370485a013 > -(0xbf8 + 3115 - 0x1822)) {
      puts("\x42\x61\x64\x20\x6d\x61\x67\x69\x63\x69\x61\x6e\x21");
      return;
    }
    z370485a013 = z05940590aa;
  }
  if (z370485a013 < (0x6f1 + 8162 - 0x26d3))
    puts("\x56\x6f\x6c\x75\x6e\x74\x65\x65\x72\x20\x63\x68\x65\x61\x74\x65\x64"
         "\x21");
  else
    printf("\x25\x64"
           "\n",
           z370485a013);
}
int main() {
  int zb15af14f7c, zdd19b22214 = (0x115 + 1688 - 0x7ac);
  scanf("\x25\x64", &zb15af14f7c);
  while (zb15af14f7c--)
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", zdd19b22214++),
        z8f1d8c70f4();
  return (0xde1 + 1273 - 0x12da);
}
