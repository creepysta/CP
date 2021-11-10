/*
    author: Creepysta
    23-10-2021 17:42:22
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
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(begin(a), end(a));
    debug(a);
    for(int i = 0; i < n; i++) {
        int j = i, req = a[i].first + l, big = a[i].second;
        for(; j < n; j++) {
            if(big >= a[j].first && a[j].second <= req)
                big = max(big, a[j].second);
        }
        if(big == req) {
            cout << "Yes\n";
            return;
        }
        //while(j < n && big >= a[j].first) {
            //small = min(small, a[j].first);
            //big = max(big, a[j].second);
            //debug(small, big);
            //if(big-small == l) {
                //cout << "Yes\n";
                //return;
            //}
            //j++;
        //}
    }
    cout << "No\n";
}

int32_t main() {
    FIO;
    int t = 1;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        // cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}

