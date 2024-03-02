
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int z45635e9ad6, z289d309355, flag;
  double C, F, X, z163b16b3f9, zaf9168c912, z203f9e8c68, za764b93a46,
      z57917febdf, z76f48e6703, zed52dd962a;
  FILE *z08aecf36a3 = fopen("\x42\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65"
                            "\x6d\x70\x74\x30\x2e\x69\x6e",
                            "\x72"),
       *z9ec72042c5 = fopen("\x6f\x75\x74\x2e\x74\x78\x74", "\x77");
  fscanf(z08aecf36a3, "\x25\x64", &z45635e9ad6);
  for (z289d309355 = (0x1a8a + 2784 - 0x256a); z289d309355 < z45635e9ad6;
       z289d309355++) {
    fscanf(z08aecf36a3, "\x25\x6c\x66\x25\x6c\x66\x25\x6c\x66", &C, &F, &X);
    z76f48e6703 = 0.0;
    z163b16b3f9 = 2.0;
    z203f9e8c68 = 0.0;
    do {
      za764b93a46 = (X - z76f48e6703) / z163b16b3f9;
      z57917febdf = 0.0;
      zed52dd962a = z76f48e6703, zaf9168c912 = z163b16b3f9;
      flag = (0x541 + 6404 - 0x1e45);
      do {
        z57917febdf += (C - zed52dd962a) / zaf9168c912;
        zed52dd962a = ((C - zed52dd962a) / zaf9168c912) * zaf9168c912 - C;
        zaf9168c912 += F;
        if (z57917febdf + (X - zed52dd962a) / zaf9168c912 < za764b93a46)
          flag = (0x21f9 + 382 - 0x2376);
      } while (!flag && z57917febdf < za764b93a46);
      if (flag) {
        z57917febdf = (C - z76f48e6703) / z163b16b3f9;
        z76f48e6703 = z57917febdf * z163b16b3f9 - C;
        z203f9e8c68 += z57917febdf;
        z163b16b3f9 += F;
      } else
        z203f9e8c68 += (X - z76f48e6703) / z163b16b3f9;
    } while (flag);
    fprintf(z9ec72042c5,
            "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x6c\x66"
            "\n",
            z289d309355 + (0x1cb7 + 2216 - 0x255e), z203f9e8c68);
  }
  fclose(z08aecf36a3);
  fclose(z9ec72042c5);
  return (0x6d6 + 2624 - 0x1116);
}
