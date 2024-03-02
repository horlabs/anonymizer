#include <stdio.h>
#include <string.h>

typedef struct {
    int count;
    char best[];
    char surprise[];
} ScoreChart;

ScoreChart createScoreChart() {
    ScoreChart chart;
    chart.count = 31;
    strcpy(chart.best, "011122233344455566677788899910101010");
    strcpy(chart.surprise, "0122333444555666677788899910101010");
    return chart;
}

void printResult(int caseNum, int count) {
    printf("Case #%d: %d\n", caseNum, count);
}

int main(int argc, char **argv)
{
    int t, i, j, n, s, p, count, score;    
    ScoreChart chart = createScoreChart();
    
    printf("Enter the number of test cases: ");
    scanf("%d", &t);
    
    for(i = 1; i <= t; i++) 
    {
        printf("Enter the number of googlers, minimum surprising score and P: ");
        scanf("%d %d %d", &n, &s, &p);
        
        int googlers[n];
        
        printf("Enter the scores of the googlers: ");
        for(j = 0; j < n; j++)
            scanf("%d", &googlers[j]);
        
        count = 0;
        
        for(j = 0; j < n; j++)
        {
            score = googlers[j];
            
            if(chart.best[score] >= p) 
                count++;
            else if(chart.surprise[score] >= p && s > 0)
            {
                count++;
                s--;
            }
        }
        
        printResult(i, count);
    }
    
    return 0;
}