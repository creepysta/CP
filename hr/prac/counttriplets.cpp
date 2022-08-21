/*
	author: Creepysta
	26-11-2020 11:38:09
*/
#include <bits/stdc++.h>

using namespace std;

// Complete the countTriplets function below.
long countTriplets(const vector<long> &a, long r) {
    int n = a.size();
    long ans = 0;
    function<bool(long a, long b, long c)> fn = [&](long a, long b, long c) {
        return a * r == b && b * r == c;
    };
    // O (N*N*N)
    // for(int i = 0; i < n-2; i++) {
    //     for (int j = i+1; j < n-1; j++) {
    //         for(int k = j+2; k < n; k++) {
    //             if(fn(a[i], a[j], a[k])) {
    //                 ans ++;
    //             }
    //         }
    //     }
    // }
    auto lb = [&](int s, int e, long x) {
        int l = s, h = e-1;
        int pos = -1;
        while(l <= h) {
            int m = l + (h-l)/2;
            if(a[m] == x) {
                pos = m;
                h = m-1;
            } else if (a[m] < x) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return pos;
    };
    auto ub = [&](int s, int e, long x) {
        int n = a.size();
        int l = s, h = e-1;
        int pos = -1;
        while(l <= h) {
            int m = l + (h-l)/2;
            if(a[m] == x) {
                pos = m;
                l = m+1;
            } else if (a[m] > x) {
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return pos;
    };
    // O(N*N*log(N))
    // for(int i = 0; i < n-2; i++) {
    //     for(int j = i+1; j < n-1; j++) {
    //         if(a[i] * r == a[j]) {
    //             long x = a[j] * r;
    //             int l = lb(j+1, n, x);
    //             int r = ub(j+1, n, x);
    //             cerr << i << " " << j << " " << x << " " << l << " " << r << endl;
    //             if(l == -1) continue;
    //             ans += r == -1 ? 1 : r-l+1;
    //         } else if (a[i] * r < a[j]) break;
    //     }
    // }
    // O(N*LOG(N))
    long ratio = r;
    for(int i = 0; i < n-2; i++) {
        long x = a[i] * ratio;
        int l = lb(i+1, n-1, x);
        int r = ub(i+1, n-1, x);
        // cerr << "finding j: " << i << " " << i << " " << x << " " << l << " " << r << endl;
        if (l == -1) continue;
        int j = r;
        int prev = r-l+1;
        x = a[j] * ratio;
        l = lb(j+1, n, x);
        r = ub(j+1, n, x);
        cerr << j << " " << a[j] << " " << r << endl;
        cerr << "finding k: " << i << " " << j << " " << x << " " << l << " " << r << endl;
        if(l == -1) continue;
        int now = r-l+1;
        ans += now * prev;
        cerr << now << " " << prev << " " << ans << endl;
    }
    return ans;
}

int main() {
    int n;
    long r;
    cin >> n >> r;
    vector<long> a(n);
    for(long &i : a)
        cin >> i;
    long ans = countTriplets(a, r);
    cout << ans << '\n';
    return 0;
}
