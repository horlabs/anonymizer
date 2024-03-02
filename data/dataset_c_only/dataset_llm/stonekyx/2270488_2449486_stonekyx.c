#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 110

typedef struct {
    int x;
    int y;
} Point;

Point records[MAX_SIZE * MAX_SIZE];
int recordCount = 0;
int heightMap[MAX_SIZE][MAX_SIZE];
int realHeightMap[MAX_SIZE][MAX_SIZE];
int lockedCells[MAX_SIZE][MAX_SIZE];

int comparePoints(const void* a, const void* b) {
    Point *pointA = (Point*)a;
    Point *pointB = (Point*)b;
    return heightMap[pointB->x][pointB->y] - heightMap[pointA->x][pointA->y];
}

void calculateRealHeightMap(int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            realHeightMap[i][j] = 100;
        }
    }
}

int canBeFlooded(int x, int y, int height) {
    for (int j = 0; j < N; j++) {
        if (realHeightMap[j][y] > height && lockedCells[j][y]) {
            return 0;
        }
    }
    return 1;
}

void floodCells(int x, int y, int height) {
    for (int j = 0; j < N; j++) {
        if (realHeightMap[j][y] > height) {
            realHeightMap[j][y] = height;
        }
    }
}

int main() {
    int T;
    int Tcount = 0;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        
        recordCount = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &heightMap[i][j]);
                records[recordCount].x = i;
                records[recordCount].y = j;
                recordCount++;
            }
        }

        qsort(records, recordCount, sizeof(Point), comparePoints);
        calculateRealHeightMap(N, M);
        
        for (int i = 0; i < recordCount; i++) {
            int currentX = records[i].x;
            int currentY = records[i].y;
            int currentHeight = heightMap[currentX][currentY];

            if (canBeFlooded(currentX, currentY, currentHeight)) {
                floodCells(currentX, currentY, currentHeight);
            } else {
                break;
            }

            lockedCells[currentX][currentY] = 1;
        }

        printf("Case #%d: ", ++Tcount);

        if (i >= recordCount) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    
    return 0;
}