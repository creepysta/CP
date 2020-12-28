#include <bits/stdc++.h>
#define endl '\n'

#define SZ(x) ((int)x.size())
#define ALL(V) V.begin(), V.end()
#define L_B lower_bound
#define U_B upper_bound
#define pb push_back

using namespace std;
template<class T, class T1> int chkmin(T &x, const T1 &y) { return x > y ? x = y, 1 : 0; }
template<class T, class T1> int chkmax(T &x, const T1 &y) { return x < y ? x = y, 1 : 0; }
const int MAXN = (1 << 20);

int n;

void read() {
	cin >> n;
}

void solve() {
	if(n == 1) {
		cout << 1 << endl;
		return;
	}

	if((n & -n) == n) {
		cout << -1 << endl;
	} else {
		cout << 2 << " " << 3 << " " << 1 << " ";
		for(int l = 2; (1 << l) <= n; l++) {
			cout << ((1 << l) ^ 1) << " " << (1 << l) << " ";
			for(int x = (1 << l); x <= min(n, (2 << l) - 1); x++) {
				if(x > 1 + (1 << l)) cout << x << " ";
			}
		}

		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;
	while(T--) {
		read();
		solve();
	}

	return 0;
}


