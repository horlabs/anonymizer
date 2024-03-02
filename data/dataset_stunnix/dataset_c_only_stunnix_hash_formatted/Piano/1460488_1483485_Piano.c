
#include <stdio.h>

int main() {
  int z0ca04850f2, z1003a66109, za070817c82;
  char *z031405c133 = "\x79\x68\x65\x73\x6f\x63\x76\x78\x64\x75\x69\x67\x6c\x62"
                      "\x6b\x72\x7a\x74\x6e\x77\x6a\x70\x66\x6d\x61\x71";
  char z0f90f405b5[(0x815 + 3730 - 0x1642)];
  scanf("\x25\x64\x25\x2a\x63", &z0ca04850f2);
  for (z1003a66109 = (0xc73 + 6328 - 0x252a); z1003a66109 <= z0ca04850f2;
       ++z1003a66109) {
    gets(z0f90f405b5);
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", z1003a66109);
    for (za070817c82 = (0x19f7 + 799 - 0x1d16); z0f90f405b5[za070817c82];
         ++za070817c82)
      putchar(z0f90f405b5[za070817c82] == ((char)(0x17a + 9144 - 0x2512))
                  ? ((char)(0x6cc + 1356 - 0xbf8))
                  : z031405c133[z0f90f405b5[za070817c82] -
                                ((char)(0x1912 + 51 - 0x18e4))]);
    puts("");
  }
  return (0xcbc + 5768 - 0x2344);
}
