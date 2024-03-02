#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int t, m, n;
  int i, j, k;
  int nc;
  scanf("%d", &t);
  char map[30] = "yhesocvxduiglbkrztnwjpfmaq";
  char line[1024];
  fgets(line, 1024, stdin);
  for (nc = 1; nc <= t; nc++) {
    fgets(line, 1024, stdin);
    line[strlen(line) - 1] = '\0';
    for (i = 0; i < strlen(line); i++) {
      if (line[i] == ' ') {
        continue;
      } else
        line[i] = map[line[i] - 'a'];
    }
    printf("Case #%d: %s\n", nc, line);
  }
  return 0;
}
