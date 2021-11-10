#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'


int dp[300][300];
vector<int> a, b,ans;

void solve() {
    int n, m;
    cin >> n >> m;
    a.clear(), b.clear();
    a.resize(n), b.resize(m);
    for(int &i : a ) cin >> i;
    for(int &i : b ) cin >> i;
    for(int i = 0; i <=n; i++) {
        for(int j = 0; j <= m; j++) {
            if(!i || !j) dp[i][j] = 0;
            else {
                if(a[i-1] == b[j-1]) {
                    dp[i][j] = 1+dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }
    // cout << dp[n][m] << endl;
    int i = n, j= m;
    ans.clear();
    int index = dp[n][m]-1;
    ans.resize(dp[n][m]);
    while(i>0 && j>0) {
        if(a[i-1] == b[j-1]) {
            ans[index] = a[i-1];
            i--; j--; index--;
        } else if(dp[i-1][j] < dp[i][j-1]) j--;
        else i--;
    }
    for(int val : ans) cout << val << ' ';
    cout << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1, tt=1;
    // cin >> t;
    while(tt <= t) {
        // cout << "case #"<<tt << ":\n";
        solve();
        tt++;
    }
}
