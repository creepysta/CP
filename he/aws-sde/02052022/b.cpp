// minimize the difference between max and min XOR if 2 edges are cut to make 3
// forests
/*
    author: Creepysta
    03-05-2022 12:28:12
*/
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using tree_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
vector<bool> vis;
vector<int> ts;

void dfs(int u, int p=-1) {
    for(int v : g[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    ts.push_back(u);
}


struct st {
    int size;
    vector<int> vec;
    void init(int n) {
        size = 1;
        while(size < n) size <<= 1;
        vec.assign(2*size-1, 0);
    }
    void build(const vector<int> &a, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) a.size()) {
                vec[x] = a[lx];
            }
            return;
        }
        int mid = lx + (rx - lx) /2;
        build(a, 2*x+1, lx, mid);
        build(a, 2*x+2, mid, rx);
        vec[x] = vec[2*x+1] + vec[2*x + 2];
    }
    void build(const vector<int> &a) {
        build(a, 0, 0, size);
    }
    int query(int l, int r, int x, int lx, int rx) {
        if(lx >= r || l >= rx) return 0;
        if(lx >= l && rx <= r) return vec[x];
        int mid = lx + (rx - lx) / 2;
        int ql = query(l, r, 2*x+1, lx, mid);
        int qr = query(l, r, 2*x+2, mid, rx);
        return ql + qr;
    }
    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

void solve() {
    int n;
    cin >> n;
    g = vector<vector<int>> (n+1);
    vis.assign(n+1, false);
    ts.clear();
    for(int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    debug(g);
    dfs(1);
    reverse(begin(ts), end(ts));
    debug(ts);
    int tn = ts.size();
    st s;
    s.init(tn);
    s.build(ts);
    int ans = INF;
    for(int i = 0; i < tn; i++) {
        for(int j = i + 1; j < tn-1; j++) {
            vector<int> check(3);
            check[0] = s.query(0, i+1);
            check[1] = s.query(i+1, j+1);
            check[2] = s.query(j+1, tn);
            int f = 0, e = tn-1;
            debug(f, i, j, e, check);
            sort(begin(check), end(check));
            int now = check[2] - check[0];
            ans = min(ans, now);
        }
    }
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

