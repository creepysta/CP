/*
    author: Creepysta
    14-07-2021 20:04:43
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1e12) + 7;
const int MOD = int(1e9) + 7;
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

int n, k;
vector<vector<int>> g;
vector<bool> vis;
vector<vector<int>> paths;

vector<vector<int>> a;
vector<int> dfs(int u, int p = -1) {
    vis[u] = 1;
    vector<int> temp;
    for(int v : g[u]) {
        if(v == p) continue;
        auto got = dfs(v, u);
        for(int i : got)
            temp.push_back(i);
        a[u] = temp;
        debug(got, temp, a);
    }
    temp.push_back(u);
    return temp;
}

void solve() {
    cin >> n >> k;
    g.clear(); g.resize(n);
    paths.clear(); paths.resize(n);
    a.clear(); a.resize(n);
    vis.assign(n, false);
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(2, 2);
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

