//
// anonymized_code.c
//

#include <stdio.h>

// Map of characters
char char_map[] = {
    'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u',
    'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w',
    'j', 'p', 'f', 'm', 'a', 'q'
};

// Function to convert characters based on the map
void convertCharacters(char* input) {
    char* p = input;
    while (*p) {
        if (*p == ' ') {
            printf(" ");
        } else if ((*p >= 'a') && (*p <= 'z')) {
            printf("%c", char_map[*p - 'a']);
        }
        p++;
    }
}

// Main program
int main() {
    int num_cases;
    int i;
    char input_buffer[128];

    scanf("%d\n", &num_cases);

    for (i = 0; i < num_cases; i++) {
        fgets(input_buffer, 120, stdin);
        printf("Case #%d: ", i + 1);
        convertCharacters(input_buffer);
        printf("\n");
    }

    return 0;
}

// End of anonymized_code.c