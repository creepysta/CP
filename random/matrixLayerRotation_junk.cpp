#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll m, n, r;
	cin >> m >> n >> r; 
	vector<vector<ll>> matrix(m);
	for(ll i = 0; i < m; i++) {
		matrix[i] = vector<ll>(n);
		for(ll j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	vector<ll> f(n*m , 0);
	ll c = 0;
	ll rings = min(m,n) / 2;
	for(ll i = 0; i < rings; i++) {
		for(ll j = i; j < n - i; j++) {
			f[c++] = matrix[i][j];
		}
		for(ll j = i+1; j < m - i ; j++) {
			f[c++] = matrix[j][n-i-1];
		}
		for(ll j = n-i-2; j >= i; j--) {
			f[c++] = matrix[m-i-1][j];
		}
		for(ll j = m-i-2; j > i; j--) {
			f[c++] = matrix[j][i];
		}
	}

	vector<ll> ans(n*m, 0);

	for(ll i = 0; ;) {
		ll st = m*n - (m-2)*(n-2);
		for(ll j=0; j < st; j++) {
			ans[i+j] = f[i+(j+r)%st];
		}
		if(m == 0 || n ==0) { 
			break;
		}
		i += m*n - (m-2)*(n-2);
		m -= 2; n -= 2;
	}


	c = 0, m = matrix.size(), n = matrix[0].size();

	for(ll i = 0; i < rings; i++) {
		for(ll j = i; j < n - i; j++) {
			matrix[i][j] = ans[c++];
		}
		for(ll j = i+1; j < m - i ; j++) {
			matrix[j][n-i-1] = ans[c++];
		}
		for(ll j = n-i-2; j >= i; j--) {
			matrix[m-i-1][j] = ans[c++];
		}
		for(ll j = m-i-2; j > i; j--) {
			matrix[j][i] = ans[c++];
		}
	}

	c = 0;
	for(ll i = 0; i < m; i++) {
		for(ll j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
			c++;
		}
		cout << '\n';
	}

	return 0;
}
