//ad a king
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve() {
	int k;
	cin >> k;
	string a[8];
	k--;
	for(int i = 0; i < 8; i++) a[i] = string(8,'.');
	a[0][0] = 'O';
	int r = ceil(k/8);
	int c = k % 8;
	if(r+1 < 8)
	for(int i = 0; i <= c+1; i++) a[r+1][i] = 'X';
	if(r==0)
	a[r][c+1] = 'X';
	else
	for(int i = c+1; i < 8; i++) a[r][i] = 'X';
	for(string s : a) cout << s << endl;
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
