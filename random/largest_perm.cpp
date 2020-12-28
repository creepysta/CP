#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n); //, pos(n+1);
  unordered_map <ll, ll> pos;
  for(ll i=0 ;i < n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  for(ll i = 0; i < n; i++) {
    if(!k) break;
    if(a[i] == n-i) continue;
    pos[a[i]] = pos[n-i];
    a[pos[n-i]] = a[i];
    a[i] = n-i;
    k--;
  }

  for(ll i : a) {
    cout << i << " ";
  }

  return 0;
}
