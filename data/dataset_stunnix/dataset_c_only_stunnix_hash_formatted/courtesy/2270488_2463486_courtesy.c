
#include <math.h>
#include <stdio.h>

typedef long long z88466c9cd8;
int z8e170581cf(z88466c9cd8 z9317710ada) {
  int z030703fed2[(0x1da4 + 1471 - 0x234f)], zff8fdf984e, z6d88fa9d0d,
      zf7fc6f5d64;
  for (zff8fdf984e = (0x4d3 + 780 - 0x7df);
       z9317710ada > (0x797 + 1445 - 0xd3c);
       zff8fdf984e++, z9317710ada /= (0x2a7 + 7502 - 0x1feb))
    z030703fed2[zff8fdf984e] = z9317710ada % (0x471 + 82 - 0x4b9);
  for (zff8fdf984e--, z6d88fa9d0d = (0x3b2 + 699 - 0x66d);
       zff8fdf984e > z6d88fa9d0d; zff8fdf984e--, z6d88fa9d0d++) {
    if (z030703fed2[zff8fdf984e] != z030703fed2[z6d88fa9d0d])
      return (0x1aea + 2867 - 0x261d);
  }
  return (0x9fa + 5406 - 0x1f17);
}
int main() {
  freopen("\x43\x3a"
          "\\"
          "\x55\x73\x65\x72\x73"
          "\\"
          "\x76\x69\x76\x65\x6b"
          "\\"
          "\x44\x65\x73\x6b\x74\x6f\x70"
          "\\"
          "\x69\x6e\x2e\x74\x78\x74",
          "\x72", stdin);
  freopen("\x43\x3a"
          "\\"
          "\x55\x73\x65\x72\x73"
          "\\"
          "\x76\x69\x76\x65\x6b"
          "\\"
          "\x44\x65\x73\x6b\x74\x6f\x70"
          "\\"
          "\x6f\x75\x74\x2e\x74\x78\x74",
          "\x77", stdout);
  int zff8fdf984e, z6d88fa9d0d, zf7fc6f5d64, z3a669ef955, zb4273b128c,
      z030703fed2, zd1cb9ba877, z6db6f76da8;
  scanf("\x25\x64", &zb4273b128c);
  for (z3a669ef955 = (0x821 + 1122 - 0xc82); z3a669ef955 <= zb4273b128c;
       z3a669ef955++) {
    scanf("\x25\x64\x20\x25\x64", &z030703fed2, &zd1cb9ba877);
    z6db6f76da8 = sqrt(zd1cb9ba877);
    for (zff8fdf984e = sqrt(z030703fed2),
        zf7fc6f5d64 = (0x13f8 + 4202 - 0x2462);
         zff8fdf984e <= z6db6f76da8; zff8fdf984e++) {
      if (z8e170581cf(zff8fdf984e)) {
        z6d88fa9d0d = zff8fdf984e * zff8fdf984e;
        if ((z6d88fa9d0d >= z030703fed2) && (z6d88fa9d0d <= zd1cb9ba877) &&
            z8e170581cf(z6d88fa9d0d))
          zf7fc6f5d64++;
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z3a669ef955, zf7fc6f5d64);
  }
  return (0x4ac + 7805 - 0x2329);
}
