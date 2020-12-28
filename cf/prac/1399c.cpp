#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n+1);
        for(int i = 0; i < n; i++) {
			int x; cin >> x;
			a[x] ++;
		}
		int ans = 0;
		for(int sum = 2; sum <= 2 * n; sum++) {
			int cur = 0;
			for(int i = 1; i < (sum+1)/2; i++) {
				if(sum - i <= n) {
					cur += min(a[i], a[sum-i]);
				}
			}
			if(sum % 2 == 0) cur += a[sum/2] / 2;
			ans = max(ans, cur);
		}
        cout << ans << endl;
    }
    return 0;
}
