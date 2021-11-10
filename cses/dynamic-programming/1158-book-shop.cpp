/*
    author: Creepysta
    03-07-2021 12:17:07
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
    int n, x;
    cin >> n >> x;
    vector<int> price(n+1), pages(n+1);
    for(int i = 0; i < n; i++)
        cin >> price[i+1];
    for(int i = 0; i < n; i++)
        cin >> pages[i+1];
    int dp[n+1][x+1];
    for(int i = 0; i <= n; i++) {
        for(int amt = 0; amt <= x; amt++) {
            if(!amt || !i)
                dp[i][amt] = 0;
            else {
                int op1 = dp[i-1][amt];
                int op2 = 0;
                if(amt >=  price[i])
                    op2 = pages[i] + dp[i-1][amt - price[i]];
                dp[i][amt] = max(op1, op2);
            }
        }
    }
    int ans = dp[n][x];
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
