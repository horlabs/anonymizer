#include <stdio.h>
#include <stdlib.h>

#define TARGET_SCORE 1
#define BELOW_TARGET_SCORE 0

typedef struct {
   int numPlayers;
   int scores[1000];
   int targetScore;
   int numSupplements;
} Input;

int calculateTotal(Input input);
int checkIfPossible(int score, int targetScore);
int checkIfPossibleWithSupplement(int score, int targetScore);

void readInput(FILE *file, Input *input);
void handleCase(Input *input);
void printResult(int result);

int main () {
   FILE *inputFile = fopen("in.txt", "r");
   FILE *outputFile = fopen("out.txt", "w");
   int numTestCases;
   fscanf(inputFile, "%d ", &numTestCases);
   for (int i = 0; i < numTestCases; i++) {
      Input input;
      readInput(inputFile, &input);
      handleCase(&input);
      printResult(calculateTotal(input));
   }
   fclose(inputFile);
   fclose(outputFile);
   return 0;
}

void readInput(FILE *file, Input *input) {
   fscanf(file, "%d %d %d ", &input->numPlayers, &input->numSupplements, &input->targetScore);
   for (int i = 0; i < input->numPlayers; i++) {
      fscanf(file, "%d ", &input->scores[i]);
   }
}

void handleCase(Input *input) {
   // Process the input data
}

int calculateTotal(Input input) {
   int total = 0;
   for (int i = 0; i < input.numPlayers; i++) {
      if (checkIfPossible(input.scores[i], input.targetScore)) {
         total++;
      } else {
         if (input.numSupplements > 0 && checkIfPossibleWithSupplement(input.scores[i], input.targetScore)) {
            total++;
            input.numSupplements--;
         }
      }
   }
   return total;
}

int checkIfPossible(int score, int targetScore) {
   int remainder = score % 3;
   int bestScore = score / 3;
   if (remainder > 0) {
      bestScore++;
   }
   return bestScore >= targetScore;
}

int checkIfPossibleWithSupplement(int score, int targetScore) {
   int remainder = score % 3;
   int bestScore = score / 3;
   if (remainder == 2) {
      bestScore += 2;
   } else {
      if (remainder == 1 || score > 0) {
         bestScore++;
      }
   }
   return bestScore >= targetScore;
}

void printResult(int result) {
   printf("%d\n", result);
}