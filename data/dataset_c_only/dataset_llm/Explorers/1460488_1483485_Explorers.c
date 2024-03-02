#include <stdio.h>
#include <string.h>

#define MAX_TEST_CASES 30
#define MAX_LENGTH 105

typedef struct {
    char str[MAX_LENGTH];
    char output[MAX_LENGTH];
} TestCase;

void encryptString(TestCase *test);
void printEncryptedStrings(TestCase *test, int ntest);

int main() {
    int ntest;
    scanf("%d ", &ntest);
    
    TestCase testcases[MAX_TEST_CASES];
    for (int i = 0; i < ntest; i++) {
        gets(testcases[i].str);
        encryptString(&testcases[i]);
    }
    
    printEncryptedStrings(testcases, ntest);
    
    return 0;
}

void encryptString(TestCase *test) {
    int mapping[] = {25,8,5,19,15,3,22,24,4,21,9,7,12,2,11,18,26,20,14,23,10,16,6,13,1,17};
    int len = strlen(test->str);
    
    for (int j = 0; j < len; j++) {
        if (test->str[j] == ' ')
            continue;
        test->str[j] = 96 + mapping[test->str[j] - 'a'];
    }
}

void printEncryptedStrings(TestCase *test, int ntest) {
    for (int i = 0; i < ntest; i++) {
        printf("Case #%d: ", i + 1);
        puts(test[i].str);
    }
}
