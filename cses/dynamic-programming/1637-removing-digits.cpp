/*
    author: Creepysta
    29-06-2021 22:26:32
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
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

const int INF = 1e12 + 7;
vector<int> dp;

int get(int n) {
    if(n == 0) return 0;
    if(dp[n] != INF)
        return dp[n];
    string now = to_string(n);
    for(char c : now) {
        int dig = c-'0';
        if(dig) {
            int rem = n - dig;
            dp[n] = min(dp[n], get(rem) + 1);
        }
    }
    return dp[n];
}

void solve() {
    int n, ans;
    cin >> n;
    dp = vector<int> (n+1, INF);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        int t = i;
        while(t) {
            int digit = t % 10;
            dp[i] = min(dp[i], dp[i-digit] + 1);
            t /= 10;
        }
        debug(i, dp);
    }
    ans = dp[n];
    cout << ans << '\n';
    debug(get(n), dp[n]);
    assert(ans = get(n));
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

