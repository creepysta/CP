/*
    author: Creepysta
    07-08-2021 20:02:30
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
    vector<vector<int>> dp(n + 1, vector<int> (m+1));
    for(int len = 1; len <= n; len++) {
        for(int wid = 1; wid <= m; wid++) {
            if(len == wid) dp[len][wid] = 0;
            else {
                int ans = INF;
                for(int i = 1; i < wid; i++) {
                    ans = min(ans, 1 + dp[len][wid-i] + dp[len][i]);
                }
                for(int i = 1; i < len; i++) {
                    ans = min(ans, 1 + dp[len-i][wid] + dp[i][wid]);
                }
                dp[len][wid] = ans;
            }
        }
    }
    cout << dp[n][m] << '\n';
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

