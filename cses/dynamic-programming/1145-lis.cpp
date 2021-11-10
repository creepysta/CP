/*
    author: Creepysta
    19-08-2021 22:56:07
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
vector<int> a;

void dp1() {
    vector<int> dp(n+1, INF);
    dp[0] = -INF;
    for(int i = 0; i < n; i++) {
        //for(int j = 1; j <= n; j++) {
            //if(dp[j-1] < a[i] && a[i] < dp[j]) {
                //dp[j] = a[i];
            //}
        //}
        int j = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if(dp[j-1] < a[i] && a[i] < dp[j]) {
            dp[j] = a[i];
        }
    }
    debug(a);
    debug(dp);
    int ans = 0;
    for(int i = 0; i <= n; i++)
        if(dp[i] < INF)
            ans = i;
    cout << ans << '\n';
}

void dp2() {
    vector<int> dp(n+1, 1);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    debug(dp);
}

void solve() {
    cin >> n;
    //a.assign(0, n);
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp1();
    dp2();
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

