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

//0 0 0 1 0 0 1
//0 1 2 3 4 5 6
void solve() {
	string s;
	cin >> s;
	int d;
	cin >> d;
	int n = s.size();
	int ans = 0;
	for(int i = 0; i < n; i++) {
		//cout << "i: " << i << endl;
		int temp =d, j = i;
		while(j < n && !(s[j]-'0') && temp--) {
			if(!temp) {
				ans++;
				break;
			}
			if(s[j+1] == '0' && temp) j++;
			else break;
		}
		//cout << "temp: " << temp<< " i: " << i<< " j: " << j<< " ans: " << ans << endl;
		i = j;
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t,tt=1;
	cin >> t;
	while(tt <= t) {
		cout << "case #" << tt << ":\n";
		solve();
		tt++;
	}
	return 0;
}
