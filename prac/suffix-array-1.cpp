#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

string fetch(string ss, int s, int e) {
	int n = ss.length();
	string ans = "";
	int i = s;
	while(i != e) {
		ans += ss[i];
		i = (i+1)%n;
	}
	return ans;
}

// ababba
/*
   s = ababba$
   $
   a
   a
   a
   b
   b
   b


 */

int main() {
	string s;
	cin >> s;
	s+='$';
	int n = s.length();
	pair<string, int> indices[n];
	for(int i = 0; i< n; i++)
		indices[i] = make_pair(string(1, s[i]), i);
	int p[n], c[n];
	{
		// k = 0
		pair<char, int> a[n];
		for(int i = 0; i < n; i++)
			a[i] = make_pair(s[i], i);
		sort(a, a+n);
		for(int i = 0; i < n; i++)
			p[i] = a[i].second;
		c[p[0]] = 0;
		for(int i = 1; i < n; i++) {
			if(a[i].first != a[i-1].first)
				c[p[i]] = c[p[i-1]] + 1;
			else
				c[p[i]] = c[p[i-1]];
		}
	}
	// k = 1 onwards
	int k = 0;
	while((1<<k) < n) {
		pair<pair<int, int>, int> a[n];
		for(int i = 0; i < n; i++)
			a[i] = make_pair(make_pair(c[i], c[(i + (1<<k)) %n]), i);
		sort(a, a+n);
		for(int i = 0; i < n; i++)
			p[i] = a[i].second;
		c[p[0]] = 0;
		for(int i = 1; i < n; i++) {
			if(a[i].first != a[i-1].first)
				c[p[i]] = c[p[i-1]] + 1;
			else
				c[p[i]] = c[p[i-1]];
		}
		k++;
	}
	for(int pp : p) {
		//cout << pp << ' ' << s.substr(pp, n-pp) << "\n";
		cout << pp << ' ';
	}
	return 0;
}
