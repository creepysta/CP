/*
 * Longest Increasing Subsequence
 */

#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF LLONG_MAX
#define MIN LLONG_MIN
#define MOD 10000001
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define umapll unordered_map<long long int,long long int>
#define umapsl unordered_map<string,long long int>
#define pll pair<long long int,long long int>
#define psl pair<string,long long int>
#define pcl pair<char,long long int>
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

int dp[10001][10001];

void input(vector<ll> &a, ll n) {
	for(ll &i : a) cin >> i;
}

void input1(vector<ll> &a, ll n) {
	for(ll i = 1; i <= n; i++) cin >> a[i];
}

void out(vector<ll> &a) {
	for(ll i : a) cout << i << ' ';
	cout << endl;
}

void out1(vector<ll> &a) {
	int n = a.size();
	for(ll i = 1; i <= n; i++) cout << a[i] << ' ';
	cout << endl;
}

// 50 3 10 7 8 40 80
// noob approach
ll solve(vector<ll> &a, ll index, ll end, ll len, ll curr) {
	//cout << a[index] << ' ' << curr << ' ' << len << endl;
	if(index == end) {
		if(a[index] > curr) {
			//cout << "a[index] > curr\n";
			//curr = a[index];
			//cout << a[index] << ' ' << curr << ' ' << len+1 << endl;
			return len+1;
		}
		else {
			//cout << "a[index] <= curr\n";
			//cout << a[index] << ' ' << curr << ' ' << len+1 << endl;
			return len;
		}
	}
	if(a[index] > curr)
		return max(solve(a, index+1, end, len+1, a[index]), solve(a, index+1, end, len, curr));
	return solve(a, index+1, end, len, curr);

}

int main() {
	fastio;
	ll t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		vector<ll> a(n);
		input(a, n);
		ll ans = 1;
		for(ll i = 0; i < n-1; i++) {
			ll ret = solve(a, i+1, n-1, 1, a[i]);
			//cout << "i: " << i << " seed: " << a[i] << " val: " << ret << endl;
			ans = max(ans, ret);
		}
		//cout << "ans: ";
		cout << ans << endl;
	}

	return 0;
}
