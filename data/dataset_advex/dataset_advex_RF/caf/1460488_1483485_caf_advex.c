#include <ctype.h>
#include <stdio.h>
#include <string.h>

typedef const char td_cc;
int goog_to_eng(int c) {
  static const char *const english = "abcdefghijklmnopqrstuvwxyz";
  static const char *const googlerese = "ynficwlbkuomxsevzpdrjgthaq";
  const char *const p = strchr(googlerese, c);

  if (p)
    return english[p - googlerese];
  else
    return c;
}

void do_voifqg_fct(int jzxi_Var) {
  int c;

  printf("Case #%d: ", jzxi_Var + 1);

  do {
    c = getchar();

    if (c == EOF)
      break;

    if (isupper(c))
      putchar(toupper(goog_to_eng(tolower(c))));
    else
      putchar(goog_to_eng(c));
  } while (c != '\n');
}

int main() {
  freopen("replace-me.in", "r", stdin);

  freopen("replace-me.out", "w", stdout);

  int jzxi_Var, plli_Var, c;

  scanf("%d", &jzxi_Var);
  do {
    c = getchar();
  } while (c != EOF && c != '\n');

  {
    plli_Var = 0;
    while (plli_Var < jzxi_Var) {
      do_voifqg_fct(plli_Var);
      plli_Var++;
    }
  }

  return 0;
}
