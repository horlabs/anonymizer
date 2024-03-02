#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char t[4][4];
} GameBoard;

void ReadInputFile(char filename[], GameBoard* board);
void WriteOutputFile(char filename[], int caseNum, char result[]);

int main() {
    FILE* fp_in, *fp_out;
    int T;
    char result[20];
    GameBoard board;
    fp_in = fopen("A-small-attempt1(1).in", "r");
    fp_out = fopen("output.txt", "w");
    fscanf(fp_in, "%d", &T);

    for (int caseNum = 1; caseNum <= T; caseNum++) {
        ReadInputFile("A-small-attempt1(1).in", &board);
        int flag = 0;
        int flagd_x = 4;
        int flagd_o = 4;
        for (int i = 0; i < 4; i++) {
            int flag_x = 4;
            int flag_o = 4;
            for (int j = 0; j < 4; j++) {
                if (board.t[i][j] == 'X' || board.t[i][j] == 'T') {
                    flag_x--;
                }
                if (board.t[i][j] == 'O' || board.t[i][j] == 'T') {
                    flag_o--;
                }
                if (i == j) {
                    if (board.t[i][j] == 'X' || board.t[i][j] == 'T') {
                        flagd_x--;
                    }
                    else if (board.t[i][j] == 'O' || board.t[i][j] == 'T') {
                        flagd_o--;
                    }
                }
            }
            if (flag_x == 0) {
                sprintf(result, "Case #%d: X won", caseNum);
                WriteOutputFile("output.txt", caseNum, result);
                break;
            }
            else if (flag_o == 0) {
                sprintf(result, "Case #%d: O won", caseNum);
                WriteOutputFile("output.txt", caseNum, result);
                break;
            }
        }
        if (flagd_x == 0) {
            sprintf(result, "Case #%d: X won", caseNum);
            WriteOutputFile("output.txt", caseNum, result);
            continue;
        }
        else if (flagd_o == 0) {
            sprintf(result, "Case #%d: O won", caseNum);
            WriteOutputFile("output.txt", caseNum, result);
            continue;
        }
        else if (flag_x == 0 || flag_o == 0) {
            continue;
        }
        flagd_x = 4;
        flagd_o = 4;
        for (int j = 0; j < 4; j++) {
            int flag_x = 4;
            int flag_o = 4;
            for (int i = 0; i < 4; i++) {
                if (board.t[i][j] == 'X' || board.t[i][j] == 'T') {
                    flag_x--;
                }
                if (board.t[i][j] == 'O' || board.t[i][j] == 'T') {
                    flag_o--;
                }
                if (board.t[i][j] == '.') {
                    flag = 1;
                }
                if ((i + j) == 3) {
                    if (board.t[i][j] == 'X' || board.t[i][j] == 'T') {
                        flagd_x--;
                    }
                    if (board.t[i][j] == 'O' || board.t[i][j] == 'T') {
                        flagd_o--;
                    }
                }
            }
            if (flag_x == 0) {
                sprintf(result, "Case #%d: X won", caseNum);
                WriteOutputFile("output.txt", caseNum, result);
                break;
            }
            else if (flag_o == 0) {
                sprintf(result, "Case #%d: O won", caseNum);
                WriteOutputFile("output.txt", caseNum, result);
                break;
            }
        }
        if (flagd_x == 0) {
            sprintf(result, "Case #%d: X won", caseNum);
            WriteOutputFile("output.txt", caseNum, result);
            continue;
        }
        else if (flagd_o == 0) {
            sprintf(result, "Case #%d: O won", caseNum);
            WriteOutputFile("output.txt", caseNum, result);
            continue;
        }
        else if (flag_x == 0 || flag_o == 0) {
            continue;
        }
        if (flag == 1) {
            sprintf(result, "Case #%d: Game has not completed", caseNum);
            WriteOutputFile("output.txt", caseNum, result);
        }
        else {
            sprintf(result, "Case #%d: Draw", caseNum);
            WriteOutputFile("output.txt", caseNum, result);
        }
    }
    fclose(fp_in);
    fclose(fp_out);
    system("pause");
}

void ReadInputFile(char filename[], GameBoard* board) {
    FILE* fp = fopen(filename, "r");
    for (int i = 0; i < 4; i++) {
        fscanf(fp, "%s", board->t[i]);
    }
    fclose(fp);
}

void WriteOutputFile(char filename[], int caseNum, char result[]) {
    FILE* fp = fopen(filename, "a");
    fprintf(fp, "%s\n", result);
    fclose(fp);
}