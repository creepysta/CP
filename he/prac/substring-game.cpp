/*
    author: Creepysta
    22-10-2021 21:00:40
*/
#include <bits/stdc++.h>
using namespace std;
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

void solve() {
    string s;
    getline(cin, s);
    int n = s.length();
    vector<int> pref(n+1);
    for(int i = 1; i <= n; i++)
        pref[i] += n-i+1 + pref[i-1];
    int q, kth;
    cin >> q;
    debug(pref);
    while(q--) {
        cin >> kth;
        int p = lower_bound(begin(pref), end(pref), kth) - begin(pref);
        int up = upper_bound(begin(pref), end(pref), kth) - begin(pref);
        debug(kth, p, up);
        if(kth <= (n*(n+1))/2 && kth >= 1) {
            kth -= pref[p-1];
            string ans = s.substr(p-1, kth);
            cout << ans << '\n';
        } else
            cout << -1 << '\n';
    }
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

