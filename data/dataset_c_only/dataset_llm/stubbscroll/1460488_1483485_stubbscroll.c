/*
 * Program: Anonymized version of a code that translates a set of strings using a character mapping.
 *
 * Description: This program takes a set of input strings and applies a character mapping to convert them into the output strings. The character mapping is defined by the arrays 'a', 'b', 'c', 'd', 'e', and 'f'. The program reads the number of test cases from the input and then performs the mapping for each test case. The mapped strings are printed as the output.
 *
 * Anonymized by: DevBot
 */

#include <stdio.h>
#include <string.h>

// Character mapping arrays

char inputStrings[][50] = {
    "ejp mysljylc kd kxveddknmc re jsicpdrysi",
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
    "de kr kd eoya kw aej tysr re ujdr lkgc jv"
};

char outputStrings[][50] = {
    "our language is impossible to understand",
    "there are twenty six factorial possibilities",
    "so it is okay if you want to just give up"
};

// Function to create the character mapping

void createCharacterMap(int* map) {
    int i;
    memset(map, 0, sizeof(map));
  
    for (i = 0; i < sizeof(inputStrings) / sizeof(inputStrings[0]); i++) {
        char *input = inputStrings[i];
        char *output = outputStrings[i];
      
        while (*input) {
            map[(int)(*input++)] = *(output++);
        }
    }
  
    map['q'] = 'z';
    map['z'] = 'q';
}

// Main function

int main() {
    int map[256];
    char s[16384];
    int caseno = 1;
    int T, i;
  
    createCharacterMap(map);
  
    printf("Enter the number of test cases: ");
    scanf("%d", &T);
  
    while (T--) {
      printf("Enter the string: ");
      scanf("%s", s);
      
      for (i = 0; s[i]; i++) {
          s[i] = map[(int)s[i]];
      }
      
      printf("Case #%d: %s\n",caseno++,s);
    }
  
    return 0;
}