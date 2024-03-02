
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *zcea3e0eede(char *, int);
int main() {
  char z3548af9efd[(0x1522 + 1407 - 0x1a97)], *z6ae89a102e;
  int za3fc8bd26c, zf7b0ee1f55, z3f284de7bb, za7b011e6aa,
      z73c28f734c = (0x1b64 + 1945 - 0x22fd);
  long int z2eaa9fb7b6, z276331c467, z3b4202c9da;
  FILE *z7f56d6437e, *zd8e88ed519;
  z7f56d6437e = fopen("\x43\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70"
                      "\x74\x30\x2e\x69\x6e",
                      "\x72");
  if (z7f56d6437e == NULL)
    printf("\x45\x52\x52\x4f\x52");
  else {
    fscanf(z7f56d6437e, "\x25\x64", &za3fc8bd26c);
    for (zf7b0ee1f55 = (0x123a + 4149 - 0x226f); zf7b0ee1f55 < za3fc8bd26c;
         zf7b0ee1f55++) {
      z73c28f734c = (0x5c + 7606 - 0x1e12);
      fscanf(z7f56d6437e, "\x25\x6c\x64\x25\x6c\x64", &z2eaa9fb7b6,
             &z276331c467);
      for (z3b4202c9da = z2eaa9fb7b6; z3b4202c9da < z276331c467;
           z3b4202c9da++) {
        itoa(z3b4202c9da, z3548af9efd, (0x1dd + 1650 - 0x845));
        for (z3f284de7bb = (0x61 + 4894 - 0x137f);
             z3f284de7bb < strlen(z3548af9efd) - (0x1bd4 + 596 - 0x1e27);
             z3f284de7bb++) {
          z6ae89a102e = zcea3e0eede(&z3548af9efd[(0x7e1 + 7709 - 0x25fe)],
                                    strlen(z3548af9efd));
          za7b011e6aa = atoi(z6ae89a102e);
          if (za7b011e6aa > z3b4202c9da && za7b011e6aa <= z276331c467)
            z73c28f734c++;
        }
      }
      zd8e88ed519 = fopen("\x6f\x75\x74\x33\x2e\x74\x78\x74", "\x61");
      fprintf(zd8e88ed519,
              "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
              "\n",
              zf7b0ee1f55 + (0x1a5 + 8733 - 0x23c1), z73c28f734c);
    }
  }
}
char *zcea3e0eede(char *z184df998d2, int z12905e8036) {
  char z7b6d5b5b32;
  int zf7b0ee1f55;
  z7b6d5b5b32 = *(z184df998d2 + z12905e8036 - (0x1dc4 + 352 - 0x1f23));
  for (zf7b0ee1f55 = z12905e8036 - (0x264 + 7748 - 0x20a7);
       zf7b0ee1f55 > (0x601 + 4795 - 0x18bc); zf7b0ee1f55--) {
    *(z184df998d2 + zf7b0ee1f55) =
        *(z184df998d2 + zf7b0ee1f55 - (0x249 + 6723 - 0x1c8b));
  }
  *z184df998d2 = z7b6d5b5b32;
  return z184df998d2;
}
