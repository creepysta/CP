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
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int dp[10001][10001];

void input(vector<ll> &a, ll n) {
	for(ll &i : a) cin >> i;
}

void input1(vector<ll> &a, ll n) {
	for(ll i = 1; i <= n; i++) cin >> a[i];
}

int main() {
	//fastio;
	ll t;
	cin >> t;
	ll tt = 1;
	while(tt <= t) {
		ll n, k;
		cin >> n >> k;
		vector<ll> a(n);
		unordered_set<ll> l;
		input(a, n);
		// O(n*2)
		// coule be made better
		cout << "case #" << tt << ":" << endl;
		for(ll i = 0; i < n; i++) {
			l.clear();
			for(ll j = i +1; j < n; j++) {
				if(l.empty() || l.find(a[j]) == l.end()) l.insert(k - a[i]- a[j]);
				else cout << a[i] << ' ' << k-a[i]-a[j] << ' ' << a[j] << endl;
			}
		}
		tt++;
	}

	return 0;
}