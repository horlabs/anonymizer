
#include <stdio.h>

int main() {
  int z2ba9f6ea6e[(0x3ec + 3853 - 0x12f1)], z74163702de;
  int z93325194e2, ze4917b6709, z2c169ee46e, z7fe21e67ee, z13761abafd,
      z3f53a399ae, ze33cd94bbc, z3fc4d1de13, z3a0fa382ed, z1769d96660, f,
      z470530d205;
  scanf("\x25\x64", &z93325194e2);
  for (ze4917b6709 = (0xeea + 403 - 0x107c); ze4917b6709 <= z93325194e2;
       ze4917b6709++) {
    scanf("\x25\x64\x25\x64", &z2c169ee46e, &z7fe21e67ee);
    ze33cd94bbc = z2c169ee46e;
    z13761abafd = z470530d205 = (0x13b + 7372 - 0x1e07);
    while (ze33cd94bbc > (0x1f1a + 1048 - 0x2332)) {
      ze33cd94bbc /= (0x148f + 1986 - 0x1c47);
      z13761abafd++;
    }
    z3f53a399ae = (0x8dc + 7037 - 0x2458);
    for (z3fc4d1de13 = (0xcc1 + 1373 - 0x121d); z3fc4d1de13 < z13761abafd;
         z3fc4d1de13++)
      z3f53a399ae *= (0x120 + 8403 - 0x21e9);
    for (z3fc4d1de13 = z2c169ee46e; z3fc4d1de13 <= z7fe21e67ee; z3fc4d1de13++) {
      ze33cd94bbc = z3fc4d1de13;
      z2ba9f6ea6e[(0x12b0 + 1598 - 0x18ee)] = z3fc4d1de13;
      z74163702de = (0xb5c + 769 - 0xe5c);
      for (z3a0fa382ed = (0x107c + 3173 - 0x1ce0); z3a0fa382ed < z13761abafd;
           z3a0fa382ed++) {
        ze33cd94bbc = (ze33cd94bbc % (0x8a4 + 4682 - 0x1ae4)) * z3f53a399ae +
                      ze33cd94bbc / (0x12e3 + 5065 - 0x26a2);
        if (ze33cd94bbc > z7fe21e67ee)
          continue;
        if (ze33cd94bbc <= z3fc4d1de13)
          continue;
        f = (0x2bb + 4177 - 0x130b);
        for (z1769d96660 = (0x1138 + 3191 - 0x1daf); z1769d96660 < z74163702de;
             z1769d96660++) {
          if (z2ba9f6ea6e[z1769d96660] == ze33cd94bbc) {
            f = (0x12a + 5725 - 0x1787);
            break;
          }
        }
        if (f) {
          z2ba9f6ea6e[z74163702de++] = ze33cd94bbc;
          z470530d205++;
        }
      }
    }
    printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20\x25\x64"
           "\n",
           ze4917b6709, z470530d205);
  }
  return (0x7bd + 2447 - 0x114c);
}
