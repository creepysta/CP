#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i != j && a[i] == a[j]) {
				ans ++;
			}
		}
	}
	cout << ans << '\n';
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
