
#include <stdio.h>
#include <string.h>

char z75544ab2ff[] = "\x65\x6a\x70\x20\x6d\x79\x73\x6c\x6a\x79\x6c\x63\x20\x6b"
                     "\x64\x20\x6b\x78\x76\x65\x64\x64\x6b\x6e\x6d\x63\x20\x72"
                     "\x65\x20\x6a\x73\x69\x63\x70\x64\x72\x79\x73\x69";
char za0b37b525e[] = "\x72\x62\x63\x70\x63\x20\x79\x70\x63\x20\x72\x74\x63\x73"
                     "\x72\x61\x20\x64\x6b\x68\x20\x77\x79\x66\x72\x65\x70\x6b"
                     "\x79\x6d\x20\x76\x65\x64\x64\x6b\x6e\x6b\x6d\x6b\x72\x6b"
                     "\x63\x64";
char zc3d628636b[] = "\x64\x65\x20\x6b\x72\x20\x6b\x64\x20\x65\x6f\x79\x61\x20"
                     "\x6b\x77\x20\x61\x65\x6a\x20\x74\x79\x73\x72\x20\x72\x65"
                     "\x20\x75\x6a\x64\x72\x20\x6c\x6b\x67\x63\x20\x6a\x76";
char z2f95ca908a[] = "\x6f\x75\x72\x20\x6c\x61\x6e\x67\x75\x61\x67\x65\x20\x69"
                     "\x73\x20\x69\x6d\x70\x6f\x73\x73\x69\x62\x6c\x65\x20\x74"
                     "\x6f\x20\x75\x6e\x64\x65\x72\x73\x74\x61\x6e\x64";
char zcba44d5794[] = "\x74\x68\x65\x72\x65\x20\x61\x72\x65\x20\x74\x77\x65\x6e"
                     "\x74\x79\x20\x73\x69\x78\x20\x66\x61\x63\x74\x6f\x72\x69"
                     "\x61\x6c\x20\x70\x6f\x73\x73\x69\x62\x69\x6c\x69\x74\x69"
                     "\x65\x73";
char f[] = "\x73\x6f\x20\x69\x74\x20\x69\x73\x20\x6f\x6b\x61\x79\x20\x69\x66"
           "\x20\x79\x6f\x75\x20\x77\x61\x6e\x74\x20\x74\x6f\x20\x6a\x75\x73"
           "\x74\x20\x67\x69\x76\x65\x20\x75\x70";
int z74e34b394e[(0x2e3 + 5210 - 0x163d)];
void z8bc241c289(char *za2d61bb224, char *z5cca2e0c34) {
  while (*za2d61bb224)
    z74e34b394e[(int)*(za2d61bb224++)] = *(z5cca2e0c34++);
}
char za2d61bb224[16384];
int main() {
  int zdb773aef05 = (0xf + 8783 - 0x225d), zdfa3e478d3, z9e5c1dc9f4;
  memset(z74e34b394e, (0x76a + 4280 - 0x1822), sizeof(z74e34b394e));
  z8bc241c289(z75544ab2ff, z2f95ca908a);
  z8bc241c289(za0b37b525e, zcba44d5794);
  z8bc241c289(zc3d628636b, f);
  z74e34b394e[((char)(0x170 + 3530 - 0xec9))] =
      ((char)(0x1a79 + 3029 - 0x25d4));
  z74e34b394e[((char)(0x4a5 + 5010 - 0x17bd))] =
      ((char)(0xacf + 4389 - 0x1b83));
  gets(za2d61bb224);
  sscanf(za2d61bb224, "\x25\x64", &zdfa3e478d3);
  while (zdfa3e478d3--) {
    gets(za2d61bb224);
    for (z9e5c1dc9f4 = (0xf26 + 2225 - 0x17d7); za2d61bb224[z9e5c1dc9f4];
         z9e5c1dc9f4++)
      za2d61bb224[z9e5c1dc9f4] = z74e34b394e[(int)za2d61bb224[z9e5c1dc9f4]];
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
           "\n",
           zdb773aef05++, za2d61bb224);
  }
  return (0x8d6 + 2396 - 0x1232);
}