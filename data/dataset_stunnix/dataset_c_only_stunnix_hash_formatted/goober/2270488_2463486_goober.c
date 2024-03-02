
#include <stdio.h>

long long zff4ef6989e(long long x) {
  long long zd46d9e4b4b = (0x478 + 2629 - 0xebd);
  while (x > (0x1ad0 + 847 - 0x1e1f)) {
    zd46d9e4b4b =
        ((0xa90 + 5578 - 0x2050) * zd46d9e4b4b) + (x % (0x22c9 + 28 - 0x22db));
    x /= (0x1a9 + 7189 - 0x1db4);
  }
  return zd46d9e4b4b;
}
long long z6af7353c76[(0x728 + 2915 - 0x1264)];
int main() {
  int zcc1c941aac = (0xc8c + 5871 - 0x237b);
  for (long long z152af994a6 = (0x8af + 286 - 0x9cc); z152af994a6 <= 10000000;
       z152af994a6++) {
    if (z152af994a6 != zff4ef6989e(z152af994a6))
      continue;
    long long z57c792c636 = z152af994a6 * z152af994a6;
    if (z57c792c636 != zff4ef6989e(z57c792c636))
      continue;
    z6af7353c76[zcc1c941aac++] = z152af994a6 * z152af994a6;
  }
  int z935c0d46ab;
  scanf("\x25\x64", &z935c0d46ab);
  for (int zfe94d8e6e7 = (0x1711 + 1315 - 0x1c33); zfe94d8e6e7 <= z935c0d46ab;
       zfe94d8e6e7++) {
    long long z0399b1d873, z1ab13439d3;
    scanf("\x25\x6c\x6c\x64\x20\x25\x6c\x6c\x64", &z0399b1d873, &z1ab13439d3);
    int z75cdcbd826 = (0x1413 + 1191 - 0x18ba);
    for (int z152af994a6 = (0x149b + 1010 - 0x188d); z152af994a6 < zcc1c941aac;
         z152af994a6++)
      if (z6af7353c76[z152af994a6] >= z0399b1d873 &&
          z6af7353c76[z152af994a6] <= z1ab13439d3)
        z75cdcbd826++;
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           zfe94d8e6e7, z75cdcbd826);
  }
  return (0x59c + 4902 - 0x18c2);
}
