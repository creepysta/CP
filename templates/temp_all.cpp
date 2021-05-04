/*
	author: Creepysta
*/
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define ff first
#define ss second
#define endl '\n'
#ifdef LOCAL
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << "debug: [ "; err(_it, args); }
#define debugi(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << "debug: [ "; err(_it, args); }
#else
#define debug(args...) 0
#endif
void err(istream_iterator<string> it) { cerr << "]\n";}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << "="  << a << " "; err(++it, args...); }
template<typename T>
template<typename T>
ostream& operator<<(ostream& o, const vector<T> &v) { cerr << "(";for(auto e : v) cerr << e << ' '; cerr<<"\b) "; return o;}
template<typename T>
ostream& operator<<(ostream& o, const set<T> &v) { cerr << "(";for(auto e : v) cerr << e << ' '; cerr<<"\b) "; return o;}
template<typename T, typename V>
ostream& operator<<(ostream& o, const map<T,V> &v) { cerr << "(";for(auto e : v) cerr << e << ' '; cerr<<"\b) "; return o;}
template<typename T, typename V>
ostream& operator<<(ostream &o, const pair<T,V> &p) { cerr << "(";cerr << p.first << ' ' << p.second << ") "; return o;}
const int MOD = int(1e9) + 7;

void solve() {
	
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}
