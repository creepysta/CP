#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

/*
aaakaeekmnnry
abohotypsu
aabadawyehhorst
*/

void solve() {
	string s, t;
	cin >> s >> t;
	string ts = s, tt = t;
	sort(ts.begin(), ts.end());
	sort(tt.begin(), tt.end());
	int n = s.length(), m = t.length();
	string tem = "";
	int i = 0, j = 0;
	for(i = 0, j = 0; i < n && j < m; i++) {
		if(ts[i] != tt[j]) {
			tem += ts[i];
		} else {
			j++;
		}
	}
	while(i < n) tem+= ts[i++];
	string ans = "";
	int l = lower_bound(tem.begin(), tem.end(), t[0]) - tem.begin();
	int r = upper_bound(tem.begin(), tem.end(), t[0]) - tem.begin();
	//cout << tem << endl;
	//cout << l << ' ' << r << endl;
	auto ins = [&] (const string &a, const string &b, const int idx) {
		return a.substr(0, idx) + b + a.substr(idx);
	};
	string ls = ins(tem, t, l);
	string rs = ins(tem, t, r);
	if(ls < rs) {
		cout << ls;
	} else {
		cout << rs;
	}
	cout << '\n';
	return;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}
