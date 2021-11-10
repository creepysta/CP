/*
    author: Creepysta
    22-08-2021 11:52:51
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

array<pair<int, int>, 1 << 20> dp;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int &i : a)
        cin >> i;
    fill(dp.begin(), dp.end(), make_pair(n+1, 0));
    dp[0] = {1, 0};
    for(int s = 1; s < 1<<20; s++) {
        for(int p = 0; p < n; p++) {
            if(s & (1 << p)) {
                auto option = dp[s ^ (1 << p)];
                if(option.second + a[p] <= x) {
                    option.second += a[p];
                } else {
                    option.first++;
                    option.second = a[p];
                }
                dp[s] = min(dp[s], option);
            }
        }
    }
    int ans = dp[(1<<n) -1].first;
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

