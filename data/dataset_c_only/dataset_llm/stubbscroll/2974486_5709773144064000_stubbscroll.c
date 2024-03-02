#include <stdio.h>

typedef struct {
	double c;
	double f;
	double x;
	double best;
	double tid;
	double produce;
} Problem;

double calculateBest(Problem prob) {
	prob.tid = 0;
	prob.best = prob.x / prob.produce;

	for (int z = 1; z < 2000000000; z++) {
		prob.tid += prob.c / prob.produce;
		prob.produce += prob.f;

		if (prob.best <= prob.tid + prob.x / prob.produce) {
			break;
		}

		prob.best = prob.tid + prob.x / prob.produce;
	}

	return prob.best;
}

void solve() {
	Problem prob;
	scanf("%lf %lf %lf", &prob.c, &prob.f, &prob.x);
	prob.produce = 2;

	prob.best = calculateBest(prob);

	printf("%.10f\n", prob.best);
}

int main() {
	int T;
	int no = 1;
	scanf("%d", &T);

	while (T--) {
		printf("Case #%d: ", no++);
		solve();
	}

	return 0;
}