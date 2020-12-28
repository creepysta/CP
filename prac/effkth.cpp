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

// this is nothn but shit !
ll partition(vector<ll> &a, ll l, ll h) {
	ll pivot = a[l];
	ll i = l, j = h+1;
	do {
		do i++; while(i <= h && a[i] < pivot);
		do j--; while(a[j] > pivot);
		if(i<j) swap(a[i], a[j]);
	} while(i < j);
	swap(a[l],a[j]);
	return j;
}

// the cool kid
ll lomutos_partition(vector<ll> &a, ll l, ll h) {
	ll i = l-1;
	ll pivot = a[h];
	for(ll j = l; j <h; j++) {
		if(a[j] <= pivot) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i+1], a[h]);
	return i+1;
}

ll quicksort(vector<ll> &a, ll l, ll h, ll k) {
	ll p = l;
	if(l<h) {
		p = lomutos_partition(a, l, h);
		//p = partition(a, l, h);
		cout << 'p' << p << " k" << k << endl;
		if(k == p)
			return a[k];
		if (k < p)
			quicksort(a, l, p-1, k);
		else
			quicksort(a, p+1, h, k);
	}
	return a[k];
}

int main() {
	//fastio;
	ll t;
	cin >> t;
	while(t--) {
		ll n, k;
		cin >> n >> k;
		vector<ll> a(n);
		input(a, n);
		ll kthbig = quicksort(a, 0, n-1, n-k);
		cout << "kth big: " << kthbig << endl;
	}

	return 0;
}
