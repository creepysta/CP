/*
    author: Creepysta
    29-09-2021 01:25:42
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1e12) + 7;
const int MOD = int(1e9) + 7;
#ifdef LOCAL
#define FIO ;
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << boolalpha << "[ "; err(_it, args); }
#else
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(args...) ;
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

vector<vector<int>> g;
vector<int> order;
vector<bool> vis;

void dfs(int u) {
    vis[u] = 1;
    for(int v : g[u]) {
        if(vis[v]) continue;
        dfs(u);
    }
    order.push_back(u);
}

void solve() {
    int n;
    cin >> n;
    g.assign(n, vector<int>());
    vis.assign(n, 0);
    order.clear();
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
    }
    for(int i = 0; i < n; i++) {
        if(!vis[i])
            dfs(i);
    }
    reverse(begin(order), end(order));
    for(int v : order)
        cout << v << ' ';
    cout << '\n';
}


int32_t main() {
    FIO;
    int t = 1;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        // cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}
