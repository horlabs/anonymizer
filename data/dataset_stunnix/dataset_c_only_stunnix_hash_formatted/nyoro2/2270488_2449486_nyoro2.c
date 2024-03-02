
#include <stdio.h>

int main() {
  int zbc6b79e2bf;
  int zcbc82f1e02;
  int z9c4871a728, z9dba4a8634;
  int z61b3adcade, z64ee17b3cf;
  int zbc7fc5235a, z700dc21f37;
  int z587fd257db[(0x352 + 8419 - 0x23b5)][(0xa44 + 357 - 0xb29)];
  int z9962c3b145;
  int z9ffc504518;
  fscanf(stdin,
         "\x25\x64"
         "\n",
         &zbc6b79e2bf);
  for (zcbc82f1e02 = (0xf68 + 3338 - 0x1c72); zcbc82f1e02 < zbc6b79e2bf;
       zcbc82f1e02++) {
    fscanf(stdin,
           "\x25\x64\x20\x25\x64"
           "\n",
           &z9c4871a728, &z9dba4a8634);
    fprintf(stdout, "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
            zcbc82f1e02 + (0xda9 + 5612 - 0x2394));
    for (z61b3adcade = (0xaed + 1264 - 0xfdd); z61b3adcade < z9c4871a728;
         z61b3adcade++) {
      for (z64ee17b3cf = (0xe7b + 2778 - 0x1955); z64ee17b3cf < z9dba4a8634;
           z64ee17b3cf++) {
        fscanf(stdin, "\x25\x64", &(z587fd257db[z61b3adcade][z64ee17b3cf]));
      }
    }
    z9ffc504518 = (0xf79 + 1724 - 0x1634);
    for (z61b3adcade = (0x9e2 + 595 - 0xc35); z61b3adcade < z9c4871a728;
         z61b3adcade++) {
      for (z64ee17b3cf = (0x168a + 1798 - 0x1d90); z64ee17b3cf < z9dba4a8634;
           z64ee17b3cf++) {
        z9962c3b145 = z587fd257db[z61b3adcade][z64ee17b3cf];
        for (zbc7fc5235a = (0x1bbb + 2267 - 0x2496); zbc7fc5235a < z9c4871a728;
             zbc7fc5235a++) {
          if (z587fd257db[zbc7fc5235a][z64ee17b3cf] > z9962c3b145)
            break;
        }
        if (zbc7fc5235a < z9c4871a728) {
          for (z700dc21f37 = (0x113 + 6838 - 0x1bc9); z700dc21f37 < z9dba4a8634;
               z700dc21f37++) {
            if (z587fd257db[z61b3adcade][z700dc21f37] > z9962c3b145)
              break;
          }
          if (z700dc21f37 < z9dba4a8634) {
            z9ffc504518 = (0xbc7 + 3632 - 0x19f7);
            goto za87d01dda4;
          }
        }
      }
    }
  za87d01dda4:
    fprintf(stdout, "\x25\x73", z9ffc504518 ? "\x59\x45\x53" : "\x4e\x4f");
    fprintf(stdout, "\n");
  }
  return (0x1c3c + 1014 - 0x2032);
}
