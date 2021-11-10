/*
    author: Creepysta
    23-09-2021 20:39:30
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    for(int i = 1; i < m; i++)
        a[0][i] += a[0][i-1];
    debug(a);
    for(int i = 1; i < n; i++)
        a[i][0] += a[i-1][0];
    debug(a);
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++)
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
    }
    debug(a);
    int q;
    cin >> q;
    while(q--) {
        int r1,c1,r2,c2;
        bool got = 0;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;c1--;r2--;c2--;
        debug(r1,c1,r2,c2);
        int ans = a[r2][c2];
        if(r1 > 0) {
            ans -= a[r1-1][c1];
            got = 1;
        }
        if(c1 > 0) {
            ans -= a[r1][c1-1];
            got = 1;
        }
        if(got)
            ans += a[r1-1][c1-1];
        cout << ans << '\n';
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

/*
public static void preprocessGrid() {
    for(int i = y-2; i >= 0; i--) {
        grid[i][0] += grid[i+1][0];
    }
    for(int i = 1; i < x; i++) {
        grid[y-1][i] += grid[y-1][i-1];
    }
    for(int i = y-2; i >= 0; i--) {
        for(int j = 1; j < x; j++) {
            grid[i][j] += grid[i+1][j] + grid[i][j-1] - grid[i+1][j-1];
        }
    }
}
public static int fastQuery(int lx, int lr, int hx, int hr) {
    lx--;hx--;lr--;hr--;
    lr = y - 1 - lr;
    hr = y - 1 - hr;
    int ans = grid[hr][hx];
    boolean got = false;
    if(lr + 1 < y) {
        ans -= grid[lr+1][hx];
        got = true;
    }
    if(lx - 1 > -1) {
        ans -= grid[hr][lx-1];
        got = true;
    }
    if(got) {
         ans += grid[lr+1][lx-1];
    }
    return ans;
}
*/
