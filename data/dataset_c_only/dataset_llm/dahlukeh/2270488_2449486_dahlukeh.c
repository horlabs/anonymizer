#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

typedef struct {
   int rows;
   int columns;
   int numbers[100][100];
} Grid;

int doesWork(Grid g, int y, int x);
void handleCase();

int main() {
   freopen("bin.txt", "r", stdin);
   freopen("bout.txt", "w", stdout);
   int numCases;
   scanf("%d ", &numCases);
   for (int i = 0; i < numCases; i++) {
      printf("Case #%d: ", i + 1);
      handleCase();
   }
   return 0;
}

void handleCase() {
   int rows, columns;
   scanf("%d %d ", &rows, &columns);
   Grid g;
   g.rows = rows;
   g.columns = columns;
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
         scanf("%d ", &g.numbers[i][j]);
      }
   }
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
         if (!doesWork(g, i, j)) {
            printf("NO\n");
            return;
         }
      }
   }
   printf("YES\n");
}

int doesWork(Grid g, int y, int x) {
   int num = g.numbers[y][x];
   for (int i = 0; i < g.rows; i++) {
      if (g.numbers[i][x] > num) {
         return FALSE;
      }
   }
   for (int i = 0; i < g.columns; i++) {
      if (g.numbers[y][i] > num) {
         return FALSE;
      }
   }
   return TRUE;
}