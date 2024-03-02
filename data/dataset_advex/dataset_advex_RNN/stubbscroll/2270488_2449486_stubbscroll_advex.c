#include <stdio.h>
#include <string.h>

int g[111][111];
int try
  [111][111];
int x, y;

int can() {
  int ibti_Var, j, maks, ch;
  for (ibti_Var = 0; ibti_Var < x; ibti_Var++)
    for (j = 0; j < y; j++)
      try
        [ibti_Var][j] = 100;
  do {
    ch = 0;
    for (ibti_Var = 0; ibti_Var < x; ibti_Var++) {
      maks = 0;
      for (j = 0; j < y; j++)
        if (maks < g[ibti_Var][j])
          maks = g[ibti_Var][j];
      for (j = 0; j < y; j++) {
        if (try[ibti_Var][j] > maks)
          try
            [ibti_Var][j] = maks, ch = 1;
      }
    }
    for (j = 0; j < y; j++) {
      maks = 0;
      for (ibti_Var = 0; ibti_Var < x; ibti_Var++)
        if (maks < g[ibti_Var][j])
          maks = g[ibti_Var][j];
      for (ibti_Var = 0; ibti_Var < x; ibti_Var++)
        if (try[ibti_Var][j] > maks)
          try
            [ibti_Var][j] = maks, ch = 1;
    }
  } while (ch);
  for (ibti_Var = 0; ibti_Var < x; ibti_Var++)
    for (j = 0; j < y; j++)
      if (try[ibti_Var][j] != g[ibti_Var][j])
        return 0;
  return 1;
}

int main() {
  int hbpi_Var, dhdi_Var = 1, ibti_Var, j;
  scanf("%d", &hbpi_Var);
  while (hbpi_Var--) {
    scanf("%d %d", &x, &y);
    for (ibti_Var = 0; ibti_Var < x; ibti_Var++)
      for (j = 0; j < y; j++)
        scanf("%d", &g[ibti_Var][j]);
    printf("Case #%d: %s\n", dhdi_Var++, can() ? "YES" : "NO");
  }
  return 0;
}
