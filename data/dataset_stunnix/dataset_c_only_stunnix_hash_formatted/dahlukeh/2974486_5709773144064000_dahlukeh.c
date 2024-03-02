
#include <math.h>
#include <stdio.h>

double C, F, X;
void z80fea55a0a() {
  scanf("\x25\x6c\x66\x20\x25\x6c\x66\x20\x25\x6c\x66\x20", &C, &F, &X);
  double z7c6f49a61f = (F * X - F * C) / C;
  double z7643a7f7e6 = 0.0;
  double z52627ec2fe = 2.0;
  while (z52627ec2fe < z7c6f49a61f) {
    z7643a7f7e6 += C / z52627ec2fe;
    z52627ec2fe += F;
  }
  z7643a7f7e6 += X / z52627ec2fe;
  printf("\x25\x2e\x37\x66"
         "\n",
         z7643a7f7e6);
}
int main() {
  int z8f46d0e8e5, z2752573fc8;
  scanf("\x25\x64\x20", &z8f46d0e8e5);
  for (z2752573fc8 = (0xc04 + 4632 - 0x1e1c); z2752573fc8 < z8f46d0e8e5;
       z2752573fc8++) {
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
           z2752573fc8 + (0x65 + 5027 - 0x1407));
    z80fea55a0a();
  }
  return (0xbbd + 6509 - 0x252a);
}
