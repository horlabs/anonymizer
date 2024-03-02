#include  <stdio.h>
#include  <stdlib.h>
#include  <ctype.h>
#include  <string.h>

#define  STRSIZE 102


int main( void )
{
	freopen("A-small-attempt4.in","r",stdin);

	int testcase = 0;
	int testcases;

	char toEnglish[] = "yhesocvxduiglbkrztnwjpfmaq";
	char googlerese[STRSIZE] = "";


	scanf("%d\n", &testcases);

	while (testcase < testcases) {

		char *c = googlerese;

		fgets(googlerese, STRSIZE, stdin);
		for(; *c!='\0'; c++) {

			if( isalpha(*c) ) *c = toEnglish[ *c - 'a'];
		}

		printf("Case #%d: %s",++testcase, googlerese);
	}

	return 0;
}
