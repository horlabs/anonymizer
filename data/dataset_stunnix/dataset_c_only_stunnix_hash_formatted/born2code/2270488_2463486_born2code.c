
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void z1b4b33b6e4(int z09f02e9f79, char zbc628220ea[]) {
  int z9c0fc0b3ab, z3198916760, z099b2f7f49;
  char x, y[(0x11b9 + 4372 - 0x2269)];
  z9c0fc0b3ab = z09f02e9f79;
  z3198916760 = (0x49f + 6436 - 0x1dc3);
  while (z09f02e9f79) {
    zbc628220ea[z3198916760++] =
        z09f02e9f79 % (0xb51 + 4487 - 0x1cce) + ((char)(0xbb8 + 4127 - 0x1ba7));
    z09f02e9f79 /= (0x3fd + 4051 - 0x13c6);
  }
  zbc628220ea[z3198916760] = '\0';
  z099b2f7f49 = strlen(zbc628220ea);
  for (z9c0fc0b3ab = (0x95b + 2453 - 0x12f0),
      z3198916760 = z099b2f7f49 - (0x1037 + 2483 - 0x19e9);
       z9c0fc0b3ab <= z099b2f7f49 - (0x800 + 1481 - 0xdc8);
       z3198916760--, z9c0fc0b3ab++) {
    y[z3198916760] = zbc628220ea[z9c0fc0b3ab];
  }
  for (z9c0fc0b3ab = (0x15f6 + 2096 - 0x1e26);
       z9c0fc0b3ab <= z099b2f7f49 - (0x15f2 + 2054 - 0x1df7); z9c0fc0b3ab++)
    zbc628220ea[z9c0fc0b3ab] = y[z9c0fc0b3ab];
}
int z13f68f814f(int z09f02e9f79) {
  char x[(0xc2b + 4606 - 0x1dc5)];
  z1b4b33b6e4(z09f02e9f79, x);
  int z5c2b22bc10 = strlen(x);
  int z9c0fc0b3ab;
  for (z9c0fc0b3ab = (0x1fe0 + 419 - 0x2183);
       z9c0fc0b3ab < z5c2b22bc10 - (0x128f + 4212 - 0x2302); z9c0fc0b3ab++) {
    if (x[z9c0fc0b3ab] !=
        x[z5c2b22bc10 - z9c0fc0b3ab - (0x1ac + 7147 - 0x1d96)])
      return (0xdaa + 4548 - 0x1f6e);
  }
  return (0x2f4 + 635 - 0x56e);
}
int z95a5c57498(int z9c0fc0b3ab) {
  int z3198916760 = z9c0fc0b3ab + (0x156a + 1827 - 0x1c8c);
  while (!(z13f68f814f(z3198916760)))
    z3198916760++;
  return z3198916760;
}
int main() {
  int zb1e02182e4, z5aa537511d, z09f02e9f79, zc9ef47b93f, z6a358b3e87,
      z0f6dddb92f, zbd77b183cb, z9c0fc0b3ab;
  zb1e02182e4 = (0x971 + 2156 - 0x11dc);
  for (scanf("\x25\x64", &z5aa537511d); zb1e02182e4 <= z5aa537511d;
       zb1e02182e4++) {
    scanf("\x25\x64\x25\x64", &z09f02e9f79, &zc9ef47b93f);
    z6a358b3e87 = ceil(sqrt(z09f02e9f79));
    z0f6dddb92f = floor(sqrt(zc9ef47b93f));
    zbd77b183cb = (0xeb9 + 1424 - 0x1449);
    z9c0fc0b3ab = z6a358b3e87;
    while (!(z13f68f814f(z9c0fc0b3ab)))
      z9c0fc0b3ab++;
    for (; z9c0fc0b3ab <= z0f6dddb92f; z9c0fc0b3ab = z95a5c57498(z9c0fc0b3ab)) {
      if (z13f68f814f(z9c0fc0b3ab * z9c0fc0b3ab)) {
        zbd77b183cb++;
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           zb1e02182e4, zbd77b183cb);
  }
  return (0x1e3 + 9195 - 0x25ce);
}
