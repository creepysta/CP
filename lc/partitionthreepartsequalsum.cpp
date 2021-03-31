/*
	author: Creepysta
	23-03-2021 22:36:10
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9) + 7;
#define int int64_t
#ifdef LOCAL
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << "debug: [ "; err(_it, args); }
#else
#define debug(args...) 0
#endif
void err(istream_iterator<string> it) { cerr << "\b\b ]\n";}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << ": "  << a << ", "; err(++it, args...); }
template<typename T>
ostream& operator<<(ostream& o, const vector<T> &v) { cerr << "[";for(auto e : v) cerr << e << ", "; cerr<<"\b\b]"; return o;}
template<typename T>
ostream& operator<<(ostream& o, const set<T> &v) { cerr << "{";for(auto e : v) cerr << e << ", "; cerr<<"\b\b}"; return o;}
template<typename T, typename V>
ostream& operator<<(ostream& o, const map<T,V> &v) { cerr << "[";for(auto e : v) cerr << e << ", "; cerr<<"\b\b]"; return o;}
template<typename T, typename V>
ostream& operator<<(ostream &o, const pair<T,V> &p) { cerr << "(";cerr << p.first << ", " << p.second << ")"; return o;}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i < n; i++) {
		a[i] += a[i-1];
	}
	if(a[n-1] % 3) {
		cout << "NO\n";
		return;
		//return false;
	}
	int count = 0, k = 1;
	for(int i = 0; i < n; i++) {
		if(a[i] == k*a[n-1]/3) {
			count++;
			k++;
		}
		if(k == 4) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
	debug(a[n-1], count, k);
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

