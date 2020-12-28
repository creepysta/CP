#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int dp[10001][10001];


int main() {
	//fastio;
	ll t;
	cin >> t;
	while(t--) {
		string s1, s2;
		cin >> s1 >> s2;
		ll n1 = s1.size(), n2=s2.size();
		for(ll i=0; i<=n1; i++) {
			for(ll j=0; j <= n2; j++) {
				if(!i || !j)
					dp[i][j] = 0;
				else {
					if(s1[i-1] == s2[j-1])
						dp[i][j] = 1+dp[i-1][j-1];
					else
						dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		ll ans = dp[n1][n2];
		cout << ans << endl;
		ll index = ans;
		char lcs[index+1];
		lcs[index] = '\0';
		ll i = n1, j = n2;
		while(i >0 && j>0){
			if(s1[i-1] == s2[j-1]) {
				lcs[index-1] = s1[i-1];
				i--, j--, index--;
			}
			else if(dp[i-1][j] < dp[i][j-1]) j--;
			else i--;
		}
		cout << lcs << endl;
	}

	return 0;
}
