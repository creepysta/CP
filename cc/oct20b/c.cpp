/*
	author: Creepysta
	19-10-2020 07:56:34
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int nax = 1e5 + 10;
int a[nax];

string out(int n) {
	string s = "";
	do {
		s += to_string(n & 1);
		n >>= 1;
	} while(n);
	reverse(s.begin(), s.end());
	cout << s << endl;
	return s;
}

void solve(int n) {
	a[1] = 2, a[2] = 3, a[3] = 1;
	if(n == 1) {
		cout << 1 << '\n';
		return;
	}
	if((n & (n-1)) == 0) {
		cout << -1 << '\n';
		return;
	}
	for(int i = 4; i <= n; i++) {
		a[i] = i;
		if((i & (i - 1)) == 0) {
			a[i] = i+1;
			a[i+1] = i;
			i++;
		}
	}
	for(int i = 1; i <= n; i++)
		cout << a[i] << ' ';
	cout << '\n';
	bool ok = true;
	for(int i = 1; i < n; i++) {
		if((a[i] & a[i+1]) == 0)
			ok = false;
	}
	assert(ok);
}

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	//int n = 100;
	//srand(stoi(argv[1]));
	//for(int i = 1; i < n; i++) {
	//	int x = rand()%10;
	//	cout << "N: " << x << endl;
	//	solve(x);
	//}
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		int n;
		cin >> n;
		solve(n);
	}
	return 0;
}

