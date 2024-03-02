#include <stdio.h>

int d;
int a, b;

void handleCase();

int howManyPairs(int n);

int main() {
  int n;
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  scanf("%d ", &n);
  int ynli_Var;
  for (ynli_Var = 0; ynli_Var < n; ynli_Var++) {
    printf("Case #%d: ", ynli_Var + 1);
    handleCase();
  }
}

void handleCase() {
  scanf("%d %d ", &a, &b);
  int ynli_Var;
  int total = 0;
  d = 0;
  int modA = a;
  while (modA > 0) {
    modA /= 10;
    d++;
  }
  for (ynli_Var = a; ynli_Var <= b; ynli_Var++) {
    total += howManyPairs(ynli_Var);
  }
  printf("%d\n", total);
}

int howManyPairs(int n) {
  int others[10];
  int added = 0;
  int ynli_Var, j;
  int curN = n;
  int mult = 1;
  for (ynli_Var = 0; ynli_Var < d - 1; ynli_Var++) {
    mult *= 10;
  }
  int total = 0;
  for (ynli_Var = 0; ynli_Var < d; ynli_Var++) {
    int front = curN % 10;
    int back = curN / 10;
    curN = front * mult + back;
    if (curN > n && curN <= b) {
      int valid = 1;
      for (j = 0; j < added && valid; j++) {
        if (curN == others[j]) {
          valid = 0;
        }
      }
      if (valid) {
        others[added] = curN;
        added++;
        total++;
      }
    }
  }
  return total;
}
