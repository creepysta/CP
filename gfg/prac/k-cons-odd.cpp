#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n, k;
	    cin >> n >> k;
	    bool got = 0;
	    vector<int> a(n);
	    for(int &i : a)
	    cin >> i;
	    sort(begin(a), end(a));
	    for(int i = 0, j = i+1; i < n ; i++) {
	        if(a[i] % 2 == 0) {
                i ++;
                continue;
	        }
	        j = i;
            while(a[j] % 2) {
                j++;
                if(j - i+1 >= k)
                    got = 1;
            }
	    }
	    if(!got)
           cout << "no\n";
        else
           cout << "yes\n";
	}
	return 0;
}
