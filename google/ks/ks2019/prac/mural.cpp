#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t;
	cin >> t;
	ll tests = 1;
	while(tests <= t) { 
		ll n;
		cin >> n;
		string s;
		cin >> s;
		vector<ll> c(n);
		for(ll i = 0; i < n; i++) {
			c[i] = s.at(i) - 48;
		}
		ll sum = 0, maxSum = LLONG_MIN;
		for(ll i = 0; i < ceil(n/2.0); i++) {
			sum += c[i];
		}
		maxSum = max(maxSum, sum);
		ll prevSum = sum;
		cout << "initial sum: " << prevSum << endl;
		for(ll i = 1; i <= n/2; i++) {
			maxSum = max(sum, maxSum);
			cout << i << " : " << prevSum << " + " << c[ceil(n/2.0) + i - 1] << " - " << c[i-1] << "= ";
			sum = sum + c[ceil(n/2.0) + i - 1] - c[i-1];
			prevSum = sum;
			maxSum = max(sum, maxSum);
			cout << sum << endl;
		}
		// out << n << ": " << ceil(n/2.0) << endl;
		cout << "Case #" << tests << ": " << maxSum << endl;
		cout << endl;
		tests ++;
	}
	return 0;
}
