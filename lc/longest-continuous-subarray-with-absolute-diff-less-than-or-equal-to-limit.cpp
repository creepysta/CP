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
		vector<ll> a(n);
		input(a, n);
		ll small=-1, big=-1, c=0, ans=1; // smalli=0, bigi=0, start = 0;
		for(ll i = 0; i < n; i++) {
			if(small == -1 && big == -1) {
				if(i >= n-1) break;
				if(abs(a[i]-a[i+1]) <= k) {
					small = min(a[i], a[i+1]);
					big = max(a[i],a[i+1]);
					//bigi = smalli = i;
					//start = i;
					//cout << i << ' ' << i+1 << endl;
					//cout << a[i] << ' ' << a[i+1] << endl;
					i +=1;
					c = 2;
				}
			} else {
				if(a[i] >= big) {
					big = a[i];
					if(big - small <= k){
						c++;
						//bigi = i;
					} else {
						c = 0;
						while(i >=0 && big-a[i] <= k) i--;
						//i = smalli;
						//i = start;
						big = small = -1;
					}
				} else if(a[i] <= small) {
					small = a[i];
					if(big - small <= k){
						c++;
						//smalli = i;
					} else {
						c = 0;
						while(i >=0 && a[i]-small <= k) i--;
						//i = bigi;
						//i = start;
						big = small = -1;
					}
				} else {
                    c++;
                }
                //cout << smalli << " " << bigi << endl;
				//cout << "i: " << i << " a[i]: " << a[i] << endl;
			}
			ans = max(ans, c);
			//cout << small << " " << big << " " << bigi << " " << smalli << endl;
		}
		cout << ans << endl;
	}

	return 0;
}
