#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int rows;
	int columns;
	int matrix[100][100];
} Matrix;

void readMatrix(Matrix* matrix) {
	scanf("%d%d", &matrix->rows, &matrix->columns);

	for (int i = 0; i < matrix->rows; i++) {
		for (int j = 0; j < matrix->columns; j++) {
			scanf("%d", &matrix->matrix[i][j]);
		}
	}
}

int checkRowColumnRelation(Matrix* matrix, int row, int column) {
	for (int i = 0; i < matrix->rows; i++) {
		if (matrix->matrix[row][column] < matrix->matrix[i][column]) {
			for (int j = 0; j < matrix->columns; j++) {
				if (matrix->matrix[row][column] < matrix->matrix[row][j]) {
					return 1;
				}
			}
			break;
		}
	}

	return 0;
}

void testMatrix(int testCase) {
	Matrix matrix;
	int failed = 1;

	readMatrix(&matrix);

	for (int i = 0; i < matrix.rows; i++) {
		for (int j = 0; j < matrix.columns; j++) {
			if (checkRowColumnRelation(&matrix, i, j)) {
				failed = 0;
				break;
			}
		}
		
		if (!failed) {
			break;
		}
	}

	printf("Case #%d: %s\n", testCase + 1, failed ? "NO" : "YES");
}

int main() {
	int testCases;

	scanf("%d", &testCases);

	for (int i = 0; i < testCases; i++) {
		testMatrix(i);
	}

	return 0;
}