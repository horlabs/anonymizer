#include <stdio.h>
#include <math.h>

#define read( x )		fscanf( fp, "%d", &x )
#define readc( x )		fscanf( fp, "%c ", &x )
#define read2( x, y)	fscanf( fp, "%ld %ld", &x, &y)

#define SetBit( x, n )	((x) & (0x1<<n))

short isPallindrome(long i) {
	long t, r=0;
	t = i;
	while( t != 0 )
	{
		r = r * 10;
		r = r + t%10;
		t /= 10;
	}
	return i==r;
}

int sqr(int n)
{
    int h = n & 0xF;
    if (h > 9) return 0;
    if ( h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8 )
    {
        int t = (int) floor( sqrt((double) n) + 0.5 );
		return ( (t*t == n) && isPallindrome(t));
    }
    return 0;
}

int main()
{
	int T=-1;
	int c=0;

	FILE *fp = fopen("C-small-attempt0.in","r");

	FILE *fo = fopen("output.txt","w");

	read( T );

	while(++c<=T) {
		unsigned long i=0,j=0;
		int count=0;
		read2( i, j);
		while(i<=j) {
			if ( isPallindrome(i)) {
				if(sqr(i)) {
					count ++;
				}
			}
			i++;
		}
		fprintf(fo,"Case #%d: %d\n",c, count);

	}

	fclose(fp);fclose(fo);
	return 0;

}