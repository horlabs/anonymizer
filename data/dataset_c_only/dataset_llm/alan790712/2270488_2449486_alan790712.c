#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int row;
    int column;
    int value;
} Cell;

typedef struct {
    int rows;
    int columns;
    Cell cells[123][123];
} Map;

int checkMap(Map* map) {
    for (int i = 0; i < map->rows; ++i) {
        for (int j = 0; j < map->columns; ++j) {
            int currentHeight = map->cells[i][j].value;
            
            int isPeak = 1;
            for (int p = 0; p < map->columns; ++p) {
                if (map->cells[i][p].value > currentHeight) {
                    isPeak = 0;
                    break;
                }
            }
            if (isPeak) {
                continue;
            }
            
            int isBasin = 0;
            for (int p = 0; p < map->rows; ++p) {
                if (map->cells[p][j].value <= currentHeight) {
                    isBasin = 1;
                    break;
                }
            }
            if (!isBasin) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int numberOfTests;
    scanf("%d", &numberOfTests);

    for (int t = 1; t <= numberOfTests; ++t) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        Map map;
        map.rows = n;
        map.columns = m;

        memset(map.cells, 0, sizeof(map.cells));

        int maxHeight = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &map.cells[i][j].value);
                if (map.cells[i][j].value >= maxHeight) {
                    maxHeight = map.cells[i][j].value;
                }
            }
        }

        int isPeakDetected = 0;
        for (int i = 0; i < n && !isPeakDetected; ++i) {
            for (int j = 0; j < m && !isPeakDetected; ++j) {
                int currentHeight = map.cells[i][j].value;

                int isPeak = 1;
                for (int p = 0; p < m; ++p) {
                    if (map.cells[i][p].value > currentHeight) {
                        isPeak = 0;
                        break;
                    }
                }
                if (isPeak) {
                    continue;
                }

                int isBasin = 0;
                for (int p = 0; p < n; ++p) {
                    if (map.cells[p][j].value <= currentHeight) {
                        isBasin = 1;
                        break;
                    }
                }
                if (!isBasin) {
                    isPeakDetected = 1;
                }
            }
        }
        
        printf("Case #%d: ", t);
        if (!isPeakDetected) {
            puts("YES");
        }
        else {
            puts("NO");
        }
    }
    
    return 0;
}