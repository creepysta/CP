#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int l, int m, int r) {
	int i = l, j = m, k = 0;
	vector<int> b(r-l+1);
	while(i < m && j < r) {
		if(a[i] <= a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while(i < m)
		b[k++] = a[i++];
	while(j < r)
		b[k++] = a[j++];
	for(i = l, k = 0; i < r; i++, k++)
		a[i] = b[k];
}

void ms(vector<int> &a, int l, int r) {
	if(l < r-1) {
		int m = (l+r)/2;
		ms(a, l, m);
		ms(a, m, r);
		merge(a, l, m, r);
	}
}

int main() {
	for(int tt = 1; tt <= 100000; tt++) {
		mt19937 rng(tt);
		int n = rng() % 10;
		while(n < 5)
			n = rng() % 10;
		vector<int> a(n);
		set<int> st;
		for(int i = 0; i < n; i++) {
			int x = rng() % 30;
			while(st.find(x) != st.end())
				x = rng() % 30;
			a[i] = x;
			st.insert(x);
		}
		shuffle(a.begin(), a.end(), rng);
		//for(int i : a)
			//cout << i << ' ';
		//cout << '\n';
		ms(a, 0, n);
		//for(int i : a)
			//cout << i << ' ';
		//cout << '\n';
		assert(is_sorted(a.begin(), a.end()));
	}
	return 0;
}
