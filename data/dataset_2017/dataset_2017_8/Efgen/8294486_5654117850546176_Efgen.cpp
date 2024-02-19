// @formatter:off
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define X first
#define Y second
template<class T> inline T sqr(T x) { return x * x; }
template<class T> inline T parse(const string&s){T x;stringstream ss(s);ss>>x;return x;}
int gcd(int a,int b){return a?gcd(b%a,a):b;}
ll gcd(ll a,ll b){return a?gcd(b%a,a):b;}
ll powmod(ll a,ll p,ll m){ll r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
// @formatter:on


void solveTest() {
    int n, r, o, y, g, b, v;
    cin >> n >> r >> o >> y >> g >> b >> v;
    vector<pair<int, char>> a(3);
    a[0] = {r, 'R'};
    a[1] = {y, 'Y'};
    a[2] = {b, 'B'};
    sort(all(a));
    reverse(all(a));
    string ans;

    int rg = a[0].first - a[1].first;
    if (rg <= a[2].first) {
        int c1 = a[1].first + a[2].first - a[0].first;
        int c2 = a[0].first - a[2].first;
        int c3 = a[0].first - a[1].first;
        forn(i, c1) {
            cout << a[0].second << a[1].second << a[2].second;
        }
        forn(i, c2) {
            cout << a[0].second << a[1].second;
        }
        forn(i, c3) {
            cout << a[0].second << a[2].second;
        }

    } else {
        cout << "IMPOSSIBLE";
    }
}

int main() {
#ifdef EFGEN_DBG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cout << "Case #" << test << ": ";
        solveTest();
        cout << endl;
    }
}
