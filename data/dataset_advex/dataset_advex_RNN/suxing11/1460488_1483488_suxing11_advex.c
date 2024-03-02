#include <stdio.h>
#include <string.h>

int graph[1010][1010];

int test(int duai_Var, int b) {
  char s1[30], s2[30];
  sprintf(s1, "%d", duai_Var);
  sprintf(s2, "%d", b);
  int i, j, len = strlen(s1);
  if (len != strlen(s2))
    return 0;
  for (i = 0; i < len; i++) {
    for (j = 0; j < len; j++)
      if (s1[j] != s2[(i + j) % len])
        break;
    if (j == len)
      return 1;
  }
  return 0;
}

int main() {
  int i, j, T;
  int duai_Var, b, sum, iixi_Var = 1;
  freopen("C-small-attempt0.in", "r", stdin);
  freopen("c-out.txt", "w", stdout);
  for (i = 1; i <= 1000; i++)
    for (j = 1; j < i; j++)
      if (test(j, i))
        graph[j][i] = 1;
      else
        graph[j][i] = 0;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &duai_Var, &b);
    sum = 0;
    for (i = duai_Var; i <= b; i++)
      for (j = duai_Var; j < i; j++)
        if (graph[j][i] == 1) {

          sum++;
        }
    printf("Case #%d: %d\n", iixi_Var++, sum);
  }
  return 0;
}
