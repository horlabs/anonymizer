#include <stdio.h>

FILE *f1, *f2;
int str1[8], str2[8], len;
long long int te[7], co;
int ln(long long int jzxl_Var) {
  int fazi_Var = 0;
  while (jzxl_Var > 0) {
    fazi_Var++;
    jzxl_Var /= 10;
  }
  return (fazi_Var - 1);
}
void conv(long long int jzxl_Var) {
  int aaei_Var;
  {
    int j = len;
    while (j >= 0) {
      str1[j] = jzxl_Var % 10;
      jzxl_Var /= 10;
      j--;
    }
  }
}
long long int get() {
  long long j = 0;

  for (int jzxl_Var = 0; jzxl_Var <= len; jzxl_Var++) {
    j += str2[jzxl_Var];
    j = j * 10;
  }
  j /= 10;
  return (j);
}

void sh() {
  int jzxl_Var, aaei_Var;
  jzxl_Var = str2[len];
  {
    int j = (len - 1);
    while (j >= 0) {
      str2[j + 1] = str2[j];
      j--;
    }
  }
  str2[0] = jzxl_Var;
}
int chk(long long int jzxl_Var, long long int ozql_Var, long long int n) {
  if (str1[0] == 0) {
    return (0);
  }
  int j, aaei_Var = 0;
  {
    j = 0;
    while (j <= len) {
      str2[j] = str1[j];
      j++;
    }
  }
  int ch;
  long long f;
  co = -1;
  {
    j = 1;
    while (j <= len) {
      sh();
      f = get();
      {
        ch = 0;
        while (ch <= co) {
          if (te[ch] == f)
            goto lst;

          ch++;
        }
      }
      if ((f > jzxl_Var) && (f >= ozql_Var))
        if ((f <= n)) {
          aaei_Var++;
          co++;
          te[co] = f;
        }
    lst:
      aaei_Var += 0;
      j++;
    }
  }
  return (aaei_Var);
}
void do_voijff_fct() {
  long long ozql_Var, n, jzxl_Var;
  long fazi_Var = 0, aaei_Var;
  fscanf(f1, "%lld", &ozql_Var);
  fscanf(f1, "%lld", &n);
  len = ln(ozql_Var);
  if (len == 0)
    goto end;

  for (jzxl_Var = ozql_Var; jzxl_Var <= n; jzxl_Var++) {
    conv(jzxl_Var);
    aaei_Var = chk(jzxl_Var, ozql_Var, n);
    fazi_Var += aaei_Var;
    if (aaei_Var > 0)
      printf("%lld:%ld\t", jzxl_Var, aaei_Var);
  }
end:
  fprintf(f2, "%ld", fazi_Var);
}
int main() {
  f1 = fopen("/home/vivek/Desktop/s.in", "r");
  f2 = fopen("/home/vivek/Desktop/s.out", "w");
  int ryji_Var;
  char c;
  fscanf(f1, "%d", &ryji_Var);
  for (int jzxl_Var = 1; jzxl_Var <= ryji_Var; jzxl_Var++) {
    fprintf(f2, "Case #%d: ", jzxl_Var);
    do_voijff_fct();
    c = '\n';
    fputc(c, f2);
  }
  return (1);
}
