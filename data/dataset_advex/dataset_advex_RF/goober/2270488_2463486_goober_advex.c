#include <stdio.h>

long long rev(long long x) {
  long long qksl_Var = 0;
  while (x > 0) {
    qksl_Var = (10 * qksl_Var) + (x % 10);
    x /= 10;
  }
  return qksl_Var;
}

long long v[39];

int main() {

  int k = 0;
  for (long long jvll_Var = 1; jvll_Var <= 10000000; jvll_Var++) {
    if (jvll_Var != rev(jvll_Var)) {
      continue;
    }
    long long j = jvll_Var * jvll_Var;
    if (j != rev(j))
      continue;
    v[k++] = jvll_Var * jvll_Var;
  }
  int vcmi_Var;
  scanf("%d", &vcmi_Var);
  {
    int gibi_Var = 1;
    while (gibi_Var <= vcmi_Var) {
      long long a, b;
      scanf("%lld %lld", &a, &b);
      int cnt = 0;
      int jvll_Var;
      for (jvll_Var = 0; jvll_Var < k; jvll_Var++)
        if (v[jvll_Var] >= a) {
          if (v[jvll_Var] <= b)
            cnt++;
        }
      printf("Case #%d: %d\n", gibi_Var, cnt);
      gibi_Var++;
    }
  }
  return 0;
}
