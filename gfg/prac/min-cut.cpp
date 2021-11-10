/*
    author: Creepysta
    30-09-2021 22:47:37
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

vector<vector<int>> g, cap, rg;
vector<int> parent;
vector<bool> vis;

int bfs(int s, int t) {
    fill(parent.begin(), parent.end(), -1);
    fill(vis.begin(), vis.end(), 0);
    parent[s] = -1;
    vis[s] = 1;
    queue<pair<int, int>> q;
    q.push({s, INF});
    while(q.size()) {
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();
        for(int v : g[u]) {
            if(!vis[v] && cap[u][v]) {
                parnet[v] = u;
                int new_flow = min(flow, cap[u][v]);
                if(v == t)
                    return new_flow;
                q.push({v, new_flow});
                vis[v] = 1;
            }
        }
    }
    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    int new_flow;
    while(new_flow = bfs(s, t)) {
        flow += new_flow;
        int v = t;
        while(v != s) {
            int par = parent[v];
            cap[par][v] -= new_flow;
            cap[v][par] += new_flow;
            v = par;
        }
    }
    return flow;
}

void dfs(int u) {
    vis[u] = 1;
    for(int v : g[u]) {
        if(!vis[v] && cap[u][v])
            dfs(v);
    }
}

void solve() {
    int n, s, t;
    cin >> n >> s >> t;
    g.assign(n, vector<int>());
    cap.assign(n, vector<int>());
    vis.assign(n, false);
    parent.assign(n, -1);
    for(int i = 0; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].push_back(y);
        g[y].push_back(x);
        cap[x][y] = c;
    }
    rg = cap;
    int flow = maxflow(int s, int t);
    vis.assign(n, 0);
    dfs(s);
    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(vis[i] && !vis[j] && rg[i][j]) {
                ans.emplace_back(i, j);
            }
        }
    }
    for(auto p : ans) {
        cout << i << '-' << j << '\n';
    }
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

