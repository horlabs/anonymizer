#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int isPalindrome(int number);

int main()
{
    FILE *inputFile, *outputFile;
    int caseCount, testCase, start, end, palindromeCount;

    inputFile = fopen("input.txt","r");
    outputFile = fopen("output.txt","w");

    fscanf(inputFile,"%d",&caseCount);

    for(testCase=1; testCase<=caseCount; testCase++)
    {
        fscanf(inputFile,"%d %d",&start,&end);
        palindromeCount = 0;           

        for(int number=start; number<=end; number++)
        {
            if(isPalindrome(number))
            {
              int sqrtNumber = (int)sqrt((double)number);
                    
               if(sqrtNumber * sqrtNumber == number)   
               {         
                   if(isPalindrome(sqrtNumber))
                   {
                       palindromeCount++;
                   }
               }
               else if ((sqrtNumber+1)*(sqrtNumber+1)==number)
               {
                   if(isPalindrome(sqrtNumber))
                   {
                       palindromeCount++;
                   }
               }
            }
        }
        
        fprintf(outputFile, "Case #%d: %d\n", testCase, palindromeCount); 
    }

    fclose(inputFile);
    fclose(outputFile);

    system("pause");
} 


int isPalindrome(int number)
{
    int temp, reverse=0, remainder;

    temp=number;
    while(number>0)
    {
        remainder=number%10;
        reverse= reverse*10 + remainder;
        number=number/10;
    }     

    if(temp == reverse)
        return 1;
    else 
        return 0;
}