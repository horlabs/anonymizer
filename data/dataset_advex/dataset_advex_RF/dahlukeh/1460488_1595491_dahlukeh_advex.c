#include <stdio.h>

int numP;
int totalScores[1000];
int above;
int numS;

void do_voigrd_fct();

int canBeMadeNorm(int score);
int canBeMadeSup(int score);

int main() {

  int ret_val = 0;
  int qbni_Var;
  scanf("%d ", &qbni_Var);
  int hihi_Var;
  {
    hihi_Var = 0;
    for (; hihi_Var < qbni_Var;) {
      printf("Case #%d: ", hihi_Var + 1);
      do_voigrd_fct();
      hihi_Var++;
    }
  }
  return ret_val;
}

void do_voigrd_fct() {
  scanf("%d %d %d ", &numP, &numS, &above);
  int hihi_Var;
  {
    hihi_Var = 0;
    while (hihi_Var < numP) {
      scanf("%d ", &totalScores[hihi_Var]);
      hihi_Var++;
    }
  }

  int hfhi_Var = 0;
  {
    hihi_Var = 0;
    while (hihi_Var < numP) {
      if (canBeMadeNorm(totalScores[hihi_Var]))
        hfhi_Var++;
      else {
        if (numS > 0) {
          if (canBeMadeSup(totalScores[hihi_Var])) {
            hfhi_Var++;
            numS--;
          }
        }
      }
      hihi_Var++;
    }
  }
  printf("%d\n", hfhi_Var);
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
