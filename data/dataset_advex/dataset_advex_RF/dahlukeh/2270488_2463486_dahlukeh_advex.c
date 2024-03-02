#include <stdio.h>

void do_voiuue_fct();

long long a, b;

char numSmall[200];

long long findNum(long long start);

int numDigits(long long num);
long long getPal(long long base, int digits);
void writeNumber(long long num, char *buf);
long long readNumber(char *buf);

int isPal(long long num);

int main() {
  int ret_val = 0;

  int n;
  scanf("%d ", &n);
  int i;
  {
    i = 0;
    while (i < n) {
      printf("Case #%d: ", i + 1);
      do_voiuue_fct();
      i++;
    }
  }
  return ret_val;
}

void do_voiuue_fct() {
  scanf("%I64d %I64d ", &a, &b);
  long long result = findNum(b) - findNum(a - 1);
  printf("%I64d\n", result);
}

long long findNum(long long start) {
  long long cur;
  long long bpvl_Var = 0ll;
  int i;
  {
    i = 1;
    while (1) {
      cur = 1ll;
      for (int gnri_Var = 0; gnri_Var < ((i - 1) / 2); gnri_Var++)
        cur *= 10ll;

      long long end = cur * 10ll;
      for (; cur < end; cur++) {
        long long pal = getPal(cur, i);
        if (pal * pal > start)
          return bpvl_Var;

        if (isPal(pal * pal)) {
          bpvl_Var++;
        }
      }
      i++;
    }
  }
  return bpvl_Var;
}

long long getPal(long long base, int digits) {
  writeNumber(base, numSmall);

  for (int i = digits - 1; i >= 0; i--)
    numSmall[i] = numSmall[digits - i - 1];

  numSmall[digits] = '\0';
  return readNumber(numSmall);
}

int isPal(long long num) {
  int ret_val = 1;
  writeNumber(num, numSmall);
  int dig = numDigits(num);
  int i;
  for (i = 0; i < dig; i++) {
    if (numSmall[i] != numSmall[dig - i - 1]) {
      int ret_val = 0;
      return ret_val;
    }
  }
  return ret_val;
}

int numDigits(long long num) {
  int i = 1;
  long long cur = 10ll;
  for (; cur <= num; i++)
    cur *= 10ll;

  return i;
}

void writeNumber(long long num, char *buf) {
  int numDig = numDigits(num);
  int i;
  buf[numDig] = '\0';
  {
    i = 0;
    while (i < numDig) {
      char dig = (num % 10ll) + '0';
      buf[numDig - i - 1] = dig;
      num /= 10ll;
      i++;
    }
  }
}

long long readNumber(char *buf) {
  long long num = 0ll;
  int i;
  for (i = 0; buf[i] != '\0'; i++) {
    num *= 10ll;
    num += (buf[i] - '0');
  }
  return num;
}
