
#include <stdio.h>
#include <stdlib.h>

int main() {
  int zc8c6f63ef5, z6ed978c81b, z8762d9f9b0, zb28703c817, zb3da8d2eed,
      zf55cf04934, z166439f496, za373daa053, z57c8e4c1d1,
      z322bdfa342[(0x575 + 5394 - 0x1a83)][(0x1a3b + 1451 - 0x1fe2)],
      z5b5ded4193[(0x703 + 5208 - 0x1b57)][(0x97 + 9798 - 0x26d9)];
  scanf("\x25\x64", &zc8c6f63ef5);
  for (z6ed978c81b = (0x70 + 7571 - 0x1e02); z6ed978c81b <= zc8c6f63ef5;
       z6ed978c81b++) {
    scanf("\x25\x64", &za373daa053);
    za373daa053--;
    for (z8762d9f9b0 = (0xdea + 2720 - 0x188a);
         z8762d9f9b0 < (0x7bc + 2071 - 0xfcf); z8762d9f9b0++)
      for (zb28703c817 = (0xc89 + 5354 - 0x2173);
           zb28703c817 < (0x1437 + 2620 - 0x1e6f); zb28703c817++)
        scanf("\x25\x64", &(z322bdfa342[z8762d9f9b0][zb28703c817]));
    scanf("\x25\x64", &z57c8e4c1d1);
    z57c8e4c1d1--;
    for (z8762d9f9b0 = (0x3b8 + 3733 - 0x124d);
         z8762d9f9b0 < (0x1b4f + 1151 - 0x1fca); z8762d9f9b0++)
      for (zb28703c817 = (0x6bd + 5733 - 0x1d22);
           zb28703c817 < (0x14a0 + 1635 - 0x1aff); zb28703c817++)
        scanf("\x25\x64", &(z5b5ded4193[z8762d9f9b0][zb28703c817]));
    zf55cf04934 = (0x16f0 + 2573 - 0x20fd);
    z166439f496 = -(0xf89 + 2724 - 0x1a2c);
    for (zb28703c817 = (0x6fc + 2731 - 0x11a7);
         zb28703c817 < (0x1684 + 2873 - 0x21b9); zb28703c817++)
      for (zb3da8d2eed = (0x1824 + 2056 - 0x202c);
           zb3da8d2eed < (0x172f + 3012 - 0x22ef); zb3da8d2eed++)
        if (z322bdfa342[za373daa053][zb28703c817] ==
            z5b5ded4193[z57c8e4c1d1][zb3da8d2eed]) {
          zf55cf04934++;
          z166439f496 = zb28703c817;
        }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", z6ed978c81b);
    if (zf55cf04934 == (0x12f + 2967 - 0xcc5))
      printf("\x25\x64"
             "\n",
             z322bdfa342[za373daa053][z166439f496]);
    else
      printf("\x25\x73"
             "\n",
             zf55cf04934
                 ? "\x42\x61\x64\x20\x6d\x61\x67\x69\x63\x69\x61\x6e\x21"
                 : "\x56\x6f\x6c\x75\x6e\x74\x65\x65\x72\x20\x63\x68\x65\x61"
                   "\x74\x65\x64\x21");
  }
  return (0x20f7 + 830 - 0x2435);
}
