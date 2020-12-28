#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define MOD 1000000007
#define endl '\n'

void tobin(ll num, ll bits) {
	while(bits--) {
		cout << ((num>>bits) & 1ll);
	}
	cout << endl;
}
// 1011 = 1010 1000 0100 0110 0010
void solve() {
	ll ts;
	cin >> ts;
	if(ts == 1 || (__builtin_popcountll(ts) == 1 && ts % 2 == 0)) {
		cout << 0 << endl;
		return;
	}
	int lbit = 0, fbit=(int) log2(ts);
	ll mask = 1ll;
	for(int i = 0; i <= fbit; i++) {
		if(ts&(mask<<i)) {
			lbit = i;
			break;
		}
	}
	ll lownum = 1ll << (lbit + 1);
	ll diff = ts-lownum;
	ll ans = diff < 0 ? 0 : diff/lownum ;
	ans++;
	//if(ts & 1) ans = ans ? ans + 1 : ans;
	//else ans -= 1;
	cout << ts << ' ' << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}
