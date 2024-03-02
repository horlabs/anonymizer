#include <stdio.h>
#include <string.h>

int main(void) {

  char str[100 * 5];
  int conv_table[26] = {
      24, 7,  4,  18, 14, 2,  21, 23, 3,  20, 8,  6, 11,
      1,  10, 17, 25, 19, 13, 22, 9,  15, 5,  12, 0, 16,
  };
  int N;
  int n;
  scanf("%d\n", &N);
  for (n = 1; n <= N; n++) {
    memset(str, 0, sizeof(str));
    scanf("%[a-z ]\n", str);
    int i = 0;
    while (str[i] != '\0') {
      if (str[i] != ' ') {
        str[i] = 'a' + conv_table[str[i] - 'a'];
      }
      i++;
    }
    printf("Case #%d: %s\n", n, str);
  }
  return 0;
}
