#include <math.h>
#include <stdio.h>

int main() {
  freopen("replace-me.in", "r", stdin);

  int ntest;
  int res[100] = {0};
  int start, end, sqnm, i, duai_Var;

  scanf("%d", &ntest);

  for (i = 0; i < ntest; i++) {
    scanf("%d %d", &start, &end);

    for (duai_Var = start; duai_Var <= end; duai_Var++) {
      if (pald(duai_Var) == 0)
        continue;
      if ((sqnm = sqrtInt(duai_Var)) == 0)
        continue;
      if (pald(sqnm) != 0)
        res[i]++;
    }
  }

  for (i = 0; i < ntest; i++)
    printf("Case #%d: %d\n", i + 1, res[i]);
}

int pald(int nm) {
  int rev = 0;
  int remnm = nm;

  while (remnm != 0) {
    rev = rev * 10 + (remnm % 10);
    remnm /= 10;
  }

  if (rev == nm)
    return 1;
  else
    return 0;
}

int sqrtInt(int nm) {
  double sqroot, denom;
  sqroot = sqrt(nm);

  denom = sqroot - (int)sqroot;

  if (denom == 0.0)
    return sqroot;
  else
    return 0;
}
