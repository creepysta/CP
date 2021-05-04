#include <bits/stdc++.h>
using namespace std;

struct S {
	int i, j;
	S(int _i, int _j) : i(_i), j(_j) {};
	const bool operator<(const S& s) const {
		return make_pair(i, j) < make_pair(s.i, s.j);
	}
	friend ostream& operator<<(ostream& ost, const S &s) {
		ost << "[" << s.i << ' ' << s.j << "]";
		return ost;
	}
};

int main() {
	set<S> s;
	vector<int> ans;
	int n = 10;
	for(int i = 0; i < n; i++) {
		int x = rand()%100, y = rand()%100;
		s.insert(S(x,y));
	}
	for(int i = 0; i < 5; i++) {
		auto it = s.begin();
		S ss = *it;
		//s.erase(it); // doesn't work prolly coz the iterator points at null
		ans.push_back(ss.i);
		s.erase(it);
	}
	for(auto &e : ans)
		cout << e << ' ';
	cout << endl;
	return 0;
}
