#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int matrix[MAX_ROWS][MAX_COLS];
int num_rows, num_cols;

int isMatrixValid()
{
  for (int i = 0; i < num_rows; i++)
  {
    for (int j = 0; j < num_cols; j++)
    {
      
      int isRowValid = 1;
      for (int k = 0; isRowValid && k < num_rows; k++)
      {
        if (matrix[k][j] > matrix[i][j])
        {
          isRowValid = 0;
        }
      }
      
      if (isRowValid)
      {
        continue;
      }
      
      int isColValid = 1;
      for (int k = 0; isColValid && k < num_cols; k++)
      {
        if (matrix[i][k] > matrix[i][j])
        {
          isColValid = 0;
        }
      }
      
      if (isColValid)
      {
        continue;
      }
      
      return 0;
    }
  }
  
  return 1;
}

int main()
{
  int numTestCases;
  scanf("%d", &numTestCases);
  
  for (int t = 1; t <= numTestCases; t++)
  {
    scanf("%d %d", &num_rows, &num_cols);
    
    for (int i = 0; i < num_rows; i++)
    {
      for (int j = 0; j < num_cols; j++)
      {
        scanf("%d", &matrix[i][j]);
      }
    }
    
    printf("Case #%d: %s\n", t, isMatrixValid() ? "YES" : "NO");
  }
  
  return 0;
}