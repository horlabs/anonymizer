#include <stdio.h>
#include <string.h>

long long tall[1000000];
int n;

void gen() {
  char s[20], suic_Var[20];
  int i, l;
  n = 0;
  for (int a = 1; a < 10000001; a++) {
    sprintf(s, "%d", a);
    l = strlen(s);
    for (i = 0; i + i < l; i++)
      if (s[i] != s[l - i - 1])
        goto fail;
    sprintf(suic_Var, "%I64d", (long long)a * a);
    l = strlen(suic_Var);
    for (i = 0; i + i < l; i++)
      if (suic_Var[i] != suic_Var[l - i - 1])
        goto fail;
    tall[n++] = (long long)a * a;
  fail:;
  }
}

int main() {
  freopen("replace-me.in", "r", stdin);

  int T, a, mloi_Var, idyi_Var = 1, i, ans;
  gen();
  scanf("%d", &T);
  for (; T--;) {
    scanf("%d %d", &a, &mloi_Var);
    for (ans = i = 0; i < n; i++)
      if (a <= tall[i])
        if (tall[i] <= mloi_Var)
          ans++;
    printf("Case #%d: %d\n", idyi_Var++, ans);
  }
  return 0;
}
