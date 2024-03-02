
#include <stdio.h>

int main() {
  int z5062b3833d, z5357d9a158;
  scanf("\x25\x64", &z5062b3833d);
  for (z5357d9a158 = (0x163f + 228 - 0x1723); z5357d9a158 < z5062b3833d;
       z5357d9a158++) {
    int x, y, zdc6f2a61da = (0xe8c + 561 - 0x10bd), z0acbaba900, z68abf46e3b;
    int zc45b63fe89[(0xcc0 + 6316 - 0x2568)][(0x35f + 1285 - 0x860)];
    int z2fd579c0f8[(0x1181 + 17 - 0x118e)][(0x1849 + 2548 - 0x2239)];
    int zd8074e3ac2[(0xe4 + 862 - 0x431)] = {(0x905 + 1301 - 0xe1a)};
    scanf("\x25\x64", &x);
    for (z0acbaba900 = (0xf29 + 599 - 0x1180);
         z0acbaba900 < (0xc9 + 5601 - 0x16a6); z0acbaba900++) {
      for (z68abf46e3b = (0x15ef + 1171 - 0x1a82);
           z68abf46e3b < (0xbc9 + 6597 - 0x258a); z68abf46e3b++) {
        scanf("\x25\x64", &zc45b63fe89[z0acbaba900][z68abf46e3b]);
      }
    }
    scanf("\x25\x64", &y);
    for (z0acbaba900 = (0x78f + 3070 - 0x138d);
         z0acbaba900 < (0x3f2 + 7584 - 0x218e); z0acbaba900++) {
      for (z68abf46e3b = (0x471 + 3459 - 0x11f4);
           z68abf46e3b < (0x150 + 1136 - 0x5bc); z68abf46e3b++) {
        scanf("\x25\x64", &z2fd579c0f8[z0acbaba900][z68abf46e3b]);
      }
    }
    for (z0acbaba900 = (0x67c + 7671 - 0x2473);
         z0acbaba900 < (0xe5 + 5183 - 0x1520); z0acbaba900++)
      zd8074e3ac2[zc45b63fe89[x - (0x31a + 2335 - 0xc38)][z0acbaba900]]++;
    for (z0acbaba900 = (0x3b9 + 3342 - 0x10c7);
         z0acbaba900 < (0x2b3 + 2018 - 0xa91); z0acbaba900++)
      zd8074e3ac2[z2fd579c0f8[y - (0xd91 + 1779 - 0x1483)][z0acbaba900]]++;
    for (z0acbaba900 = (0x1754 + 3334 - 0x2459);
         z0acbaba900 <= (0x214 + 7496 - 0x1f4c); z0acbaba900++) {
      if (zd8074e3ac2[z0acbaba900] == (0x182 + 3897 - 0x10b9)) {
        if (zdc6f2a61da == (0x4d6 + 6755 - 0x1f39)) {
          zdc6f2a61da = z0acbaba900;
        } else {
          zdc6f2a61da = -(0x4e4 + 4105 - 0x14ec);
        }
      }
    }
    if (zdc6f2a61da == (0x1d58 + 465 - 0x1f29)) {
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x56\x6f\x6c\x75\x6e\x74"
             "\x65\x65\x72\x20\x63\x68\x65\x61\x74\x65\x64\x21"
             "\n",
             z5357d9a158 + (0xa86 + 1374 - 0xfe3));
    } else if (zdc6f2a61da == -(0x773 + 3517 - 0x152f)) {
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x42\x61\x64\x20\x6d\x61"
             "\x67\x69\x63\x69\x61\x6e\x21"
             "\n",
             z5357d9a158 + (0x1c78 + 2025 - 0x2460));
    } else {
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
             "\n",
             z5357d9a158 + (0x1042 + 3707 - 0x1ebc), zdc6f2a61da);
    }
  }
  return (0x1495 + 3585 - 0x2296);
}
