
#include <stdio.h>

int main() {
  int z6cf7af8582, zbdf0ef0e9a;
  scanf("\x25\x64", &z6cf7af8582);
  for (zbdf0ef0e9a = (0x1503 + 3841 - 0x2403); zbdf0ef0e9a <= z6cf7af8582;
       ++zbdf0ef0e9a) {
    int z664b43c130, z4c275d262c, zee2fbda1db, z9f8d726cae;
    int zc510236fb0[(0x11ec + 2501 - 0x1b4d)][(0x14ea + 2368 - 0x1dc6)],
        zdb0917b082[(0xd10 + 4602 - 0x1ea6)] = {},
                                    z7e42b0eceb[(0x76d + 5798 - 0x1daf)] = {};
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", zbdf0ef0e9a);
    scanf("\x25\x64\x25\x64", &z664b43c130, &z4c275d262c);
    for (zee2fbda1db = (0x933 + 5843 - 0x2006); zee2fbda1db < z664b43c130;
         ++zee2fbda1db) {
      for (z9f8d726cae = (0x120f + 4744 - 0x2497); z9f8d726cae < z4c275d262c;
           ++z9f8d726cae) {
        scanf("\x25\x64", &zc510236fb0[zee2fbda1db][z9f8d726cae]);
        if (zc510236fb0[zee2fbda1db][z9f8d726cae] > zdb0917b082[zee2fbda1db])
          zdb0917b082[zee2fbda1db] = zc510236fb0[zee2fbda1db][z9f8d726cae];
        if (zc510236fb0[zee2fbda1db][z9f8d726cae] > z7e42b0eceb[z9f8d726cae])
          z7e42b0eceb[z9f8d726cae] = zc510236fb0[zee2fbda1db][z9f8d726cae];
      }
    }
    for (zee2fbda1db = (0x4e4 + 5520 - 0x1a74); zee2fbda1db < z664b43c130;
         ++zee2fbda1db) {
      for (z9f8d726cae = (0x3cf + 1108 - 0x823); z9f8d726cae < z4c275d262c;
           ++z9f8d726cae) {
        if (zc510236fb0[zee2fbda1db][z9f8d726cae] !=
            (zdb0917b082[zee2fbda1db] < z7e42b0eceb[z9f8d726cae]
                 ? zdb0917b082[zee2fbda1db]
                 : z7e42b0eceb[z9f8d726cae]))
          break;
      }
      if (z9f8d726cae < z4c275d262c)
        break;
    }
    puts(zee2fbda1db == z664b43c130 ? "\x59\x45\x53" : "\x4e\x4f");
  }
  return (0xf28 + 1355 - 0x1473);
}
