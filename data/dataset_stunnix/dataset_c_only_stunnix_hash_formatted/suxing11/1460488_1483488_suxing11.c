
#include <stdio.h>
#include <string.h>

int z0c6e20bae2[(0x14b3 + 2439 - 0x1a48)][(0x9ff + 6136 - 0x1e05)];
int z627f7ba04c(int z8e80448537, int z783b12756a) {
  char zf2c589f694[(0x1018 + 3195 - 0x1c75)],
      zd2974baf3b[(0x99d + 6189 - 0x21ac)];
  sprintf(zf2c589f694, "\x25\x64", z8e80448537);
  sprintf(zd2974baf3b, "\x25\x64", z783b12756a);
  int z9fbaf7cfe7, zcc12137ebf, z9b7fce4adc = strlen(zf2c589f694);
  if (z9b7fce4adc != strlen(zd2974baf3b))
    return (0x159a + 2030 - 0x1d88);
  for (z9fbaf7cfe7 = (0x161b + 301 - 0x1748); z9fbaf7cfe7 < z9b7fce4adc;
       z9fbaf7cfe7++) {
    for (zcc12137ebf = (0xc6b + 5010 - 0x1ffd); zcc12137ebf < z9b7fce4adc;
         zcc12137ebf++)
      if (zf2c589f694[zcc12137ebf] !=
          zd2974baf3b[(z9fbaf7cfe7 + zcc12137ebf) % z9b7fce4adc])
        break;
    if (zcc12137ebf == z9b7fce4adc)
      return (0xb70 + 2151 - 0x13d6);
  }
  return (0x55f + 3329 - 0x1260);
}
int main() {
  int z9fbaf7cfe7, zcc12137ebf, z65a4e757ce;
  int z8e80448537, z783b12756a, z1abf41fb2b,
      z3b9dd94fde = (0x88f + 4850 - 0x1b80);
  freopen("\x43\x2d\x73\x6d\x61\x6c\x6c\x2d\x61\x74\x74\x65\x6d\x70\x74\x30\x2e"
          "\x69\x6e",
          "\x72", stdin);
  freopen("\x63\x2d\x6f\x75\x74\x2e\x74\x78\x74", "\x77", stdout);
  for (z9fbaf7cfe7 = (0xa73 + 5484 - 0x1fde);
       z9fbaf7cfe7 <= (0x7db + 1175 - 0x88a); z9fbaf7cfe7++)
    for (zcc12137ebf = (0xb20 + 2178 - 0x13a1); zcc12137ebf < z9fbaf7cfe7;
         zcc12137ebf++)
      if (z627f7ba04c(zcc12137ebf, z9fbaf7cfe7))
        z0c6e20bae2[zcc12137ebf][z9fbaf7cfe7] = (0x936 + 3049 - 0x151e);
      else
        z0c6e20bae2[zcc12137ebf][z9fbaf7cfe7] = (0xc2d + 6210 - 0x246f);
  scanf("\x25\x64", &z65a4e757ce);
  while (z65a4e757ce--) {
    scanf("\x25\x64\x25\x64", &z8e80448537, &z783b12756a);
    z1abf41fb2b = (0x6dc + 7471 - 0x240b);
    for (z9fbaf7cfe7 = z8e80448537; z9fbaf7cfe7 <= z783b12756a; z9fbaf7cfe7++)
      for (zcc12137ebf = z8e80448537; zcc12137ebf < z9fbaf7cfe7; zcc12137ebf++)
        if (z0c6e20bae2[zcc12137ebf][z9fbaf7cfe7] == (0x14e5 + 2443 - 0x1e6f)) {
          z1abf41fb2b++;
        }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           z3b9dd94fde++, z1abf41fb2b);
  }
  return (0xfe1 + 4685 - 0x222e);
}
