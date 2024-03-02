#include <stdio.h>
#include <math.h>
#define MAX_LENGTH 8

int str1[MAX_LENGTH], str2[MAX_LENGTH], len;
long long int te[MAX_LENGTH-1], co;

int getLength(long long int num) {
    int r = 0;
    while(num>0) {
        r++;
        num /= 10;
    }
    return r-1;
}

void convertToArray(long long int num) {
    int j;
    for(j=len; j>=0; j--) {
        str1[j] = num % 10;
        num /= 10;
    }
}

long long int getNumber() {
    long long int num = 0;
    int i;
    for(i=0; i<=len; i++) {
        num += str2[i];
        num = num * 10;
    }
    num /= 10;
    return num;
}

int isEqual(long long int num) {
    int i;
    for(i=0; i<=len; i++) {
        if (str1[i] != str2[i])
            return 0;
    }
    return 1;
}

void shiftArray() {
    int i, j;
    i = str2[len];
    for(j=(len-1); j>=0; j--)
        str2[j+1] = str2[j];
    str2[0] = i;
}

int checkNumber(long long int num, long long int m, long long int n) {
    if(str1[0] == 0)
        return 0;
    int j, k = 0;
    for(j=0; j<=len; j++)
        str2[j] = str1[j];
    int ch;
    long long int f;
    co = -1;
    for(j=1; j<=len; j++) {
        shiftArray();
        f = getNumber();
        for(ch=0; ch<=co; ch++) {
            if(te[ch] == f)
                goto lst;
        }
        if(f > num && f >= m && f <= n) {
            k++;
            co++;
            te[co] = f;
        }
        lst:
        k += 0;
    }
    return k;
}

void Main(FILE* in, FILE* out) {
    long long int m, n, i;
    long int r=0, k;
    fscanf(in, "%lld", &m);
    fscanf(in, "%lld", &n);
    len = getLength(m);
    if(len == 0)
        goto end;
    for(i=m; i<=n; i++) {
        convertToArray(i);
        k = checkNumber(i, m, n);
        r += k;
        if(k > 0)
            fprintf(out, "%lld:%ld\t", i, k);
    }
    end:
    fprintf(out, "%ld", r);
}

int main() {
    FILE *inputFile, *outputFile;
    inputFile = fopen("/home/vivek/Desktop/input.txt","r");
    outputFile = fopen("/home/vivek/Desktop/output.txt","w");

    int cs, i;
    fscanf(inputFile, "%d", &cs);
    for(i=1; i<=cs; i++) {
        fprintf(outputFile, "Case #%d: ", i);
        Main(inputFile, outputFile);
        fprintf(outputFile, "\n");
    }
    return 1;
}
