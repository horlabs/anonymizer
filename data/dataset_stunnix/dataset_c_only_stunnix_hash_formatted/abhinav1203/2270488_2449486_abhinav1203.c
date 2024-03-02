
#include <stdio.h>

int zb3200b1c16[(0xccd + 3582 - 0x1a62)][(0x14e3 + 3109 - 0x209f)],
    zdfcd3e1d36[(0x430 + 7482 - 0x2101)][(0xb90 + 6745 - 0x2580)];
int main() {
  int zabd90f64b0, z11e1519b24, z186c871c3f, z3e1f3c421c, zadc1080549,
      z4b39e31669, max;
  scanf("\x25\x64", &zabd90f64b0);
  for (z11e1519b24 = (0x15bb + 1086 - 0x19f8); z11e1519b24 <= zabd90f64b0;
       z11e1519b24++) {
    scanf("\x25\x64\x20\x25\x64", &z186c871c3f, &z3e1f3c421c);
    for (zadc1080549 = (0x1275 + 4067 - 0x2258); zadc1080549 < z186c871c3f;
         zadc1080549++)
      for (z4b39e31669 = (0x112a + 2115 - 0x196d); z4b39e31669 < z3e1f3c421c;
           z4b39e31669++) {
        zb3200b1c16[zadc1080549][z4b39e31669] = (0x156 + 2314 - 0x9fc);
        scanf("\x25\x64", &zdfcd3e1d36[zadc1080549][z4b39e31669]);
      }
    for (zadc1080549 = (0xc8 + 9657 - 0x2681); zadc1080549 < z186c871c3f;
         zadc1080549++) {
      max = (0x106d + 1859 - 0x17b0);
      for (z4b39e31669 = (0x10dd + 275 - 0x11f0); z4b39e31669 < z3e1f3c421c;
           z4b39e31669++)
        if (zdfcd3e1d36[zadc1080549][z4b39e31669] > max)
          max = zdfcd3e1d36[zadc1080549][z4b39e31669];
      for (z4b39e31669 = (0xad + 5142 - 0x14c3); z4b39e31669 < z3e1f3c421c;
           z4b39e31669++) {
        if (zb3200b1c16[zadc1080549][z4b39e31669] >= max)
          zb3200b1c16[zadc1080549][z4b39e31669] = max;
      }
    }
    for (zadc1080549 = (0x99b + 6278 - 0x2221); zadc1080549 < z3e1f3c421c;
         zadc1080549++) {
      max = (0x160 + 1699 - 0x803);
      for (z4b39e31669 = (0x47b + 7085 - 0x2028); z4b39e31669 < z186c871c3f;
           z4b39e31669++)
        if (zdfcd3e1d36[z4b39e31669][zadc1080549] > max)
          max = zdfcd3e1d36[z4b39e31669][zadc1080549];
      for (z4b39e31669 = (0xe9b + 3458 - 0x1c1d); z4b39e31669 < z186c871c3f;
           z4b39e31669++)
        if (zb3200b1c16[z4b39e31669][zadc1080549] >= max)
          zb3200b1c16[z4b39e31669][zadc1080549] = max;
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", z11e1519b24);
    for (zadc1080549 = (0x142 + 4680 - 0x138a); zadc1080549 < z186c871c3f;
         zadc1080549++) {
      for (z4b39e31669 = (0x389 + 4062 - 0x1367); z4b39e31669 < z3e1f3c421c;
           z4b39e31669++)
        if (zb3200b1c16[zadc1080549][z4b39e31669] !=
            zdfcd3e1d36[zadc1080549][z4b39e31669])
          break;
      if (z4b39e31669 < z3e1f3c421c)
        break;
    }
    if (zadc1080549 < z186c871c3f)
      printf("\x4e\x4f"
             "\n");
    else
      printf("\x59\x45\x53"
             "\n");
  }
  return (0x18c + 1961 - 0x935);
}
