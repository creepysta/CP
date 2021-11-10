/*
    author: Creepysta
    23-10-2021 12:29:34
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
    int n;
    cin >> n;
    int big = -INF;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        big = max(big, a[i]);
    }
    const int mod = 1e5;
    for(int exp = 1; big/exp > 0; exp *= 1e5) {
        vector<int> count(1e6), op(n);
        for(int i = 0; i < n; i++)
            count[(a[i]/exp)%mod]++;
        for(int i = 1; i < 1e6; i++)
            count[i] += count[i-1];
        op.clear();
        for(int i = n-1; i >= 0; i--)
            op[--count[(a[i]/exp)%mod]] = a[i];
        for(int i = 0; i < n; i++)
            a[i] = op[i];
        for(int i : a)
            cout << i << ' ';
        cout << '\n';
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

