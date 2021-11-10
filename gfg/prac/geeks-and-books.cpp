#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int k; cin >> k;
        stack<int> s;
	    while(k--) {
    	    string ss;
    	    int n;
    	    cin >> ss;
    	    if(ss == "place") {
                cin >> n;
                s.push(n);
            } else {
    	        if(s.empty())
    	        cout << -1 << ' ';
    	        else {
    	            cout << s.top();
    	            s.pop();
    	        }
    	    }
	    }
	    cout << '\n';
	}
	return 0;
}
