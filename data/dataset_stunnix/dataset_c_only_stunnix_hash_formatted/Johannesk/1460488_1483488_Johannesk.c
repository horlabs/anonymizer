
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int z812cd34ef5(int z608d06f266, int z04ace26da6, int z71c720f20b) {
  int z1887d8cc86, z7fe72371a3 = (0x8ca + 6073 - 0x2082),
                   z66eb5a2a35 = (0x1101 + 3656 - 0x1f48), z0bee8d464b;
  z0bee8d464b = z71c720f20b - z04ace26da6;
  while (z0bee8d464b--)
    z7fe72371a3 = z7fe72371a3 * (0x60a + 2392 - 0xf58);
  while (z04ace26da6--)
    z66eb5a2a35 = z66eb5a2a35 * (0x1159 + 3693 - 0x1fbc);
  z1887d8cc86 =
      (z608d06f266 % z7fe72371a3) * z66eb5a2a35 + (z608d06f266 / z7fe72371a3);
  return z1887d8cc86;
}
int main(int z5b6d739246, char **z1a547397f4) {
  int z49e4a8ba86, zc2f18f495f, zd9293c4a5e, z9b8d4184df, ze3688d3e24,
      zc67739c713, z043510503b, zbc17911e9c, z1e744b6117, z7fe72371a3;
  int z79a3dad34b;
  assert(scanf("\x25\x64", &zd9293c4a5e) == (0x364 + 8123 - 0x231e));
  for (z9b8d4184df = (0xc4b + 1018 - 0x1044); z9b8d4184df <= zd9293c4a5e;
       z9b8d4184df++) {
    z1e744b6117 = (0x18bc + 3300 - 0x25a0);
    assert(scanf("\x25\x64\x20\x25\x64", &z49e4a8ba86, &zc2f18f495f) ==
           (0xedf + 1158 - 0x1363));
    for (ze3688d3e24 = z49e4a8ba86; ze3688d3e24 <= zc2f18f495f; ze3688d3e24++) {
      z79a3dad34b = (0x10a8 + 4523 - 0x2253);
      z043510503b = floor(log10(ze3688d3e24)) + (0xe4c + 6329 - 0x2704);
      for (zbc17911e9c = (0x725 + 3930 - 0x167e); zbc17911e9c < z043510503b;
           zbc17911e9c++) {
        z7fe72371a3 = z812cd34ef5(ze3688d3e24, zbc17911e9c, z043510503b);
        if (z7fe72371a3 >= z49e4a8ba86 && z7fe72371a3 <= zc2f18f495f &&
            z7fe72371a3 > ze3688d3e24 && z7fe72371a3 != z79a3dad34b) {
          z1e744b6117++;
          z79a3dad34b = z7fe72371a3;
        }
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z9b8d4184df, z1e744b6117);
  }
  return (0x120 + 2125 - 0x96d);
}
