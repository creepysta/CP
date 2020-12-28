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

//int dp[10001][10001];

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
		ll n;
		cin >> n;
		vector<ll> a(n), ans(n);
		input(a, n);
		ll i = -1, neg=0, pos=0;
		for(ll j : a) {
			if(j<0) neg ++;
			else pos ++;
		}
		//if(abs(pos-neg) > 1) {
			//cout << "not possible\n";
			//continue;
		//}
		bool op=false, ep=false;
		if(neg > pos) {
			i = 1;op=ep=0;
			cout << "neg > pos\n";
			for(ll j=0; i < n && j < n;) {
				if(pos && neg) {
					if(!ep && a[j] < 0) {
						j+=2;
						neg--;
					} else {
						ep = 1;
					}
					if(!op && a[i] > 0) {
						i+=2;
						pos++;
					} else {
						op = 1;
					}
					if(op && ep) {
						swap(a[i], a[j]);
						op = ep = 0;
						j+=2;
						i+=2;
					}
				}
			}
		}
		else {
			i = 1; op=ep=0;
			cout << "neg <= pos\n";
			for(ll j=0; i < n && j < n;) {
				if(pos && neg) {
					if(!ep && a[j] < 0) {
						j+=2;
						neg--;
					} else {
						ep = 1;
					}
					if(!op && a[i] > 0) {
						i+=2;
						pos++;
					} else {
						op = 1;
					}
					if(op && ep) {
						swap(a[i], a[j]);
						op = ep = 0;
						j+=2;
						i+=2;
					}
				}
			}
		}
		for(ll val : a) cout << val << " ";
		cout << endl;
	}

	return 0;
}
