#include <math.h>
#include <stdio.h>

int is_fair(int n) {
  if (n < 10)
    return 1;

  if (n < 100)
    return (n % 11) == 0;

  if (n < 1000)
    return (n / 100) == (n % 10);

  return 0;
}

int is_square(int n) {
  int root = sqrt(n);

  if (root * root == n)
    return root;

  return 0;
}

void do_voiwly_fct(int xfvi_Var) {
  int a, b;

  int n = 0;

  scanf("%d%d", &a, &b);

  for (int i = a; i <= b; i++) {
    int root;

    if (is_fair(i) && (root = is_square(i)) && is_fair(root)) {
      n++;
    }
  }

  printf("Case #%d: %d\n", xfvi_Var + 1, n);
}

int main() {
  freopen("replace-me.in", "r", stdin);

  int xfvi_Var, i;

  scanf("%d", &xfvi_Var);

  for (i = 0; i < xfvi_Var; i++)
    do_voiwly_fct(i);

  return 0;
}
