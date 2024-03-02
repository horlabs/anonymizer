#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 4
#define MAX_COLS 4

typedef struct {
   int data[MAX_ROWS][MAX_COLS];
} Matrix;

void checkRows(int c, Matrix *a, Matrix *b) {
   int i, j;
   int count = 0;
   int answer = 0;
   
   for (i = 0; i < MAX_COLS; i++) {
      for (j = 0; j < MAX_COLS; j++) {
         if (a->data[i][j] == b->data[i][j]) {
            count++;
            answer = a->data[i][j];
         }       
      }
   }

   if (count == 1)
      printf("Case #%d: %d\n", c, answer);
   if (count == 0)
      printf("Case #%d: Volunteer cheated!\n", c);
   if (count > 1)
      printf("Case #%d: Bad magician!\n", c);
}

void readMatrix(Matrix *m) {
   int i, j;

   for (i = 0; i < MAX_ROWS; i++) {
      for (j = 0; j < MAX_COLS; j++) {
         scanf("%d", &m->data[i][j]);
      }
   }
}

int main() {
   int t, i;
   Matrix a, b;
   
   scanf("%d", &t); // Number of test cases
   
   for (i = 1; i <= t; i++) {
      int rowA, rowB;

      scanf("%d", &rowA);
      readMatrix(&a);
      
      scanf("%d", &rowB);
      readMatrix(&b);
      
      checkRows(i, &a, &b);
   }
   
   return 0;
}