#include <ctype.h>
#include <stdio.h>
#include <string.h>
const char mapping[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd',
                          'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't',
                          'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int main() {
  int dtgi_Var;
  int cnt = 0;
  for (scanf("%d\n", &dtgi_Var); dtgi_Var; dtgi_Var--, cnt++) {
    static char buf[200];
    int len = 0;
    int i = 0;
    fgets(buf, 200, stdin);
    len = strlen(buf);
    while (len && !isprint(buf[len - 1]))
      buf[--len] = 0;
    for (i = 0; i < len; i++) {
      if (buf[i] == ' ')
        continue;
      buf[i] = mapping[buf[i] - 'a'];
    }
    printf("Case #%d: %s\n", cnt + 1, buf);
  }
  return 0;
}
