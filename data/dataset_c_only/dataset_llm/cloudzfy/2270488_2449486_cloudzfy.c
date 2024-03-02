#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int value;
    int marked;
} Cell;

int main() {
    int numCases;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&numCases);

    for(int caseNum=1; caseNum<=numCases; caseNum++) {
        int numRows, numColumns;
        scanf("%d%d", &numRows, &numColumns);

        Cell map[MAX_SIZE][MAX_SIZE];

        for(int i=0; i<numRows; i++) {
            for(int j=0; j<numColumns; j++) {
                scanf("%d", &map[i][j].value);
                map[i][j].marked = 0;
            }
        }

        int flag;
        for(int k=0; k<numRows+numColumns; k++) {
            int min=200, mark[2];
            for(int i=0; i<numRows; i++) {
                for(int j=0; j<numColumns; j++) {
                    if(!map[i][j].marked && map[i][j].value < min) {
                        mark[0] = i;
                        mark[1] = j;
                        min = map[i][j].value;
                    }
                }
            }
            flag = 1;
            for(int i=0; i<numRows; i++) {
                if(!map[i][mark[1]].marked && map[i][mark[1]].value != map[mark[0]][mark[1]].value) {
                    flag = 0;
                    break;
                }
            }
            if(!flag) {
                flag = 2;
                for(int j=0; j<numColumns; j++) {
                    if(!map[mark[0]][j].marked && map[mark[0]][j].value != map[mark[0]][mark[1]].value) {
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag==1) {
                for(int i=0; i<numRows; i++) {
                    map[i][mark[1]].marked = 1;
                }
            }
            else if(flag==2) {
                for(int j=0; j<numColumns; j++) {
                    map[mark[0]][j].marked = 1;
                }
            }
            else break;
        }

        if(flag==0) {
            printf("Case #%d: NO\n",caseNum);
        }
        else {
            printf("Case #%d: YES\n",caseNum);
        }
    }
    return 0;
}