
#include <stdio.h>
#include <stdlib.h>

void z3cccabb4f5();
long long z94c37775d4, z30e3e089e9;
char zb0b2217a33[(0x1258 + 327 - 0x12d7)];
long long z1ce0e9860f(long long z3915b59e44);
int z0dba3470e0(long long zdc1e9328d5);
long long z260e7d6186(long long z80f31db545, int z52ed0d82df);
void z52ebfd46e6(long long zdc1e9328d5, char *z0cda775ae6);
long long zc0009c2051(char *z0cda775ae6);
int zdc90ad10d0(long long zdc1e9328d5);
int main() {
  freopen("\x63\x69\x6e\x2e\x74\x78\x74", "\x72", stdin);
  freopen("\x63\x6f\x75\x74\x2e\x74\x78\x74", "\x77", stdout);
  int z9c55adf803;
  scanf("\x25\x64\x20", &z9c55adf803);
  int za5bbdd0a96;
  for (za5bbdd0a96 = (0x103f + 1463 - 0x15f6); za5bbdd0a96 < z9c55adf803;
       za5bbdd0a96++) {
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
           za5bbdd0a96 + (0xd44 + 2162 - 0x15b5));
    z3cccabb4f5();
  }
  return (0x879 + 378 - 0x9f3);
}
void z3cccabb4f5() {
  scanf("\x25\x49\x36\x34\x64\x20\x25\x49\x36\x34\x64\x20", &z94c37775d4,
        &z30e3e089e9);
  long long z6f45db1f3d = z1ce0e9860f(z30e3e089e9) -
                          z1ce0e9860f(z94c37775d4 - (0x1c6 + 8137 - 0x218e));
  printf("\x25\x49\x36\x34\x64"
         "\n",
         z6f45db1f3d);
}
long long z1ce0e9860f(long long z3915b59e44) {
  long long z113f89430d;
  long long z9fbd170d49 = 0ll;
  int za5bbdd0a96, z88f8c2c93c;
  for (za5bbdd0a96 = (0x12f + 210 - 0x200);; za5bbdd0a96++) {
    z113f89430d = 1ll;
    for (z88f8c2c93c = (0xab9 + 5582 - 0x2087);
         z88f8c2c93c <
         ((za5bbdd0a96 - (0x6e0 + 2872 - 0x1217)) / (0xb99 + 1492 - 0x116b));
         z88f8c2c93c++) {
      z113f89430d *= 10ll;
    }
    long long z1ef530b613 = z113f89430d * 10ll;
    for (; z113f89430d < z1ef530b613; z113f89430d++) {
      long long zec72734578 = z260e7d6186(z113f89430d, za5bbdd0a96);
      if (zec72734578 * zec72734578 > z3915b59e44) {
        return z9fbd170d49;
      }
      if (zdc90ad10d0(zec72734578 * zec72734578)) {
        z9fbd170d49++;
      }
    }
  }
  return z9fbd170d49;
}
long long z260e7d6186(long long z80f31db545, int z52ed0d82df) {
  z52ebfd46e6(z80f31db545, zb0b2217a33);
  int za5bbdd0a96;
  for (za5bbdd0a96 = z52ed0d82df - (0x15b + 7930 - 0x2054);
       za5bbdd0a96 >= (0x2ea + 378 - 0x464); za5bbdd0a96--) {
    zb0b2217a33[za5bbdd0a96] =
        zb0b2217a33[z52ed0d82df - za5bbdd0a96 - (0xf76 + 5644 - 0x2581)];
  }
  zb0b2217a33[z52ed0d82df] = '\0';
  return zc0009c2051(zb0b2217a33);
}
int zdc90ad10d0(long long zdc1e9328d5) {
  z52ebfd46e6(zdc1e9328d5, zb0b2217a33);
  int z0e234c3c45 = z0dba3470e0(zdc1e9328d5);
  int za5bbdd0a96;
  for (za5bbdd0a96 = (0x1a0 + 3688 - 0x1008); za5bbdd0a96 < z0e234c3c45;
       za5bbdd0a96++) {
    if (zb0b2217a33[za5bbdd0a96] !=
        zb0b2217a33[z0e234c3c45 - za5bbdd0a96 - (0x7d2 + 1868 - 0xf1d)]) {
      return (0x1000 + 258 - 0x1102);
    }
  }
  return (0x16a + 3045 - 0xd4e);
}
int z0dba3470e0(long long zdc1e9328d5) {
  int za5bbdd0a96 = (0x831 + 867 - 0xb93);
  long long z113f89430d = 10ll;
  for (; z113f89430d <= zdc1e9328d5; za5bbdd0a96++) {
    z113f89430d *= 10ll;
  }
  return za5bbdd0a96;
}
void z52ebfd46e6(long long zdc1e9328d5, char *z0cda775ae6) {
  int z453b0c4a65 = z0dba3470e0(zdc1e9328d5);
  int za5bbdd0a96;
  z0cda775ae6[z453b0c4a65] = '\0';
  for (za5bbdd0a96 = (0xfd3 + 3507 - 0x1d86); za5bbdd0a96 < z453b0c4a65;
       za5bbdd0a96++) {
    char z0e234c3c45 = (zdc1e9328d5 % 10ll) + ((char)(0x1e0f + 1058 - 0x2201));
    z0cda775ae6[z453b0c4a65 - za5bbdd0a96 - (0x173b + 234 - 0x1824)] =
        z0e234c3c45;
    zdc1e9328d5 /= 10ll;
  }
}
long long zc0009c2051(char *z0cda775ae6) {
  long long zdc1e9328d5 = 0ll;
  int za5bbdd0a96;
  for (za5bbdd0a96 = (0xb25 + 427 - 0xcd0); z0cda775ae6[za5bbdd0a96] != '\0';
       za5bbdd0a96++) {
    zdc1e9328d5 *= 10ll;
    zdc1e9328d5 +=
        (z0cda775ae6[za5bbdd0a96] - ((char)(0x1585 + 3622 - 0x237b)));
  }
  return zdc1e9328d5;
}
