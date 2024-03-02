
#include <stdio.h>

int main(int zd69417efc6, char *z13018c2655[]) {
  FILE *zfc406c79cb, *za0f612cc14;
  zfc406c79cb = (zd69417efc6 <= (0x1 + 7305 - 0x1c89))
                    ? fopen("\x69\x6e\x70\x75\x74\x2e\x74\x78\x74", "\x72\x2b")
                    : fopen(z13018c2655[(0x1633 + 2785 - 0x2113)], "\x72\x2b");
  za0f612cc14 = fopen("\x6f\x75\x74\x70\x75\x74\x2e\x74\x78\x74", "\x77\x2b");
  if (zfc406c79cb) {
    int z168f6b890f;
    int z379ce9ffa2;
    int z53071e14f2, zfc8d5f1f7a;
    fscanf(zfc406c79cb, "\x25\x64", &z168f6b890f);
    for (z379ce9ffa2 = (0x264 + 29 - 0x281); z379ce9ffa2 < z168f6b890f;
         z379ce9ffa2++) {
      int ze0333ad65e, zb9aafd2490, zce6757a0c9;
      int zcc7407423e = (0xe7b + 2604 - 0x18a7),
          zab564b07a7 = (0x18b2 + 3296 - 0x2592);
      fscanf(zfc406c79cb, "\x25\x64\x20\x25\x64\x20\x25\x64", &ze0333ad65e,
             &zb9aafd2490, &zce6757a0c9);
      for (z53071e14f2 = (0x1646 + 2148 - 0x1eaa); z53071e14f2 < ze0333ad65e;
           z53071e14f2++) {
        int x, y, zaa1f355c2d;
        short flag = (0x132b + 996 - 0x170f);
        fscanf(zfc406c79cb, "\x25\x64", &x);
        for (y = (0x8ea + 5988 - 0x204b), zaa1f355c2d = zce6757a0c9;
             y > (0x162a + 2073 - 0x1e42) && zaa1f355c2d <= x;
             y = zfc8d5f1f7a) {
          y = (x - zaa1f355c2d) / (0x15dd + 1617 - 0x1c2c);
          zfc8d5f1f7a = (y > zaa1f355c2d)
                            ? y - zaa1f355c2d + (0x1043 + 1866 - 0x178c)
                            : zaa1f355c2d - y;
          if (zfc8d5f1f7a > (0x81c + 2687 - 0x1299)) {
            if (y < zaa1f355c2d)
              break;
            zaa1f355c2d++;
          } else if (zfc8d5f1f7a == (0x118c + 5055 - 0x2549)) {
            if (zab564b07a7 < zb9aafd2490) {
              zab564b07a7++;
              zcc7407423e++;
              flag = (0x1c5f + 109 - 0x1ccb);
            } else if (y < zaa1f355c2d)
              break;
            zaa1f355c2d++;
          } else {
            if (!flag) {
              zcc7407423e++;
              flag = (0xe67 + 3522 - 0x1c29);
            } else
              zab564b07a7--;
            break;
          }
        }
      }
      fprintf(za0f612cc14,
              "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
              "\n",
              z379ce9ffa2 + (0x3f1 + 7998 - 0x232e), zcc7407423e);
    }
  }
  return (0x9b + 6917 - 0x1ba0);
}
