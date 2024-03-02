
#include <stdio.h>
#include <stdlib.h>

typedef struct z7a725870b3 {
  int z5bbbe28ef8;
  int zb5d07fed08;
  int z1a7a09baba;
  struct z7a725870b3 *z5808dd28f4[(0x34b + 2226 - 0xbfb)];
} z244af74b79;
z244af74b79 *zb8364f1de4(z244af74b79 *z0ccd11aa7a, int z0499cba7ab,
                         int z480e819866);
int z3c489b83c3(int z190df8c305, int z02a15aca36) {
  return z190df8c305 - z02a15aca36;
}
int zce66e1e6e1(z244af74b79 *z0ccd11aa7a) {
  if (z0ccd11aa7a == NULL) {
    return (0x300 + 1608 - 0x947);
  } else {
    return (0x89a + 4984 - 0x1c12);
  }
}
int zb5d07fed08(z244af74b79 *z0ccd11aa7a) {
  if (z0ccd11aa7a == NULL) {
    return (0x3ad + 2160 - 0xc1d);
  } else {
    return z0ccd11aa7a->zb5d07fed08;
  }
}
int z1a7a09baba(z244af74b79 *z0ccd11aa7a) {
  if (z0ccd11aa7a == NULL) {
    return (0x9e5 + 2976 - 0x1585);
  } else {
    return z0ccd11aa7a->z1a7a09baba;
  }
}
z244af74b79 *z3e38abb7fc(z244af74b79 *z0ccd11aa7a) {
  int z22e5eef86a;
  for (z22e5eef86a = (0x33f + 5450 - 0x1889);
       z22e5eef86a < (0x1178 + 1561 - 0x178f); z22e5eef86a++) {
    if (z1a7a09baba(z0ccd11aa7a->z5808dd28f4[!z22e5eef86a]) -
            z1a7a09baba(z0ccd11aa7a->z5808dd28f4[z22e5eef86a]) <
        -(0x990 + 7378 - 0x2661)) {
      if (z1a7a09baba(z0ccd11aa7a->z5808dd28f4[z22e5eef86a]
                          ->z5808dd28f4[!z22e5eef86a]) -
              z1a7a09baba(z0ccd11aa7a->z5808dd28f4[z22e5eef86a]
                              ->z5808dd28f4[z22e5eef86a]) >
          (0x4a3 + 7520 - 0x2203)) {
        z0ccd11aa7a->z5808dd28f4[z22e5eef86a] = zb8364f1de4(
            z0ccd11aa7a->z5808dd28f4[z22e5eef86a], z22e5eef86a, !z22e5eef86a);
      }
      return zb8364f1de4(z0ccd11aa7a, !z22e5eef86a, z22e5eef86a);
    }
  }
  if (z0ccd11aa7a != NULL) {
    if (z1a7a09baba(z0ccd11aa7a->z5808dd28f4[(0x145 + 4769 - 0x13e6)]) >
        z1a7a09baba(z0ccd11aa7a->z5808dd28f4[(0xb63 + 1092 - 0xfa6)])) {
      z0ccd11aa7a->z1a7a09baba =
          z1a7a09baba(z0ccd11aa7a->z5808dd28f4[(0x520 + 561 - 0x751)]) +
          (0x1175 + 2390 - 0x1aca);
    } else {
      z0ccd11aa7a->z1a7a09baba =
          z1a7a09baba(z0ccd11aa7a->z5808dd28f4[(0xa3 + 6055 - 0x1849)]) +
          (0x61a + 6373 - 0x1efe);
    }
    z0ccd11aa7a->zb5d07fed08 =
        zb5d07fed08(z0ccd11aa7a->z5808dd28f4[(0x23a + 1902 - 0x9a8)]) +
        zb5d07fed08(z0ccd11aa7a->z5808dd28f4[(0x862 + 6759 - 0x22c8)]) +
        (0x81d + 245 - 0x911);
  }
  return z0ccd11aa7a;
}
z244af74b79 *zb8364f1de4(z244af74b79 *z0ccd11aa7a, int z0499cba7ab,
                         int z480e819866) {
  z244af74b79 *zc2cf7ef417 = z0ccd11aa7a->z5808dd28f4[z480e819866];
  z0ccd11aa7a->z5808dd28f4[z480e819866] = zc2cf7ef417->z5808dd28f4[z0499cba7ab];
  zc2cf7ef417->z5808dd28f4[z0499cba7ab] = z3e38abb7fc(z0ccd11aa7a);
  if (z0ccd11aa7a != NULL)
    z0ccd11aa7a->zb5d07fed08 =
        zb5d07fed08(z0ccd11aa7a->z5808dd28f4[(0x168f + 3735 - 0x2526)]) +
        zb5d07fed08(z0ccd11aa7a->z5808dd28f4[(0xe41 + 729 - 0x1119)]) +
        (0x2306 + 174 - 0x23b3);
  if (zc2cf7ef417 != NULL)
    zc2cf7ef417->zb5d07fed08 =
        zb5d07fed08(zc2cf7ef417->z5808dd28f4[(0x5f0 + 6747 - 0x204b)]) +
        zb5d07fed08(zc2cf7ef417->z5808dd28f4[(0x17aa + 1034 - 0x1bb3)]) +
        (0x1dad + 1676 - 0x2438);
  return z3e38abb7fc(zc2cf7ef417);
}
z244af74b79 *z163479c318(z244af74b79 *z0ccd11aa7a, int z5bbbe28ef8) {
  int x;
  if (z0ccd11aa7a == NULL) {
    z244af74b79 *z5c2a7135cb = malloc(sizeof(z244af74b79));
    z5c2a7135cb->z5bbbe28ef8 = z5bbbe28ef8;
    z5c2a7135cb->zb5d07fed08 = (0x107c + 3150 - 0x1cc9);
    z5c2a7135cb->z1a7a09baba = (0x3e6 + 5541 - 0x198a);
    z5c2a7135cb->z5808dd28f4[(0x117b + 938 - 0x1525)] = NULL;
    z5c2a7135cb->z5808dd28f4[(0xa6d + 3672 - 0x18c4)] = NULL;
    return z5c2a7135cb;
  }
  x = z3c489b83c3(z0ccd11aa7a->z5bbbe28ef8, z5bbbe28ef8);
  if (x == (0x1bcd + 1 - 0x1bce))
    return z0ccd11aa7a;
  if (x > (0x13ec + 3023 - 0x1fbb)) {
    z0ccd11aa7a->z5808dd28f4[(0xf22 + 4265 - 0x1fcb)] = z163479c318(
        z0ccd11aa7a->z5808dd28f4[(0x65a + 5349 - 0x1b3f)], z5bbbe28ef8);
  } else {
    z0ccd11aa7a->z5808dd28f4[(0x55a + 1476 - 0xb1d)] = z163479c318(
        z0ccd11aa7a->z5808dd28f4[(0x1039 + 1088 - 0x1478)], z5bbbe28ef8);
  }
  z0ccd11aa7a->zb5d07fed08++;
  return z3e38abb7fc(z0ccd11aa7a);
}
z244af74b79 *z4367154fc3(z244af74b79 *z0ccd11aa7a, z244af74b79 *zc2cf7ef417) {
  if (z0ccd11aa7a == NULL)
    return zc2cf7ef417;
  z0ccd11aa7a->z5808dd28f4[(0x1e85 + 1534 - 0x2482)] = z4367154fc3(
      z0ccd11aa7a->z5808dd28f4[(0x12f8 + 4474 - 0x2471)], zc2cf7ef417);
  return z3e38abb7fc(z0ccd11aa7a);
}
int zd93d3029f3(z244af74b79 *z0ccd11aa7a, int z5bbbe28ef8) {
  int x;
  if (z0ccd11aa7a == NULL)
    return (0x1583 + 796 - 0x189f);
  x = z3c489b83c3(z0ccd11aa7a->z5bbbe28ef8, z5bbbe28ef8);
  if (x == (0xb19 + 2449 - 0x14aa))
    return (0xbe3 + 2622 - 0x1620);
  if (x > (0x34 + 7240 - 0x1c7c)) {
    return zd93d3029f3(z0ccd11aa7a->z5808dd28f4[(0x2e8 + 9152 - 0x26a8)],
                       z5bbbe28ef8);
  } else {
    return zd93d3029f3(z0ccd11aa7a->z5808dd28f4[(0x1782 + 2974 - 0x231f)],
                       z5bbbe28ef8);
  }
}
void z8e1874ba90(z244af74b79 *z0ccd11aa7a) {
  if (z0ccd11aa7a == NULL)
    return;
  z8e1874ba90(z0ccd11aa7a->z5808dd28f4[(0x1493 + 2123 - 0x1cde)]);
  z8e1874ba90(z0ccd11aa7a->z5808dd28f4[(0x256 + 1599 - 0x894)]);
  free(z0ccd11aa7a);
}
int zc96ebf8275(z244af74b79 *z0ccd11aa7a, int z5800f17622) {
  int zfc7a42ca25 =
      zb5d07fed08(z0ccd11aa7a->z5808dd28f4[(0x19c + 3578 - 0xf96)]);
  if (z5800f17622 < zfc7a42ca25) {
    return zc96ebf8275(z0ccd11aa7a->z5808dd28f4[(0x8e9 + 5114 - 0x1ce3)],
                       z5800f17622);
  } else if (z5800f17622 == zfc7a42ca25) {
    return z0ccd11aa7a->z5bbbe28ef8;
  } else {
    return zc96ebf8275(z0ccd11aa7a->z5808dd28f4[(0xaad + 4959 - 0x1e0b)],
                       z5800f17622 - zfc7a42ca25 - (0x3b8 + 5136 - 0x17c7));
  }
}
int z8e74aeca8f[2000001][(0x90a + 1899 - 0x106b)];
int z3dda3383e2[2000001];
int main() {
  int zc2cf7ef417, z22e5eef86a, za3a831d501, z1a2daa2679;
  z244af74b79 *z0ccd11aa7a = NULL;
  for (z22e5eef86a = (0x719 + 4688 - 0x1968); z22e5eef86a <= 2000000;
       z22e5eef86a++) {
    int z190df8c305[(0x4e9 + 7916 - 0x23cb)];
    int x = z22e5eef86a, y = (0x12a5 + 4505 - 0x243e);
    while (x) {
      z190df8c305[y++] = x % (0x501 + 6809 - 0x1f90);
      x /= (0x428 + 446 - 0x5dc);
    }
    for (za3a831d501 = (0x170 + 8677 - 0x2355);
         za3a831d501 < y - (0x399 + 1507 - 0x97b); za3a831d501++) {
      int z6182a7e68a = (0x1042 + 1673 - 0x16cb);
      if (z190df8c305[za3a831d501] == (0xb7f + 7009 - 0x26e0))
        continue;
      for (z1a2daa2679 = za3a831d501; z1a2daa2679 >= (0xd01 + 6000 - 0x2471);
           z1a2daa2679--) {
        z6182a7e68a *= (0x169c + 78 - 0x16e0);
        z6182a7e68a += z190df8c305[z1a2daa2679];
      }
      for (z1a2daa2679 = y - (0x23d + 4926 - 0x157a); z1a2daa2679 > za3a831d501;
           z1a2daa2679--) {
        z6182a7e68a *= (0x531 + 310 - 0x65d);
        z6182a7e68a += z190df8c305[z1a2daa2679];
      }
      if (z6182a7e68a < z22e5eef86a)
        z0ccd11aa7a = z163479c318(z0ccd11aa7a, z6182a7e68a);
    }
    for (za3a831d501 = zb5d07fed08(z0ccd11aa7a) - (0x510 + 8060 - 0x248b);
         za3a831d501 >= (0x1a1b + 301 - 0x1b48); za3a831d501--) {
      z8e74aeca8f[z22e5eef86a][z3dda3383e2[z22e5eef86a]++] =
          zc96ebf8275(z0ccd11aa7a, za3a831d501);
    }
    z8e1874ba90(z0ccd11aa7a);
    z0ccd11aa7a = NULL;
  }
  scanf("\x25\x64", &zc2cf7ef417);
  for (z22e5eef86a = (0x574 + 2391 - 0xecb); z22e5eef86a < zc2cf7ef417;
       z22e5eef86a++) {
    int z190df8c305, z02a15aca36, z225951dd38 = (0xbeb + 95 - 0xc4a);
    scanf("\x25\x64\x20\x25\x64", &z190df8c305, &z02a15aca36);
    for (za3a831d501 = z190df8c305; za3a831d501 <= z02a15aca36; za3a831d501++) {
      for (z1a2daa2679 = (0x14e8 + 4410 - 0x2622);
           z1a2daa2679 < z3dda3383e2[za3a831d501]; z1a2daa2679++) {
        if (z8e74aeca8f[za3a831d501][z1a2daa2679] < z190df8c305)
          break;
        z225951dd38++;
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z22e5eef86a + (0xe6d + 6003 - 0x25df), z225951dd38);
  }
  return (0x970 + 5779 - 0x2003);
}
