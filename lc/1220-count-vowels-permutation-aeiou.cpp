#include <bits/stdc++.h>
using namespace std;


int MOD = int(1e9) + 7;
vector<vector<int>> g {
    {1},
    {0, 2},
    {0, 1, 3, 4},
    {2, 4},
    {0},
};
vector<vector<int>> mem;
int calc(int n, int curr) {
    if (n == 1) {
        return 1;
    }
    int cnt = 0;
    if (mem[curr][n] != -1) return mem[curr][n];
    for(int i : g[curr]) {
        cnt = (cnt + calc(n-1, i)) % MOD;
    }
    mem[curr][n] = cnt;
    return cnt;
}
int fast(int n) {
    vector<vector<int>> dp(5, vector<int> (n+1));
    for(int i = 0; i < 5; i++) {
        dp[i][1] = 1;
    }
    for(int i = 1; i < n; i++) {
        for(int u = 0; u < 5; u++) {
            for(int v : g[u]) {
                dp[v][i+1] = (dp[v][i+1] + dp[u][i]) % MOD;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 5; i++) {
        ans = (ans + dp[i][n]) % MOD;
    }
    return ans;
}
int countVowelPermutation(int n) {
    int ans = 0;
    mem.assign(5, vector<int> (n+1, -1));
    for(int i = 0; i < 5; i++) {
        ans = (ans + calc(n, i)) % MOD;
    }
    int f = fast(n);
    //cerr << ans << " " << f << '\n';
    assert(ans == f);
    ans = f;
    return ans % MOD;
}

int main() {
    int nax = 1e5;
    for(int i = 1; i <= nax; i++) {
        int n = i;
        //cerr << "Testing n : " << n << '\n';
        cout << countVowelPermutation(n) << '\n';
    }
}
