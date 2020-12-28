#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int zeros = -1, ones = n;
		while(zeros+1 < n && s[zeros+1] != '1') zeros ++;
		while(ones-1 >= 0 && s[ones-1] != '0') ones --;
		//cout << zeros << ' ' << ones << endl;
		if(ones-zeros == 1) cout << s << endl;
		else {
			string ans = "";
			if(zeros >= 0)
				for(int i = 0; i <= zeros; i++) ans+='0';
			ans+='0';
			if(ones < n)
				for(int i = ones; i < n; i++) ans+='1';
			cout << ans << endl;
		}
	}
	return 0;
}
