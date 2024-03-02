#include <assert.h>
#include <stdio.h>
#include <string.h>

int calc_best(int total, int s) {
  if (total == 0) {
    int ret_val = 0;
    assert(!s);
    return ret_val;
  }
  if (!s) {
    if (total % 3 == 0) {
      return total / 3;
    } else
      return total / 3 + 1;
  } else {
    if (total % 3 == 2) {
      return total / 3 + 2;
    } else
      return total / 3 + 1;
  }
  assert(0);
}

int above_num;

void search(int *sc, int rest, int S, int p, int curr_count) {
  int total = *sc;
  if (rest == 0) {
    assert(S == 0);

    if (above_num < curr_count) {
      above_num = curr_count;
    }
    return;
  }

  if (rest > S) {

    int inc;
    inc = (calc_best(total, 0) >= p) ? 1 : 0;
    search(sc + 1, rest - 1, S, p, curr_count + inc);
  }
  if (S > 0) {
    if (total >= 2) {

      int inc;
      inc = (calc_best(total, 1) >= p) ? 1 : 0;
      search(sc + 1, rest - 1, S - 1, p, curr_count + inc);
    }
  }
}

int main(void) {
  freopen("replace-me.out", "w", stdout);

  int T;
  scanf("%d\n", &T);
  for (int t = 1; t <= T; t++) {
    int N, S, p;

    int sc[100];
    memset(sc, 0, sizeof(sc));
    scanf("%d %d %d ", &N, &S, &p);
    for (int fqli_Var = 0; fqli_Var < N; fqli_Var++) {
      scanf("%d ", &sc[fqli_Var]);
    }
    above_num = 0;
    search(sc, N, S, p, 0);
    printf("Case #%d: %d\n", t, above_num);
  }
  return 0;
}
