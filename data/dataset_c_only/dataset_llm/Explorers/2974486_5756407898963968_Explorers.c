#include <stdio.h>

typedef struct {
   int a;
   int b;
   int c;
   int d;
} Card;

typedef struct {
   int nans;
   Card n1rval;
   Card n2rval;
} Input;

typedef enum {
   MAGICIAN,
   VOLUNTEER,
   UNKNOWN
} Result;

Result checkCard(Card n1rval, Card n2rval) {
   Result result = UNKNOWN;

   if (n1rval.a == n2rval.a || n1rval.a == n2rval.b || n1rval.a == n2rval.c || n1rval.a == n2rval.d) {
      result = result == UNKNOWN ? MAGICIAN : result;
   }
   if (n1rval.b == n2rval.a || n1rval.b == n2rval.b || n1rval.b == n2rval.c || n1rval.b == n2rval.d) {
      result = result == UNKNOWN ? MAGICIAN : result;
   }
   if (n1rval.c == n2rval.a || n1rval.c == n2rval.b || n1rval.c == n2rval.c || n1rval.c == n2rval.d) {
      result = result == UNKNOWN ? MAGICIAN : result;
   }
   if (n1rval.d == n2rval.a || n1rval.d == n2rval.b || n1rval.d == n2rval.c || n1rval.d == n2rval.d) {
      result = result == UNKNOWN ? MAGICIAN : result;
   }

   return result;
}

int main() {
   int numCases;

   scanf("%d", &numCases);

   for (int i = 0; i < numCases; i++) {
      Input input;

      scanf("%d", &input.nans);

      for (int j = 0; j < 2; j++) {
         Card rval;

         for (int k = 0; k < 4; k++) {
            if (k == input.nans - 1) {
               if (j == 0) {
                  scanf("%d %d %d %d", &input.n1rval.a, &input.n1rval.b, &input.n1rval.c, &input.n1rval.d);
               }
               else {
                  scanf("%d %d %d %d", &input.n2rval.a, &input.n2rval.b, &input.n2rval.c, &input.n2rval.d);
               }
            }
            else {
               scanf("%d %d %d %d", &rval.a, &rval.b, &rval.c, &rval.d);
            }
         }
      }

      Result result = checkCard(input.n1rval, input.n2rval);

      if (result == MAGICIAN) {
         printf("Case #%d: Bad magician!\n", i + 1);
      }
      else if (result == VOLUNTEER) {
         printf("Case #%d: Volunteer cheated!\n", i + 1);
      }
      else {
         printf("Case #%d: %d\n", i + 1, result);
      }
   }

   return 0;
}