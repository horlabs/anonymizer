#include <stdio.h>
#include <stdbool.h>

// Function to encode a given message
void encodeMessage() {
    char *mapping = "yhesocvxduiglbkrztnwjpfmaq";  // The mapping of characters
    int testCases;  // Number of test cases
    scanf("%d%*c", &testCases);

    // Loop through each test case
    for (int i = 1; i <= testCases; ++i) {
        char message[101];
        gets(message);
        printf("Case #%d: ", i);

        // Loop through each character in the message
        for (int j = 0; message[j]; ++j) {
            char currentChar = message[j];

            // Check if current character is a space
            if (currentChar == ' ') {
                putchar(' ');
            } else {
                // Map the character to the encoded character
                int index = currentChar - 'a';
                char encodedChar = mapping[index];
                putchar(encodedChar);
            }
        }
        puts("");
    }
}

int main() {
    encodeMessage();
    return 0;
}