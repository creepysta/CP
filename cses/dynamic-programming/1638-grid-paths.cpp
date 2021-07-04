/*
    author: Creepysta
    01-07-2021 13:20:55
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

int n;
vector<string> g;
vector<vector<bool>> vis;
vector<vector<int>> dp;
const vector<pair<int, int>> dirs{{0,1}, {1, 0}};

bool valid(int u, int v) {
    return 0 <= u && u < n && 0 <= v && v < n && !vis[u][v] && g[u][v] != '*';
}

int get(int u, int v) {
    if( u == n-1 && v == n-1 ) {
        return 1;
    }
    int ans = 0;
    vis[u][v] = 1;
    for(auto d : dirs) {
        int du = u + d.first;
        int dv = v + d.second;
        if(valid(du, dv)) ans = (ans + get(du, dv)) % MOD;
    }
    vis[u][v] = 0;
    return ans;
}

void solve() {
    cin >> n;
    g = vector<string> (n);
    vis = vector<vector<bool>> (n, vector<bool> (n, 0));
    for(int i = 0; i < n; i++)
        cin >> g[i];
    int paths = 0;
    dp = vector<vector<int>>(n, vector<int> (n, 0));
    if(valid(n-1, n-1) && valid(0, 0)) {
        dp[n-1][n-1] = 1;
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                for (auto d : dirs) {
                    int du = i - d.first,
                        dv = j - d.second;
                    if(valid(i, j) && valid(du, dv)) {
                        dp[du][dv] = (dp[du][dv] + dp[i][j]) % MOD;
                    }
                }
            }
        }
        //vis = vector<vector<bool>> (n, vector<bool> (n, 0));
        //paths = get(0, 0);
        //debug(paths, dp[0][0]);
        //assert(paths == dp[0][0]);
        paths = dp[0][0];

    }
    cout << paths << '\n';
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

