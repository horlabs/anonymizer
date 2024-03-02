
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int z9f0f557e84, zeb49751e39;
int zb94b6630e5[(0x613 + 5855 - 0x1c84)][(0x16b6 + 1619 - 0x1c9b)];
int z6bf5a22e76[(0x1d88 + 1384 - 0x2282)][(0xba6 + 2057 - 0x1341)];
struct zb3219f78b9 {
  int x, y;
} z3eff284180[11000];
int z74f64839e8;
int z55e6530d83[(0xb19 + 1242 - 0xf85)][(0x1870 + 82 - 0x1854)];
int zc91b1f817e(const void *z70cdef1ef6, const void *z85cdfdc9ed) {
  struct zb3219f78b9 *zbd3dc8d7b1 = (struct zb3219f78b9 *)z70cdef1ef6,
                     *ze40a81394f = (struct zb3219f78b9 *)z85cdfdc9ed;
  return zb94b6630e5[ze40a81394f->x][ze40a81394f->y] -
         zb94b6630e5[zbd3dc8d7b1->x][zbd3dc8d7b1->y];
}
int main() {
  int z93f8ffe959, z46f03ee5c9 = (0x6bd + 1978 - 0xe77);
  for (scanf("\x25\x64", &z93f8ffe959); z93f8ffe959; z93f8ffe959--) {
    int z751047649c;
    z74f64839e8 = (0xce3 + 5103 - 0x20d2);
    scanf("\x25\x64\x25\x64", &z9f0f557e84, &zeb49751e39);
    for (z751047649c = (0x569 + 6552 - 0x1f01); z751047649c < z9f0f557e84;
         z751047649c++) {
      int zf4fae02419;
      for (zf4fae02419 = (0x21f + 2969 - 0xdb8); zf4fae02419 < zeb49751e39;
           zf4fae02419++) {
        scanf("\x25\x64", zb94b6630e5[z751047649c] + zf4fae02419);
        z3eff284180[z74f64839e8].x = z751047649c;
        z3eff284180[z74f64839e8].y = zf4fae02419;
        z74f64839e8++;
        z6bf5a22e76[z751047649c][zf4fae02419] = (0x1f3 + 5400 - 0x16a7);
      }
    }
    qsort(z3eff284180, z74f64839e8, sizeof(struct zb3219f78b9), zc91b1f817e);
    memset(z55e6530d83, (0x1f35 + 1353 - 0x247e), sizeof(z55e6530d83));
    for (z751047649c = (0x6cd + 4603 - 0x18c8); z751047649c < z74f64839e8;
         z751047649c++) {
      int zf4fae02419, zf867c87568 = zb94b6630e5[z3eff284180[z751047649c].x]
                                                [z3eff284180[z751047649c].y];
      for (zf4fae02419 = (0x1575 + 3991 - 0x250c); zf4fae02419 < z9f0f557e84;
           zf4fae02419++) {
        if (z6bf5a22e76[zf4fae02419][z3eff284180[z751047649c].y] >
                zf867c87568 &&
            z55e6530d83[zf4fae02419][z3eff284180[z751047649c].y])
          break;
      }
      if (zf4fae02419 >= z9f0f557e84) {
        for (zf4fae02419 = (0x19af + 2753 - 0x2470); zf4fae02419 < z9f0f557e84;
             zf4fae02419++) {
          if (z6bf5a22e76[zf4fae02419][z3eff284180[z751047649c].y] >
              zf867c87568) {
            z6bf5a22e76[zf4fae02419][z3eff284180[z751047649c].y] = zf867c87568;
          }
        }
      } else {
        for (zf4fae02419 = (0x9c + 4008 - 0x1044); zf4fae02419 < zeb49751e39;
             zf4fae02419++) {
          if (z6bf5a22e76[z3eff284180[z751047649c].x][zf4fae02419] >
                  zf867c87568 &&
              z55e6530d83[z3eff284180[z751047649c].x][zf4fae02419])
            break;
        }
        if (zf4fae02419 >= zeb49751e39) {
          for (zf4fae02419 = (0x18f + 3961 - 0x1108); zf4fae02419 < zeb49751e39;
               zf4fae02419++) {
            if (z6bf5a22e76[z3eff284180[z751047649c].x][zf4fae02419] >
                zf867c87568) {
              z6bf5a22e76[z3eff284180[z751047649c].x][zf4fae02419] =
                  zf867c87568;
            }
          }
        } else {
          break;
        }
      }
      z55e6530d83[z3eff284180[z751047649c].x][z3eff284180[z751047649c].y] =
          (0x16d1 + 2394 - 0x202a);
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", ++z46f03ee5c9);
    if (z751047649c >= z74f64839e8) {
      puts("\x59\x45\x53");
    } else {
      puts("\x4e\x4f");
    }
  }
  return (0x1529 + 343 - 0x1680);
}
