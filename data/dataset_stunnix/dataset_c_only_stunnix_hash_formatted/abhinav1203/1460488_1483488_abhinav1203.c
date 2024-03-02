
#include <stdio.h>
#include <stdlib.h>

int zc0af711bec(const void *z1dbae40845, const void *zd6963f17a5) {
  if (*(int *)z1dbae40845 < *(int *)zd6963f17a5)
    return -(0xb6c + 1032 - 0xf73);
  return (0xd3 + 2856 - 0xbfa);
}
int ze59ce03dfa(int zce73ba55ea) {
  int z5fffa5d949 = (0x102b + 5594 - 0x2605);
  while (zce73ba55ea > (0xb53 + 5818 - 0x220d)) {
    z5fffa5d949++;
    zce73ba55ea /= (0xaa7 + 2748 - 0x1559);
  }
  return z5fffa5d949;
}
int z90b2e61b78(int zce73ba55ea) {
  int z5fffa5d949 = (0x6ff + 3958 - 0x1674), zfd5eb934ca;
  for (zfd5eb934ca = (0x12a7 + 1009 - 0x1698); zfd5eb934ca < zce73ba55ea;
       zfd5eb934ca++)
    z5fffa5d949 *= (0x7e1 + 331 - 0x922);
  return z5fffa5d949;
}
int main() {
  int z6b3a3186af, z1dbae40845, zd6963f17a5, zfd5eb934ca, zb9227886f1, x, y,
      z5fffa5d949, z7e2c28210b[(0x4db + 4601 - 0x1670)],
      z9d54e513e5 = (0x180b + 1115 - 0x1c65);
  scanf("\x25\x64", &z6b3a3186af);
  while (z6b3a3186af--) {
    scanf("\x25\x64\x20\x25\x64", &z1dbae40845, &zd6963f17a5);
    z5fffa5d949 = (0x1486 + 2423 - 0x1dfd);
    for (zfd5eb934ca = z1dbae40845; zfd5eb934ca <= zd6963f17a5; zfd5eb934ca++) {
      z7e2c28210b[(0xc21 + 6599 - 0x25e8)] = zfd5eb934ca;
      x = ze59ce03dfa(zfd5eb934ca);
      y = z90b2e61b78(x - (0x80b + 4742 - 0x1a90));
      for (zb9227886f1 = (0x768 + 174 - 0x815); zb9227886f1 < x;
           zb9227886f1++) {
        z7e2c28210b[zb9227886f1] =
            z7e2c28210b[zb9227886f1 - (0xadf + 1884 - 0x123a)] /
                (0x3f1 + 3448 - 0x115f) +
            z7e2c28210b[zb9227886f1 - (0x957 + 1760 - 0x1036)] %
                (0x8d2 + 3406 - 0x1616) * y;
      }
      qsort(z7e2c28210b, x, sizeof(int), &zc0af711bec);
      for (zb9227886f1 = (0x1601 + 715 - 0x18cc); zb9227886f1 < x;
           zb9227886f1++)
        if (z7e2c28210b[zb9227886f1] >= z1dbae40845 &&
            z7e2c28210b[zb9227886f1] <= zd6963f17a5 &&
            (zb9227886f1 == (0x1483 + 3169 - 0x20e4) ||
             z7e2c28210b[zb9227886f1] !=
                 z7e2c28210b[zb9227886f1 - (0x15ff + 637 - 0x187b)]) &&
            z7e2c28210b[zb9227886f1] != zfd5eb934ca)
          z5fffa5d949++;
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z9d54e513e5, z5fffa5d949 / (0xb74 + 3579 - 0x196d));
    z9d54e513e5++;
  }
  return (0xa8f + 4176 - 0x1adf);
}
