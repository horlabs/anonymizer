
#include <stdio.h>

int main() {
  int z242cf67dd3, z84fa05b5c0, za3f4fda90a,
      z298ff718d1 = (0xec5 + 2356 - 0x17f9);
  long long z80501dc6ef[(0x929 + 1771 - 0xfed)];
  for (za3f4fda90a = (0xc1 + 9096 - 0x2448); za3f4fda90a <= 2001002;
       ++za3f4fda90a) {
    char zc39a74aff1[(0x741 + 2514 - 0x10fe)] = {};
    long long z25e8a4b868 = (long long)za3f4fda90a * za3f4fda90a,
              z6d79c9a19f = (long long)za3f4fda90a * za3f4fda90a;
    int z1081ae1128 = (0x33 + 3803 - 0xf0e);
    while (z6d79c9a19f) {
      zc39a74aff1[z1081ae1128++] = z6d79c9a19f % (0x121 + 1480 - 0x6df) +
                                   ((char)(0x1336 + 4441 - 0x245f));
      z6d79c9a19f /= (0x781 + 1902 - 0xee5);
    }
    sscanf(zc39a74aff1, "\x25\x49\x36\x34\x64", &z6d79c9a19f);
    if (z25e8a4b868 == z6d79c9a19f) {
      char z6ec930d5aa[(0x1af1 + 2521 - 0x24b5)] = {};
      z6d79c9a19f = za3f4fda90a, z1081ae1128 = (0x6 + 2681 - 0xa7f);
      while (z6d79c9a19f) {
        z6ec930d5aa[z1081ae1128++] = z6d79c9a19f % (0x7dc + 7039 - 0x2351) +
                                     ((char)(0x11c2 + 3890 - 0x20c4));
        z6d79c9a19f /= (0x527 + 7431 - 0x2224);
      }
      sscanf(z6ec930d5aa, "\x25\x49\x36\x34\x64", &z6d79c9a19f);
      if (za3f4fda90a == z6d79c9a19f) {
        z80501dc6ef[z298ff718d1++] = z25e8a4b868;
      }
    }
  }
  scanf("\x25\x64", &z242cf67dd3);
  for (z84fa05b5c0 = (0x94 + 4247 - 0x112a); z84fa05b5c0 <= z242cf67dd3;
       ++z84fa05b5c0) {
    long long z69139cd744, z0cf5da3917;
    int za430f11ba7, z29a71ebee6, z0a80995200, x, y;
    scanf("\x25\x49\x36\x34\x64\x25\x49\x36\x34\x64", &z69139cd744,
          &z0cf5da3917);
    for (za430f11ba7 = (0xa92 + 3016 - 0x165a),
        z29a71ebee6 = (0x1961 + 868 - 0x1c9e);
         za430f11ba7 < z29a71ebee6;) {
      z0a80995200 = (za430f11ba7 + z29a71ebee6) / (0x1001 + 799 - 0x131e);
      if (z80501dc6ef[z0a80995200] == z69139cd744) {
        za430f11ba7 = z0a80995200;
        break;
      } else if (z80501dc6ef[z0a80995200] < z69139cd744)
        za430f11ba7 = z0a80995200 + (0x1445 + 4628 - 0x2658);
      else
        z29a71ebee6 = z0a80995200;
    }
    x = za430f11ba7;
    for (za430f11ba7 = (0x1254 + 522 - 0x145e),
        z29a71ebee6 = (0x4ec + 6047 - 0x1c64);
         za430f11ba7 < z29a71ebee6;) {
      z0a80995200 = (za430f11ba7 + z29a71ebee6) / (0x195 + 6462 - 0x1ad1);
      if (z80501dc6ef[z0a80995200] <= z0cf5da3917) {
        za430f11ba7 = z0a80995200 + (0x504 + 2067 - 0xd16);
      } else
        z29a71ebee6 = z0a80995200;
    }
    y = za430f11ba7;
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z84fa05b5c0, y - x);
  }
  return (0x1ab + 6757 - 0x1c10);
}
