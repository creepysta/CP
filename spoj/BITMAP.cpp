/*
	author: Creepysta
	28-05-2021 22:40:34
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9) + 7;
#define int int64_t
#ifdef LOCAL
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << boolalpha << "[ "; err(_it, args); }
#else
#define debug(args...) ;
#define FIO ;
#endif
#define tmpt template < class T
#define ostop ostream& operator<<(ostream& o
#define itfr { if(x.empty()) {cout<<"[ ]";return o;} o<<"[";for(auto e:x) o<<e<<", ";o<<"\b\b]";return o;}
void err(istream_iterator<string> it) {cerr<<"\b\b ]\n";}
tmpt , class... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr<<*it<<": "<<a<< ", ";err(++it,args...);}
tmpt > ostop , const vector<T> &x) itfr
tmpt > ostop , const set<T> &x) itfr
tmpt > ostop , const multiset<T> &x) itfr
tmpt , class V> ostop , const map<T,V> &x) itfr
tmpt , class V> ostop , const pair<T,V> &p) {o<<"(";o<<p.first<<", "<<p.second<<")";return o;}

int n, m;
vector<vector<int>> a;
vector<vector<int>> dis;
vector<vector<bool>> vis;
typedef pair<int, int> pii;
const vector<pii> dirs { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
#define F first
#define S second

bool valid(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < m);
}

int get(int i, int j) {
	vis = vector<vector<bool>>(n, vector<bool> (m));
	dis = vector<vector<int>>(n, vector<int> (m));
	queue<pii> q;
	q.emplace(i, j);
	vis[i][j] = 1;
	while(q.size()) {
		pii u = q.front();
		q.pop();
		for(auto d : dirs) {
			int x = u.F + d.F,
				y = u.S + d.S;
			if(valid(x, y) && !vis[x][y]) {
				q.emplace(x, y);
				vis[x][y] = 1;
				dis[x][y] = dis[u.F][u.S] + 1;
				if(a[x][y] == 1)
					return dis[x][y];
			}
		}
	}
	return -1;
}

void solve(int t) {
#ifndef LOCAL
	cin >> n >> m;
	a = vector<vector<int>> (n, vector<int> (m));
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < m; j++)
			a[i][j] = s[j] - '0';
	}
#else
	mt19937 rng(t);
	auto rand = [&](int x, int y) {
		return x + rng() % (y-x);
	};
	n = rand(1, 182), m = rand(1, 182);
	n = 182;
	m = 182;
	int ones = 0;
	a = vector<vector<int>> (n, vector<int> (m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int x = rand(0, 100);
			if(x <= 30)
				a[i][j] = 1, ones++;
		}
	}
	debug(n, m, ones);
#endif
	//vis = vector<vector<bool>>(n, vector<bool> (m));
	//dis = vector<vector<int>>(n, vector<int> (m));
	//vector<vector<int>> ans (n, vector<int> (m));
	//for(int i = 0; i < n; i++) {
		//for(int j = 0; j < m; j++) {
			//if(a[i][j])
				//cout << 0 << " ";
				//ans[i][j] = 0;
			//else
				//cout << get(i, j) << " ";
				//ans[i][j] = get(i, j);

		//}
		//cout << "\n";
	//}
	vis = vector<vector<bool>>(n, vector<bool> (m));
	dis = vector<vector<int>>(n, vector<int> (m));
	queue<pii> q;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j])
				q.emplace(i, j), vis[i][j] = 1;
		}
	}
	auto multiSrcBfs = [&] () {
		while(q.size()) {
			pii u = q.front();
			q.pop();
			for(pii d : dirs) {
				int dx = u.F + d.F,
					dy = u.S + d.S;
				if(valid(dx, dy) && !vis[dx][dy] && !a[dx][dy]) {
					q.emplace(dx, dy);
					vis[dx][dy] = 1;
					dis[dx][dy] = dis[u.F][u.S] +1;
				}
			}
		}
	};
	multiSrcBfs();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << dis[i][j] << " ";
		}
		cout << "\n";
	}
	//assert(dis == ans);
}



int32_t main() {
	FIO;
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		auto t1 = chrono::high_resolution_clock::now();
		solve(tt);
		auto t2 = chrono::high_resolution_clock::now();
		auto timeDiff = chrono::duration_cast<chrono::duration<double>>
			(t2-t1).count();
		debug(timeDiff);
	}
	return 0;
}

