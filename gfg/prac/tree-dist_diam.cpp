/*
    author: Creepysta
    27-09-2021 20:23:00
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9) + 7;
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
int dist = 0, node;
vector<pair<int, int>> order;

void dfs(int u, int p = -1, int h = 0) {
    debug(u, p, h);
    order.emplace_back(u, h);
    for(int v : g[u]) {
        if(v == p) continue;
        dfs(v, u, h + 1);
        if(h > dist) {
            dist = h;
            node = v;
        }
    }
}

void solve() {
    int n, x;
    cin >> n >> x;
    x--;
    g.assign(n, vector<int> ());
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    debug(n, x, g);
    order.clear();
    dfs(x);
    debug(order);
    int ans = -1;
    for(auto i : order)
        ans = max(ans, i.second);
    cout << ans << '\n';
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

