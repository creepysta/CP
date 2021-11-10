/*
    author: Creepysta
    14-08-2021 23:58:39
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
    int n;
    cin >> n;
    vector<int> a(n+1);
    int m = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i+1];
    }
    m = n*1000;
    vector<vector<bool>> dp(n+1, vector<bool> (m+1));
    sort(begin(a), end(a));
    debug(a);
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= a[i])
                dp[i][j] = dp[i][j] || dp[i-1][j-a[i]];
        }
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(j && dp[i][j])
                ans.push_back(j);
        }
    }
    sort(begin(ans), end(ans));
    int d = unique(begin(ans), end(ans)) - begin(ans);
    cout << d << '\n';
    for(int i = 0; i < d; i++)
        cout << ans[i] << " ";
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

