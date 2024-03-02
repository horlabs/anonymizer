
#include <stdio.h>
#include <stdlib.h>

int main() {
  int z2a119a5cfd, z002ea1fb22, z98b34aacbf;
  char zeac749098a[(0xacf + 2059 - 0x1244)];
  char z4a7a3ceb12[] = "\x79\x68\x65\x73\x6f\x63\x76\x78\x64\x75\x69\x67\x6c"
                       "\x62\x6b\x72\x7a\x74\x6e\x77\x6a\x70\x66\x6d\x61\x71";
  fgets(zeac749098a, sizeof(zeac749098a), stdin);
  z2a119a5cfd = atoi(zeac749098a);
  for (z002ea1fb22 = (0x682 + 5034 - 0x1a2b); z002ea1fb22 <= z2a119a5cfd;
       z002ea1fb22++) {
    fgets(zeac749098a, sizeof(zeac749098a), stdin);
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20", z002ea1fb22);
    for (z98b34aacbf = (0x1283 + 1168 - 0x1713); zeac749098a[z98b34aacbf];
         z98b34aacbf++) {
      if (zeac749098a[z98b34aacbf] < ((char)(0x1fec + 1677 - 0x2618)) ||
          zeac749098a[z98b34aacbf] > ((char)(0xcf5 + 1800 - 0x1383)))
        printf("\x25\x63", zeac749098a[z98b34aacbf]);
      else
        printf("\x25\x63", z4a7a3ceb12[zeac749098a[z98b34aacbf] -
                                       ((char)(0x30c + 6645 - 0x1ca0))]);
    }
    printf("\n");
  }
  return (0xcd3 + 210 - 0xda5);
}
