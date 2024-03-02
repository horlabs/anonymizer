
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int zd59ae30418, z42219e47f5, z171714bbe3;
  int z4eee78440a, z81e9e50057, z018825aa8b;
  int ze719d30c6e;
  scanf("\x25\x64", &zd59ae30418);
  char ze06026418e[(0x2406 + 601 - 0x2641)] =
      "\x79\x68\x65\x73\x6f\x63\x76\x78\x64\x75\x69\x67\x6c\x62\x6b\x72\x7a\x74"
      "\x6e\x77\x6a\x70\x66\x6d\x61\x71";
  char line[(0x1986 + 1134 - 0x19f4)];
  fgets(line, (0xb2b + 1811 - 0xe3e), stdin);
  for (ze719d30c6e = (0x207 + 1348 - 0x74a); ze719d30c6e <= zd59ae30418;
       ze719d30c6e++) {
    fgets(line, (0xb65 + 639 - 0x9e4), stdin);
    line[strlen(line) - (0x3bd + 3806 - 0x129a)] = '\0';
    for (z4eee78440a = (0x78b + 1142 - 0xc01); z4eee78440a < strlen(line);
         z4eee78440a++) {
      if (line[z4eee78440a] == ((char)(0x130 + 7298 - 0x1d92)))
        continue;
      else
        line[z4eee78440a] =
            ze06026418e[line[z4eee78440a] - ((char)(0xa73 + 2326 - 0x1328))];
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x73"
           "\n",
           ze719d30c6e, line);
  }
}
