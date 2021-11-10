#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    deque<int> q;
	    for(int i = 0; i < n; i++) {
	        q.push_back(i+1);
	    }
	    while(q.size() > 1) {
	        int val = q.front();
	        q.pop_front();
	        q.push_back(val);
	        q.pop_front();
	    }
	    //while(q.size()) {
	        //cout << q.front() << ' ';
	        //q.pop_front();
	    //}
	    cout << q.front() << '\n';
        //cout << endl;
	}
	return 0;
}
