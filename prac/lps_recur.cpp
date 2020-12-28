#include<bits/stdc++.h>
using namespace std;

int lps(const string &seq, int i, int j, unordered_map<string, int> &dp) {
	if (i == j)
		return 1;

	if (seq[i] == seq[j] && i + 1 == j)
		return 2;
	string key = to_string(i) + "," + to_string(j);
	if(dp.find(key) == dp.end()) {
		if (seq[i] == seq[j]) {
			dp[key] = lps (seq, i+1, j-1, dp) + 2;
		}
		else {
			dp[key] = max(lps(seq, i, j-1, dp), lps(seq, i+1, j, dp));
		}
	}
	return dp[key];
}

int lps(const string &s, int i, int j) {
	unordered_map<string, int> dp;
	return lps(s, i, j, dp);
}

int lps(const string &s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;++i)
            dp[i][i] = 1;
        for(int i=n-1;i>=0;--i){
            for(int j=i+1;j<n;++j){
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1]+2;
                else
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }


int main() {
	string s = "abaababaab";
	int n = s.length();
	cout << "The length of the LPS is "	<< lps(s, 0, n-1) << endl;
	int ans = lps(s);
	cout << ans;
	return 0;
}
