#include <stdio.h>

int main() {
  int ret_val = 0;
  int fhoi_Var[200], cdci_Var[200][3], ysji_Var, p, q, r, N, S,
      irmi_Var = 0, suii_Var, gnxi_Var, m = 1;
  FILE *znlF_Var, *ahlF_Var;
  znlF_Var = fopen("B-small-attempt0.in", "r");
  ahlF_Var = fopen("output.txt", "w");
  fscanf(znlF_Var, "%d", &gnxi_Var);
  while (m <= gnxi_Var) {
    fscanf(znlF_Var, "%d %d %d", &N, &S, &p);
    fhoi_Var[0] = N;
    fhoi_Var[1] = S;
    fhoi_Var[2] = p;
    {
      ysji_Var = 0;
      while (ysji_Var < N) {
        fscanf(znlF_Var, "%d", &fhoi_Var[ysji_Var + 3]);
        ysji_Var++;
      }
    }
    {
      ysji_Var = 0;
      while (ysji_Var < fhoi_Var[0]) {
        {

          {
            int vyxi_Var = 10;
            while (vyxi_Var > 0) {

              if (fhoi_Var[ysji_Var + 3] / vyxi_Var == 0) {
                if (vyxi_Var - 1 == 0) {
                  cdci_Var[ysji_Var][0] = 0;
                  cdci_Var[ysji_Var][1] = 0;
                  cdci_Var[ysji_Var][2] = 0;
                }
                vyxi_Var--;
                continue;
              }

              if (abs((fhoi_Var[ysji_Var + 3] % vyxi_Var) - vyxi_Var) == 2) {
                cdci_Var[ysji_Var][1] = vyxi_Var;

                cdci_Var[ysji_Var][0] = fhoi_Var[ysji_Var + 3] % vyxi_Var;
                cdci_Var[ysji_Var][2] = vyxi_Var;
                break;
              } else if (abs((fhoi_Var[ysji_Var + 3] % vyxi_Var) - vyxi_Var) ==
                         1) {
                cdci_Var[ysji_Var][1] = vyxi_Var;

                cdci_Var[ysji_Var][0] = fhoi_Var[ysji_Var + 3] % vyxi_Var;
                cdci_Var[ysji_Var][2] = vyxi_Var;
                break;
              }
              vyxi_Var--;
            }
          }
        }
        ysji_Var++;
      }
    }
    while (S > 0) {
      {
        ysji_Var = 0;
        while (ysji_Var < N) {
          if (cdci_Var[ysji_Var][0] <= p) {
            S--;
            cdci_Var[ysji_Var][0]++;
            cdci_Var[ysji_Var][1]--;
            cdci_Var[ysji_Var][2]--;
            break;
          } else if (cdci_Var[ysji_Var][1] <= p) {
            S--;
            cdci_Var[ysji_Var][0]--;
            cdci_Var[ysji_Var][1]++;
            cdci_Var[ysji_Var][2]--;
            break;
          } else {
            S--;
            cdci_Var[ysji_Var][0]--;
            cdci_Var[ysji_Var][1]--;
            cdci_Var[ysji_Var][2]++;
            break;
          }
          ysji_Var++;
        }
      }
    }
    {
      ysji_Var = 0;
      while (ysji_Var < fhoi_Var[0]) {
        if (cdci_Var[ysji_Var][2] >= p)
          irmi_Var++;
        else if (cdci_Var[ysji_Var][0] >= p) {
          irmi_Var++;
        } else if (cdci_Var[ysji_Var][1] >= p) {
          irmi_Var++;
        }
        ysji_Var++;
      }
    }
    fprintf(ahlF_Var, "Case #%d: %d\n", m, irmi_Var);
    m++;
    irmi_Var = 0;
  }
  return ret_val;
}
