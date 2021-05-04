/*
	author: Creepysta
	20-04-2021 22:19:04
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9) + 7;
//#define int int64_t
#ifdef LOCAL
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << "debug: [ "; err(_it, args); }
#else
#define debug(args...) 0;
#endif
#define tmpt template < class T
#define ostop ostream& operator<<(ostream& o
#define itfr { if(x.empty()) return o;o << "[";for(auto e : x) o << e << ", "; o<<"\b\b]"; return o;}
void err(istream_iterator<string> it) { cerr << "\b\b ]\n";}
tmpt , class... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << ": " << a << ", "; err(++it, args...); }
tmpt > ostop , const vector<T> &x) itfr
tmpt > ostop , const set<T> &x) itfr
tmpt , class V> ostop , const map<T,V> &x) itfr
tmpt , class V> ostop , const pair<T,V> &p) { o << "(";o << p.first << ", " << p.second << ")"; return o;}

struct S {
	int start, time, i;
	S(const vector<int> &v, int _i) : start(v[0]), time(v[1]), i(_i) {};
	const bool operator<(const S& s) const {
		return make_pair(time, start) < make_pair(s.time, s.start);
	}
	friend ostream& operator<<(ostream& ost, const S &s) {
		ost << "[" << s.start << ' ' << s.time << ' ' << s.i << "]";
		return ost;
	}
};


typedef pair<int, int> T; // processing time, index
vector<int> getOrder(vector<vector<int>> tasks) {
	priority_queue<T, vector<T>, greater<>> pq;
	long N = tasks.size(), time = 0, i = 0;
	for (int i = 0; i < N; ++i) tasks[i].push_back(i);
	sort(tasks.begin(), tasks.end());
	vector<int> ans;
	while (i < N || pq.size()) {
		if (pq.empty()) { // if nothing in queue, update time to the next proc
			time = max(time, (long)tasks[i][0]);
		}
		while (i < N && time >= tasks[i][0]) { // all proc in queue where time < current time
			pq.emplace(tasks[i][1], tasks[i][2]);
			++i;
		}
		auto [pro, index] = pq.top();
		pq.pop();
		time += pro;
		ans.push_back(index);
	}
	return ans;
}

int32_t main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	int t = 1;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		vector<vector<vector<int>>> v = {{{1,2},{2,4},{3,2},{4,1}},
			{{7,10},{7,12},{7,5},{7,4},{7,2}},
			{{1,2},{2,4},{3,2},{4,1},{7,10},{7,12},{7,5},{7,4},{7,2}}};
		for(auto e : v) {
			vector<int> op = getOrder(e);
			for(int i : op)
				cout << i << " ";
			cout << "\n";
		}
	}
	return 0;
}

