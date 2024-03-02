
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(int z1028d424fc, char **z6b7a6d00f2) {
  char z15d8ad5484[(0xadb + 678 - 0xd67)] =
      "\x79\x68\x65\x73\x6f\x63\x76\x78\x64\x75\x69\x67\x6c\x62\x6b\x72\x7a\x74"
      "\x6e\x77\x6a\x70\x66\x6d\x61\x71";
  char za3e8f99875[(0xa20 + 2114 - 0x11f9)],
      z9330aa421e[(0x79 + 6066 - 0x17c2)];
  int ze0d0bfd543, z56268beb10, zb8e20ded1e, zcde1c0d920, zfd66fe9231;
  assert(scanf("\x25\x64\x20", &ze0d0bfd543) == (0x1086 + 3205 - 0x1d0a));
  for (zb8e20ded1e = (0x848 + 2661 - 0x12ac); zb8e20ded1e <= ze0d0bfd543;
       zb8e20ded1e++) {
    assert(fgets(za3e8f99875, (0x12fc + 2423 - 0x1c0a), stdin) != NULL);
    zfd66fe9231 = strlen(za3e8f99875);
    for (zcde1c0d920 = (0xc4d + 5305 - 0x2106); zcde1c0d920 < zfd66fe9231;
         zcde1c0d920++) {
      if ((za3e8f99875[zcde1c0d920] != ((char)(0x2672 + 54 - 0x2688))) &&
          (za3e8f99875[zcde1c0d920] != (0x493 + 3304 - 0x1171)))
        z9330aa421e[zcde1c0d920] = z15d8ad5484[za3e8f99875[zcde1c0d920] -
                                               ((char)(0x21ff + 584 - 0x23e6))];
      else if (za3e8f99875[zcde1c0d920] == ((char)(0x1eb + 2720 - 0xc6b)))
        z9330aa421e[zcde1c0d920] = za3e8f99875[zcde1c0d920];
    }
    z9330aa421e[zcde1c0d920 - (0x468 + 903 - 0x7ee)] = '\0';
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
           "\n",
           zb8e20ded1e, z9330aa421e);
  }
  return (0xd93 + 2602 - 0x17bd);
}
