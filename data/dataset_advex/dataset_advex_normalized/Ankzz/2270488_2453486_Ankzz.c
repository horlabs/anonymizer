#include <stdio.h>


int main() {
    int T = -1;
    int c = 0;
    char dummy[100];

    FILE *fp = fopen("A-small-attempt0.in", "r");

    FILE *fo = fopen("output.txt", "w");

    fscanf(fp, "%d", &T);

    while (++c <= T) {
        int i = 0, j = 0;
        char map[4][5];
        char prev = 0;
        char empty = 0;

        for (; i < 4; i++) {
            fscanf(fp, "%s", &map[i]);
            prev = (map[i][0] == 'T') ? 0 : map[i][0];
            for (j = 0; j < 4; j++) {
                char x = map[i][j];
                if (prev > 0) {
                    if (prev != x && x != 'T') {
                        prev = -1;
                    }
                } else if (x != 'T' && prev == 0) {
                    prev = x;
                }
                if (x == '.') empty = 1;
            }
            if (prev > 0 && prev != '.') {
                i++;
                break;
            }
        }
        while (i < 4) {
            fscanf(fp, "%s", dummy);

            i++;
        }

        if (prev <= 0 || prev == '.') {
            for (i = 0; i < 4; i++) {
                prev = (map[0][i] == 'T') ? 0 : map[0][i];


                for (j = 1; j < 4; j++) {
                    char x = map[j][i];

                    if (prev > 0) {
                        if (prev != x && x != 'T') {
                            prev = -1;
                        }
                    } else if (x != 'T' && prev == 0) {
                        prev = x;
                    }
                }

                if (prev > 0 && prev != '.') {
                    break;
                }
            }
        }

        if (prev <= 0 || prev == '.') {
            prev = 0;
            for (i = 0; i < 4; i++) {
                char x = map[i][i];

                if (prev > 0) {
                    if (prev != x && x != 'T') {
                        prev = -1;
                    }
                } else if (x != 'T' && prev == 0) {
                    prev = x;
                }
            }
        }

        if (prev <= 0 || prev == '.') {
            prev = 0;
            for (i = 0; i < 4; i++) {
                char x = map[i][3 - i];

                if (prev > 0) {
                    if (prev != x && x != 'T') {
                        prev = -1;
                    }
                } else if (x != 'T' && prev == 0) {
                    prev = x;
                }
            }
        }

        if (prev > 0 && prev != '.') {
            fprintf(fo, "Case #%d: %c won\n", c, prev);
        } else {
            fprintf(fo, "Case #%d: %s\n", c, (empty) ? "Game has not completed" : "Draw");
        }
    }

    return 0;
}
