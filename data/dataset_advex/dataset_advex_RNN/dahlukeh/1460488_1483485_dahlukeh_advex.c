#include <stdio.h>
#include <stdlib.h>

void do_voizbu_fct();

char map[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l',
              'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int main() {
  int n;
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  scanf("%d ", &n);

  for (int i = 0; i < n; i++) {
    printf("Case #%d: ", i + 1);
    do_voizbu_fct();
  }
}

void do_voizbu_fct() {
  char line[2000];
  char c;
  int i = 0;
  scanf("%c", &c);
  while (c != '\n') {
    line[i] = c;
    i++;
    scanf("%c", &c);
  }
  line[i] = '\0';
  for (i = 0; line[i] != '\0'; i++) {
    if (line[i] >= 'a' && line[i] <= 'z')
      printf("%c", map[line[i] - 'a']);
    else {
      printf(" ");
    }
  }
  printf("\n");
}
