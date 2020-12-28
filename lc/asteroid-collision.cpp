#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& a) {
    int n = a.size();
    //for(int i = 0, j = 1; i < n || j < n;) {
        //if((a[i] < 0 && a[j] >0) || (a[i] > 0 && a[j] < 0)) {
            //if(abs(a[i]) > abs(a[j])) {
                //a[j] = 0;
                //j += j < n-1 ? 1 : 0;
            //} else if(abs(a[i]) < abs(a[j])) {
                //a[i] = 0;
                //i += i < n-1 ? 1 : 0;
                //if(i==j)
                    //j += j < n-1 ? 1 : 0;
            //} else {
                //i += i < n-1 ? 1 : 0;
                //j += j < n-1 ? 1 : 0;
            //}
        //}
        //if(i == n-1 || j == n-1) break;
    //}
    //for(int i = 0; i < n; i++) {
		//if(a[i]) {
			//if(i+1 < n && a[i] * a[i+1] < 0) {
				//if(abs(a[i]) < abs(a[i+1])) a[i] = 0;
				//else if(abs(a[i]) > abs(a[i+1])) a[i+1] = 0;
				//else a[i] = a[i+1] = 0;
			//}
		//}
	//}
	for(int i = 0; i < n; i++) {
		if((a[i] < 0 && a[j] >0) || (a[i] > 0 && a[j] < 0)) {
            if(abs(a[i]) > abs(a[j])) {
				a.erase(a.begin() + j);
                //j += j < n-1 ? 1 : 0;
            } else if(abs(a[i]) < abs(a[j])) {
				a.erase(a.begin() + i);
                //i += i < n-1 ? 1 : 0;
                if(i==j)
                    j += j < n-1 ? 1 : 0;
            } else {
                i += i < n-1 ? 1 : 0;
                j += j < n-1 ? 1 : 0;
            }
        }
        if(i == n-1 || j == n-1) break;
	}
    vector<int> ans;
    for(int i = 0; i < n; i++) if(a[i]) ans.push_back(a[i]);
    return ans;
}

int main() {
	//vector<int> a = {10,2,-5};
	vector<int> a = {5,10,-5};
	//vector<int> a = {5,-5};

	auto ans = asteroidCollision(a);
	for(int i : ans) cout << i << ' ';
	return 0;
}
