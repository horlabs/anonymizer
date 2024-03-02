//
// gcj_a.c
//

#include <stdio.h>


char letter_map[] = {
//	 a   b   c   d   e   f   g   h   i   j
	'y','h','e','s','o','c','v','x','d','u',
//	 k   l   m   n   o   p   q   r   s   t
	'i','g','l','b','k','r','z','t','n','w',
//	 u   v   w   x   y   z
	'j','p','f','m','a','q'
};

int main()
{
	int t;
	int i;
	char cbuf[128];
	char *p;

	fscanf(stdin,"%d\n",&t);
	for(i = 0; i < t; i++) {
		fgets(cbuf,120,stdin);
//		fprintf(stderr,"%s\n",cbuf);
		fprintf(stdout,"Case #%d: ",i+1);
		p = cbuf;
		while(*p) {
//			fprintf(stderr,"%c",*p);
			if(*p == ' ') fprintf(stdout, " ");
			else if((*p >= 'a') && (*p <= 'z')) {
				fprintf(stdout, "%c", letter_map[*p - 'a']);
			}
			p++;
		}
		fprintf(stdout,"\n");
	}

	return 0;
}

// End of gcj_a.c
