#include <stdio.h>
#include <string.h>

int ymyi_Var[2000010];
int main() {
  int ret_val = 0;
  int shqi_Var, zrmi_Var, A, B, omgi_Var, xcri_Var, fqgi_Var, bits, tmp1, tmp2,
      result;

  scanf("%d", &zrmi_Var);
  for (shqi_Var = 1; shqi_Var <= zrmi_Var; shqi_Var++) {
    scanf("%d%d", &A, &B);
    memset(ymyi_Var, 0, sizeof(ymyi_Var));
    result = 0;
    bits = 1;
    for (omgi_Var = 1; omgi_Var < 10; omgi_Var++) {
      bits *= 10;
      if (A / bits == 0) {
        break;
      }
    }
    bits /= 10;
    fqgi_Var = omgi_Var;
    for (omgi_Var = A; omgi_Var <= B; omgi_Var++) {
      int num = 1;
      tmp1 = omgi_Var;
      ymyi_Var[tmp1] = 1;
      for (xcri_Var = 0; xcri_Var < fqgi_Var; xcri_Var++) {
        tmp2 = bits * (tmp1 % 10) + tmp1 / 10;
        if (tmp2 == tmp1) {
          break;
        }
        if (tmp2 <= B)
          if (tmp2 >= A) {
            if (!ymyi_Var[tmp2]) {
              num++;
            }
            ymyi_Var[tmp2] = 1;
          }
        tmp1 = tmp2;
      }
      result += (num - 1) * num / 2;
    }
    printf("Case #%d: %d\n", shqi_Var, result);
  }
  return ret_val;
}
