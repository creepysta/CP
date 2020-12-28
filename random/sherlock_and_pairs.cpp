#include <bits/stdc++.h>
using namespace std;

long fact(int n) {
	if(n==0 || n == 1) {
		return 1;
	}
	long ans = 1;
	while(n) {
		ans *= n--;
	}
	return ans;
}

long npr(int n, int r) {
	if(n == 0 || n==1) {
		return 0;
	}
	return fact(n) / fact(n - r);
}

int main() {
    int t;
    cin >> t;
    while(t --) {
        int n, ans = 0;
        cin >> n;
        vector<int> a(n);
        //for(int i = 0; i < n ;i++) {
			//int temp;
			//cin >> temp;
			//if(find(a.begin(), a.end(), temp) != a.end()) {
				//count += 1;
			//} else {
				//a.push_back(temp);
			//}
        //}
        for(int &i : a) {
			cin >> i;
		}
        vector<int> temp = a;
        sort(temp.begin(), temp.end());
        auto it = unique(temp.begin(), temp.end());
        temp.resize(distance(temp.begin(), it));
        vector<int> pairs(temp.size());
        //sort(a.begin(), a.end());
        for(int i = 0; i < (int) temp.size(); i++) {
			pairs[i] = count(a.begin(), a.end(), temp[i]);
		}
		for(int i = 0; i < (int) pairs.size(); i++) {
			ans += npr(pairs[i], 2);
		}	
        cout << ans << '\n';
    }

    return 0;
}
