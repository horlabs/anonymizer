# include <stdio.h>


int scores[110] ;

int calculateScore(int num, int threshold) {
    if (num >= 3*threshold-2) {
        return 1;
    } else if (threshold > 1 && num >= 3*threshold-4) {
        return 2;
    }
    return 0;
}

int main () {
    int T, i, nCase = 1 ;
    int num1, num2 ;
    int n, s, p ;
    freopen ("B-small-attempt0.in", "r", stdin) ;
    freopen ("bout.txt", "w", stdout) ;
    scanf ("%d", &T) ;
    while (T--) {
        scanf ("%d%d%d", &n, &s, &p) ;
        num1 = 0, num2 = 0 ;
        for (i = 0 ; i < n ; i++) {
            scanf ("%d", &scores[i]) ;
            num1 += calculateScore(scores[i], p);
            if (scores[i] >= 3*p-2) {
                num1++;
            } else if (p>1 && scores[i] >= 3*p-4) {
                num2++;
            }
        }
        if (num2 > s) {
            num2 = s;
        }
        printf ("Case #%d: %d\n", nCase++, num1+num2) ;
    }
    return 0 ;
}