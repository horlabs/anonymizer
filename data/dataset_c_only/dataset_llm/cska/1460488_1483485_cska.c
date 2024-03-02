#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define BUFFER_SIZE 128

void encryptAndWrite(FILE *fout, const char *abc, const char *buffer) {
    for (int j = 0; buffer[j] != 0; j++) {
        if (islower(buffer[j])) {
            fputc(abc[buffer[j] - 'a'], fout);
        } else {
            fputc(buffer[j], fout);
        }
    }
}

int main(void) {
    char buffer[BUFFER_SIZE];
    char abc[] = "yhesocvxduiglbkrztnwjpfmaq";
    int T;
    FILE *fin = fopen("A-small-attempt0.in", "r");
    FILE *fout = fopen("out.txt", "w");

    fscanf(fin, "%d\n", &T);
    for (int i = 0; i < T; i++) {
        fgets(buffer, BUFFER_SIZE, fin);
        fprintf(fout, "Case #%d: ", i + 1);
        encryptAndWrite(fout, abc, buffer);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}