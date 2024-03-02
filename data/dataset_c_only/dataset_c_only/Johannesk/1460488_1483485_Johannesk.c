#include <stdio.h>
#include <string.h>
#include <assert.h>

int main(int argc, char **argv)
{
    char s[26]="yhesocvxduiglbkrztnwjpfmaq";
    char d[105], e[105];
    int n,v,i,j,l;

    assert (scanf("%d ",&n) == 1);
    for(i=1;i<=n;i++)
    {
        assert (fgets(d,105,stdin) != NULL);
        l=strlen(d);
        for(j=0;j<l;j++)
        {
            if((d[j] != ' ') && (d[j] != 0xA))
                e[j]=s[d[j]-'a'];
            else if (d[j] == ' ')
                e[j]=d[j];
        }
        e[j-1]='\0';
        printf("Case #%d: %s\n",i,e);
    }
    return 0;
}
