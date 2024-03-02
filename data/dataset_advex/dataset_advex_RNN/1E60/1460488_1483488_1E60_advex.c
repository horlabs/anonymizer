#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {

  int duai_Var, ojmi_Var;
  scanf("%d\n", &duai_Var);
  {
    ojmi_Var = 1;
    while (ojmi_Var <= duai_Var) {
      int A, B;
      scanf("%d %d\n", &A, &B);
      int ret = 0;

      int ndli_Var;
      {
        ndli_Var = A;
        while (ndli_Var <= B) {

          char i_str_org[100], i_str[100];
          int i_str_len;

          sprintf(i_str_org, "%d", ndli_Var);
          i_str_len = strlen(i_str_org);
          strcpy(i_str, i_str_org);
          while (1) {

            char c0 = i_str[i_str_len - 1];
            memmove(&i_str[1], &i_str[0], sizeof(char) * (i_str_len - 1));
            i_str[0] = c0;

            if (strcmp(i_str, i_str_org) == 0) {
              break;
            }

            if (i_str[0] == '0')
              continue;

            int i2 = atoi(i_str);

            if (A <= i2) {
              if (i2 <= B) {

                ret++;
              }
            }
          }
          ndli_Var++;
        }
      }
      assert(ret % 2 == 0);
      printf("Case #%d: %d\n", ojmi_Var, ret / 2);
      ojmi_Var++;
    }
  }
  return 0;
}
