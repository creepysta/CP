/*
    author: Creepysta
    28-09-2021 21:36:42
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

vector<int> a;
vector<vector<int>> g;

void solve() {
    int n;
    cin >> n;
    a.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    g.assign(n, vector<int> ());
    for(int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    queue<int> q;
    vector<bool> vis(n, 0);
    q.push(0);
    vis[0] = 1;
    bool even = 1;
    int s1 = 0, s2 = 0, cnt = q.size();
    while(q.size()) {
        int node = q.front();
        q.pop();
        for(int v : g[node]) {
            if(!vis[v]) {
                q.push(v);
                vis[v] = 1;
            }
        }
        if(even) s1 += a[node];
        else s2 += a[node];
        if(--cnt == 0) {
            even = !even;
            cnt = q.size();
        }
    }
    int ans = abs(s1 - s2);
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

