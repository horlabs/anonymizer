#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
  FILE *fout;

  fout = freopen("A-small-attempt1.out", "w", stdout);

  int Testcases, t;
  char Line[100000];
  scanf("%d", &Testcases);
  int i, L;
  getchar();
  for (t = 1; t <= Testcases; t++) {
    printf("Case #%d: ", t);
    gets(Line);
    i = 0;
    L = strlen(Line);

    for (i = 0; i < L; i++) {
      if (isalpha(Line[i]))
        switch (Line[i]) {
        case 'a':
          putchar('y');
          break;
        case 'b':
          putchar('h');
          break;
        case 'c':
          putchar('e');
          break;
        case 'd':
          putchar('s');
          break;
        case 'e':
          putchar('o');
          break;
        case 'f':
          putchar('c');
          break;
        case 'g':
          putchar('v');
          break;
        case 'h':
          putchar('x');
          break;
        case 'i':
          putchar('d');
          break;
        case 'j':
          putchar('u');
          break;
        case 'k':
          putchar('i');
          break;
        case 'l':
          putchar('g');
          break;
        case 'm':
          putchar('l');
          break;
        case 'n':
          putchar('b');
          break;
        case 'o':
          putchar('k');
          break;
        case 'p':
          putchar('r');
          break;
        case 'q':
          putchar('z');
          break;
        case 'r':
          putchar('t');
          break;
        case 's':
          putchar('n');
          break;
        case 't':
          putchar('w');
          break;
        case 'u':
          putchar('j');
          break;
        case 'v':
          putchar('p');
          break;
        case 'w':
          putchar('f');
          break;
        case 'x':
          putchar('m');
          break;
        case 'y':
          putchar('a');
          break;
        case 'z':
          putchar('q');
          break;
        }
      else
        putchar(Line[i]);
    }

    putchar(10);
  }

  fclose(fout);

  return 0;
}
