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

int main() {
	fastio;
	ll t;
	cin >> t;
	while(t--) {
		ll n, m;
		cin >> n >> m;
		vector<ll> a(n), b(m), union_set, intersection_set;
		input(a, n);
		input(b, m);
		ll i=0, j=0;
		while(i < n && j < m) {
			if(a[i] == b[j]) {
				intersection_set.pb(a[i]);
				union_set.pb(a[i]);
				i++; j++;
			} else if(a[i] < b[j]) {
				union_set.pb(a[i]);
				i++;
			}
			else {
				union_set.pb(b[j]);
				j++;
			}
		}
		while(i < n) union_set.pb(a[i++]);
		while(j < m) union_set.pb(b[j++]);
		cout << "Union: ";
		for(ll ans : union_set) cout << ans << ' ';
		cout << "\nIntersection: ";
		for(ll ans : intersection_set) cout << ans << ' ';

	}

	return 0;
}
