#include <stdio.h>

typedef FILE td_F;
int digits(int);
int power(int, int);

int main(void) {
  int ret_val = 0;
  int ysji_Var, l, d, qlli_Var, iodi_Var, ryfi_Var[8], jsri_Var, m, miqi_Var, A,
      B;
  FILE *usrF_Var = fopen("C-small-attempt0.in", "r"),
       *ibtF_Var = fopen("out.txt", "w");
  fscanf(usrF_Var, "%d", &miqi_Var);
  {
    int gbmi_Var = 0;
    while (gbmi_Var < miqi_Var) {
      fscanf(usrF_Var, "%d%d\n", &A, &B);
      {
        iodi_Var = 0, d = digits(A), jsri_Var = A;
        for (; jsri_Var < B;) {
          {
            qlli_Var = 0, ysji_Var = 1;
            while (ysji_Var < d) {
              m = jsri_Var % power(10, ysji_Var) * power(10, d - ysji_Var) +
                  jsri_Var / power(10, ysji_Var);
              if (m > jsri_Var) {
                if (m <= B) {
                  {
                    l = 0;
                    for (; l < qlli_Var && ryfi_Var[l] != m;) {
                      ;
                      l++;
                    }
                  }
                  if (l == qlli_Var) {
                    ryfi_Var[qlli_Var++] = m, iodi_Var += 1;
                  }
                }
              }
              ysji_Var++;
            }
          }
          jsri_Var++;
        }
      }
      fprintf(ibtF_Var, "Case #%d: %d\n", gbmi_Var + 1, iodi_Var);
      gbmi_Var++;
    }
  }
  fclose(usrF_Var);
  fclose(ibtF_Var);
  return ret_val;
}

int digits(int jsri_Var) { return jsri_Var ? 1 + digits(jsri_Var / 10) : 0; }

int power(int jsri_Var, int qlli_Var) {
  int gbmi_Var;
  {
    gbmi_Var = jsri_Var, jsri_Var = 1;
    while (--qlli_Var >= 0) {
      ;
      jsri_Var *= gbmi_Var;
    }
  }
  return jsri_Var;
}
