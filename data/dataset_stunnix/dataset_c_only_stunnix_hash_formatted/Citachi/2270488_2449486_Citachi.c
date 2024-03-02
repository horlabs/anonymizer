
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *z37dc063842, *z9e6bf81529;
  int z9d3d3f7258[(0xea6 + 997 - 0x1281)][(0xf35 + 4998 - 0x22b1)], z97a8c75fcd,
      z5c9bc6256c, z5cb793faa9, zafc3985367, z2aa23c06c3, zfe1be8f29a,
      z6bad172811, flag = (0xc45 + 4253 - 0x1ce2);
  z37dc063842 = fopen("\x42\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70"
                      "\x74\x31\x2e\x69\x6e",
                      "\x72");
  z9e6bf81529 = fopen("\x6f\x75\x74\x70\x75\x74\x2e\x74\x78\x74", "\x77");
  fscanf(z37dc063842, "\x25\x64", &z97a8c75fcd);
  for (z6bad172811 = (0x886 + 223 - 0x964); z6bad172811 <= z97a8c75fcd;
       z6bad172811++) {
    flag = (0x486 + 8079 - 0x2415);
    fscanf(z37dc063842, "\x25\x64\x20\x25\x64", &z5c9bc6256c, &z5cb793faa9);
    for (zafc3985367 = (0x179 + 2115 - 0x9bc); zafc3985367 < z5c9bc6256c;
         zafc3985367++) {
      for (z2aa23c06c3 = (0x1046 + 2045 - 0x1843); z2aa23c06c3 < z5cb793faa9;
           z2aa23c06c3++)
        fscanf(z37dc063842, "\x25\x64", &z9d3d3f7258[zafc3985367][z2aa23c06c3]);
    }
    for (zafc3985367 = (0xcc + 9652 - 0x2680); zafc3985367 < z5c9bc6256c;
         zafc3985367++) {
      zfe1be8f29a = z9d3d3f7258[zafc3985367][(0xe00 + 577 - 0x1041)];
      for (z2aa23c06c3 = (0x1a10 + 420 - 0x1bb4); z2aa23c06c3 < z5cb793faa9;
           z2aa23c06c3++) {
        if (z9d3d3f7258[zafc3985367][z2aa23c06c3] != (0xeb5 + 5084 - 0x2291)) {
          z9d3d3f7258[zafc3985367][z2aa23c06c3] =
              (int)abs(zfe1be8f29a - z9d3d3f7258[zafc3985367][z2aa23c06c3]);
        }
      }
    }
    for (z2aa23c06c3 = (0x114d + 1835 - 0x1878); z2aa23c06c3 < z5cb793faa9;
         z2aa23c06c3++) {
      zfe1be8f29a = z9d3d3f7258[(0x11fc + 555 - 0x1427)][z2aa23c06c3];
      for (zafc3985367 = (0x6ad + 1159 - 0xb34); zafc3985367 < z5c9bc6256c;
           zafc3985367++) {
        if (z9d3d3f7258[zafc3985367][z2aa23c06c3] != (0xb98 + 6268 - 0x2414)) {
          z9d3d3f7258[zafc3985367][z2aa23c06c3] =
              (int)abs(zfe1be8f29a - z9d3d3f7258[zafc3985367][z2aa23c06c3]);
        }
      }
    }
    for (zafc3985367 = (0x362 + 6438 - 0x1c88); zafc3985367 < z5c9bc6256c;
         zafc3985367++) {
      zfe1be8f29a =
          z9d3d3f7258[zafc3985367][z5cb793faa9 - (0xdf1 + 4482 - 0x1f72)];
      if (zfe1be8f29a == (0x2448 + 49 - 0x2479))
        continue;
      for (z2aa23c06c3 = (0x1775 + 23 - 0x178c); z2aa23c06c3 < z5cb793faa9;
           z2aa23c06c3++) {
        if (z9d3d3f7258[zafc3985367][z2aa23c06c3] != (0x1fed + 1758 - 0x26cb)) {
          z9d3d3f7258[zafc3985367][z2aa23c06c3] =
              (int)abs(zfe1be8f29a - z9d3d3f7258[zafc3985367][z2aa23c06c3]);
        }
      }
    }
    for (z2aa23c06c3 = (0x12b8 + 3846 - 0x21be); z2aa23c06c3 < z5cb793faa9;
         z2aa23c06c3++) {
      zfe1be8f29a =
          z9d3d3f7258[z5c9bc6256c - (0xf81 + 4601 - 0x2179)][z2aa23c06c3];
      if (zfe1be8f29a == (0x11b9 + 3247 - 0x1e68))
        continue;
      for (zafc3985367 = (0x70a + 7874 - 0x25cc); zafc3985367 < z5c9bc6256c;
           zafc3985367++) {
        if (z9d3d3f7258[zafc3985367][z2aa23c06c3] != (0xd82 + 398 - 0xf10)) {
          z9d3d3f7258[zafc3985367][z2aa23c06c3] =
              (int)abs(zfe1be8f29a - z9d3d3f7258[zafc3985367][z2aa23c06c3]);
        }
      }
    }
    for (zafc3985367 = (0x540 + 5360 - 0x1a2f);
         zafc3985367 < z5c9bc6256c - (0x1eec + 386 - 0x206d); zafc3985367++) {
      for (z2aa23c06c3 = (0x1137 + 4224 - 0x21b6);
           z2aa23c06c3 < z5cb793faa9 - (0x1cbc + 202 - 0x1d85); z2aa23c06c3++)
        if (z9d3d3f7258[zafc3985367][z2aa23c06c3] != (0x2d2 + 6490 - 0x1c2c)) {
          flag = (0x737 + 2470 - 0x10dc);
          break;
        }
    }
    if (flag == (0x1193 + 3589 - 0x1f98))
      fprintf(z9e6bf81529,
              "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x59\x45\x53"
              "\n",
              z6bad172811);
    else
      fprintf(z9e6bf81529,
              "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x4e\x4f"
              "\n",
              z6bad172811);
  }
  fclose(z37dc063842);
  fclose(z9e6bf81529);
  system("\x70\x61\x75\x73\x65");
}
