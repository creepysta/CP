#include <bits/stdc++.h>
using namespace std;


void rec(vector<int> a, int kth, int i, int &ans) {
    if(a.size() == 1) {
        ans = a[0];
        return;
    }
    int d_index = (i + kth) % a.size();
    a.erase(a.begin() + d_index);
    rec(a, kth, d_index, ans);
}

int iter(int n, int k) {
    int pos = -1;
    vector<bool> a(n, true);
    int kth = 0;
    int i = 0;
    int now_alive = 0;
    for(;;) {
        // check total alive now
        now_alive = 0;
        for(int ii=0; ii<n; ii++) now_alive += a[ii];
        // find kth alive to kill
        if(now_alive < 2) break;
        for(; ; i=(i+1)%n)
            if(a[i]) break;
        kth = 0;
        while (true) {
            i = (i + 1) % n;
            kth += a[i];
            if(kth == k) break;
        }
        a[i] = 0;
        i = (i + 1) % n;
    }
    for(int ii=0; ii<n; ii++)
        if (a[ii])
            pos = ii;
    return pos+1;
}

void test(char *argv[]) {
    mt19937 rng(stoi(argv[1]));
    for(int i = 0; i < 100; i++) {
        int n = rng() % 100;
        int k = 2+i;
        cout << n << ' ' << k;
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        int _iter = iter(n, k);
        int _rec = -1;
        rec(a, k, 0, _rec);
        assert(_iter == _rec);
        cout << ' ' << _iter << ' ' << _rec << '\n';
    }
}

void run() {
    int n = 40, k = 2;
    n = 73, k = 38;
    n = 60, k = 21;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    int _iter = iter(n, k);
    int _rec = -1;
    rec(a, k, 0, _rec);
    cout << _iter << ' ' << _rec;
}

int32_t main(int32_t argc, char *argv[]) {
    test(argv);
    //run();
    return 0;
}
