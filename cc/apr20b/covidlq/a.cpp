#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		bool in, flag=true;
		ll czero=0, cone = 0;
		while(n--) {
			cin >> in;
			if(!in && cone) {
				czero ++;
			} else {
				if(cone && czero <5)
					flag = false;
				if(in) cone++;
				czero = 0;
			}
			//cout << cone << " " << czero << " " << flag << " for " << in << endl; 
		}
		if(flag || cone == 1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
			
	return 0;
}
