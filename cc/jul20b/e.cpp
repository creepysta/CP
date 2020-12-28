#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve() {
	int n;
	cin >> n;
	map<int, int> a, b;
	int minelem = 1e9+5;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		a[x] ++;
		minelem = min(x, minelem);
	}
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		b[x] ++;
		minelem = min(x, minelem);
	}
	ll cost = 0LL;
	bool impos = false;
	//for(auto m : a) cout << "a: " << m.first << ' ' << m.second << endl;
	//for(auto m : b) cout << "b: " << m.first << ' ' << m.second << endl;
	vector<int> na, nb;
	for(auto ia = a.begin(); ia != a.end(); ia++) {
		if(ia->second > b[ia->first]) {
			int total = ia->second - b[ia->first];
			if(total %2) {
				impos = true;
				break;
			}
			int togive = total / 2;
			for(int i = 0; i < togive; i++) {
				nb.push_back(ia->first);
			}
		}
	}
	for(auto ib = b.rbegin(); ib != b.rend(); ib++) {
		if(ib->second > a[ib->first]) {
			int total = ib->second - a[ib->first];
			if(total % 2) {
				impos = true;
				break;
			}
			int togive = total/2;
			for(int i = 0; i < togive; i++) {
				na.push_back(ib->first);
			}
		}
	}
	// makes no sense
	// doesn't take the 1 elem from b
	//for(; ia != a.end() && ib != b.rend(); ia++, ib++ ) {
		//cout << ib->first <<  ' ' << ib->second << endl;
		//if(ia->second > b[ia->first]) {
			//cout << "nb: " << ia->first << endl;
			//int total = ia->second - b[ia->first];
			//if(total %2) {
				//impos = true;
				////cout << "--------impos----------" << ia->first << endl;
				//break;
			//}
			//int togive = total / 2;
			//for(int i = 0; i < togive; i++) {
				//nb.push_back(ia->first);
			//}
		//}
		//if(ib->second > a[ib->first]) {
			//cout << "na: " << ib->first << endl;
			//int total = ib->second - a[ib->first];
			//if(total % 2) {
				//impos = true;
				////cout << "--------impos----------" << ib->first << endl;
				//break;
			//}
			//int togive = total/2;
			//for(int i = 0; i < togive; i++) {
				//na.push_back(ib->first);
			//}
		//}
	//}
	if(impos) cout << -1 << endl;
	else {
		//sort(na.begin(), na.end());
		//sort(nb.rbegin(), nb.rend());
		//for(int i : na) cout << i << ' ';
		//cout << endl;
		//for(int i : nb) cout << i << ' ';
		//cout << endl;
		n = na.size();
		for(int i = 0; i< n; i++) {
			int cal = min(na[i], nb[i]) != minelem ? min(2*minelem, min(na[i], nb[i])) : minelem;
			cost += (ll) cal;
		}
		cout << cost << endl;
	}
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
