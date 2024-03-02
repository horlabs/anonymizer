
#include <stdio.h>

int main() {
  int z9f99cfbfb1, z9091d6ceb6;
  double z1c52401f4c, f, x, z35c8df3acc, z685c8cf508, z9b2d046f65, z462d9fdd5f;
  scanf("\x25\x64", &z9f99cfbfb1);
  for (z9091d6ceb6 = (0x56d + 3736 - 0x1405); z9091d6ceb6 < z9f99cfbfb1;
       z9091d6ceb6++) {
    z35c8df3acc = (0x3c8 + 6818 - 0x1e68);
    scanf("\x25\x6c\x66\x20\x25\x6c\x66\x20\x25\x6c\x66", &z1c52401f4c, &f, &x);
    z685c8cf508 = x / z35c8df3acc;
    z9b2d046f65 = (0xb3b + 2295 - 0x1432);
    z462d9fdd5f = (0x6af + 1041 - 0xac0);
    while ((0x3fb + 8164 - 0x23de)) {
      z462d9fdd5f += z1c52401f4c / z35c8df3acc;
      z35c8df3acc += f;
      z9b2d046f65 = z462d9fdd5f + x / z35c8df3acc;
      if (z9b2d046f65 < z685c8cf508)
        z685c8cf508 = z9b2d046f65;
      else
        break;
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x2e\x37\x6c\x66"
           "\n",
           z9091d6ceb6 + (0x8b2 + 1035 - 0xcbc), z685c8cf508);
  }
}
