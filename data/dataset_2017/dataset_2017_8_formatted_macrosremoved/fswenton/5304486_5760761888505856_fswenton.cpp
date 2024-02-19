#include <iostream>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

template <class P0, class P1>
ostream &operator<<(ostream &os, const pair<P0, P1> &p) {
  return os << "(" << p.first << "," << p.second << ")";
}
template <class T> void _dump(const T &t) {
  cerr << "[";
  for (auto it = t.begin(); it != t.end(); ++it)
    cerr << " " << *it;
  cerr << " ]"
       << "\n";
}
int main(void) {
  int T;
  cin >> T;

  for (int iCase = 1; iCase <= T; ++iCase) {
    cout << "Case #" << iCase << ":\n";
    {
      cerr << "iCase"
           << ": " << iCase << "\n";
    };

    int i, j, R, C;
    cin >> R >> C;
    vector<string> cake(R);
    for (i = 0; i < R; ++i)
      cin >> cake[i];

    {
      cerr << "cake"
           << ": ";
      _dump(cake);
    };

    for (i = 0; i < R; ++i) {
      for (j = 0; j < C;)
        if (cake[i][j] != '?') {
          char ch = cake[i][j];
          while (++j < C && cake[i][j] == '?')
            cake[i][j] = ch;
        } else
          ++j;

      for (j = C - 1; j >= 0;)
        if (cake[i][j] != '?') {
          char ch = cake[i][j];
          while (--j >= 0 && cake[i][j] == '?')
            cake[i][j] = ch;
        } else
          --j;
    }

    string empty(C, '?');
    for (i = 0; i < R;)
      if (cake[i] != empty) {
        string s = cake[i];
        while (++i < R && cake[i] == empty)
          cake[i] = s;
      } else
        ++i;

    for (i = R - 1; i >= 0;)
      if (cake[i] != empty) {
        string s = cake[i];
        while (--i >= 0 && cake[i] == empty)
          cake[i] = s;
      } else
        --i;

    for (i = 0; i < R; ++i)
      cout << cake[i] << "\n";
  }

  return 0;
}
