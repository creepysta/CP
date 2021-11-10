/*
    author: Creepysta
    06-10-2021 21:27:39
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
vector<int> vals, subt, trav, tval;

void dfs(int u, int p=-1) {
    trav.emplace_back(u+1);
    tval.emplace_back(vals[u]);
    subt[u] = 1;
    for(int v : g[u]) {
        if(v != p) {
            dfs(v, u);
            subt[u] += subt[v];
        }
    }
}

void solve() {
    int n;
    cin >> n;
    g.assign(n, vector<int> ());
    subt.assign(n, 0);
    for(int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vals.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> vals[i];
    }
    dfs(0);
    //reverse(trav.begin(), trav.end());
    debug(trav);
    cout << "[ subt: [";
    for(int i = 0; i < n; i++)
        cout << subt[trav[i]-1] << ", ";
    cout << "\b\b] ]\n";
    debug(tval);
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

