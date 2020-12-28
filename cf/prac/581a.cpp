#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int rem = (max(a, b) - min(a, b)) / 2;
	cout << min(a,b) << ' ' << rem;
}
