#include <bits/stdc++.h>
using namespace std;

#define ui unsigned int
#define ll long long

//using prefix array sum
//

long maximumSum(vector<long> &a, long m) {
  long ans = LONG_MIN;
  pair<long, int> ar[a.size()];
  for(int i = 0; i < a.size(); i++) {
    ar[i].first = a[i];
    ar[i].second = i + 1;
  }
  ar[0].first %= m;
  long maxelem = LONG_MIN;
  for(int i = 1; i < a.size(); i++) {
    ar[i].first = (ar[i].first % m + ar[i - 1].first % m) % m;
    maxelem = max(maxelem, ar[i].first);
  }
  sort(ar, ar + a.size());
  long minelem = LONG_MAX;
  for(int i = 0; i < a.size() - 1; i ++) {
    if(ar[i].second > ar[i+1].second) {
      minelem = min(minelem, ar[i+1].first - ar[i].first);
    }
  }
  ans = max(maxelem, m - minelem);
  return ans;
}

int main() {
  long q;
  cin >> q;
  while(q--) {
    long n;
    long m;
    cin >> n;
    cin >> m;
    vector<long> a(n);
    for(int i = 0; i < n ; i++) {
      cin >> a[i];
    }
    long result = maximumSum(a, m);
    cout << result << endl;
  }
  return 0;
}
