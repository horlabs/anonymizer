
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int zbc62d2a9d2, zf6fc27cb0e, z700fdeba8e, zaa7198f0f7, zf61fa733c8,
      z7f422b38d1, z4ea95073da, z1a4713f42f[(0x4f2 + 4004 - 0x1416)];
  FILE *z52262ab51a = fopen("\x42\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65"
                            "\x6d\x70\x74\x30\x2e\x69\x6e",
                            "\x72"),
       *zcbf238e0a4 = fopen("\x6f\x75\x74\x2e\x74\x78\x74", "\x77");
  fscanf(z52262ab51a,
         "\x25\x64"
         "\n",
         &zaa7198f0f7);
  for (zbc62d2a9d2 = (0x253 + 2219 - 0xafe);
       z700fdeba8e = (0x1ebd + 47 - 0x1eec), zbc62d2a9d2 < zaa7198f0f7;
       zbc62d2a9d2++) {
    fscanf(z52262ab51a,
           "\x25\x64"
           "\n"
           "\x25\x64"
           "\n"
           "\x25\x64"
           "\n",
           &zf61fa733c8, &z7f422b38d1, &z4ea95073da);
    for (zf6fc27cb0e = (0x1558 + 352 - 0x16b8); zf6fc27cb0e < zf61fa733c8;
         zf6fc27cb0e++) {
      fscanf(z52262ab51a,
             "\x25\x64"
             "\n",
             &z1a4713f42f[zf6fc27cb0e]);
      switch (z1a4713f42f[zf6fc27cb0e] % (0x13b0 + 183 - 0x1464)) {
      case (0x1db5 + 2192 - 0x2645):
        if (z1a4713f42f[zf6fc27cb0e] / (0x603 + 6036 - 0x1d94) >= z4ea95073da)
          z700fdeba8e++;
        else if (z7f422b38d1 > (0xaad + 1543 - 0x10b4) &&
                 z1a4713f42f[zf6fc27cb0e] / (0x172a + 3147 - 0x2372) >
                     (0x17b2 + 936 - 0x1b5a) &&
                 z1a4713f42f[zf6fc27cb0e] / (0x6ff + 8132 - 0x26c0) <
                     (0x1c1b + 1637 - 0x2276) &&
                 z1a4713f42f[zf6fc27cb0e] / (0x8df + 7200 - 0x24fc) +
                         (0x3f0 + 6597 - 0x1db4) >=
                     z4ea95073da)
          z7f422b38d1--, z700fdeba8e++;
        break;
      case (0x1209 + 3715 - 0x208b):
        if (z1a4713f42f[zf6fc27cb0e] / (0x78c + 2687 - 0x1208) +
                (0x1168 + 9 - 0x1170) >=
            z4ea95073da)
          z700fdeba8e++;
        break;
      case (0x55d + 6143 - 0x1d5a):
        if (z1a4713f42f[zf6fc27cb0e] / (0xce1 + 759 - 0xfd5) +
                (0x957 + 1177 - 0xdef) >=
            z4ea95073da)
          z700fdeba8e++;
        else if (z7f422b38d1 > (0x4cd + 8256 - 0x250d) &&
                 z1a4713f42f[zf6fc27cb0e] / (0x1032 + 4994 - 0x23b1) <
                     (0x4b + 5323 - 0x150d) &&
                 z1a4713f42f[zf6fc27cb0e] / (0x1bf9 + 876 - 0x1f62) +
                         (0x34c + 5186 - 0x178c) >=
                     z4ea95073da)
          z7f422b38d1--, z700fdeba8e++;
        break;
      }
    }
    fprintf(zcbf238e0a4,
            "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
            "\n",
            zbc62d2a9d2 + (0x3f1 + 1886 - 0xb4e), z700fdeba8e);
  }
  fclose(z52262ab51a);
  fclose(zcbf238e0a4);
  return (0x6f4 + 851 - 0xa47);
}
