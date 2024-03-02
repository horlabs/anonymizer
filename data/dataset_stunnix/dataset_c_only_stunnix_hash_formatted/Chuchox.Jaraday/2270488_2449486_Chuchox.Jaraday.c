
#include <stdio.h>

int main(void) {
  int zf9584eba9d, z8869786217, ze68ec05284, z5cf3d144a9, z4c20b1d8cf,
      z3f25b16b37;
  int zbd8bd86b17, z50a9874bce;
  int z980ac297c1[(0x1206 + 2286 - 0x1a90)][(0x7cf + 285 - 0x888)];
  scanf("\x25\x64", &zf9584eba9d);
  for (z8869786217 = (0x2c4 + 794 - 0x5dd); z8869786217 <= zf9584eba9d;
       z8869786217++) {
    scanf("\x25\x64\x20\x25\x64"
          "\n",
          &z4c20b1d8cf, &z3f25b16b37);
    for (ze68ec05284 = (0x1000 + 2260 - 0x18d4); ze68ec05284 < z4c20b1d8cf;
         ze68ec05284++) {
      for (z5cf3d144a9 = (0x59c + 796 - 0x8b8); z5cf3d144a9 < z3f25b16b37;
           z5cf3d144a9++) {
        scanf("\x25\x64", &z980ac297c1[ze68ec05284][z5cf3d144a9]);
      }
    }
    if ((z4c20b1d8cf < (0x8e4 + 140 - 0x96e)) ||
        (z3f25b16b37 < (0x158c + 1893 - 0x1cef))) {
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x59\x45\x53"
             "\n",
             z8869786217);
      continue;
    }
    for (ze68ec05284 = (0x1a6b + 1266 - 0x1f5d); ze68ec05284 < z4c20b1d8cf;
         ze68ec05284++) {
      for (z5cf3d144a9 = (0x7b1 + 1751 - 0xe88); z5cf3d144a9 < z3f25b16b37;
           z5cf3d144a9++) {
        z50a9874bce = (0x1017 + 5558 - 0x25cc);
        for (zbd8bd86b17 = (0x16bf + 3112 - 0x22e7); zbd8bd86b17 < z4c20b1d8cf;
             zbd8bd86b17++) {
          if (z980ac297c1[ze68ec05284][z5cf3d144a9] <
              z980ac297c1[zbd8bd86b17][z5cf3d144a9]) {
            z50a9874bce = (0x12b4 + 5190 - 0x26fa);
            break;
          }
        }
        if (z50a9874bce) {
          continue;
        }
        z50a9874bce = (0xf30 + 578 - 0x1171);
        for (zbd8bd86b17 = (0xfb7 + 3907 - 0x1efa); zbd8bd86b17 < z3f25b16b37;
             zbd8bd86b17++) {
          if (z980ac297c1[ze68ec05284][z5cf3d144a9] <
              z980ac297c1[ze68ec05284][zbd8bd86b17]) {
            z50a9874bce = (0x137 + 8056 - 0x20af);
            break;
          }
        }
        if (z50a9874bce) {
          continue;
        }
        break;
      }
      if (!z50a9874bce) {
        break;
      }
    }
    if (z50a9874bce) {
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x59\x45\x53"
             "\n",
             z8869786217);
    } else {
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x4e\x4f"
             "\n",
             z8869786217);
    }
  }
  return ((0x22f1 + 777 - 0x25fa));
}
