
#include <stdio.h>

int zb6f718ba38[(0x1763 + 312 - 0x1837)][(0x15d4 + 2608 - 0x1fa0)],
    zb1c709d684[(0x1483 + 982 - 0x17f5)], ze6f919e241[(0xb44 + 3362 - 0x1802)],
    zea2e732f56, zd50159c8cb;
int main() {
  freopen("\x43\x3a"
          "\\"
          "\x55\x73\x65\x72\x73"
          "\\"
          "\x76\x69\x76\x65\x6b"
          "\\"
          "\x44\x65\x73\x6b\x74\x6f\x70"
          "\\"
          "\x69\x6e\x2e\x74\x78\x74",
          "\x72", stdin);
  freopen("\x43\x3a"
          "\\"
          "\x55\x73\x65\x72\x73"
          "\\"
          "\x76\x69\x76\x65\x6b"
          "\\"
          "\x44\x65\x73\x6b\x74\x6f\x70"
          "\\"
          "\x6f\x75\x74\x2e\x74\x78\x74",
          "\x77", stdout);
  int ze7484d3d3c, zae87e4a777, z6cb3315653, z0d29ad8ce0, zbf525dd0a5;
  scanf("\x25\x64", &ze7484d3d3c);
  for (zbf525dd0a5 = (0x1dd5 + 723 - 0x20a7); zbf525dd0a5 <= ze7484d3d3c;
       zbf525dd0a5++) {
    scanf("\x25\x64\x20\x25\x64", &zea2e732f56, &zd50159c8cb);
    for (zae87e4a777 = (0x1add + 321 - 0x1c1e);
         zae87e4a777 < (0xe37 + 5697 - 0x2414); zae87e4a777++)
      zb1c709d684[zae87e4a777] = ze6f919e241[zae87e4a777] =
          (0xb9c + 5639 - 0x21a3);
    for (zae87e4a777 = (0xf97 + 3424 - 0x1cf7); zae87e4a777 < zea2e732f56;
         zae87e4a777++) {
      for (z6cb3315653 = (0x1168 + 4555 - 0x2333); z6cb3315653 < zd50159c8cb;
           z6cb3315653++) {
        scanf("\x25\x64", &zb6f718ba38[zae87e4a777][z6cb3315653]);
        if (zb6f718ba38[zae87e4a777][z6cb3315653] > zb1c709d684[zae87e4a777])
          zb1c709d684[zae87e4a777] = zb6f718ba38[zae87e4a777][z6cb3315653];
        if (zb6f718ba38[zae87e4a777][z6cb3315653] > ze6f919e241[z6cb3315653])
          ze6f919e241[z6cb3315653] = zb6f718ba38[zae87e4a777][z6cb3315653];
      }
    }
    for (zae87e4a777 = (0x675 + 4784 - 0x1925); zae87e4a777 < zea2e732f56;
         zae87e4a777++) {
      for (z6cb3315653 = (0xa26 + 1011 - 0xe19);
           (z6cb3315653 < zd50159c8cb) &&
           ((zb6f718ba38[zae87e4a777][z6cb3315653] >=
             zb1c709d684[zae87e4a777]) ||
            (zb6f718ba38[zae87e4a777][z6cb3315653] >=
             ze6f919e241[z6cb3315653]));
           z6cb3315653++)
        ;
      if (z6cb3315653 < zd50159c8cb)
        break;
    }
    if (zae87e4a777 < zea2e732f56)
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x4e\x4f"
             "\n",
             zbf525dd0a5);
    else
      printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x59\x45\x53"
             "\n",
             zbf525dd0a5);
  }
  return (0x17cb + 1537 - 0x1dcc);
}
