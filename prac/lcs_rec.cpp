#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF LLONG_MAX
#define MIN LLONG_MIN
#define MOD 1000000007
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
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

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

ll solve(string &s1, string &s2, ll n1, ll n2, ll len) {
	if(!n1 | !n2) {
		return len;
	}
	if(s1[n1] == s2[n2]) return solve(s1, s2, n1-1, n2-1,len+1);
	else return max(solve(s1,s2,n1-1,n2,len), solve(s1,s2,n1,n2-1,len));
}

int main() {
	//fastio;
	ll t;
	cin >> t;
	while(t--) {
		string s1, s2;
		cin >> s1 >> s2;
		ll n1 = s1.size();
		ll n2 = s2.size();
		ll ans = solve(s1, s2, n1-1, n2-1, 0);
		cout << ans << endl;
	}

	return 0;
}
