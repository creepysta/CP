#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> l(n);
  for(ll i = 0; i < n; i++) {
    l[i] = vector<ll>(2);
    cin >> l[i][0] >> l[i][1];
  }
  
  sort(l.begin(), l.end(), [](vector<ll> a, vector<ll> b){return a[1] < b[1];});
  sort(l.begin(), l.end(), [](vector<ll> a, vector<ll> b){return a[0] > b[0] && (a[1] && b[1]);});
  for(ll i = 0; i < n; i++) {
    cout << l[i][0] << ' '<< l[i][1] << endl;
  }
  cout << endl;

  ll luck = 0;
  for(ll i = 0; i < n; i++) {
    if(l[i][1] && k >= 0) {
      k -= 1;
    }
    if(l[i][1] && k==-1){
      // cout << "         " << l[i][0];
      luck -= l[i][0];
      continue;
    }
    luck += l[i][0];
  }
  cout << luck;
  return 0;
}
