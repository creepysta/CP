/*
    author: Creepysta
    10-07-2021 11:36:59
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

//2 _ _

//_ _ 1 _
//_ 1 1 _
//_ _ 1 _
//_ _ _ _

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i = 0; i < n; i++)
        cin >> a[i+1];
    vector<vector<int>> dp(n+1, vector<int> (m+2, 0));
    debug(m, a);
    int ans = 0;
    if(a[1])
        dp[1][a[1]] = 1;
    else
        for(int j = 1; j <= m; j++)
            dp[1][j] = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i]) {
            //int paths = 0;
            //for(int j = 1; j <= m; j++) {
                //if(abs(j - a[i]) <= 1)
                    //paths = (paths + dp[i-1][j]) % MOD;
            //}
            //dp[i][a[i]] = paths;
            //ans = (ans + paths) % MOD;

            dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][a[i]-1] + dp[i-1][a[i]] + dp[i-1][a[i]+1]) % MOD;
        } else {
            //if(a[i-1]) {
                //for(int j = 1; j <= m; j++) {
                    //if(abs(j - a[i-1]) <= 1)
                        //dp[i][j] = 1;
                //}
            //} else {
                for(int j = 1; j <= m; j++) {
                    //int low = 1;
                    //int diff = min(m, j + 1) - max(low, j - 1) + 1;
                    //dp[i][j] = (dp[i-1][j] * diff) % MOD;
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD;
                }
            //}
        }
    }
    debug(dp);
    //if(!a[n]) {
        for(int j = 1; j <= m; j++) {
            ans = (ans + dp[n][j]) % MOD;
        }
    //}
    cout << ans << '\n';
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

