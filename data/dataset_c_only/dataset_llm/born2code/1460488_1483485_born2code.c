// Anonymized version of the given C code

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to hash characters
char characterHash(char x) {
	switch(x) {
		case 'a': return 'y';
		case 'b': return 'h';
		case 'c': return 'e';
		case 'd': return 's';
		case 'e': return 'o';
		case 'f': return 'c';
		case 'g': return 'v';
		case 'h': return 'x';
		case 'i': return 'd';
		case 'j': return 'u';
		case 'k': return 'i';
		case 'l': return 'g';
		case 'm': return 'l';
		case 'n': return 'b';
		case 'o': return 'k';
		case 'p': return 'r';
		case 'q': return 'z';
		case 'r': return 't';
		case 's': return 'n';
		case 't': return 'w';
		case 'u': return 'j';
		case 'v': return 'p';
		case 'w': return 'f';
		case 'x': return 'm';
		case 'y': return 'a';
		case 'z': return 'q';
		default: return ' ';
	}
}

// Function to anonymize the given string
void anonymizeString(char* input, char* output) {
	int j = 0;
	for(int i = 0; input[i] != '\0'; i++) {
		output[i] = characterHash(input[i]);
		j++;
	}
	output[j] = '\0';
}

int main() {
	int numCases;
	scanf("%d",&numCases);
	scanf("%*c");
	
	char originalString[200];
	char anonymizedString[200];
	
	for(int i = 1; i <= numCases; i++) {
		gets(originalString);
		
		anonymizeString(originalString, anonymizedString);
		
		printf("Case #%d: %s\n", i, anonymizedString);
	}
	return 0;
}