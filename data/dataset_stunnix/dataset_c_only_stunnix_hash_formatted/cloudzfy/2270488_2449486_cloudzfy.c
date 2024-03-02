
#include <stdio.h>
#include <string.h>

int z4c8ae2b8f5, z6f4ac91993,
    z9f300234c8[(0x25e5 + 60 - 0x25bd)][(0x1a66 + 3138 - 0x2644)],
    x[(0x229 + 4329 - 0x12ae)][(0x203a + 130 - 0x2058)];
int main() {
  int z79b90d37fd, flag;
  freopen("\x42\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x31\x2e"
          "\x69\x6e\x2e\x74\x78\x74",
          "\x72", stdin);
  freopen("\x42\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x31\x2e"
          "\x6f\x75\x74\x2e\x74\x78\x74",
          "\x77", stdout);
  scanf("\x25\x64", &z79b90d37fd);
  for (int zbfb8595d99 = (0xcc0 + 1287 - 0x11c6); zbfb8595d99 <= z79b90d37fd;
       zbfb8595d99++) {
    memset(x, (0x2b1 + 4245 - 0x1346), sizeof(x));
    scanf("\x25\x64\x25\x64", &z4c8ae2b8f5, &z6f4ac91993);
    for (int zfa2f2d3822 = (0x302 + 4398 - 0x1430); zfa2f2d3822 < z4c8ae2b8f5;
         zfa2f2d3822++) {
      for (int z7f848561f2 = (0x1155 + 1667 - 0x17d8);
           z7f848561f2 < z6f4ac91993; z7f848561f2++) {
        scanf("\x25\x64", &z9f300234c8[zfa2f2d3822][z7f848561f2]);
      }
    }
    for (int z6bd90b267a = (0xe1a + 6312 - 0x26c2);
         z6bd90b267a < z4c8ae2b8f5 + z6f4ac91993; z6bd90b267a++) {
      int min = (0x1587 + 3712 - 0x233f), z33890fdf76[(0x406 + 6035 - 0x1b97)];
      for (int zfa2f2d3822 = (0x1080 + 2230 - 0x1936);
           zfa2f2d3822 < z4c8ae2b8f5; zfa2f2d3822++) {
        for (int z7f848561f2 = (0xaa5 + 4836 - 0x1d89);
             z7f848561f2 < z6f4ac91993; z7f848561f2++) {
          if (!x[zfa2f2d3822][z7f848561f2] &&
              z9f300234c8[zfa2f2d3822][z7f848561f2] < min) {
            z33890fdf76[(0x146f + 4294 - 0x2535)] = zfa2f2d3822;
            z33890fdf76[(0x170c + 1711 - 0x1dba)] = z7f848561f2;
            min = z9f300234c8[zfa2f2d3822][z7f848561f2];
          }
        }
      }
      flag = (0xdf8 + 4142 - 0x1e25);
      for (int zfa2f2d3822 = (0x3e1 + 5740 - 0x1a4d); zfa2f2d3822 < z4c8ae2b8f5;
           zfa2f2d3822++) {
        if (!x[zfa2f2d3822][z33890fdf76[(0x101b + 5504 - 0x259a)]] &&
            z9f300234c8[zfa2f2d3822][z33890fdf76[(0xe80 + 1786 - 0x1579)]] !=
                z9f300234c8[z33890fdf76[(0xb93 + 5078 - 0x1f69)]]
                           [z33890fdf76[(0x928 + 4614 - 0x1b2d)]]) {
          flag = (0x1a13 + 2195 - 0x22a6);
          break;
        }
      }
      if (!flag) {
        flag = (0xd95 + 1740 - 0x145f);
        for (int z7f848561f2 = (0xad8 + 2793 - 0x15c1);
             z7f848561f2 < z6f4ac91993; z7f848561f2++) {
          if (!x[z33890fdf76[(0x6c6 + 3597 - 0x14d3)]][z7f848561f2] &&
              z9f300234c8[z33890fdf76[(0x159d + 3657 - 0x23e6)]][z7f848561f2] !=
                  z9f300234c8[z33890fdf76[(0x2117 + 378 - 0x2291)]]
                             [z33890fdf76[(0xa7 + 7856 - 0x1f56)]]) {
            flag = (0xc76 + 1658 - 0x12f0);
            break;
          }
        }
      }
      if (flag == (0x266 + 3514 - 0x101f)) {
        for (int zfa2f2d3822 = (0x15cf + 3950 - 0x253d);
             zfa2f2d3822 < z4c8ae2b8f5; zfa2f2d3822++) {
          x[zfa2f2d3822][z33890fdf76[(0x1427 + 2977 - 0x1fc7)]] =
              (0x158a + 919 - 0x1920);
        }
      } else if (flag == (0x16d7 + 2911 - 0x2234)) {
        for (int z7f848561f2 = (0x84 + 2293 - 0x979); z7f848561f2 < z6f4ac91993;
             z7f848561f2++) {
          x[z33890fdf76[(0x838 + 7502 - 0x2586)]][z7f848561f2] =
              (0xfb5 + 3870 - 0x1ed2);
        }
      } else
        break;
    }
    if (flag == (0x1593 + 706 - 0x1855)) {
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x4e\x4f"
             "\n",
             zbfb8595d99);
    } else {
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x59\x45\x53"
             "\n",
             zbfb8595d99);
    }
  }
  return (0x1354 + 65 - 0x1395);
}
