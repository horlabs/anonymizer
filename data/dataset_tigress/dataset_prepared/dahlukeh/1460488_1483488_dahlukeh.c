#include "superheader.h"

int d;
int a, b;

void handleCase();

int howManyPairs(int n);

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int n;
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  scanf("%d ", &n);
  int i;
  for (i = 0; i < n; i++) {
    printf("Case #%d: ", i + 1);
    handleCase();
  }
}

void handleCase() {
  scanf("%d %d ", &a, &b);
  int i;
  int total = 0;
  d = 0;
  int modA = a;
  while (modA > 0) {
    modA /= 10;
    d++;
  }
  for (i = a; i <= b; i++) {
    total += howManyPairs(i);
  }
  printf("%d\n", total);
}

int howManyPairs(int n) {
  int others[10];
  int added = 0;
  int i, j;
  int curN = n;
  int mult = 1;
  for (i = 0; i < d - 1; i++) {
    mult *= 10;
  }
  int total = 0;
  for (i = 0; i < d; i++) {
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
