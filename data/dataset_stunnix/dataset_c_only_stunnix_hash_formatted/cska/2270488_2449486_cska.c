
#include <stdio.h>
#include <stdlib.h>

struct z800904349b {
  int z9a2bf742b1, z4780b6a21d, z407d75b5e5, z9bca456efe;
};
int z831aee7ed5(const void *zb7e7b3cdb9, const void *zde03ccbb44) {
  return ((struct z800904349b *)zb7e7b3cdb9)->z407d75b5e5 -
         ((struct z800904349b *)zde03ccbb44)->z407d75b5e5;
}
int main(void) {
  int z9a2bf742b1, z4780b6a21d, z8e3e3fece8, z4f615578d2, z761a475b76,
      zbd7cc20334, z1a0fc34461, zcee4d7442f, z0012a90974, z9bca456efe,
      z4233ec3918;
  struct z800904349b zbb78b9fe38[(0x113b + 5291 - 0x2582)]
                                [(0x15a5 + 3525 - 0x2306)],
      z7384753b84[10000];
  FILE *z8a2c645eb1 = fopen("\x42\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65"
                            "\x6d\x70\x74\x30\x2e\x69\x6e",
                            "\x72"),
       *z66ac2a7bdb = fopen("\x6f\x75\x74\x2e\x74\x78\x74", "\x77");
  fscanf(z8a2c645eb1, "\x25\x64", &z1a0fc34461);
  for (z4f615578d2 = (0x1276 + 2573 - 0x1c83); z4f615578d2 < z1a0fc34461;
       z4f615578d2++) {
    fscanf(z8a2c645eb1, "\x25\x64\x25\x64", &z761a475b76, &zbd7cc20334);
    for (z9a2bf742b1 = (0x4d9 + 5088 - 0x18b9); z9a2bf742b1 < z761a475b76;
         z9a2bf742b1++)
      for (z4780b6a21d = (0x203b + 26 - 0x2055); z4780b6a21d < zbd7cc20334;
           z4780b6a21d++) {
        zbb78b9fe38[z9a2bf742b1][z4780b6a21d].z9a2bf742b1 = z9a2bf742b1;
        zbb78b9fe38[z9a2bf742b1][z4780b6a21d].z4780b6a21d = z4780b6a21d;
        zbb78b9fe38[z9a2bf742b1][z4780b6a21d].z9bca456efe =
            (0x5d4 + 2111 - 0xe13);
        fscanf(z8a2c645eb1, "\x25\x64",
               &(zbb78b9fe38[z9a2bf742b1][z4780b6a21d].z407d75b5e5));
      }
    for (z8e3e3fece8 = z9a2bf742b1 = (0x426 + 1183 - 0x8c5);
         z9a2bf742b1 < z761a475b76; z9a2bf742b1++)
      for (z4780b6a21d = (0x1247 + 5205 - 0x269c); z4780b6a21d < zbd7cc20334;
           z4780b6a21d++) {
        z7384753b84[z8e3e3fece8].z9a2bf742b1 =
            zbb78b9fe38[z9a2bf742b1][z4780b6a21d].z9a2bf742b1;
        z7384753b84[z8e3e3fece8].z4780b6a21d =
            zbb78b9fe38[z9a2bf742b1][z4780b6a21d].z4780b6a21d;
        z7384753b84[z8e3e3fece8].z9bca456efe =
            zbb78b9fe38[z9a2bf742b1][z4780b6a21d].z9bca456efe;
        z7384753b84[z8e3e3fece8].z407d75b5e5 =
            zbb78b9fe38[z9a2bf742b1][z4780b6a21d].z407d75b5e5;
        z8e3e3fece8++;
      }
    qsort(z7384753b84, z8e3e3fece8, sizeof(struct z800904349b), z831aee7ed5);
    for (z9a2bf742b1 = (0x4b3 + 984 - 0x88b),
        z9bca456efe = (0x111b + 4079 - 0x2109);
         z9a2bf742b1 < z8e3e3fece8 && z9bca456efe; z9a2bf742b1++) {
      z4233ec3918 = z7384753b84[z9a2bf742b1].z407d75b5e5;
      zcee4d7442f = z7384753b84[z9a2bf742b1].z9a2bf742b1;
      z0012a90974 = z7384753b84[z9a2bf742b1].z4780b6a21d;
      for (z4780b6a21d = (0x339 + 1142 - 0x7af);
           z4780b6a21d < zbd7cc20334 &&
           zbb78b9fe38[zcee4d7442f][z4780b6a21d].z407d75b5e5 <= z4233ec3918;
           z4780b6a21d++)
        ;
      if (z4780b6a21d == zbd7cc20334)
        z9bca456efe = (0x1492 + 1106 - 0x18e3);
      else {
        for (z4780b6a21d = (0x741 + 7490 - 0x2483);
             z4780b6a21d < z761a475b76 &&
             zbb78b9fe38[z4780b6a21d][z0012a90974].z407d75b5e5 <= z4233ec3918;
             z4780b6a21d++)
          ;
        if (z4780b6a21d == z761a475b76)
          z9bca456efe = (0x68c + 1714 - 0xd3d);
        else
          z9bca456efe = (0xa2 + 7407 - 0x1d91);
      }
    }
    fprintf(z66ac2a7bdb,
            "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
            "\n",
            z4f615578d2 + (0x475 + 4581 - 0x1659),
            z9bca456efe == (0x111a + 3266 - 0x1ddb) ? "\x59\x45\x53"
                                                    : "\x4e\x4f");
  }
  fclose(z8a2c645eb1);
  fclose(z66ac2a7bdb);
  return (0xe2d + 3681 - 0x1c8e);
}
