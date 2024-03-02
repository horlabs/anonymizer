
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
  FILE *zd9564b3be0, *zf3a7203b6c;
  zd9564b3be0 = freopen("\x43\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d"
                        "\x70\x74\x30\x2e\x69\x6e",
                        "\x72", stdin);
  zf3a7203b6c = freopen("\x43\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d"
                        "\x70\x74\x30\x2e\x6f\x75\x74",
                        "\x77", stdout);
  int z8a4688ea01, ze052171ac3, z8c5ec8c33e, zd7837df5a8, zefc953b53a,
      z9306d4e8fc, z684bbb1693, zc0511441db, z54889ac4d9, z0bdad1397d,
      za43b318091[(0x431 + 4193 - 0x1488)];
  scanf("\x25\x64", &z8a4688ea01);
  for (ze052171ac3 = (0x2b0 + 365 - 0x41c); ze052171ac3 <= z8a4688ea01;
       ze052171ac3++) {
    z0bdad1397d = (0x333 + 5743 - 0x19a2);
    scanf("\x25\x64\x25\x64", &z8c5ec8c33e, &zd7837df5a8);
    if (zd7837df5a8 < (0xcec + 4516 - 0x1e7b)) {
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x30"
             "\n",
             ze052171ac3);
      continue;
    }
    for (zefc953b53a = z8c5ec8c33e; zefc953b53a < zd7837df5a8; zefc953b53a++) {
      za43b318091[(0x427 + 2184 - 0xcaf)] = zefc953b53a;
      zc0511441db = (0x4c9 + 5387 - 0x19d4);
      z54889ac4d9 = (0x179b + 609 - 0x19fb);
      while (za43b318091[(0x831 + 1568 - 0xe51)] /= (0xab3 + 466 - 0xc7b)) {
        zc0511441db++;
        z54889ac4d9 *= (0x6a1 + 756 - 0x98b);
      }
      za43b318091[(0x19d + 9288 - 0x25e5)] = zefc953b53a;
      for (z684bbb1693 = (0x67c + 6078 - 0x1e39); z684bbb1693 <= zc0511441db;
           z684bbb1693++)
        za43b318091[z684bbb1693] =
            za43b318091[z684bbb1693 - (0xc96 + 2536 - 0x167d)] / z54889ac4d9 +
            (0x10e3 + 1952 - 0x1879) *
                (za43b318091[z684bbb1693 - (0x167a + 3447 - 0x23f0)] %
                 z54889ac4d9);
      for (z9306d4e8fc = (0x1d65 + 2204 - 0x2601); z9306d4e8fc < zc0511441db;
           z9306d4e8fc++)
        for (z684bbb1693 = z9306d4e8fc + (0xb6f + 528 - 0xd7e);
             z684bbb1693 <= zc0511441db; z684bbb1693++)
          if (za43b318091[z684bbb1693] == za43b318091[z9306d4e8fc])
            za43b318091[z684bbb1693] = (0xab2 + 6500 - 0x2416);
      for (z9306d4e8fc = (0xae8 + 1286 - 0xfed); z9306d4e8fc <= zc0511441db;
           z9306d4e8fc++) {
        if (za43b318091[z9306d4e8fc] <= zefc953b53a) {
          za43b318091[z9306d4e8fc] = (0x9e8 + 6039 - 0x217f);
          continue;
        }
        if (za43b318091[z9306d4e8fc] > zd7837df5a8) {
          za43b318091[z9306d4e8fc] = (0x1325 + 2371 - 0x1c68);
          continue;
        }
        if (za43b318091[z9306d4e8fc] < z8c5ec8c33e) {
          za43b318091[z9306d4e8fc] = (0x906 + 2720 - 0x13a6);
          continue;
        }
        if (za43b318091[z9306d4e8fc] > (0x15c4 + 1848 - 0x1cfc)) {
          z0bdad1397d++;
          continue;
        }
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           ze052171ac3, z0bdad1397d);
  }
  fclose(zd9564b3be0);
  fclose(zf3a7203b6c);
  return (0xf1 + 6913 - 0x1bf2);
}
