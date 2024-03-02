#include <stdio.h>

#define MAX_SIZE 4

typedef struct {
    int nums[MAX_SIZE];
} Magic;

void readMagicSquare(Magic *ms, int size) {
    int temp;
    for (int i = 0; i < (size - 1) * MAX_SIZE; i++)
        scanf("%d", &temp);

    for (int i = 0; i < size; i++)
        scanf("%d", &ms->nums[i]);

    for (int i = size * MAX_SIZE; i < 16; i++)
        scanf("%d", &temp);
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int magicSquareSize;
        scanf("%d", &magicSquareSize);

        Magic magician1;
        readMagicSquare(&magician1, magicSquareSize);

        int l = -1;

        for (int j = 0; j < magicSquareSize * MAX_SIZE; j++) {
            int temp;
            scanf("%d", &temp);

            for (int k = 0; k < MAX_SIZE; k++) {
                if (temp == magician1.nums[k]) {
                    if (l == -1)
                        l = magician1.nums[k];
                    else
                        l = 0;
                }
            }
        }

        for (int j = magicSquareSize * MAX_SIZE; j < 16; j++) {
            int temp;
            scanf("%d", &temp);
        }

        printf("Case #%d: ", i + 1);

        switch (l) {
            case -1:
                puts("Volunteer cheated!");
                break;
            case 0:
                puts("Bad magician!");
                break;
            default:
                printf("%d\n", l);
        }
    }

    return 0;
}