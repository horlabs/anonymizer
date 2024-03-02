#include <stdio.h>
#include <string.h>

#define MAX_CARDS 16

void readInput(int *array, int size) {
    for(int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}

int countDuplicates(int *array, int size) {
    int count = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(j != i && array[i] == array[j]) {
                count++;
                break;
            }
        }
    }
    return count;
}

int findUniqueCard(int *array, int size) {
    for(int i = 0; i < size; i++) {
        int count = 0;
        for(int j = 0; j < size; j++) {
            if(array[j] == i + 1) {
                count++;
            }
        }
        if(count == 2) {
            return i + 1;
        }
    }
    return -1;
}

int main() {
    freopen("A-small-attempt0.in.txt", "r", stdin);
    freopen("A-small-attempt0.out.txt", "w", stdout);

    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++) {
        int data[MAX_CARDS];
        memset(data, 0, sizeof(data));

        int A1, A2;
        scanf("%d", &A1);
        readInput(&data[A1 - 1], 4);

        scanf("%d", &A2);
        readInput(&data[A2 + 3], 4);

        int duplicateCount = countDuplicates(data, MAX_CARDS);

        printf("Case #%d: ", t);
        if(duplicateCount == 0) {
            printf("Volunteer cheated!\n");
        } else if(duplicateCount == 1) {
            int uniqueCard = findUniqueCard(data, MAX_CARDS);
            printf("%d\n", uniqueCard);
        } else {
            printf("Bad magician!\n");
        }
    }

    return 0;
}