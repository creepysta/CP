#include <bits/stdc++.h>
using namespace std;

double modpow(double a, int n) {
    double res = 1.0;
    while(n) {
        if(n & 1) res *= a;
        a *= a;
        n /= 2;
    }
    return res;
}

double nthRoot(double x, int n) {
    double l = 0, h = x;
    double eps = 1e-3;
    double m = 0.0;
    if(n == 0) return 1.;
    else if(n == 1) return x;
    while(1) {
        m = l + (h-l)/2;
        double p = modpow(m, n);
        double got = abs(p - x);
        if(got <= eps) break;
        if(p > x)
            h = m;
        else
            l = m;
    }
    return m;
}

int main() {
    //vector<int> a {2, 3, 5, 43, 344};
    //for(int i : a)
        //cout << i << ' ';
    //cout << endl;
    //int x;
    //while(cin >> x) {
        //cout << (lower_bound(begin(a), end(a), x)-begin(a)) << endl;
    //}
    mt19937 rng(3);
    int n;
    double x = rng() % 1000;
    x = (1LL << 62) -1;
    cout << x << endl;
    cout << setprecision(12) << fixed;
    //doesn't work with 1/3 root
    while(cin >> n) {
        cout << nthRoot(x, n) << " ";
        double pow = nthRoot(x, n);
        pow = modpow(pow, n);
        cout << pow << endl;
    }
	return 0;
}
