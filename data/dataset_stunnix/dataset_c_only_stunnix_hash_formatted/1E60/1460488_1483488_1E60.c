
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int z6892658404, z2f214580a4;
  scanf("\x25\x64"
        "\n",
        &z6892658404);
  for (z2f214580a4 = (0x9c + 2864 - 0xbcb); z2f214580a4 <= z6892658404;
       z2f214580a4++) {
    int z9fce5cadeb, z2fdcd4d1ec;
    scanf("\x25\x64\x20\x25\x64"
          "\n",
          &z9fce5cadeb, &z2fdcd4d1ec);
    int z7d827d1ef8 = (0x1146 + 3448 - 0x1ebe);
    int z166541dd65;
    for (z166541dd65 = z9fce5cadeb; z166541dd65 <= z2fdcd4d1ec; z166541dd65++) {
      char zafdd69af2a[(0x3ef + 2143 - 0xbea)],
          za30de44796[(0x16f0 + 107 - 0x16f7)];
      int zc2a49319dc;
      sprintf(zafdd69af2a, "\x25\x64", z166541dd65);
      zc2a49319dc = strlen(zafdd69af2a);
      strcpy(za30de44796, zafdd69af2a);
      while ((0xb3f + 2719 - 0x15dd)) {
        char z59197f9d8e = za30de44796[zc2a49319dc - (0x555 + 3116 - 0x1180)];
        memmove(&za30de44796[(0x152a + 2729 - 0x1fd2)],
                &za30de44796[(0x5a5 + 1630 - 0xc03)],
                sizeof(char) * (zc2a49319dc - (0x2138 + 1336 - 0x266f)));
        za30de44796[(0x65c + 7137 - 0x223d)] = z59197f9d8e;
        if (strcmp(za30de44796, zafdd69af2a) == (0x69a + 6093 - 0x1e67))
          break;
        if (za30de44796[(0x746 + 318 - 0x884)] ==
            ((char)(0x9ac + 1133 - 0xde9)))
          continue;
        int z463e2f9984 = atoi(za30de44796);
        if (z9fce5cadeb <= z463e2f9984 && z463e2f9984 <= z2fdcd4d1ec) {
          z7d827d1ef8++;
        }
      }
    }
    assert(z7d827d1ef8 % (0x1164 + 4669 - 0x239f) == (0x2a3 + 1549 - 0x8b0));
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z2f214580a4, z7d827d1ef8 / (0x1c03 + 1660 - 0x227d));
  }
  return (0x3ab + 3023 - 0xf7a);
}
