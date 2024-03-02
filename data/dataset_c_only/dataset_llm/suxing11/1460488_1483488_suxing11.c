#include <stdio.h>
#include <string.h>

// Define the size of the graph
#define MAX_SIZE 1010

// Declare the graph as a 2D array
int graph[MAX_SIZE][MAX_SIZE];

// Function to check if two integers are cyclic permutations of each other
int isCyclicPermutation(int a, int b)
{
	char str_a[30], str_b[30];
	sprintf(str_a, "%d", a);
	sprintf(str_b, "%d", b);
	
	int i, j, len = strlen(str_a);
	
	if (len != strlen(str_b))
		return 0;
	
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (str_a[j] != str_b[(i + j) % len])
				break;
		}
		
		if (j == len)
			return 1;
	}
	
	return 0;
}

// Function to count the number of cyclic permutations within a given range
int countCyclicPermutations(int a, int b)
{
	int i, j, sum = 0;
	
	for (i = a; i <= b; i++)
	{
		for (j = a; j < i; j++)
		{
			if (graph[j][i] == 1)
				sum++;
		}
	}
	
	return sum;
}

int main()
{
	int i, j, T;
	int a, b, sum, testCase = 1;
	
	// Open input and output files
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("c-out.txt", "w", stdout);
	
	// Initialize the graph
	for (i = 1; i <= 1000; i++)
	{
		for (j = 1; j < i; j++)
		{
			if (isCyclicPermutation(j, i))
				graph[j][i] = 1;
			else
				graph[j][i] = 0;
		}
	}
	
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &a, &b);
		sum = countCyclicPermutations(a, b);
		printf("Case #%d: %d\n", testCase++, sum);
	}
	
	return 0;
}