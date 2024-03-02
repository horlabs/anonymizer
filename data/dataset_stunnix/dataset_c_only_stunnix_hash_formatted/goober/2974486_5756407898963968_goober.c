
#include <stdio.h>

int main() {
  int z0b2dce73d7;
  scanf("\x25\x64", &z0b2dce73d7);
  for (int zc2134bc0a3 = (0x1721 + 3356 - 0x243c); zc2134bc0a3 <= z0b2dce73d7;
       zc2134bc0a3++) {
    char zc438977c4b[(0x669 + 4271 - 0x1707)] = {(0x31a + 5492 - 0x188e)};
    for (int z7c4d0a98d8 = (0x196 + 3890 - 0x10c8);
         z7c4d0a98d8 < (0x6d9 + 431 - 0x886); z7c4d0a98d8++) {
      int zcd5974895a;
      scanf("\x25\x64", &zcd5974895a);
      for (int z60b975eee8 = (0x315 + 6124 - 0x1b00);
           z60b975eee8 <= (0xf34 + 1273 - 0x1429); z60b975eee8++)
        for (int z6c81a5303e = (0x1216 + 3480 - 0x1fae);
             z6c81a5303e < (0x54a + 7795 - 0x23b9); z6c81a5303e++) {
          int x;
          scanf("\x25\x64", &x);
          if (z60b975eee8 == zcd5974895a)
            zc438977c4b[x]++;
        }
    }
    int ze4e5bc84ac = (0xfcd + 2205 - 0x186a);
    int z15bfb3eed2 = (0xc0a + 5729 - 0x226b);
    for (int z60b975eee8 = (0x556 + 8391 - 0x261c);
         z60b975eee8 <= (0xd1 + 2727 - 0xb68); z60b975eee8++)
      if (zc438977c4b[z60b975eee8] == (0x8ec + 6146 - 0x20ec)) {
        z15bfb3eed2 = z60b975eee8;
        ze4e5bc84ac++;
      }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", zc2134bc0a3);
    if (ze4e5bc84ac == (0xadc + 6420 - 0x23f0))
      printf("\x56\x6f\x6c\x75\x6e\x74\x65\x65\x72\x20\x63\x68\x65\x61\x74\x65"
             "\x64\x21");
    else if (ze4e5bc84ac >= (0x3e2 + 6818 - 0x1e82))
      printf("\x42\x61\x64\x20\x6d\x61\x67\x69\x63\x69\x61\x6e\x21");
    else
      printf("\x25\x64", z15bfb3eed2);
    printf("\n");
  }
}
