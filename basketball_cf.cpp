#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int **h = new int*[n];
	for(int i = 0; i < 2; i++) {
		h[i] = new int[2];
		for(int j = 0; j<n;j++) {
			cin >> h[i][j];
		}
	}
	int c;
	int s1 = 0, s2 = 0, max = INT_MIN;
	s1 = h[0][0] > h[1][0] ? h[0][0] : h[1][0];
	s2 = s1;
	max = s1;
	c = s1 == h[0][0] ? 0 : 1;
	for(int i = 1; i < n; i++) {
		c = 1 -c;
		s1 += h[c][i];
		s2 += h[c][i+1];
		// max = s1 > s2 ? s1 : s2;
		 max = s1 > max ? s1 : max;
		// i += max == s2 ? 1 : 0;
	}

	cout << max << endl;

	return 0;
 }
