#include <stdio.h>
#include <stdlib.h>

#define MAX_CASES 100
#define MAX_ITERATIONS 100

typedef struct {
	double c;
	double f;
	double x;
} TestCase;

double calculateTime(TestCase testCase);
void readTestCases(TestCase testCases[], int numCases);

int main()
{
	int numCases;
	TestCase testCases[MAX_CASES];

	scanf("%d",&numCases);
	require(numCases >= 1 && numCases <= MAX_CASES, "Number of test cases must be between 1 and 100.");

	readTestCases(testCases, numCases);

	for(int tcase = 0; tcase < numCases; tcase++)
	{
		double minTime = calculateTime(testCases[tcase]);
		printf("Case #%d: %.7lf\n",tcase+1, minTime);
	}

	return 0;
}

double calculateTime(TestCase testCase)
{
	double time = 0;
	double velocity = 2.0;
	double timeFarm = 0;
	double minTime = testCase.x / velocity;

	for(int counter = 0; counter < MAX_ITERATIONS; counter++)
	{
		timeFarm += testCase.c / velocity;
		velocity += testCase.f;
		time = timeFarm + testCase.x / velocity;

		if(time < minTime)
		{
			minTime = time;
			if(counter > 0)
				fprintf(stderr,"Resetting counter.\n");
			counter = 0;
		}
		else
			counter++;
	}

	return minTime;
}

void readTestCases(TestCase testCases[], int numCases)
{
	for(int i = 0; i < numCases; i++)
	{
		scanf("%lf %lf %lf", &testCases[i].c, &testCases[i].f, &testCases[i].x);
	}
}