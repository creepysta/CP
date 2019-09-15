#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int b, p, f;
		int h,c;
		int profit;
		cin >> b >> p >> f;
		cin >> h >> c;

		int max_pr = max(h, c);
		int min_pr = min(h, c);

		int imp = max_pr == h ? p : f;
		int nimp = max_pr == h ? f : p;
				
		bool eb = p*2 + f*2 <= b ? true : false;

		if(eb) {
			profit = h * p + c * f;
		} else {
			bool extra = imp < b / 2 ? true : false;
			if(extra) {
				profit = imp * max_pr ;
				b -= 2 * imp;
				b = nimp < b/2 ? nimp : b/2;
				profit += min_pr * b ;
			} else {
				profit = b/2 * max_pr;
			}
		}
		cout << profit << "\n";
	}
	
	return 0;
}
