
#include <stdio.h>
#include <string.h>

int zf63215cf57[(0x7c7 + 13 - 0x765)][(0x8da + 3991 - 0x1802)];
int try
  [(0x1127 + 2997 - 0x1c6d)][(0x60c + 470 - 0x773)];
int x, y;
int z865174410a() {
  int z516739982b, z3c5b6f8173, zcfe36146bb, zc5c1bcbadb;
  for (z516739982b = (0x1573 + 647 - 0x17fa); z516739982b < x; z516739982b++)
    for (z3c5b6f8173 = (0x6bd + 1653 - 0xd32); z3c5b6f8173 < y; z3c5b6f8173++)
      try
        [z516739982b][z3c5b6f8173] = (0x2a9 + 6792 - 0x1ccd);
  do {
    zc5c1bcbadb = (0x14b9 + 2263 - 0x1d90);
    for (z516739982b = (0x2312 + 391 - 0x2499); z516739982b < x;
         z516739982b++) {
      zcfe36146bb = (0x1b6 + 4412 - 0x12f2);
      for (z3c5b6f8173 = (0x1d5c + 70 - 0x1da2); z3c5b6f8173 < y; z3c5b6f8173++)
        if (zcfe36146bb < zf63215cf57[z516739982b][z3c5b6f8173])
          zcfe36146bb = zf63215cf57[z516739982b][z3c5b6f8173];
      for (z3c5b6f8173 = (0x7b0 + 3112 - 0x13d8); z3c5b6f8173 < y;
           z3c5b6f8173++)
        if (try[z516739982b][z3c5b6f8173] > zcfe36146bb)
          try
            [z516739982b][z3c5b6f8173] = zcfe36146bb,
            zc5c1bcbadb = (0x717 + 3327 - 0x1415);
    }
    for (z3c5b6f8173 = (0x1525 + 2315 - 0x1e30); z3c5b6f8173 < y;
         z3c5b6f8173++) {
      zcfe36146bb = (0xb61 + 5492 - 0x20d5);
      for (z516739982b = (0x9c2 + 3017 - 0x158b); z516739982b < x;
           z516739982b++)
        if (zcfe36146bb < zf63215cf57[z516739982b][z3c5b6f8173])
          zcfe36146bb = zf63215cf57[z516739982b][z3c5b6f8173];
      for (z516739982b = (0x804 + 1309 - 0xd21); z516739982b < x; z516739982b++)
        if (try[z516739982b][z3c5b6f8173] > zcfe36146bb)
          try
            [z516739982b][z3c5b6f8173] = zcfe36146bb,
            zc5c1bcbadb = (0xb + 7790 - 0x1e78);
    }
  } while (zc5c1bcbadb);
  for (z516739982b = (0xab8 + 1790 - 0x11b6); z516739982b < x; z516739982b++)
    for (z3c5b6f8173 = (0x12a0 + 975 - 0x166f); z3c5b6f8173 < y; z3c5b6f8173++)
      if (try[z516739982b][z3c5b6f8173] !=
          zf63215cf57[z516739982b][z3c5b6f8173])
        return (0x2dd + 9256 - 0x2705);
  return (0x219 + 4950 - 0x156e);
}
int main() {
  int z0ff3dcd35a, zbe04eff2ca = (0x1e4c + 60 - 0x1e87), z516739982b,
                   z3c5b6f8173;
  scanf("\x25\x64", &z0ff3dcd35a);
  while (z0ff3dcd35a--) {
    scanf("\x25\x64\x20\x25\x64", &x, &y);
    for (z516739982b = (0x17b + 5060 - 0x153f); z516739982b < x; z516739982b++)
      for (z3c5b6f8173 = (0x5fb + 1954 - 0xd9d); z3c5b6f8173 < y; z3c5b6f8173++)
        scanf("\x25\x64", &zf63215cf57[z516739982b][z3c5b6f8173]);
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
           "\n",
           zbe04eff2ca++, z865174410a() ? "\x59\x45\x53" : "\x4e\x4f");
  }
  return (0x1444 + 634 - 0x16be);
}
