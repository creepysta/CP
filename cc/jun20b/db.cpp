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

void solve() {
	ll ts;
	cin >> ts;
	if(ts == 1 || (__builtin_popcountll(ts) == 1 && ts % 2 == 0)) {
		cout << 0 << endl;
		return;
	}
	ll ans = 0;
	int fbit = log2(ts), lbit = 0;
	int mask = 1;
	for(int i  =0 ; i <= fbit; i++) {
		mask = 1 << i;
		if(mask & ts) {
			lbit = i;
			break;
		}
	}
	for(int js = 1<<(lbit+1); js <= ts; js+=2) {
		bool ok = true;
		ll tts= ts, jjs = js;
		if(js&1) continue;
		else {
			while(jjs>=1 && tts >= 1) {
				if(tts%2 && jjs %2==0) {
					ok = true;
					break;
				}
				if((tts%2==0 && jjs%2) || (tts%2 && jjs%2)) {
					ok = false;
					break;
				}
				if(tts%2==0 && jjs%2 ==0) {
					tts /=2;
					jjs /=2;
				}
			}
			if(ok) {
				ans++;
				//cout << js << endl;
			}
		}
	}
	//cout << "ans: ";
	cout << ts << ' ';
	cout << ans << endl;

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
