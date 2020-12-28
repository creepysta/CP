#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF LLONG_MAX
#define MIN LLONG_MIN
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

int main() {
	fastio;
	ll t;
	cin >> t;
	while(t--) {
		ll n, k;
		cin >> n >> k;
		vector<ll> big(k+1,0), small(k+1,INF);
		for(ll i = 0; i < n; i++) {
			ll temp;
			cin >> temp;
			ll j = 1;
			// for kth largest
			while(j<=k && temp < big[j]) j++;
			ll m = k;
			while(m > j) {
				big[m] = big[m-1];
				m--;
			}
			big[j] = temp;
			j=1;
			// for kth smallest
			while(j<=k && temp > small[j]) j++;
			m = k;
			while(m > j) {
				small[m] = small[m-1];
				m--;
			}
			small[j] = temp;
			j=1;
		}
		cout << big[k] << " " << small[k] << endl;
	}

	return 0;
}
