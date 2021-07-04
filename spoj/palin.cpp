#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		a[i] = s[i] - '0';
	bool all9s = true;
	for(int i = 0; i < n; i++)
			all9s &= a[i] == 9;
	if(all9s) {
		string temp = "1";
		for(int i = 0; i < n-1; i++)
			temp += "0";
		temp += "1";
		cout << temp << "\n";
		return;
	}
	bool leftSmaller = false;
	int mid = n/2;
	int lt = mid - 1,
		rt = n % 2 ? mid + 1 : mid;
	// check if left is greater than right
	while(lt >= 0 && a[lt] == a[rt])
		lt--, rt++;
	// already palindrome, increase middle elements
	if(lt < 0 || a[lt] < a[rt])
		leftSmaller = true;
	while(lt >= 0)
		a[rt++] = a[lt--];
	if(leftSmaller) {
		int carry = 1;
		lt = mid - 1;
		if(n % 2) {
			a[mid] += carry;
			carry = a[mid] / 10;
			a[mid] %= 10;
			rt = mid + 1;
		} else
			rt = mid;
		while(lt >=  0) {
			a[lt] += carry;
			carry = a[lt] / 10;
			a[lt] %= 10;
			a[rt++] = a[lt--];
		}
	}
	for(int i = 0; i < n; i++)
		cout << a[i];
	cout << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	cin >> t;
	for(int tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}

