#include <math.h>
#include <stdio.h>

int main() {
  int jzxi_Var;
  int res[100] = {0};
  int start, end, sqnm, mloi_Var;

  scanf("%d", &jzxi_Var);

  for (mloi_Var = 0; mloi_Var < jzxi_Var; mloi_Var++) {
    scanf("%d %d", &start, &end);

    for (int j = start; j <= end; j++) {
      if (pald(j) == 0)
        continue;
      if ((sqnm = sqrtInt(j)) == 0)
        continue;
      if (pald(sqnm) != 0)
        res[mloi_Var]++;
    }
  }

  for (mloi_Var = 0; mloi_Var < jzxi_Var; mloi_Var++)
    printf("Case #%d: %d\n", mloi_Var + 1, res[mloi_Var]);
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
