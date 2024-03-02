#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

struct MagicSquare {
    int nums[17];
};

struct Guess {
    int nums[4];
};

void readMagicSquare(struct MagicSquare *square) {
    int i;
    for (i = 1 ; i <= 4 ; ++i){
        scanf("%*d%*d%*d%*d"); // Skip numbers
        scanf("%d", &square->nums[i]);
    }
}

void readGuess(struct Guess *guess) {
    int i;
    for (i = 0 ; i < 4 ; ++i){
        scanf("%d", &guess->nums[i]);
    }
}

bool hasDuplicate(struct MagicSquare square, struct Guess guess) {
    int i, cnt = 0, ans;
    for (i = 0 ; i < 4 ; ++i){
        int num = guess.nums[i];
        if (square.nums[num]) {
            ++cnt;
            ans = num;
        }
    }
    if (cnt == 0) {
        printf("Volunteer cheated!\n");
    }
    else if (cnt == 1) {
        printf("%d\n", ans);
    }
    else {
        printf("Bad magician!\n");
    }
}

int main() {
    int t, u;
    scanf("%d", &t);
    for (u = 1 ; u <= t ; ++u){
        int n;
        struct MagicSquare square;
        scanf("%d", &n);
        readMagicSquare(&square);
        scanf("%d", &n);
        struct Guess guess;
        readGuess(&guess);
        printf("Case #%d: ", u);
        hasDuplicate(square, guess);
    }
    return 0;
}