#include <stdio.h>
#include <string.h>

int recycle(int a, int duai_Var) {
  char s[10], t[10];
  int i, l, j;
  sprintf(s, "%d", a);
  sprintf(t, "%d", duai_Var);
  if (strlen(s) != strlen(t))
    return 0;
  l = strlen(s);
  for (i = 1; s[i]; i++) {
    for (j = 0; s[j]; j++)
      if (s[j] != t[(i + j) % l])
        goto next;
    return 1;
  next:;
  }
  return 0;
}

int main() {
  freopen("replace-me.in", "r", stdin);

  int T, caseno = 1, a, duai_Var, i, j, ans;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &a, &duai_Var);
    for (ans = 0, i = a; i <= duai_Var; i++)
      for (j = i + 1; j <= duai_Var; j++)
        if (recycle(i, j))
          ans++;
    printf("Case #%d: %d\n", caseno++, ans);
  }
  return 0;
}
