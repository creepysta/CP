/*
 * https://codeforces.com/contest/1187/problem/A
 *
 */

#include <bits/stdc++.h>
using namespace std;

int min( int &a, int &b) {

	return a < b ? a : b;
}

int main()
{
	int T;
	cin >> T;
	int s, n, t;
	while (T--) {
		cin >> n >> s >> t;
		int st = min(s, t);
		int diff = n - st;

		if(n==s && s==t) {
			cout << 1 << endl;
		}
		else if(n > s) {
			cout << diff + 1 << endl;
		}
		
	////if(diff == 0) {
	////	cout << 1 << endl;
	////} else {
	////	cout << st + 1 << endl;
	////}	
	}

	return 0;
}
