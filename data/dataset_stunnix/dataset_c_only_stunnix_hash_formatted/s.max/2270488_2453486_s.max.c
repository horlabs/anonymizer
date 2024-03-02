
#include <stdio.h>

int z16e7ddfa5d(char z0d9ced7e0f[][(0x2335 + 415 - 0x24cf)], char z7dd85e025d,
                char ze1cd765ede) {
  int zd951e9826a, z4e4e1044c8;
  for (zd951e9826a = (0xd4 + 2085 - 0x8f9);
       zd951e9826a < (0xdbd + 2083 - 0x15dc); zd951e9826a++) {
    for (z4e4e1044c8 = (0x1906 + 3498 - 0x26b0);
         z4e4e1044c8 < (0x1e07 + 1190 - 0x22a9); z4e4e1044c8++)
      if (z0d9ced7e0f[zd951e9826a][z4e4e1044c8] != z7dd85e025d &&
          z0d9ced7e0f[zd951e9826a][z4e4e1044c8] != ze1cd765ede)
        break;
    if (z4e4e1044c8 == (0x45a + 8221 - 0x2473))
      return (0xc2c + 4204 - 0x1c97);
  }
  for (zd951e9826a = (0x1064 + 1264 - 0x1554);
       zd951e9826a < (0x12d8 + 4275 - 0x2387); zd951e9826a++) {
    for (z4e4e1044c8 = (0x1a02 + 1824 - 0x2122);
         z4e4e1044c8 < (0xce3 + 3267 - 0x19a2); z4e4e1044c8++)
      if (z0d9ced7e0f[z4e4e1044c8][zd951e9826a] != z7dd85e025d &&
          z0d9ced7e0f[z4e4e1044c8][zd951e9826a] != ze1cd765ede)
        break;
    if (z4e4e1044c8 == (0x140c + 1913 - 0x1b81))
      return (0xe46 + 128 - 0xec5);
  }
  for (zd951e9826a = (0x319 + 1048 - 0x731);
       zd951e9826a < (0x1070 + 293 - 0x1191); zd951e9826a++)
    if (z0d9ced7e0f[zd951e9826a][zd951e9826a] != z7dd85e025d &&
        z0d9ced7e0f[zd951e9826a][zd951e9826a] != ze1cd765ede)
      break;
  if (zd951e9826a == (0x485 + 3965 - 0x13fe))
    return (0xac3 + 2346 - 0x13ec);
  for (zd951e9826a = (0x3e4 + 2727 - 0xe8b);
       zd951e9826a < (0x190 + 7806 - 0x200a); zd951e9826a++)
    if (z0d9ced7e0f[zd951e9826a][(0x9b5 + 7418 - 0x26ac) - zd951e9826a] !=
            z7dd85e025d &&
        z0d9ced7e0f[zd951e9826a][(0x172 + 538 - 0x389) - zd951e9826a] !=
            ze1cd765ede)
      break;
  if (zd951e9826a == (0x85f + 5455 - 0x1daa))
    return (0x2039 + 1018 - 0x2432);
  return (0x6 + 3484 - 0xda2);
}
int z8dd6db40a8(char z0d9ced7e0f[][(0xa3 + 5666 - 0x16c0)]) {
  int zd951e9826a, z4e4e1044c8;
  for (zd951e9826a = (0x19d9 + 3199 - 0x2658);
       zd951e9826a < (0x777 + 3392 - 0x14b3); zd951e9826a++)
    for (z4e4e1044c8 = (0x1475 + 1785 - 0x1b6e);
         z4e4e1044c8 < (0x3a7 + 3397 - 0x10e8); z4e4e1044c8++)
      if (z0d9ced7e0f[zd951e9826a][z4e4e1044c8] ==
          ((char)(0x4fd + 4789 - 0x1784)))
        return (0x1b70 + 216 - 0x1c48);
  return (0xa65 + 1822 - 0x1182);
}
int main() {
  int za3a857935d, ze5eb294367;
  scanf("\x25\x64", &za3a857935d);
  for (ze5eb294367 = (0x1b3 + 8251 - 0x21ed); ze5eb294367 <= za3a857935d;
       ze5eb294367++) {
    int zd951e9826a;
    char z0d9ced7e0f[(0xcd + 3978 - 0x1053)][(0x1fc3 + 1506 - 0x25a0)];
    for (zd951e9826a = (0x8db + 450 - 0xa9d);
         zd951e9826a < (0x866 + 4614 - 0x1a68); zd951e9826a++)
      scanf("\x25\x73", z0d9ced7e0f[zd951e9826a]);
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", ze5eb294367);
    if (z16e7ddfa5d(z0d9ced7e0f, ((char)(0x1c86 + 2406 - 0x2594)),
                    ((char)(0xbd + 2471 - 0xa10))))
      printf("\x58\x20\x77\x6f\x6e");
    else if (z16e7ddfa5d(z0d9ced7e0f, ((char)(0x89b + 2964 - 0x13e0)),
                         ((char)(0x50b + 7113 - 0x2080))))
      printf("\x4f\x20\x77\x6f\x6e");
    else if (z8dd6db40a8(z0d9ced7e0f))
      printf("\x44\x72\x61\x77");
    else
      printf("\x47\x61\x6d\x65\x20\x68\x61\x73\x20\x6e\x6f\x74\x20\x63\x6f\x6d"
             "\x70\x6c\x65\x74\x65\x64");
    printf("\n");
  }
  return (0x183f + 885 - 0x1bb4);
}
