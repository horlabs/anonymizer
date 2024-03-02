#include "superheader.h"
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T, t;
  scanf("%d\n", &T);
  for (t = 1; t <= T; t++) {
    int A, B;
    scanf("%d %d\n", &A, &B);
    int ret = 0;

    int i;
    for (i = A; i <= B; i++) {

      char i_str_org[100], i_str[100];
      int i_str_len;

      sprintf(i_str_org, "%d", i);
      i_str_len = strlen(i_str_org);
      strcpy(i_str, i_str_org);
      while (1) {

        char c0 = i_str[i_str_len - 1];
        memmove(&i_str[1], &i_str[0], sizeof(char) * (i_str_len - 1));
        i_str[0] = c0;

        if (strcmp(i_str, i_str_org) == 0)
          break;

        if (i_str[0] == '0')
          continue;

        int i2 = atoi(i_str);

        if (A <= i2 && i2 <= B) {

          ret++;
        }
      }
    }
    (ret % 2 == 0);
    printf("Case #%d: %d\n", t, ret / 2);
  }
  return 0;
}
