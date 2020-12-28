#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ff first
#define ss second
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

int dp[10001][10001];

void input(vector<ll> &a, ll n) {
	for(ll &i : a) cin >> i;
}

void input1(vector<ll> &a, ll n) {
	for(ll i = 1; i <= n; i++) cin >> a[i];
}

// array:   4 1 2 5 3 6
// indices: 0 1 2 3 4 5
// pivot: a[0] = 4
// i: 1 2 3
// j: 5 4
ll hoare_partition(vector<ll> &a, ll l, ll h) {
	ll pivot = a[l];
	ll i = l-1, j = h+1;
	while(true) {
		do
			i++;
		while(a[i] < pivot);
		do
			j--;
		while(a[j] > pivot);
		if(i >= j)
			return j;
		swap(a[i], a[j]);
	}
}

void quicksort_hoare(vector<ll> &a, ll l, ll h) {
	ll p;
	if(l < h) {
		p = hoare_partition(a, l, h);
		quicksort_hoare(a, l, p);
		quicksort_hoare(a, p+1, h);
	}
}

ll lomuto_partition(vector<ll> &a, ll l, ll h) {
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

void quicksort_lomuto(vector<ll> &a, ll l, ll h) {
	ll p;
	if(l < h) {
		p = lomuto_partition(a, l, h);
		quicksort_lomuto(a, l, p-1);
		quicksort_lomuto(a, p+1, h);
	}
}

int main() {
	fastio;
	ll t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		vector<ll> a(n), b;
		input(a, n);
		b = a;
		quicksort_lomuto(a, 0, n-1);
		quicksort_hoare(b, 0, n-1);
		for(ll i : a) cout << i << ' ';
		cout << endl;
		for(ll i : b) cout << i << ' ';
		cout << endl;
	}

	return 0;
}
