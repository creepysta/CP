/*
    author: Creepysta
    22-09-2021 20:45:24
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

vector<bool> vis;
vector<vector<int>> g;
int comp;

void dfs(int u) {
    vis[u] = 1;
    for(int v : g[u]) {
        if(!vis[v]) {
            dfs(v);
            comp++;
        }
    }
}

void solve(int n, int m, vector<vector<int>> &a, int x) {
    g.resize(n);
    for(int i = 0; i < m; i++) {
        g[a[i][0]].push_back(a[i][1]);
        g[a[i][1]].push_back(a[i][0]);
    }
    debug(n, m, x);
    vector<int> c;
    vis.assign(n, 0);
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            comp = 1;
            dfs(i);
            c.push_back(comp);
        }
    }
    sort(begin(c), end(c));
    vector<bool> dp(x+4);
    dp[0] = 1;
    for(int i = 0; i < (int)c.size(); i++) {
        for(int j = 1; j <= x; j++) {
            if(j >= c[i])
                dp[j] = dp[j] || dp[j-c[i]];
        }
    }
    while(!dp[x])
        x--;
    debug(c, dp, x);
    int ans = 0;
    //for(int i = 0; i < x; i++) {
        //ans += c[i];
    //}
    ans = x;
    cout << ans << '\n';
}

int32_t main() {
    FIO;
    int t = 1;
    for(int tt = 1; tt <= t; tt++) {
        // cout << "Case #" << tt << ": ";
        int n, m, x;
        cin >> n >> m >> x;
        vector<vector<int>> a(m, vector<int> (2));
        for(int i = 0; i < m; i++) cin >> a[i][0] >> a[i][1];
        solve(n, m, a, x);
    }
    return 0;
}

