/*
author: Creepysta
16-05-2021 18:40:53
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

/*
   If you step into air, your health increases by 3 and your armor increases by 2

   If you step into water, your health decreases by 5 and your armor decreases by 10

   If you step into fire, your health decreases by 20 and your armor increases by 5
 * */
struct p {
	int x, y; // health -> x, armor -> y;
	p() : x(0), y(0) {}
	p(int _x, int _y) : x(_x), y(_y) {}
	void read () {
		cin >> x >> y;
	}
	void operator += (const p& o) { x+= o.x, y+= o.y; }
	p operator + (const p& o) { return {x + o.x, y+o.y}; }
	bool check() { return x<=0 || y<=0; }
};


const int MAX_N = 1005;
int dp[1010][1010][3];
const vector<vector<int>> moves {{2, 1}, {0, 2}, {1, 0}};
const vector<p> rules{{3, 2}, {-5, -10}, {-20, 5}};
vector<int> path;

int brute(p I, int pos=0, int h = 0) {
	p P1 = I;
	p P2 = rules[pos];
	p P = P1 + P2;
	if(P.check())
		return h;
	int pv = brute(P, moves[pos][0], h+1);
	int nx = brute(P, moves[pos][1], h+1);
	int now = max(pv, nx);
	return now;
}

int f(int h,int a,int c)
{
	if(a <= 0 || h <= 0) {
		return 0;
	}
	if(dp[h][a][c] != -1)
		return dp[h][a][c];
	dp[h][a][c] = max(
			f(h+rules[moves[c][0]].x, a+rules[moves[c][0]].y, moves[c][0]),
			f(h+rules[moves[c][1]].x, a+rules[moves[c][1]].y, moves[c][1])
			) + 1;
	return dp[h][a][c];

}

int mem(p I, int pos) {
	if(I.check())
		return 0;
	if(dp[I.x][I.y][pos] != -1)
		return dp[I.x][I.y][pos];
	p PV = I + rules[moves[pos][0]];
	p NV = I + rules[moves[pos][1]];
	int pv = mem(PV, moves[pos][0]);
	int nx = mem(NV, moves[pos][1]);
	return dp[I.x][I.y][pos] = max(pv, nx) + 1;
}

int test(p I, int pos) {
	p now = I + rules[pos];
	if(now.check())
		return 0;
	int &val = dp[now.x][now.y][pos];
	if(val != -1)
		return val;
	int pv = test(now, moves[pos][0]);
	int nv = test(now, moves[pos][1]);
	val = max(pv, nv) + 1;
	return val;
}

int test1(p I, int pos, int h = 0) {
	p now = I + rules[pos];
	if(now.check())
		return h;
	int &val = dp[now.x][now.y][pos];
	if(val != -1)
		return val;
	val = max(test1(now, moves[pos][0], h+1), test1(now, moves[pos][1], h+1));
	return val;
}

void solve() {
	p init;
	init.read();
	memset(dp, -1, sizeof(dp));
	int got = -1;
	//got = brute(init);
	//got = mem(init + rules[0], 0);
	got = test(init, 0);
	//got = test1(init, 0);
	cout << got << "\n";
	//debug(path);
}

int32_t main() {
	FIO;
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		path.clear();
		solve();
	}
	return 0;
}

