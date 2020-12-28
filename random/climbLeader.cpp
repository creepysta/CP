
//https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n, m;
  cin >> n;
  vector<ll> scores(n), rank(n,1);
  for(ll i = 0; i < n; i++) {
    cin >> scores[i];
    if(i > 0) {
      if(scores[i] != scores[i-1])
        rank[i] = rank[i-1] + 1;
      else
        rank[i] = rank[i-1];
    }
  }
  cin >> m;
  vector<ll> alice(m);
  for(ll &i : alice) {
    cin >> i;
  }
  sort(alice.begin(), alice.end(), [](ll a, ll b){return a> b;});
  ll i = 0, j = 0;
  vector<ll> stand;
  while(i < n && j < m) {
    if(scores[i] <= alice[j]) { // >
      stand.push_back(rank[i]);
      j++;
    }
    else {
      i++;
    }
  }
  ll stnd = rank.back() + 1;
  while(j < m) {
    stand.push_back(stnd);
    j++;
  }
  for(i = m-1; i >= 0; i--) {
    cout << stand[i] << endl;
  }
}
