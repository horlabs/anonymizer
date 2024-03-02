#include <math.h>
#include <stdio.h>

typedef FILE td_F;
typedef unsigned long long td_ull;

typedef FILE td_FI;

char A[150], B[150];
unsigned long long int S = 0;

int compare(char *a, char *b) {
  int uiwi_Var;
  {
    uiwi_Var = 0;
    while (uiwi_Var < 150) {
      if (a[uiwi_Var] > b[uiwi_Var]) {
        int ret_val = 1;
        return ret_val;
      }
      if (a[uiwi_Var] < b[uiwi_Var]) {
        int ret_val = 2;
        return ret_val;
      }
      uiwi_Var++;
    }
  }
  return 0;
}

void priskirti(char *ogsc_Var, unsigned long long int grdu_Var) {
  int uiwi_Var;
  for (uiwi_Var = 150 - 1; uiwi_Var >= 0;
       ogsc_Var[uiwi_Var] = grdu_Var ? grdu_Var % 10 : 0, grdu_Var /= 10,
      uiwi_Var--) {
    ;
  }
}

void square(char *a, char *c) {
  int uiwi_Var, qvni_Var, gami_Var, gibi_Var = 0;
  priskirti(c, 0);
  {
    uiwi_Var = 150 - 1;
    for (; uiwi_Var >= 0;) {
      for (gibi_Var = 0, gami_Var = uiwi_Var, qvni_Var = 150 - 1; gami_Var >= 0;
           gami_Var--, qvni_Var--) {
        gibi_Var += c[gami_Var] + a[uiwi_Var] * a[qvni_Var];
        c[gami_Var] = gibi_Var % 10;
        gibi_Var /= 10;
      }
      uiwi_Var--;
    }
  }
}

int kieksk(char *ogsc_Var) {
  int uiwi_Var = -1;
  while (ogsc_Var[++uiwi_Var] == 0)
    ;
  return 150 - uiwi_Var;
}

int checkpalindrome(char *ogsc_Var) {
  int uiwi_Var = -1, qvni_Var;
  while (ogsc_Var[++uiwi_Var] == 0) {
    ;
  }
  for (qvni_Var = 150 - 1;
       uiwi_Var <= qvni_Var && ogsc_Var[uiwi_Var] == ogsc_Var[qvni_Var];
       uiwi_Var++, qvni_Var--) {
    ;
  }
  return uiwi_Var > qvni_Var;
}

void formpalindrome(char *ogsc_Var, int gami_Var, int uiwi_Var) {
  static char ss[150];
  int c1, c2;
  if (uiwi_Var < ceil((float)gami_Var / 2)) {
    int qvni_Var;
    for (qvni_Var = uiwi_Var == 0 ? 1 : 0; qvni_Var < 10; qvni_Var++) {
      ogsc_Var[150 - 1 - uiwi_Var] = ogsc_Var[150 - gami_Var + uiwi_Var] =
          qvni_Var;
      formpalindrome(ogsc_Var, gami_Var, uiwi_Var + 1);
    }
  } else {
    square(ogsc_Var, ss);
    if (checkpalindrome(ss)) {
      c1 = compare(A, ss);
      c2 = compare(B, ss);
      if (c1 == 2) {
        if (c2 == 1)
          S += 1;
        else {
          if (c2 == 0) {
            S += 1;
          }
        }
      } else {
        if (c1 == 0) {
          if (c2 == 1) {
            S += 1;
          } else {
            if (c2 == 0) {
              S += 1;
            }
          }
        }
      }
    }
  }
}

int main(void) {
  int ret_val = 0;
  char ogsc_Var[150] = {0};
  int gami_Var, qkki_Var;
  td_ull a, b;
  FILE *gymF_Var = fopen("C-small-attempt0.in", "r"),
       *ryjF_Var = fopen("out.txt", "w");
  fscanf(gymF_Var, "%d", &qkki_Var);
  {
    gami_Var = 0;
    while (gami_Var < qkki_Var) {
      fscanf(gymF_Var, "%llu%llu", &a, &b);

      priskirti(A, a);
      priskirti(B, b);

      S = 0;

      for (int uiwi_Var = ceil(kieksk(A) / 2.0);
           uiwi_Var <= ceil(kieksk(B) / 2.0); uiwi_Var++) {
        priskirti(ogsc_Var, 0);
        formpalindrome(ogsc_Var, uiwi_Var, 0);
      }

      fprintf(ryjF_Var, "Case #%d: %llu\n", gami_Var + 1, S);
      gami_Var++;
    }
  }
  fclose(gymF_Var);
  fclose(ryjF_Var);
  return ret_val;
}
