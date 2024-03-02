
#include <stdio.h>

int main() {
  int z612057b444, zb30cc237bb, z3dfceddbe3, zdf4ba60c6d, zfca606fa3a,
      z1044c2957c, z2229cdff95, za4d96917cd = (0xba4 + 5987 - 0x2307);
  FILE *zebd303c777, *zef990dbd82;
  zebd303c777 = fopen("\x42\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70"
                      "\x74\x30\x2e\x69\x6e",
                      "\x72");
  if (zebd303c777 == NULL)
    printf("\x45\x52\x52\x4f\x52"
           "\n");
  else {
    fscanf(zebd303c777, "\x25\x64", &z612057b444);
    for (zdf4ba60c6d = (0xb86 + 1707 - 0x1231); zdf4ba60c6d < z612057b444;
         zdf4ba60c6d++) {
      za4d96917cd = (0x1c6c + 372 - 0x1de0);
      fscanf(zebd303c777, "\x25\x64", &z1044c2957c);
      fscanf(zebd303c777, "\x25\x64", &zb30cc237bb);
      fscanf(zebd303c777, "\x25\x64", &z3dfceddbe3);
      for (zfca606fa3a = (0x9b + 1517 - 0x688); zfca606fa3a < z1044c2957c;
           zfca606fa3a++) {
        fscanf(zebd303c777, "\x25\x64", &z2229cdff95);
        if (z2229cdff95 / (0x91f + 1662 - 0xf9a) >= z3dfceddbe3)
          za4d96917cd++;
        else if (z2229cdff95 % (0x455 + 4368 - 0x1562) >
                     (0x12d7 + 4401 - 0x2408) &&
                 z2229cdff95 / (0xf6c + 5991 - 0x26d0) +
                         (0x1945 + 102 - 0x19aa) >=
                     z3dfceddbe3)
          za4d96917cd++;
        else if ((zb30cc237bb > (0xd1b + 2441 - 0x16a4) &&
                  z2229cdff95 % (0x4e3 + 5707 - 0x1b2b) ==
                      (0xa0d + 4105 - 0x1a14) &&
                  z2229cdff95 / (0x475 + 3288 - 0x114a) +
                          (0x5b6 + 6268 - 0x1e30) >=
                      z3dfceddbe3) ||
                 (zb30cc237bb > (0xa47 + 6280 - 0x22cf) &&
                  z2229cdff95 % (0x22e5 + 599 - 0x2539) ==
                      (0x579 + 7746 - 0x23bb) &&
                  z2229cdff95 / (0x289 + 5877 - 0x197b) +
                          (0x498 + 2802 - 0xf89) ==
                      z3dfceddbe3 &&
                  z2229cdff95 > (0xcbc + 5218 - 0x211e))) {
          za4d96917cd++;
          zb30cc237bb--;
        }
      }
      zef990dbd82 =
          fopen("\x6f\x75\x74\x70\x75\x74\x32\x2e\x6f\x75\x74", "\x61");
      fprintf(zef990dbd82,
              "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
              "\n",
              zdf4ba60c6d + (0x108b + 3585 - 0x1e8b), za4d96917cd);
    }
  }
}
