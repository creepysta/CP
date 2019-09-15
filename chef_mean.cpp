/*
 * 
 * https://www.codechef.com/JULY19B/problems/CHFM
 */

#include <bits/stdc++.h>
using namespace std;

int main() {

	long t;
	cin >> t;
	while(t--) {
		long n;
		cin >> n;
		vector<long> v(n);
		double avg = 0;
		double sum = 0;
		for(long i =0;i < n; i++) {
			cin >> v[i];
			sum += v[i];
		}
		avg = (sum / (double)n);
		if((long) avg != avg) {
			cout << "Impossible\n";
		}else {
			auto it = find(v.begin(), v.end(), (long)avg);
			if(it != v.end()) {
				long dist = it - v.begin();
				cout << dist + 1 << "\n";
			} else {
				cout << "Impossible\n";
			}
		}
	}

	return 0;
}
