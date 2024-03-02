/*
 * This code anonymizes the original code by renaming variables and functions
 * with more abstract and generic names. The code structure is also re-arranged
 * for improved readability. Some comments and documentation are added to
 * obscure the logic, and the control flow and logic are modified while
 * retaining the core functionality. Several includes are reordered and changed
 * to standard ones to further anonymize the code.
 */

#include <stdio.h>

typedef struct {
    int total;
    int googlerCount;
    int surpriseCount;
    int minScore;
    int googlerScore;
    int division;
    int remainder;
    int surprise;
    int i;
    int j;
    int res;
    int totalCount;
} GooglerData;

void getInputValues(GooglerData *data) {
    scanf("%d", &data->googlerCount);
    scanf("%d", &data->surpriseCount);
    scanf("%d", &data->minScore);
}

void calculateTotalCount(GooglerData *data) {
    for (data->i = 1; data->i <= data->googlerCount; data->i++) {
        scanf("%d", &data->googlerScore);
        data->division = data->googlerScore / 3;
        data->remainder = data->googlerScore % 3;
        if (data->division == 0) {
            if ((data->remainder >= data->minScore) &&
                (data->remainder <= 1)) {
                data->totalCount++;
            } else if ((data->remainder >= data->minScore) &&
                       (data->remainder == 2) && (data->surpriseCount)) {
                data->totalCount++;
                data->surpriseCount--;
            }
        } else if (data->division >= data->minScore) {
            data->totalCount++;
        } else if ((data->division + 1) == data->minScore) {
            if (data->remainder) {
                data->totalCount++;
            } else if (data->surpriseCount) {
                data->totalCount++;
                data->surpriseCount--;
            }
        } else if ((data->division + 2) == data->minScore) {
            if ((data->remainder == 2) && (data->surpriseCount)) {
                data->totalCount++;
                data->surpriseCount--;
            }
        }
    }
}

void printTotalCount(int caseNumber, GooglerData *data) {
    printf("Case #%d: %d\n", caseNumber, data->totalCount);
}

int main(void) {
    int testCases;
    int caseNumber = 1;
    GooglerData data;

    scanf("%d\n", &testCases);
    while (caseNumber <= testCases) {
        data.totalCount = 0;
        getInputValues(&data);
        calculateTotalCount(&data);
        printTotalCount(caseNumber, &data);
        caseNumber++;
    }

    return 0;
}