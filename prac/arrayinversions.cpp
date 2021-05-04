#include <bits/stdc++.h>
using namespace std;

long long merge(long long a[], long long l, long long m, long long r) {
	long long i = l, j = m, k = 0;
	long long rev = 0;
	long long b[r-l+1];
	while(i < m && j < r) {
	//while(i < m && j <= r) {
		if(a[i] <= a[j]) {
			b[k++] = a[i++];
		} else {
			b[k++] = a[j++];
			rev += m-i;
		}
	}
	while(i < m)
		b[k++] = a[i++];
	while(j < r)
	//while(j <= r)
		b[k++] = a[j++];
	for(i = l, k = 0; i < r; i++, k++)
	//for(i = l, k = 0; i <= r; i++, k++)
		a[i] = b[k];
	return rev;
}

long long ms(long long a[], long long l, long long r) {
	long long m = (l + r) / 2;
	long long rev = 0;
	if(l < r-1) {
	//if(l < r) {
		rev += ms(a,l,m);
		rev += ms(a, m, r);
		rev += merge(a, l, m, r);
		//rev += ms(a, m+1, r);
		//rev += merge(a, l, m+1, r);
	}
	return rev;
}

long long inversionCount(long long arr[], long long N) {
	// Your Code Here
	return ms(arr, 0, N);
	//return ms(arr, 0, N-1);
}

void solve() {
	long n;
	cin >> n;
	long long a[n];
	for(long long i = 0; i < n; i++)
		cin >> a[i];
	long long ans = inversionCount(a, n);
	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}



