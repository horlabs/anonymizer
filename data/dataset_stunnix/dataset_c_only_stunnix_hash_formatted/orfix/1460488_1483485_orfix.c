
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  freopen("\x41\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x34\x2e"
          "\x69\x6e",
          "\x72", stdin);
  int z6ec348a9be = (0x14a + 5484 - 0x16b6);
  int z149d666d4c;
  char zff88ddd4a5[] = "\x79\x68\x65\x73\x6f\x63\x76\x78\x64\x75\x69\x67\x6c"
                       "\x62\x6b\x72\x7a\x74\x6e\x77\x6a\x70\x66\x6d\x61\x71";
  char z86d6f3e534[(0x1e48 + 1888 - 0x2542)] = "";
  scanf("\x25\x64"
        "\n",
        &z149d666d4c);
  while (z6ec348a9be < z149d666d4c) {
    char *z44f0f8c515 = z86d6f3e534;
    fgets(z86d6f3e534, (0x70f + 3482 - 0x1443), stdin);
    for (; *z44f0f8c515 != '\0'; z44f0f8c515++) {
      if (isalpha(*z44f0f8c515))
        *z44f0f8c515 =
            zff88ddd4a5[*z44f0f8c515 - ((char)(0x1c7b + 1574 - 0x2240))];
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73", ++z6ec348a9be,
           z86d6f3e534);
  }
  return (0x1805 + 3208 - 0x248d);
}
