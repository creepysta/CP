#include <bits/stdc++.h>
using namespace std;
#define MAX INT_MAX
#define MIN INT_MIN
#define MOD 1000000007
#define endl '\n'

int dp[102][102][2];


int findinrange(int pos, int cnt, int tight, vector<int> &num, int k) {
    if (pos == (int) num.size()) {
        if (cnt == k)
            return 1;
        return 0;
    }
    if (dp[pos][cnt][tight] != -1)
        return dp[pos][cnt][tight];

    int ans = 0;
    int limit = (tight ? 9 : num[pos]);

    for (int dig = 0; dig <= limit; dig++) {
        int currCnt = cnt;
		if (dig != 0)
            currCnt++;

        int currTight = tight;
		if (dig < num[pos])
            currTight = 1;

        ans += findinrange(pos + 1, currCnt,
                                currTight, num, k);
    }
    return dp[pos][cnt][tight] = ans;
}

int count(int x, int k) {
    vector<int> num;
    while (x) {
        num.push_back(x % 10);
        x /= 10;
    }
    reverse(num.begin(), num.end());

    memset(dp, -1, sizeof(dp));
    return findinrange(0, 0, 0, num, k);
}

void solve() {
	int l,r, k;
	cin >> l >> r >> k;
	int ans = count(r, k) - count(l, k);
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1,tt=1;
	cin >> t;
	while(tt <= t) {
		//cout << "case #" << tt << ":\n";
		solve();
		tt++;
	}

	return 0;
}
