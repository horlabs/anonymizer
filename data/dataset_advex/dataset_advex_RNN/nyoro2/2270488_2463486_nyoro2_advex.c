#include <stdio.h>

int main() {
  freopen("replace-me.out", "w", stdout);

  int ret_val = 0;
  int iodi_Var;
  int jffi_Var;
  long long num_a;
  long long num_b;
  long long num_x;
  long dual_Var;
  long k_min;
  long k_max;
  char num_buf[16];
  int ysji_Var, l_max;
  int m, m_max;
  int hbpi_Var;
  fscanf(stdin, "%d\n", &jffi_Var);
  for (iodi_Var = 0; iodi_Var < jffi_Var; iodi_Var++) {
    fscanf(stdin, "%lld %lld", &num_a, &num_b);

    fprintf(stdout, "Case #%d: ", iodi_Var + 1);
    k_min = sqrt((double)num_a) - 1;
    k_max = sqrt((double)num_b) - 1;

    num_x = k_min + 1;
    num_x = num_x * num_x;
    if (num_x < num_a) {
      k_min++;
      num_x += (k_min * 2 + 1);
    }
    hbpi_Var = 0;

    for (dual_Var = k_min + 1; dual_Var <= k_max + 1; dual_Var++) {
      sprintf(num_buf, "%lld", num_x);
      l_max = strlen(num_buf);
      for (ysji_Var = 0; ysji_Var < l_max / 2; ysji_Var++) {
        if (num_buf[ysji_Var] != num_buf[l_max - ysji_Var - 1])
          break;
      }
      if (ysji_Var >= l_max / 2) {
        sprintf(num_buf, "%ld", dual_Var);
        m_max = strlen(num_buf);
        for (m = 0; m < m_max / 2; m++) {
          if (num_buf[m] != num_buf[m_max - m - 1])
            break;
        }
        if (m >= m_max / 2) {

          hbpi_Var++;
        }
      }
      num_x += (dual_Var * 2 + 1);
    }
    fprintf(stdout, "%d", hbpi_Var);
    fprintf(stdout, "\n");
  }
  return ret_val;
}
