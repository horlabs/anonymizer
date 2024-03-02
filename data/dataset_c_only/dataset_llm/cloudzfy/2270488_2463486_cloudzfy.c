#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 10000001

int palindromeArray[MAX];

void initialize()
{
    int num[20], j, flag;
    long long tmp;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    memset(palindromeArray, 0, sizeof(palindromeArray));
    
    for (int i=0; i<MAX; i++)
    {
        tmp = i*i;
        j = 0;
        
        while (tmp != 0)
        {
            num[j] = tmp % 10;
            tmp = tmp / 10;
            j++;
        }
        
        flag = 1;
        
        for(int k=0; k<j; k++)
        {
            if(num[k] != num[j-k-1])
            {
                flag = 0;
                break;
            }
        }
        
        tmp = i;
        j = 0;
        
        while (tmp != 0)
        {
            num[j] = tmp % 10;
            tmp = tmp / 10;
            j++;
        }
        
        for(int k=0; k<j; k++)
        {
            if(num[k] != num[j-k-1])
            {
                flag = 0;
                break;
            }
        }
        
        if(flag)
        {
            palindromeArray[i] = 1;
        }
    }
    
    for(int i=1; i<MAX; i++)
    {
        palindromeArray[i] = palindromeArray[i-1] + palindromeArray[i];
    }
}

int main()
{
    long long num1, num2;
    int T;
    
    initialize();
    
    scanf("%d", &T);
    
    for(int t=1; t<=T; t++)
    {
        scanf("%lld%lld", &num1, &num2);
        
        int a = (int)sqrt(num1);
        int b = (int)sqrt(num2);
        
        if(a*a == num1) 
        {
            a--;
        }
        
        printf("Case #%d: %d\n", t, palindromeArray[b]-palindromeArray[a]);
    }
    
    return 0;
}