// guessing game
#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void operator<<(ostream &cout, const pair<int, int> &p) {
	cout << p.first << ' ' << p.second << endl;
}

void solve() {
	ll n;
	cin >> n;
	ll l = 1, h = n;
	char c, pc = 'a';
	queue<pair<int, int>> q;
	while(l <= h) {
		ll m = l + (h-l) /2;
		cout << m << endl;
		cin >> c;
		if(c == 'E') {
			return;
		}
		else if(c == 'L') {
			q.push(make_pair(m+1, h));
			h = m - 1;
		}
		else if(c == 'G') {
			q.push(make_pair(l, m-1));
			l = m + 1;
		}
		pc = c;
	}
	while(!q.empty()) {
		//cout << s.top();
		//l = s.top().first; h = s.top().second;
		//s.pop();
		l = q.front().first; h = q.front().second;
		q.pop();
		while(l <= h) {
			ll m = l + (h-l) /2;
			cout << m << endl;
			cin >> c;
			if(c == 'E') {
				return;
			}
			else if(c == 'L') {
				q.push(make_pair(m+1, h));
				h = m - 1;
			}
			else if(c == 'G') {
				q.push(make_pair(l, m-1));
				l = m + 1;
			}
			pc = c;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1;
	//cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}
