/*
	author: Creepysta
 */
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

/*
   2
   6
   1 1 1 10 10 10
   1 9
   5
   1 2 3 4 5
   4 -1
 */

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int &i : a)
		cin >> i;
	int k, x;
	cin >> k >> x;
	int l = 0, h = n-1, mid = 0, maybe = 0;
	while(l <= h) {
		mid = l + (h - l) / 2;
		if(a[mid] >= x) {
			maybe = mid;
			h = mid - 1;
		}
		else
			l = mid + 1;
	}
	int left = max(0, maybe - k - 1), right = min(n-1, maybe + k - 1);
	// cout << maybe << ' ' << left << ' ' << right << '\n';
	while(right - left > k-1) {
		if(left < 0 || (x-a[left]) <= (a[right] - x))
			right --;
		else if(right > n-1 || (x - a[left]) > (a[right]-x))
			left++;
	}
	vector<int> ans(a.begin() + left, a.begin() + right+1);
	for(int i : ans)
		cout << i << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

