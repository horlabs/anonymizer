#include <stdio.h>

int main(void) {
  int cases, googlers, surprice, min, glog;

  int cos, res, total;
  scanf("%d\n", &cases);
  for (int i = 1; i <= cases; i++) {
    total = 0;
    scanf("%d", &googlers);
    scanf("%d", &surprice);
    scanf("%d", &min);
    for (int j = 1; j <= googlers; j++) {
      scanf("%d", &glog);
      cos = glog / 3;
      res = glog % 3;
      if (cos == 0) {
        if ((res >= min) && (res <= 1))
          total++;
        else if ((res >= min) && (res == 2) && (surprice)) {
          total++;
          surprice--;
        }
      } else if (cos >= min) {
        total++;
      } else if ((cos + 1) == min) {
        if (res) {
          total++;
        } else if (surprice) {
          total++;
          surprice--;
        }
      } else if ((cos + 2) == min) {
        if ((res == 2) && (surprice)) {
          total++;
          surprice--;
        }
      }
    }
    printf("Case #%d: %d\n", i, total);
  }
}
