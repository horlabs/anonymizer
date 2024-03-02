
#include <stdio.h>

int main() {
  int ze81fb95544[(0x602 + 8107 - 0x25a9)][(0x9d1 + 4612 - 0x1bd1)],
      zdf619c1a05[(0x446 + 4984 - 0x17ba)][(0x1e3 + 6509 - 0x1b4c)];
  FILE *zc4a33bc197, *zebe6e26843;
  zc4a33bc197 = fopen("\x41\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70"
                      "\x74\x32\x2e\x69\x6e",
                      "\x72");
  zebe6e26843 =
      fopen("\x6d\x61\x67\x69\x63\x5f\x6f\x75\x74\x2e\x74\x78\x74", "\x77");
  int ze390c5a36e, z08f446a211, ze33ab2d80d, z90315087c4, za6d09a1118, y,
      z74923e10ae, z730a3c0d03;
  fscanf(zc4a33bc197, "\x25\x64", &z730a3c0d03);
  z74923e10ae = (0x2e0 + 3436 - 0x104b);
  while (z74923e10ae <= z730a3c0d03) {
    fscanf(zc4a33bc197, "\x25\x64", &ze390c5a36e);
    for (ze33ab2d80d = (0x8b + 1106 - 0x4dd);
         ze33ab2d80d < (0x8b3 + 4209 - 0x1920); ze33ab2d80d++) {
      fscanf(zc4a33bc197, "\x25\x64\x20\x25\x64\x20\x25\x64\x20\x25\x64",
             &ze81fb95544[ze33ab2d80d][(0xc28 + 3839 - 0x1b27)],
             &ze81fb95544[ze33ab2d80d][(0x23f3 + 729 - 0x26cb)],
             &ze81fb95544[ze33ab2d80d][(0x460 + 64 - 0x49e)],
             &ze81fb95544[ze33ab2d80d][(0x522 + 2899 - 0x1072)]);
    }
    fscanf(zc4a33bc197, "\x25\x64", &z08f446a211);
    for (ze33ab2d80d = (0x2157 + 600 - 0x23af);
         ze33ab2d80d < (0x21f + 955 - 0x5d6); ze33ab2d80d++) {
      fscanf(zc4a33bc197, "\x25\x64\x20\x25\x64\x20\x25\x64\x20\x25\x64",
             &zdf619c1a05[ze33ab2d80d][(0x880 + 6783 - 0x22ff)],
             &zdf619c1a05[ze33ab2d80d][(0x1669 + 2429 - 0x1fe5)],
             &zdf619c1a05[ze33ab2d80d][(0x74f + 1023 - 0xb4c)],
             &zdf619c1a05[ze33ab2d80d][(0x94b + 3778 - 0x180a)]);
    }
    za6d09a1118 = (0x824 + 3706 - 0x169e);
    for (ze33ab2d80d = (0x113 + 5331 - 0x15e6);
         ze33ab2d80d < (0xfcb + 4443 - 0x2122); ze33ab2d80d++) {
      for (z90315087c4 = (0x1a9b + 822 - 0x1dd1);
           z90315087c4 < (0xebb + 5416 - 0x23df); z90315087c4++) {
        if (ze81fb95544[ze390c5a36e - (0xdcf + 5862 - 0x24b4)][ze33ab2d80d] ==
            zdf619c1a05[z08f446a211 - (0x2491 + 558 - 0x26be)][z90315087c4]) {
          za6d09a1118++;
          y = ze81fb95544[ze390c5a36e - (0x1c14 + 2226 - 0x24c5)][ze33ab2d80d];
        }
      }
    }
    if (z74923e10ae == z730a3c0d03) {
      if (za6d09a1118 == (0x1172 + 4845 - 0x245e))
        fprintf(zebe6e26843, "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64",
                z74923e10ae, y);
      else if (za6d09a1118 > (0x4f5 + 2963 - 0x1087))
        fprintf(zebe6e26843,
                "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x42\x61\x64\x20\x6d"
                "\x61\x67\x69\x63\x69\x61\x6e\x21",
                z74923e10ae);
      else
        fprintf(zebe6e26843,
                "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x56\x6f\x6c\x75\x6e"
                "\x74\x65\x65\x72\x20\x63\x68\x65\x61\x74\x65\x64\x21",
                z74923e10ae);
    } else {
      if (za6d09a1118 == (0x9ef + 3752 - 0x1896))
        fprintf(zebe6e26843,
                "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
                "\n",
                z74923e10ae, y);
      else if (za6d09a1118 > (0x9dc + 2603 - 0x1406))
        fprintf(zebe6e26843,
                "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x42\x61\x64\x20\x6d"
                "\x61\x67\x69\x63\x69\x61\x6e\x21"
                "\n",
                z74923e10ae);
      else
        fprintf(zebe6e26843,
                "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x56\x6f\x6c\x75\x6e"
                "\x74\x65\x65\x72\x20\x63\x68\x65\x61\x74\x65\x64\x21"
                "\n",
                z74923e10ae);
    }
    z74923e10ae++;
  }
  fclose(zc4a33bc197);
  fclose(zebe6e26843);
  return (0x38b + 5587 - 0x195e);
}
