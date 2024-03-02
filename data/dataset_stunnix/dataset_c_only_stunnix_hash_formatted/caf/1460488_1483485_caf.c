
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int zaf4fb66b6c(int z1c234eb3fe) {
  static const char *const z3353874f52 = "\x61\x62\x63\x64\x65\x66\x67\x68\x69"
                                         "\x6a\x6b\x6c\x6d\x6e\x6f\x70\x71\x72"
                                         "\x73\x74\x75\x76\x77\x78\x79\x7a";
  static const char *const z8aeecb5c21 = "\x79\x6e\x66\x69\x63\x77\x6c\x62\x6b"
                                         "\x75\x6f\x6d\x78\x73\x65\x76\x7a\x70"
                                         "\x64\x72\x6a\x67\x74\x68\x61\x71";
  const char *const zb31e63274f = strchr(z8aeecb5c21, z1c234eb3fe);
  if (zb31e63274f)
    return z3353874f52[zb31e63274f - z8aeecb5c21];
  else
    return z1c234eb3fe;
}
void zdee3126686(int z39d956d3ae) {
  int z1c234eb3fe;
  printf("\x43\x61\x73\x65\x20\x23\x25\x64\x3a\x20",
         z39d956d3ae + (0x12b + 6562 - 0x1acc));
  do {
    z1c234eb3fe = getchar();
    if (z1c234eb3fe == EOF)
      break;
    if (isupper(z1c234eb3fe))
      putchar(toupper(zaf4fb66b6c(tolower(z1c234eb3fe))));
    else
      putchar(zaf4fb66b6c(z1c234eb3fe));
  } while (z1c234eb3fe != '\n');
}
int main() {
  int z39d956d3ae, ze0ca49b543, z1c234eb3fe;
  scanf("\x25\x64", &z39d956d3ae);
  do {
    z1c234eb3fe = getchar();
  } while (z1c234eb3fe != EOF && z1c234eb3fe != '\n');
  for (ze0ca49b543 = (0x1319 + 3256 - 0x1fd1); ze0ca49b543 < z39d956d3ae;
       ze0ca49b543++)
    zdee3126686(ze0ca49b543);
  return (0x5e2 + 6570 - 0x1f8c);
}
