#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k, m, t;
	cin >> n >> k >> m >> t;

	while(t--) {
		int z, i;
		cin >> z >> i;
		if(z) {
			if(n < m) {
				n += 1;
				if(i <= k) {
					k += 1;
				}
			}
		} else {
			if(i <= k) {
				n = n - i;
				k = k - i;
			} else {
				n = i;
			}
		}
		cout << n << " " << k << endl;
	}


	return 0;
}
