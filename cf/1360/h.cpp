/*
Binary Median
https://codeforces.com/problemset/problem/1360/H
*/

//#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
//#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF LLONG_MAX
#define MIN LLONG_MIN
#define MOD 1000000007
#define endl '\n'

//ll dp[10001][10001];
//ll dp[1000001];

ll stb(string s) {
	ll ans = 0;
	for(char c:s) {
		ans = (ans<<1ll)|(c - '0');
	}
	return ans;
}

void tobin(ll num, ll bits) {
	while(bits--) {
		cout << ((num>>bits) & 1ll);
	}
	cout << endl;
}
/*
3 3
010
001
111
limit = 8
m = 3 n = 3
0 1 2 3 4 5 6 7
table = {2 1 7}
0 3 4 5 6
limit - 3= 5
limit / 2 = 2;
*/
void solve() {
	ll n, m;
	cin >> n >> m;
	ll limit = (1ll<<m);
	unordered_set<ll> table;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		ll bits = stb(s);
		table.insert(bits);
		a[i] = bits;
	}
	sort(a.begin(), a.end());
	ll median = (limit-n) ? (limit-n-1)>>1ll : 0;
	//ll median = (1<<(m-1))-1;
	ll pos = median;
	for(int i : a) {
		if(i < pos) {
			pos++;
		}
		//else if(i>pos) {
			//pos--;
		//}
		else if(table.find(pos) != table.end()) {
			pos ++;
		}
	}
	//pos =-1;
	//for(ll i = 0; i < limit; i++) {
		//if(table.find(i) == table.end()) pos ++;
		//if(pos==median) {
			//pos = i;
			//break;
		//}
	//}
	tobin(pos, m);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t,tt=1;
	cin >> t;
	while(tt <= t) {
		//cout << "case #" << tt << ":\n";
		solve();
		tt++;
	}

	return 0;
}
