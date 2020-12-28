#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main() {
	ll t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		vector<ll> arr(n);
		//cout << "input" << endl;
		for(ll &i : arr) {
			cin >> i;
			//cout << i << " ";
		}
		//cout << endl;
		bool turn = 1;
		ll a = 0, b = n-1;
		ll alice = 0, bob= 0;
		ll curr = 0, sum = 0;
		ll steps = 0;
		while (a <= b) {
			if(turn) {
				//cout << "alice " << arr[a] << endl;
				sum += arr[a++];
			} else {
				//cout << "bob " << arr[b] << endl;
				sum += arr[b--];
			}
			if(sum > curr) {
				if(turn) alice += sum;
				else bob += sum;
				turn = !turn;
				curr = sum;
				steps ++;
				sum = 0;
			} else if(sum <= curr && a>=b) {
				//cout << "remaining";
				if(turn) {
					if(a==b)
						alice += sum + arr[a];
					else
						alice += arr[a-1];
					//cout << " alice " << sum << " " << arr[a] << endl;
				} else {
					if(a==b)
						bob += sum + arr[b];
					else
						bob += arr[b+1];
					//cout << " bob " <<  sum << " " << arr[a] << endl;
				}
				steps ++;
				break;
			}
		}
		cout << steps << " " << alice << " " << bob << endl;
		//cout << endl;

	}

	return 0;
}
