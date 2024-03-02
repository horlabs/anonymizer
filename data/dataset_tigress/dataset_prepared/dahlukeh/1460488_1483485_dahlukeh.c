#include "superheader.h"

void handleCase();

char map[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l',
              'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int n;
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  scanf("%d ", &n);
  int i;
  for (i = 0; i < n; i++) {
    printf("Case #%d: ", i + 1);
    handleCase();
  }
}

void handleCase() {
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
    if (line[i] >= 'a' && line[i] <= 'z') {
      printf("%c", map[line[i] - 'a']);
    } else {
      printf(" ");
    }
  }
  printf("\n");
}
