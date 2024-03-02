#include <stdio.h>
#include <stdlib.h>

int numP;
int totalScores[1000];
int above;
int numS;

void do_voizbu_fct();

int canBeMadeNorm(int score);
int canBeMadeSup(int score);

int main() {
  int n;
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  scanf("%d ", &n);

  for (int i = 0; i < n; i++) {
    printf("Case #%d: ", i + 1);
    do_voizbu_fct();
  }
}

void do_voizbu_fct() {
  scanf("%d %d %d ", &numP, &numS, &above);
  int i;
  for (i = 0; i < numP; i++)
    scanf("%d ", &totalScores[i]);

  int total = 0;
  for (i = 0; i < numP; i++) {
    if (canBeMadeNorm(totalScores[i])) {
      total++;
    } else {
      if (numS > 0 && canBeMadeSup(totalScores[i])) {
        total++;
        numS--;
      }
    }
  }
  printf("%d\n", total);
}

int canBeMadeNorm(int score) {
  int rem = score % 3;
  int bestP = score / 3;
  if (rem > 0) {
    bestP++;
  }
  return bestP >= above;
}

int canBeMadeSup(int score) {
  int rem = score % 3;
  int bestP = score / 3;
  if (rem == 2) {
    bestP += 2;
  } else {
    if (rem == 1 || score > 0) {
      bestP++;
    }
  }
  return bestP >= above;
}
