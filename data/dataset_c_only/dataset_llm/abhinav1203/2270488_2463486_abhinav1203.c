#include <stdio.h>
#include <math.h>

int fairNumbers[10000005];
int digits[100];

int isPalindrome(long long int number) {
  int i = 0, j;
  
  while(number > 0) {
    digits[i++] = number % 10;
    number /= 10;
  }
  
  i--;
  j = 0;

  while(i > j && digits[i] == digits[j]) {
    i--;
    j++;
  }
  
  if(i <= j) 
    return 1;
  
  return 0;
}

void calculateFairNumbersCount(int t) {
  int count = 0;
  fairNumbers[0] = 0;
  
  for(long long int i = 1; i <= 1e7; i++) {
    if(isPalindrome(i) && isPalindrome(i * i))
      count++;

    fairNumbers[i] = count;
  }
}

void printFairNumbersCounts(int t) {
  long long int a, b;
  
  for(int i = 1; i <= t; i++) {
    scanf("%lld %lld", &a, &b);
    printf("Case #%d: %d\n", i, fairNumbers[(int)floor(sqrt(b))] - fairNumbers[(int)floor(sqrt(a - 1))]);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  
  calculateFairNumbersCount(t);
  printFairNumbersCounts(t);
  
  return 0;
}