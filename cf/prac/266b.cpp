#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, t;
	cin >> n >> t;
	string s;
	cin >> s;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'B') {
			int j = i, tt = t;
			while(tt-- && j+1 < n) {
				swap(s[j], s[j+1]);
				j++;
			}
		}
	}
	cout << s << endl;
	return 0;
}
