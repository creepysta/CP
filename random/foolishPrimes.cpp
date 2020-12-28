/*
 * https://www.hackerrank.com/contests/projecteuler/challenges/euler239/problem
*/

#include <bits/stdc++.h>
using namespace std;

#define ll unsigned int
const auto N = 1000000123;

ll fact(ll n) {
    while(n > 0) {
        n *= n--;
        n %= N;
    }
    return n;
}

ll nCr(ll n, ll r) {
    ll maxden = max(n-r, r);
    ll minden = min(n-r, r);
    while(n > maxden) {
        n *= n--;
        n %= N;
    }
    n = n / fact(minden);
    return n % N;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<bool> p(n+1, 1);
    p[1] = 0;
    p[2] = 1;
    for(ll i = 2; i*i <= n; i++) {
        if(p[i]) {
            for(ll j = i * i; j <= n; j += i) {
                p[j] = 0;
            }
        }
    }
    ll c = 0;
    for(ll i = 2; i <= n; i++) {
        if(p[i])
            c++;
    }

    ll pp = nCr(c, k);
    ll tpp = pp;
    ll ans = 1;
    n -= 1;
    while(tpp--) {
        ans *= n--;
        ans %= N;
    }
    ans *= pp;
    n += 1;
    while(n > 0) {
        ans *= n--;
        ans %= N;
    }
    cout << ans << '\n';

    return 0;
}
