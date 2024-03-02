#include <stdio.h>
#include <string.h>

int isRecyclablePair(int num1, int num2) {
  char str1[10], str2[10];
  int i, len, j;
  sprintf(str1, "%d", num1);
  sprintf(str2, "%d", num2);
  
  if(strlen(str1) != strlen(str2))
    return 0;
  
  len = strlen(str1);
  
  for(i = 1; str1[i]; i++) {
    for(j = 0; str1[j]; j++)
      if(str1[j] != str2[(i + j) % len])
        goto next;
    return 1;
    next:;
  }
  return 0;
}

int main() {
  int numTestCases, caseNum = 1, num1, num2, i, j, answer;
  scanf("%d", &numTestCases);
  
  while(numTestCases--) {
    scanf("%d %d", &num1, &num2);
    for(answer = 0, i = num1; i <= num2; i++)
      for(j = i + 1; j <= num2; j++)
        if(isRecyclablePair(i, j))
          answer++;
    printf("Case #%d: %d\n", caseNum++, answer);
  }
  return 0;
}