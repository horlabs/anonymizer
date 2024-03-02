
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double z46b19b04ae(int zec019063f5, double C, double F, double X) {
  int zee412fe4ad;
  double z642f20a0ad = (0x1b2f + 2903 - 0x2686);
  for (zee412fe4ad = (0x7eb + 247 - 0x8e2); zee412fe4ad < zec019063f5;
       zee412fe4ad++) {
    z642f20a0ad += C / (2.0 + F * zee412fe4ad);
  }
  return z642f20a0ad + X / (2.0 + zec019063f5 * F);
}
int z0f183bf271(double C, double F, double X) {
  int zec019063f5 = (F * X - (0x61d + 4037 - 0x15e0) * C) / (F * C);
  if (zec019063f5 < (0xdb1 + 4604 - 0x1fad))
    zec019063f5 = (0xfb2 + 5042 - 0x2364);
  return zec019063f5;
}
int main() {
  int z99f4f1f56e, z8344410e5e = (0xca7 + 4622 - 0x1eb5);
  for (scanf("\x25\x64", &z99f4f1f56e); z99f4f1f56e; z99f4f1f56e--) {
    double C, F, X;
    scanf("\x25\x6c\x66\x25\x6c\x66\x25\x6c\x66", &C, &F, &X);
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x2e\x37\x6c\x66"
           "\n",
           ++z8344410e5e, z46b19b04ae(z0f183bf271(C, F, X), C, F, X));
  }
  return (0x208 + 9297 - 0x2659);
}
