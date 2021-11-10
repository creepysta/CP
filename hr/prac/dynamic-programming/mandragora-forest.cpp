#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    ll a[n], sum = 0;
    for(ll i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    sort(a, a+n);
    ll p = sum, s = 1;
    for(ll i =0; i < n; i++) {
      s+= 1;
      sum -= a[i];
      p = max(p, s*sum);
    }
    cout << p << endl;
  }
}
