
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int z2874f4c78b(int);
int main() {
  FILE *z0293382a04, *z28042ed34a;
  int zf663cd7579, z8a1e9b7120 = (0x1269 + 750 - 0x154d),
                   z32de4ca788 = (0x21f + 2647 - 0xbfe), z93c0757287,
                   z6f55580b09, zc5cf723f91, z1c7e9d8639;
  z0293382a04 = fopen("\x43\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70"
                      "\x74\x30\x28\x31\x29\x2e\x69\x6e",
                      "\x72");
  z28042ed34a = fopen("\x6f\x75\x74\x70\x75\x74\x2e\x74\x78\x74", "\x77");
  fscanf(z0293382a04, "\x25\x64", &z93c0757287);
  for (zc5cf723f91 = (0x1a04 + 1885 - 0x2160); zc5cf723f91 <= z93c0757287;
       zc5cf723f91++) {
    fscanf(z0293382a04, "\x25\x64\x20\x25\x64", &z8a1e9b7120, &z32de4ca788);
    z1c7e9d8639 = (0x3f1 + 4647 - 0x1618);
    for (zf663cd7579 = z8a1e9b7120; zf663cd7579 <= z32de4ca788; zf663cd7579++) {
      if (z2874f4c78b(zf663cd7579)) {
        z6f55580b09 = (int)sqrt((double)zf663cd7579);
        if (z6f55580b09 * z6f55580b09 == zf663cd7579) {
          if (z2874f4c78b(z6f55580b09)) {
            z1c7e9d8639++;
          }
        } else if ((z6f55580b09 + (0x837 + 7204 - 0x245a)) *
                       (z6f55580b09 + (0x1c2f + 1196 - 0x20da)) ==
                   zf663cd7579) {
          if (z2874f4c78b(z6f55580b09)) {
            z1c7e9d8639++;
          }
        }
      }
    }
    fprintf(z28042ed34a,
            "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
            "\n",
            zc5cf723f91, z1c7e9d8639);
  }
  fclose(z0293382a04);
  fclose(z28042ed34a);
  system("\x70\x61\x75\x73\x65");
}
int z2874f4c78b(int z3f018f548c) {
  int z6f55580b09, z34a1398ad2, z8f6c29c629 = (0xfff + 4459 - 0x216a);
  z6f55580b09 = z3f018f548c;
  while (z3f018f548c > (0x232f + 959 - 0x26ee)) {
    z34a1398ad2 = z3f018f548c % (0x16e3 + 3603 - 0x24ec);
    z8f6c29c629 = z34a1398ad2 + z8f6c29c629 * (0x6c3 + 3188 - 0x132d);
    z3f018f548c = z3f018f548c / (0xd14 + 2528 - 0x16ea);
  }
  if (z6f55580b09 == z8f6c29c629)
    return (0x87 + 7967 - 0x1fa5);
  else
    return (0x6d + 9831 - 0x26d4);
}
