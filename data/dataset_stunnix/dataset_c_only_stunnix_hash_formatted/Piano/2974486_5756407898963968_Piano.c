
#include <stdio.h>

int main() {
  int z086352d4b7, z977c7d6461;
  scanf("\x25\x64", &z086352d4b7);
  for (z977c7d6461 = (0x390 + 7651 - 0x2172); z977c7d6461 <= z086352d4b7;
       ++z977c7d6461) {
    int z84d42a1b74, z7caa083593, z03bce7228d, zf101036653, z941bb81838,
        zf6491e00e8, zf1e661c1b6;
    int z54acb4caba[(0xb4f + 2518 - 0x1514)] = {};
    scanf("\x25\x64", &z84d42a1b74);
    for (zf6491e00e8 = (0xb1c + 3160 - 0x1773);
         zf6491e00e8 <= (0xf53 + 1364 - 0x14a3); ++zf6491e00e8) {
      if (zf6491e00e8 != z84d42a1b74)
        scanf("\x25\x2a\x64\x25\x2a\x64\x25\x2a\x64\x25\x2a\x64");
      else {
        scanf("\x25\x64\x25\x64\x25\x64\x25\x64", &z7caa083593, &z03bce7228d,
              &zf101036653, &z941bb81838);
        z54acb4caba[z7caa083593] = z54acb4caba[z03bce7228d] =
            z54acb4caba[zf101036653] = z54acb4caba[z941bb81838] =
                (0x6d2 + 892 - 0xa4d);
      }
    }
    scanf("\x25\x64", &z84d42a1b74);
    for (zf6491e00e8 = (0xb51 + 3731 - 0x19e3);
         zf6491e00e8 <= (0xf8f + 5431 - 0x24c2); ++zf6491e00e8) {
      if (zf6491e00e8 != z84d42a1b74)
        scanf("\x25\x2a\x64\x25\x2a\x64\x25\x2a\x64\x25\x2a\x64");
      else {
        int zec72312fdd, za572a633c4 = (0xbd1 + 964 - 0xf95);
        for (zf1e661c1b6 = (0x1b26 + 86 - 0x1b7c);
             zf1e661c1b6 < (0x1c08 + 26 - 0x1c1e); ++zf1e661c1b6) {
          scanf("\x25\x64", &z7caa083593);
          if (z54acb4caba[z7caa083593])
            ++za572a633c4, zec72312fdd = z7caa083593;
        }
        if (!za572a633c4)
          printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x56\x6f\x6c\x75\x6e"
                 "\x74\x65\x65\x72\x20\x63\x68\x65\x61\x74\x65\x64\x21"
                 "\n",
                 z977c7d6461);
        else if (za572a633c4 == (0x1efa + 1536 - 0x24f9))
          printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
                 "\n",
                 z977c7d6461, zec72312fdd);
        else
          printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x42\x61\x64\x20\x6d"
                 "\x61\x67\x69\x63\x69\x61\x6e\x21"
                 "\n",
                 z977c7d6461);
      }
    }
  }
  return (0x209 + 3276 - 0xed5);
}
