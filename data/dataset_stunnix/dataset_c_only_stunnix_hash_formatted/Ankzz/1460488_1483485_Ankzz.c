
#include <stdio.h>

int main(int z2074678c22, char *z3053284625[]) {
  FILE *z002fffbfcc, *z52b3095de2;
  z002fffbfcc = (z2074678c22 <= (0x163d + 4064 - 0x261c))
                    ? fopen("\x69\x6e\x70\x75\x74\x2e\x74\x78\x74", "\x72\x2b")
                    : fopen(z3053284625[(0x614 + 5148 - 0x1a2f)], "\x72\x2b");
  z52b3095de2 = fopen("\x6f\x75\x74\x70\x75\x74\x2e\x74\x78\x74", "\x77\x2b");
  if (z002fffbfcc) {
    int z608bb94d05;
    char z8a054d751c[(0x857 + 5126 - 0x1c43)] = {
        ((char)(0x538 + 1649 - 0xb30)),   ((char)(0x19a6 + 804 - 0x1c62)),
        ((char)(0x938 + 563 - 0xb06)),    ((char)(0xc7f + 1527 - 0x1203)),
        ((char)(0xb1b + 1819 - 0x11c7)),  ((char)(0x676 + 293 - 0x738)),
        ((char)(0x19f + 8777 - 0x2372)),  ((char)(0x169 + 7442 - 0x1e03)),
        ((char)(0x684 + 6424 - 0x1f38)),  ((char)(0x7c4 + 7415 - 0x2446)),
        ((char)(0x13e7 + 4655 - 0x25ad)), ((char)(0xa72 + 578 - 0xc4d)),
        ((char)(0x454 + 8882 - 0x269a)),  ((char)(0xa4c + 5175 - 0x1e21)),
        ((char)(0x21f + 3259 - 0xe6f)),   ((char)(0x1559 + 2073 - 0x1d00)),
        ((char)(0xf45 + 1168 - 0x135b)),  ((char)(0xd71 + 6130 - 0x24ef)),
        ((char)(0xcdf + 980 - 0x1045)),   ((char)(0x1ab0 + 1635 - 0x209c)),
        ((char)(0x16bf + 2818 - 0x2157)), ((char)(0x1a97 + 1373 - 0x1f84)),
        ((char)(0x1014 + 4499 - 0x2141)), ((char)(0x147 + 1176 - 0x572)),
        ((char)(0x1675 + 1342 - 0x1b52)), ((char)(0x845 + 2343 - 0x10fb))};
    int ze26dc2b329;
    fscanf(z002fffbfcc, "\x25\x64", &z608bb94d05);
    fgetc(z002fffbfcc);
    for (ze26dc2b329 = (0xa81 + 807 - 0xda8); ze26dc2b329 < z608bb94d05;
         ze26dc2b329++) {
      int x;
      fprintf(z52b3095de2, "\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
              ze26dc2b329 + (0xf7c + 1068 - 0x13a7));
      do {
        x = fgetc(z002fffbfcc);
        if (x != ((char)(0xd6f + 3103 - 0x196e)) && x != '\n' && x != EOF)
          x = z8a054d751c[x - ((char)(0x970 + 2927 - 0x147e))];
        if (x != EOF)
          fprintf(z52b3095de2, "\x25\x63", x);
      } while (x != '\n' && x != EOF);
    }
  }
  return (0x26c + 6594 - 0x1c2e);
}
