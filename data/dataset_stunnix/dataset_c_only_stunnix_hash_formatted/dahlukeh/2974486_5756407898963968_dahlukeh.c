
#include <stdio.h>

int zdcca7b95a0;
int z2e60b7f237[(0x158f + 592 - 0x177a)][(0x164f + 3398 - 0x2330)];
int zdbd16f84a1[(0x1654 + 2934 - 0x2165)];
int zabbe0e9548[(0x772 + 4368 - 0x181d)];
void z5a153d4451(int *z3dbc042ec6) {
  int zde1828ce74;
  for (zde1828ce74 = (0x35f + 2943 - 0xedd);
       zde1828ce74 <= (0x529 + 7604 - 0x22cd); zde1828ce74++) {
    z3dbc042ec6[zde1828ce74] = (0x7ed + 6227 - 0x2040);
  }
  for (zde1828ce74 = (0x119c + 5239 - 0x2613);
       zde1828ce74 < (0x189d + 1557 - 0x1eae); zde1828ce74++) {
    z3dbc042ec6[z2e60b7f237[zdcca7b95a0 - (0x4a6 + 1527 - 0xa9c)]
                           [zde1828ce74]] = (0x1288 + 4815 - 0x2556);
  }
}
void z5d9e0f5a5f() {
  int zde1828ce74, z5abf00bd4a;
  scanf("\x25\x64\x20", &zdcca7b95a0);
  for (zde1828ce74 = (0x456 + 3242 - 0x1100);
       zde1828ce74 < (0xada + 1608 - 0x111e); zde1828ce74++) {
    for (z5abf00bd4a = (0x1d1 + 4640 - 0x13f1);
         z5abf00bd4a < (0x170 + 6279 - 0x19f3); z5abf00bd4a++) {
      scanf("\x25\x64\x20", &z2e60b7f237[zde1828ce74][z5abf00bd4a]);
    }
  }
  z5a153d4451(zdbd16f84a1);
  scanf("\x25\x64\x20", &zdcca7b95a0);
  for (zde1828ce74 = (0x1450 + 2364 - 0x1d8c);
       zde1828ce74 < (0x1edb + 971 - 0x22a2); zde1828ce74++) {
    for (z5abf00bd4a = (0x2245 + 890 - 0x25bf);
         z5abf00bd4a < (0x17f7 + 2596 - 0x2217); z5abf00bd4a++) {
      scanf("\x25\x64\x20", &z2e60b7f237[zde1828ce74][z5abf00bd4a]);
    }
  }
  z5a153d4451(zabbe0e9548);
  int z9a8e1b8dea = (0x1201 + 1146 - 0x167b);
  int z69dbcd6f35 = (0x7b3 + 885 - 0xb28);
  int z0175fead60 = (0x4b5 + 5513 - 0x1a3e);
  for (zde1828ce74 = (0x1816 + 3182 - 0x2483);
       zde1828ce74 <= (0x204b + 1730 - 0x26fd); zde1828ce74++) {
    if (zdbd16f84a1[zde1828ce74] && zabbe0e9548[zde1828ce74]) {
      if (z9a8e1b8dea) {
        z69dbcd6f35 = (0x17e6 + 2909 - 0x2342);
      }
      z9a8e1b8dea = (0x4af + 7237 - 0x20f3);
      z0175fead60 = zde1828ce74;
    }
  }
  if (!z9a8e1b8dea) {
    printf("\x56\x6f\x6c\x75\x6e\x74\x65\x65\x72\x20\x63\x68\x65\x61\x74\x65"
           "\x64\x21"
           "\n");
  } else if (z69dbcd6f35) {
    printf("\x42\x61\x64\x20\x6d\x61\x67\x69\x63\x69\x61\x6e\x21"
           "\n");
  } else {
    printf("\x25\x64"
           "\n",
           z0175fead60);
  }
}
int main() {
  int zaa11dd57a0, zde1828ce74;
  scanf("\x25\x64\x20", &zaa11dd57a0);
  for (zde1828ce74 = (0x63b + 4914 - 0x196d); zde1828ce74 < zaa11dd57a0;
       zde1828ce74++) {
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
           zde1828ce74 + (0x297 + 1996 - 0xa62));
    z5d9e0f5a5f();
  }
  return (0x98d + 5991 - 0x20f4);
}
