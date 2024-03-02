//
// qual_a.c
//

#include <stdio.h>


int main()
{
	int t;
	int i;
	int k,l;
	int board_ptn[4][4];
	char cbuf[8];
	int result;
	int j;
	int line_result[10];
	int chk_dot;

	fscanf(stdin,"%d\n",&t);
	for(i = 0; i < t; i++) {
		// input data
		chk_dot = 0;
		for(l = 0; l < 4; l++) {
			fgets(cbuf,sizeof(cbuf),stdin);
//			fprintf(stderr,"%s",cbuf);
			for(k = 0; k < 4; k++) {
				switch(cbuf[k]) {
				case 'O':
					board_ptn[l][k] = 1;
					break;
				case 'X':
					board_ptn[l][k] = 2;
					break;
				case 'T':
					board_ptn[l][k] = 3;
					break;
				default:
					board_ptn[l][k] = 0;
					chk_dot = 1;
					break;
				}
			}
		}
		fgets(cbuf,sizeof(cbuf),stdin);	// skip blank line
		// check data
		for(j = 0; j < 10; j++) line_result[j] = 3;
		for(l = 0; l < 4; l++) {
			for(k = 0; k < 4; k++) {
				line_result[l] &= board_ptn[l][k];
				line_result[l+4] &= board_ptn[k][l];
			}
			line_result[8] &= board_ptn[l][l];
			line_result[9] &= board_ptn[l][3-l];
		}
		result = 0;
		for(j = 0; j < 10; j++) {
//			fprintf(stderr,"line_result[%d] = %d\n",j,line_result[j]);
			result |= line_result[j];
		}
//		fprintf(stderr,"chk_dot : %d\n",chk_dot);
		fprintf(stdout,"Case #%d: ",i+1);
		if(result & 1) {	// O won
			fprintf(stdout,"O won");
		} else if(result & 2) {	// X won
			fprintf(stdout,"X won");
		} else if(chk_dot) {	// not completed
			fprintf(stdout,"Game has not completed");
		} else {	// draw
			fprintf(stdout,"Draw");
		}
		fprintf(stdout,"\n");
	}

	return 0;
}

// End of qual_a.c
