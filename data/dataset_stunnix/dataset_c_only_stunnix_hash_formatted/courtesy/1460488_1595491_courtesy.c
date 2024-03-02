
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *zb57e9b2e74, *z2be264da96;
void Main() {
  int z12a8282064, z198c3e58e8, zbcc8c8d5ec,
      zb81c2adb87 = (0x2231 + 249 - 0x232a);
  fscanf(zb57e9b2e74, "\x25\x64", &z12a8282064);
  fscanf(zb57e9b2e74, "\x25\x64", &zbcc8c8d5ec);
  fscanf(zb57e9b2e74, "\x25\x64", &z198c3e58e8);
  int zed9948eda1, z0157cfff15, za1edaa1ea5;
  for (zed9948eda1 = (0x155b + 552 - 0x1782); zed9948eda1 <= z12a8282064;
       zed9948eda1++) {
    fscanf(zb57e9b2e74, "\x25\x64", &z0157cfff15);
    za1edaa1ea5 = z0157cfff15 / (0x9d3 + 5634 - 0x1fd2);
    switch (z0157cfff15 % (0x1644 + 2444 - 0x1fcd)) {
    case (0x1f58 + 606 - 0x21b6):
      if (za1edaa1ea5 >= z198c3e58e8) {
        zb81c2adb87++;
      } else if ((za1edaa1ea5 != (0x1582 + 181 - 0x1637)) &&
                 ((za1edaa1ea5 + (0x1937 + 3220 - 0x25ca)) >= z198c3e58e8) &&
                 (zbcc8c8d5ec > (0x145c + 2858 - 0x1f86))) {
        zb81c2adb87++;
        zbcc8c8d5ec--;
      }
      goto z26b04977df;
    case (0x1665 + 3183 - 0x22d3):
      if ((za1edaa1ea5 + (0x2037 + 1355 - 0x2581)) >= z198c3e58e8)
        zb81c2adb87++;
      goto z26b04977df;
    case (0xb8c + 1944 - 0x1322):
      if ((za1edaa1ea5 + (0x1e16 + 2236 - 0x26d1)) >= z198c3e58e8)
        zb81c2adb87++;
      else if ((zbcc8c8d5ec > (0x1a77 + 2706 - 0x2509)) &&
               ((za1edaa1ea5 + (0xa3f + 2989 - 0x15ea)) >= z198c3e58e8)) {
        zb81c2adb87++;
        zbcc8c8d5ec--;
      }
      goto z26b04977df;
    }
  z26b04977df:
    z0157cfff15++;
  }
  fprintf(z2be264da96, "\x25\x64", zb81c2adb87);
}
int main() {
  zb57e9b2e74 = fopen("\x2f\x68\x6f\x6d\x65\x2f\x76\x69\x76\x65\x6b\x2f\x44\x65"
                      "\x73\x6b\x74\x6f\x70\x2f\x73\x2e\x69\x6e",
                      "\x72");
  z2be264da96 = fopen("\x2f\x68\x6f\x6d\x65\x2f\x76\x69\x76\x65\x6b\x2f\x44\x65"
                      "\x73\x6b\x74\x6f\x70\x2f\x73\x2e\x6f\x75\x74",
                      "\x77");
  int z9b9911ffa4, zed9948eda1;
  char z83dcf02994;
  fscanf(zb57e9b2e74, "\x25\x64", &z9b9911ffa4);
  for (zed9948eda1 = (0x1198 + 4759 - 0x242e); zed9948eda1 <= z9b9911ffa4;
       zed9948eda1++) {
    fprintf(z2be264da96, "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
            zed9948eda1);
    Main();
    z83dcf02994 = '\n';
    fputc(z83dcf02994, z2be264da96);
    printf("\x25\x64", zed9948eda1);
  }
  return ((0x1c65 + 1390 - 0x21d2));
}
