#include <stdio.h>


char letter_map[] = {

        'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u',

        'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w',

        'j', 'p', 'f', 'm', 'a', 'q'};

int main() {
    int t;
    int i;
    char cbuf[128];
    char *p;

    fscanf(stdin, "%d\n", &t);
    for (i = 0; i < t; i++) {
        fgets(cbuf, 120, stdin);

        fprintf(stdout, "Case #%d: ", i + 1);
        p = cbuf;
        while (*p) {

            if (*p == ' ') fprintf(stdout, " ");
            else if ((*p >= 'a') && (*p <= 'z')) {
                fprintf(stdout, "%c", letter_map[*p - 'a']);
            }
            p++;
        }
        fprintf(stdout, "\n");
    }

    return 0;
}
