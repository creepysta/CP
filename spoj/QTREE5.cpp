/*
    author: Creepysta
    01-06-2021 02:11:34
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9) + 7;
#define int64_t int;
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

vector<int> U, V, W, sub, par, level;
vector<vector<int>> t, g, dist;
vector<bool> deleted;
int n, sz, LOG;

int adj(int x, int e) { return U[e] ^ V[e] ^ x; }

void dfs(int u, int p = -1) {
    sub[u] = 1;
    sz++;
    for(int e : g[u]) {
        int v = adj(u, e);
        if(v != p && !deleted[e]) {
            dfs(v, u);
            sub[u] += sub[v];
        }
    }
}

void find_centroid(int u, int p) {
    for(int e : g[u]) {
        if(deleted[e]) continue;
        int v = adj(u, e);
        if(v != p && sub[v] > sz / 2)
            return find_centroid(v, u);
    }
    return u;
}

void add_edge(int parent, int child) {
    par[child] = parent;
    level[child] = level[parent] + 1;
}

void dfs2(int u, int p, int lvl) {
    for(int e : g[u]) {
        int v = adj(u, e);
        if(v == p || deleted[e]) continue;
        dist[lvl][w] = dist[lvl][u] + W[e];
        dfs2(v, u, lvl);
    }
}

void decompose(int root, int p = -1) {
    sz = 0;
    dfs(root, root);
    int centroid = find_centroid(root, root);
    if(p == -1) p = root;
    add_edge(p, centroid);
    dfs2(centroid, centroid, level[centroid]);
    for(int e : g[centroid]) {
        if(deleted[e]) continue;
        deleted[e] = 1;
        int v = adj(centroid, e);
        decompose(v, centroid);
    }
}

void solve() {
    int n;
    cin >> n;
    U = vector<int> (n+1);
    V = vector<int> (n+1);
    W = vector<int> (n+1);
    for(int i = 1; i < n; i++) {
        cin >> U[i] >> V[i];
        W[i] = 1;
        g[U[i]].push_back(i);
        g[V[i]].push_back(i);
    }
    decompose(1);
    int m;
    cin >> m;
    while(m--) {
        int i, v;
        cin >> i >> v;
        if(i) {

        } else {

        }
    }
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

