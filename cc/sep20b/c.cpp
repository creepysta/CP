/*
	author: Creepysta
	05-09-2020 21:18:06
 * */

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

const int MOD = 1e9 + 7;
/*
 * 1 2 3
 * 3 2 1
 * 3 1 2
 * 2 1 3
 * 2 3 1
 *
 * 1 1 1
 * 2 2 2
 * 3 3 3
 * */

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	/*
	vector<vector<pair<int, int>>> infect(6);
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if(a[i] > a[j])
				infect[a[i]].push_back(make_pair(a[j], j));
		}
	}
	for(int i = 0; i < (int) infect.size(); i++) {
		for(int j = 0; j < (int) infect[i].size(); j++) {
			cout << infect[i][j].ff << ' ';
		}
		cout << '\n';
	}
	*/
	int low = INT_MAX, high = -1;
	for(int src = 0; src < n; src++) {
		int infected = 0;
		vector<bool> dead(10, false);
		dead[src] = true;
		// infected infecting others
		for(int spread = src+1; spread < n; spread++) {
			if(a[src] > a[spread])
				dead[spread] = 1;
		}
		// runners behind infected
		for(int runner = 0; runner < src; runner++) {
			if(a[runner] > a[src])
				dead[runner] = 1;
			for(int probable = src + 1; probable < n; probable++) {
				if(a[runner] > a[probable])
					dead[probable] = 1;
			}
		}
		for(int i = src + 1; i < n; i++) {
			if(dead[i]) {
				for(int j = 0; j < src; j++) {
					if(a[j] > a[i])
						dead[j] = 1;
				}
			}
		}
		// cout << src << ' ' << a[src] << '\n';
		for(bool is : dead)
			infected += is; //cout << is << ' ';
		// cout << '\n';
		low = min(infected, low);
		high = max(infected, high);
	}
	cout << low << ' ' << high << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		//cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

