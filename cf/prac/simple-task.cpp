//https://codeforces.com/contest/11/problem/D
//https://codeforces.com/blog/entry/337
/*
    author: Creepysta
    11-07-2021 12:03:32
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1e12) + 7;
const int MOD = int(1e9) + 7;
#ifdef LOCAL
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << fixed << setprecision(10) << boolalpha << "[ "; err(_it, args); }
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
vector<vector<int>> g;
vector<vector<int>> dp(19);

string bin(int vis=0) {
    string s = "";
    for(int i = 5; i >= 0; i--) {
        s += (vis & (1 << i)) ? "1" : "0";
    }
    return s;
}

int recur(int mask, int u, int i) {
    int &val = dp[i][mask];
    if(val != -1) return val;
    val = 0;
    if(__builtin_popcount(mask) >= 3 && g[i][u]) val ++;
    for(int v = u; v < n; v++) {
        if(mask & (1 << v)) continue;
        if(g[i][v]) val += recur(mask | (1 << v), u, v);
    }
    return val;
}

int iter() {
    fill(dp.begin(), dp.end(), vector<int> (1 << 19, -1));
    for(int start = 0; start < n; start++) {
        for(int mask = 0; mask < (1<<n - start - 1); mask++) {
            for (int j = 0; j < n; j++) {

            }
        }

    }
}

void solve() {
    cin >> n >> m;
    g.clear(); g.resize(n, vector<int> (n));
    fill(dp.begin(), dp.end(), vector<int> (1 << 19, -1));
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x][y] = g[y][x] = 1;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += recur(1 << i, i, i);
    }
    cout << ans/2 << '\n';
}

int32_t main() {
    FIO;
    int t = 1;
    for(int tt = 1; tt <= t; tt++) {
        // cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}

