#include <bits/stdc++.h>
using namespace std;

struct findelem {
  char _c;
  findelem(char c) : _c(c) {}
  bool operator () (pair<char, int> &p) {
    return p.first == _c;
  }
};

bool sortelem(pair<char, int> &p, pair<char, int> &q) {
  return p.second > q.second;
}

int main() {
  string s;
  cin >> s;
  vector<pair<char, int>> p = {make_pair(s.at(0), 1)};
  
  if(s.size() == 1) {
    cout << "YES";
    return 0;
  }
  for(int i = 1; i < s.size(); i++) {
    auto it = find_if(p.begin(), p.end(), findelem(s.at(i)));
    if(it != p.end()) {
      int dist = distance(p.begin(), it);
      p[dist].second += 1;
    } else {
      p.push_back(make_pair(s.at(i), 1));
    }
  }
  sort(p.begin(), p.end(), sortelem);
  // for(int i = 0; i < p.size(); i++) {
  //   cout << p[i].first << " " << p[i].second << endl;
  // }
  int count = 0, f = 0, i = 0;
  for(i = 0; i < p.size()- 1; i++) {
    if(p[i].second == p[i+1].second) {
      while(i < p.size()-1 && p[i].second == p[i+1].second) {i++;}
      f += 1;
      i -= 1;
    } else if(abs(p[i].second-p[i+1].second) == 1) {
      count += 1;
    } else {
      cout << "NO";
      return 0;
    }
  }
  // cout << count << " " << f;
  if(count <= 1 && f == 1) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
