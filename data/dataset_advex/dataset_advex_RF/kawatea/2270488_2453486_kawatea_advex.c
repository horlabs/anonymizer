#include <stdio.h>

int main() {
  int cuai_Var, i;

  scanf("%d", &cuai_Var);

  for (i = 0; i < cuai_Var; i++) {
    int f = 0, omgi_Var, jvli_Var;
    char redc_Var[4][5];

    for (omgi_Var = 0; omgi_Var < 4; omgi_Var++)
      scanf("%s", redc_Var[omgi_Var]);

    for (omgi_Var = 0; omgi_Var < 4; omgi_Var++) {
      for (jvli_Var = 0; jvli_Var < 4; jvli_Var++) {
        if (redc_Var[omgi_Var][jvli_Var] == 'O' ||
            redc_Var[omgi_Var][jvli_Var] == '.')
          break;
      }

      if (jvli_Var == 4)
        f = 1;

      for (jvli_Var = 0; jvli_Var < 4; jvli_Var++) {
        if (redc_Var[jvli_Var][omgi_Var] == 'O' ||
            redc_Var[jvli_Var][omgi_Var] == '.')
          break;
      }

      if (jvli_Var == 4)
        f = 1;

      for (jvli_Var = 0; jvli_Var < 4; jvli_Var++) {
        if (redc_Var[omgi_Var][jvli_Var] == 'X' ||
            redc_Var[omgi_Var][jvli_Var] == '.')
          break;
      }

      if (jvli_Var == 4)
        f = 2;

      for (jvli_Var = 0; jvli_Var < 4; jvli_Var++) {
        if (redc_Var[jvli_Var][omgi_Var] == 'X' ||
            redc_Var[jvli_Var][omgi_Var] == '.')
          break;
      }

      if (jvli_Var == 4)
        f = 2;
    }

    for (omgi_Var = 0; omgi_Var < 4; omgi_Var++) {
      if (redc_Var[omgi_Var][omgi_Var] == 'O' ||
          redc_Var[omgi_Var][omgi_Var] == '.')
        break;
    }

    if (omgi_Var == 4)
      f = 1;

    for (omgi_Var = 0; omgi_Var < 4; omgi_Var++) {
      if (redc_Var[omgi_Var][3 - omgi_Var] == 'O' ||
          redc_Var[omgi_Var][3 - omgi_Var] == '.')
        break;
    }

    if (omgi_Var == 4)
      f = 1;

    for (omgi_Var = 0; omgi_Var < 4; omgi_Var++) {
      if (redc_Var[omgi_Var][omgi_Var] == 'X' ||
          redc_Var[omgi_Var][omgi_Var] == '.')
        break;
    }

    if (omgi_Var == 4)
      f = 2;

    for (omgi_Var = 0; omgi_Var < 4; omgi_Var++) {
      if (redc_Var[omgi_Var][3 - omgi_Var] == 'X' ||
          redc_Var[omgi_Var][3 - omgi_Var] == '.')
        break;
    }

    if (omgi_Var == 4)
      f = 2;

    if (f == 1) {
      printf("Case #%d: X won\n", i + 1);
    } else if (f == 2) {
      printf("Case #%d: O won\n", i + 1);
    } else {
      for (omgi_Var = 0; omgi_Var < 4; omgi_Var++) {
        for (jvli_Var = 0; jvli_Var < 4; jvli_Var++) {
          if (redc_Var[omgi_Var][jvli_Var] == '.')
            f = 1;
        }
      }

      if (f == 1) {
        printf("Case #%d: Game has not completed\n", i + 1);
      } else {
        printf("Case #%d: Draw\n", i + 1);
      }
    }
  }

  return 0;
}
