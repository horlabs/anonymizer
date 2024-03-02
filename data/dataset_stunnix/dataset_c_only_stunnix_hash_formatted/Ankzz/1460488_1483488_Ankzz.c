
#include <stdio.h>

int main(int zff7aa166f6, char *zb6ef5b98b1[]) {
  FILE *z9a73f45b9b, *z8740921eab;
  z9a73f45b9b = (zff7aa166f6 <= (0x33d + 1327 - 0x86b))
                    ? fopen("\x69\x6e\x70\x75\x74\x2e\x74\x78\x74", "\x72")
                    : fopen(zb6ef5b98b1[(0x971 + 7443 - 0x2683)], "\x72");
  z8740921eab = fopen("\x6f\x75\x74\x70\x75\x74\x2e\x74\x78\x74", "\x77\x2b");
  if (z9a73f45b9b) {
    int z7f81d177bb;
    int z6d932e9df2;
    fscanf(z9a73f45b9b, "\x25\x64", &z7f81d177bb);
    for (z6d932e9df2 = (0x92b + 4904 - 0x1c53); z6d932e9df2 < z7f81d177bb;
         z6d932e9df2++) {
      int x, y;
      int zcf00536f90, zb5cd61d8d6;
      int za2eb366da2 = (0x1352 + 2638 - 0x1d9f);
      int zf2c33e00a5 = (0x1c60 + 10 - 0x1c6a);
      int z5c41993d2d, z2e945d75d2 = (0x1494 + 928 - 0x182a);
      fscanf(z9a73f45b9b, "\x25\x64\x20\x25\x64", &x, &y);
      zf2c33e00a5 = x;
      while (zf2c33e00a5 = zf2c33e00a5 / (0x534 + 1540 - 0xb2e)) {
        za2eb366da2++;
        z2e945d75d2 *= (0x1ad + 6594 - 0x1b65);
      }
      for (zcf00536f90 = x; zcf00536f90 <= y; zcf00536f90++) {
        int z2cf8fa38dc = z2e945d75d2;
        while ((z2cf8fa38dc = z2cf8fa38dc / (0x2443 + 597 - 0x268e)) >=
               (0x9c5 + 1851 - 0x10f6)) {
          int z18132722c6 =
              (zcf00536f90 % z2cf8fa38dc) * (z2e945d75d2 / z2cf8fa38dc) +
              (zcf00536f90 / z2cf8fa38dc);
          if (zcf00536f90 < z18132722c6 && z18132722c6 <= y &&
              z18132722c6 >= x) {
            zf2c33e00a5++;
          }
        }
      }
      fprintf(z8740921eab,
              "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
              "\n",
              z6d932e9df2 + (0x11b4 + 4574 - 0x2391), zf2c33e00a5);
    }
    fclose(z9a73f45b9b);
  }
  fclose(z8740921eab);
  return (0x7d9 + 3188 - 0x144d);
}
