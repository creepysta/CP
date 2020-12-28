#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define umapll unordered_map<long long int,long long int>
#define umapsl unordered_map<string,long long int>
#define pll pair<long long int,long long int>
#define psl pair<string,long long int>
#define pcl pair<char,long long int>
#define all(x) (x).begin(),(x).end()
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
		ll n;
		cin >> n;
		if(n==1) {
			cout << 1 << endl << 1 << " " << 1 << endl;
			continue;
		} else if(n==2) {
			cout << 1 << endl << 2 << " " << 1  << " " << 2 << endl;
			continue;
		}
		cout << n/2 << endl;
		cout << 3 << " " << 1 << " " << 2 << " " << 3 << endl;
		for(ll i = 4;i <= n; i+=2) {
			i+1 <= n ? cout << 2 << " " << i << ' ' << i + 1  : cout << 1 << " " << i;
			cout << endl;
		}
			
	}
	
	return 0;
}
