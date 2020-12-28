//https://app.codility.com/cert/view/certMJ93PA-DVBFCJTJG9CXNYZZ/
//https://app.codility.com/cert/view/cert2PQR4C-XHJBF46QM9WY7K6W/ 
#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int solution(vector<int> &juice, vector<int> &capacity) {
    // write your code in C++14 (g++ 6.2.0)
    int n = juice.size();
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        a[i] = {juice[i], capacity[i]};
    }
    sort(a.begin(), a.end());
    vector<int> rem(n);
    for(int i = 0; i < n; i++) {
        rem[i] = a[i].second - a[i].first;
    }
    vector<ll> prep(n);
    prep[0] = a[0].first;
    for(int i = 1; i < n; i++) {
        prep[i] = prep[i-1] + a[i].first;
    }
    /*for(auto i : prep)
        cout << i << ' ';
    cout << endl;
    for(auto i : a)
        cout << i.first << ' ';
    cout << endl;
    for(auto i : rem)
        cout << i << ' ';
    cout << endl;*/
    auto search = [&](ll val, ll ded, int l, int r) {
        int index = -1;
        if(l >= n || r < 0)
            return index;
        while(l <= r) {
            int mid = (l + r) / 2;
			int sub = ded == -1 ? 0 : prep[ded];
            ll look = prep[mid] - sub; //a[ded].first;
            if(look <= val) {
                index = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return index;
    };
    int ans = 1;
    for(int i = 0; i < n; i++) {
        int left = search(rem[i], -1, 0, i-1);
        if(left != -1) {
            rem[i] -= prep[left];
        }
        left = left == -1 ? 0 : left + 1;
        int right = search(rem[i], i, i+1, n-1);
        right = max(0, right - i);
        int now = left + right + 1;
        // cout << left << ' ' << right << ' ' << now << endl;
        ans = max(ans, now);
    }
    return ans;
}


int main() {
	vector<vector<vector<int>>> a = {
		{ {10, 2, 1, 1}, {10, 3, 2, 2} },
		{ {1, 2, 3, 4}, {3, 6, 4, 4}},
		{{2, 3}, {3, 4}},
		{{1, 1, 5}, {6, 5, 8}}
	};
	for(auto aa : a) {
		int ans = solution(aa[0], aa[1]);
		cout << ans << endl;
	}
}

