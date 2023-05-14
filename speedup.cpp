#include <bits/stdc++.h>
#include <vector>


const int MOD = 1e9 + 7;

double babylonRoot(int num) {
    double x = num;
    double y = 1;
    double eps = 1e-9;
    while(x - y > eps) {
        x = (x+y)/2;
        y = num / x;
    }
    return x;
}

int binarySearchRoot(int num) {
    int low = 0, high = num, ans;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(mid * mid == num)
            return mid;
        else if(mid * mid < num) {
            ans = mid;
            low = mid+1;
        } else
            high = mid-1;
    }
    return ans;
}

double modpow(double a, int n) {
    double res = 1.0;
    while(n) {
        if(n & 1) res *= a;
        a *= a;
        n /= 2;
    }
    return res;
}

double nthRoot(int x, int n) {
    double l = 0, h = x;
    double eps = 1e-3;
    double mid = 0.0;
    while(1) {
        mid = l + (h-l)/2;
        double p = modpow(mid, n);
        double got = std::abs(p - x);
        if(got < eps) break;
        if(p > x)
            h = mid;
        else
            l = mid;
    }
    return mid;
}

int modpow(int a, int b, int mod) {
    int res = 1ll;
    while(b) {
        if(b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int gcd(int a, int b) {
    while(b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int fgcd(int a, int b) {
    if(!a || !b)
        return a | b;
    unsigned shift = __builtin_ctzll(a | b);
    a >>= __builtin_ctzll(a);
    do {
        b >>= __builtin_ctzll(b);
        if(a > b)
            std::swap(a, b);
        b -= a;
    } while (b);
    return  a << shift;
}

int extgcd(int a, int b, int &x, int &y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while(b1) {
        int q = a1 / b1;
        std::tie(x, x1) = std::make_tuple(x1, x - q * x1);
        std::tie(y, y1) = std::make_tuple(y1, y - q * y1);
        std::tie(a1, b1) = std::make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

std::vector<int> invs(const std::vector<int> &a, int m) {
    int n = a.size();
    if (n == 0) return {};
    std::vector<int> b(n);
    int v = 1;
    for (int i = 0; i != n; ++i) {
        b[i] = v;
        v = static_cast<long long>(v) * a[i] % m;
    }
    int x, y;
    extgcd(v, m, x, y);
    x = (x % m + m) % m;
    for (int i = n - 1; i >= 0; --i) {
        b[i] = static_cast<long long>(x) * b[i] % m;
        x = static_cast<long long>(x) * a[i] % m;
    }
    return b;
}

