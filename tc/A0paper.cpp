#include<bits/stdc++.h>
using namespace std;

string canBuild (vector<int> &a) {
    int n = a.size();
    for (int i = n-1; i > 0 ; i--) {
        if(a[i] >= pow(2,i)) {
            return "Possible";
        } else {
            a[i-1] += a[i] /2;
        }
    }
		if(a[0] > 0)
			return "Possible";
		else
			return "Impossible";
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int &i : a) {
			cin >> i;
		}
		cout << canBuild(a) << endl;
	}
	return 0;
}
