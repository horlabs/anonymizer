#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>
#include <list>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <queue>
#include <stack>
#include <complex>
#include <limits.h>

#define Cpp11
#ifdef Cpp11
#include <cassert>
#include <chrono>
#include <regex>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <valarray>
using namespace std::chrono;
#endif
using namespace std;

typedef double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

//const int mx[4] = { 1, 0, -1, 0 };
//const int my[4] = { 0, 1, 0, -1 };

const int Inf = 1000000000;
const int Mi = 1000000007;
const int N = 105;
const int M = 100005;
//const int K = 20;
const ld eps = 10e-7;
const ld PI = 2 * acos(0.0);
const ll InfLL = ll(Inf) * ll(Inf);

unsigned rand16() { return rand() % (1 << 16); }
unsigned rand32() { return (rand16() << 16) + rand16(); }
ull rand64() { return (((ull)rand32()) << 32) + rand32(); }
int rand(int L, int R) { if (L > R) return R; return rand32() % (R - L + 1) + L; }
ld random(ld L, ld R) { return rand(ceil((L - eps) * 100), floor((R + eps) * 100)) / 100.0; }

ll Abs(ll a) { return a < 0 ? -a : a; }
ll sqr(ll a) { return a*a; }
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }


string toStr(int n) {
	char s[100];
	sprintf(s, "%d", n);
	return string(s);
}

ll S[N], E[N], A[N][N];
ll A_nxt[N];
ld ans[N];


//#define ONLINE_JUDGE
int main() {
	std::ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		cout << "Case #" << (t + 1) << ": ";

		int n, q;
		cin >> n >> q;
		for (int i = 0; i < n; ++i) {
			cin >> E[i] >> S[i];
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> A[i][j];
			}
			A_nxt[i] = A[i][i + 1];
		}
		ans[n - 1] = 0;
		for (int i = n - 2; i >= 0; --i) {
			ans[i] = 1e18;
			ll dst_nxt = 0;
			for (int j = i + 1; j < n; ++j) {
				dst_nxt += A_nxt[j - 1];
				if (E[i] >= dst_nxt) {
					ans[i] = min(ans[i], double(dst_nxt) / S[i] + ans[j]);
				}
				else {
					break;
				}
			}
		}
		for (int i = 0; i < q; ++i) {
			int a, b;
			cin >> a >> b;
			cout << fixed << setprecision(10) << ans[0] << endl;
		}
	}
	return 0;
}