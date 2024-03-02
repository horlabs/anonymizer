
#include <math.h>
#include <stdio.h>

int z21933d3e08[10000005], zd4fee9ab2f[(0x1eb + 3250 - 0xe39)];
int zb56f57485b(long long int z79fd5559da) {
  int z7d28531a9b = (0x5f4 + 205 - 0x6c1), z534a13569a;
  while (z79fd5559da > (0xe3c + 4129 - 0x1e5d)) {
    zd4fee9ab2f[z7d28531a9b++] = z79fd5559da % (0x88d + 7210 - 0x24ad);
    z79fd5559da /= (0x145c + 656 - 0x16e2);
  }
  z7d28531a9b--;
  z534a13569a = (0x768 + 7469 - 0x2495);
  while (z7d28531a9b > z534a13569a &&
         zd4fee9ab2f[z7d28531a9b] == zd4fee9ab2f[z534a13569a]) {
    z7d28531a9b--;
    z534a13569a++;
  }
  if (z7d28531a9b <= z534a13569a)
    return (0xc4b + 594 - 0xe9c);
  return (0x27 + 3128 - 0xc5f);
}
int main() {
  int z764e199cb4, z634ddee160;
  long long int z7d28531a9b, z5e87048e06, zc090019694;
  scanf("\x25\x64", &z764e199cb4);
  z634ddee160 = (0x941 + 1675 - 0xfcc);
  z21933d3e08[(0x4c8 + 1772 - 0xbb4)] = (0x24f1 + 387 - 0x2674);
  for (z7d28531a9b = (0x17b1 + 2731 - 0x225b); z7d28531a9b <= 1e7;
       z7d28531a9b++) {
    if (zb56f57485b(z7d28531a9b) && zb56f57485b(z7d28531a9b * z7d28531a9b))
      z634ddee160++;
    z21933d3e08[z7d28531a9b] = z634ddee160;
  }
  for (z7d28531a9b = (0xc69 + 3028 - 0x183c); z7d28531a9b <= z764e199cb4;
       z7d28531a9b++) {
    scanf("\x25\x6c\x6c\x64\x20\x25\x6c\x6c\x64", &z5e87048e06, &zc090019694);
    printf("\x43\x61\x73\x65\x20\x23\x25\x6c\x6c\x64\x3a\x20\x25\x64"
           "\n",
           z7d28531a9b,
           z21933d3e08[(int)floor(sqrt(zc090019694))] -
               z21933d3e08[(int)floor(
                   sqrt(z5e87048e06 - (0xa1f + 1045 - 0xe33)))]);
  }
  return (0x9ea + 6077 - 0x21a7);
}
